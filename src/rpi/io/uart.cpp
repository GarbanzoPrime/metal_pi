/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "rpi/io/uart.hpp"
#include "rpi/gpu/clock.hpp"
#include "rpi/cpu/timing.hpp"

namespace rpi {
	namespace uart0 {
		void enable( unsigned int baud_rate ) {
			io::UART0_CR.set( Control::DISABLE ) ;

			io::setPUDLow( io::GPPIOPUD::OFF ,
							 io::GPPIO_14 | io::GPPIO_15 ) ;

			// Clear pending interrupts.
			io::UART0_ICR.set( 0x7FF ) ;

			//we are going to assume no one is going to be messing with that clock rate from now on
			units::Hertz<uint32_t , units::ratio<1> > uart_clock_rate = gpu::getClockRate( gpu::ClockId::UART ) ;
			auto baud_rate_16 = baud_rate * 16 ;

			io::UART0_IBRD.set( uart_clock_rate.count() / baud_rate_16 ) ;
			io::UART0_FBRD.set( ( ( ( uart_clock_rate.count() % baud_rate_16 ) * 4 ) + (baud_rate / 2 ) ) / baud_rate ) ;

			io::UART0_LCRH.set( LineControl::FEN | LineControl::BITS_8 ) ;

			//TODO: add api control over interrupts
			io::UART0_IMSC.set( Interupt::ALL ) ;

			io::UART0_CR.set( Control::ENABLE | Control::TXE | Control::RXE ) ;
		}


		void write( uint8_t byte ) {
			while( testFlag( Flag::TXFF ) ) { }

			io::UART0_DR.set( byte ) ;
		}

		uint8_t read() {
			while( testFlag( Flag::RXFE ) ) { }

			return io::UART0_DR.get() ; 
		}

		void read( uint8_t* target , size_t bytes ) {
			for( size_t i = 0 ; i < bytes ; ++i ) {
				target[i] = read() ;
			}
		}

		bool testFlag( Flag::Val flags ) {
			return ( io::UART0_FR.get() & flags ) != 0 ;
		}

		//I am putting this in as a necessity, but I thoroughly dislike it...
		void writeStr( const char * str ) {
			while(*str) {
			    write(*str++);
			}
		}
	}
}
