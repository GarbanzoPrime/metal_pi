/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "rpi/gpu/clock.hpp"

namespace rpi {
	namespace gpu {
		units::Hertz< uint32_t , units::ratio<1> > getClockRate( ClockId clock ) {
			return sendProperyMail<GetClockRate>( GetClockRate::Request{ clock } ).rate ;
		}
	}
}

