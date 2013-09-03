/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "./gpio.hpp"

namespace rpi {
	namespace io {
		void setPUDLow( GPPIOPUD setting , uint32_t lines ) {
			GPPUD.set( static_cast<uint32_t>( setting ) ) ;
			cpu::delay( 150 ) ;

			GPPUDCLK0.set( lines ) ;
			cpu::delay( 150 ) ;
			GPPUDCLK0.set( 0x00000000 ) ;
		}

		void setPUDHigh( GPPIOPUD setting , uint32_t lines ) {
			GPPUD.set( static_cast<uint32_t>( setting ) ) ;
			cpu::delay( 150 ) ;

			GPPUDCLK1.set( lines ) ;
			cpu::delay( 150 ) ;
			GPPUDCLK1.set( 0x00000000 ) ;
		}	
	}
}
