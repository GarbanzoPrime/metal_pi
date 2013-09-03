/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_GPU_MAIL_115ebfb9_e57d_493a_8f6e_34056239aec3
#define RPI_GPU_MAIL_115ebfb9_e57d_493a_8f6e_34056239aec3

#include "rpi/config.hpp"

#include "kul/array.hpp"

namespace rpi {

	namespace gpu {


		enum class MailChannel : uint8_t {
			power_management 	= 0x0 ,
			framebuffer 		= 0x1 ,
			virtual_uart		= 0x2 ,
			VCHIQ				= 0x3 ,
			LEDs				= 0x4 ,
			buttons				= 0x5 ,
			touch_screen		= 0x6 ,
		
			property_tags_arm_to_vc = 0x8 ,
			property_tags_vc_to_arm = 0x9 ,
		} ;	

		uint32_t readMail( MailChannel channel ) ;
		void writeMail( MailChannel channel , uint32_t data ) ;
	

	}
}

#endif