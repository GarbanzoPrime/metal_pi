/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_IO_GPIO_330d10d3_a5d1_46a3_a79e_63afc2a98adb
#define RPI_IO_GPIO_330d10d3_a5d1_46a3_a79e_63afc2a98adb

#include "rpi/config.hpp"
#include "./memory_locations.hpp"
#include "./constants.hpp"

namespace rpi {
	namespace io {
		void setPUDLow( GPPIOPUD setting , uint32_t lines ) ;
		void setPUDHigh( GPPIOPUD setting , uint32_t lines ) ;
	}
}

#endif