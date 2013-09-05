/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_GPU_CLOCK_74311ea4_42e7_4063_9c69_e495b8aa82ed
#define RPI_GPU_CLOCK_74311ea4_42e7_4063_9c69_e495b8aa82ed

#include "rpi/config.hpp"

#include "properties.hpp"
#include "units/frequency.hpp"


namespace rpi {
	namespace gpu {
		enum class ClockId : uint32_t  {
			EMMC  = 1,
			UART  = 2,
			ARM   = 3,
			CORE  = 4,
			V3D   = 5,
			H264  = 6,
			ISP   = 7,
			SDRAM = 8, 
			PIXEL = 9,
			PWM   = 10,
		} ;

		struct GetClockRate {

			static const uint32_t tag = 0x00030002 ;

			struct Request {
				ClockId clock_id ;
			} ;

			struct Response {
				ClockId clock_id ;
				units::Hertz< uint32_t , units::ratio<1> > rate ;
			} ;
		} ;

		units::Hertz< uint32_t , units::ratio<1> > getClockRate( ClockId clock );
 	}
}

#endif
