/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_IO_UART_fe8420d1_0da5_4e61_acec_a4691542b6a7
#define RPI_IO_UART_fe8420d1_0da5_4e61_acec_a4691542b6a7

#include "rpi/config.hpp"

#include "kul/units.hpp"
#include "gpio.hpp"

namespace rpi {
	namespace uart0 {
		void enable( Baud baud_rate ) ;

		struct LineControl { 
			enum Val : uint32_t {
				BRK  = 1 ,
				PEN  = 1 << 1 ,
				EPS  = 1 << 2 ,
				STP2 = 1 << 3 ,
				FEN  = 1 << 4 ,

				BITS_5 = 0x0,

				//TODO: BITS_6 and BITS_7 may very be inverted, please test
				BITS_6 = 1 << 5 ,
				BITS_7 = 2 << 5 ,

				BITS_8 = 3 << 5 ,

				SPS = 1 << 7 
			} ; 
		} ;

		struct Control {
			enum Val : uint32_t {
				ENABLE = 1 ,
				//SIRENT = 1 << 1 ,
				//SIRPL = 1 << 2 ,
				LBE = 1 << 7 ,
				TXE = 1 << 8 ,
				RXE = 1 << 9 ,
				//DTR = 1 << 10 ,
				RTS = 1 << 11 ,
				//OUT1 = 1 <<12 ,
				//OUT2 = 1 <<13 ,
				RTSEN = 1 << 14 ,
				CTSEN = 1 << 15 ,

				DISABLE = 0  
			} ;
		};

		struct Interupt {
			enum Val : uint32_t {
				//RIMIC = 1 ,
				CTSMIC = 1 << 1 ,
				//DCDMIC = 1 << 2 ,
				//DSRMIC = 1 << 3 ,
				RXIC = 1 << 4 ,
				TXIC = 1 << 5 ,
				RTIC = 1 << 6 ,
				FEIC = 1 << 7 ,
				PEIC = 1 << 8 ,
				BEIC = 1 << 9 ,
				OEIC = 1 << 10 ,

				ALL = CTSMIC | RXIC | TXIC | RTIC | FEIC | PEIC | BEIC | OEIC
			} ;
		};

		struct Flag {
			enum Val :uint32_t {
				TXFE = 1 << 7 ,
				RXFF = 1 << 6 ,
				TXFF = 1 << 5,
				RXFE = 1 << 4 ,
				BUSY = 1 << 3 ,
			} ;
		} ;

		bool testFlag( Flag::Val flags );



		
		uint8_t read() ;
		void read( uint8_t* target , size_t bytes ) ;
		template<typename T>		
		void read( T & into ) {
			read( reinterpret_cast<uint8_t*>( &into ) , sizeof( T ) ) ;		
		}

		void write( uint8_t byte ) ;
		template< typename ITE >
		void write( ITE begin , ITE end ) {
			while( begin != end ) {
				write( *begin ) ;
				++begin ;
			}
		}

		//I am putting this in as a necessity, but I thoroughly dislike it...
		void writeStr( const char * str ) ;
	}
}

#endif