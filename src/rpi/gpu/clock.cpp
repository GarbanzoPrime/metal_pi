/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "clock.hpp"

namespace rpi {
	namespace gpu {
		Frequency< uint32_t , ratio<1> > getClockRate( ClockId clock ) {
			return sendProperyMail<GetClockRate>( GetClockRate::Request{ clock } ).rate ;
		}
	}
}

