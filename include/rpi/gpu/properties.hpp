/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_GPU_PROPERTIES_b868ebc9_b0dd_4a78_86a7_f51cf7ce1f76
#define RPI_GPU_PROPERTIES_b868ebc9_b0dd_4a78_86a7_f51cf7ce1f76

#include "rpi/config.hpp"

#include "mail.hpp"

namespace rpi {
	namespace gpu {
		/*

		*/
		template< typename MESSAGE >
		struct alignas( 16 ) PropertyMail {
			//only to be sizeofed
			union Payload {
				typename MESSAGE::Request request ;
				typename MESSAGE::Response response ;
			} ;


			uint32_t buffer_length = sizeof( PropertyMail< MESSAGE > ) ;
			uint32_t request_code  = 0 ;

			uint32_t tag_id 			= MESSAGE::tag ;
			uint32_t value_buffer_size = sizeof( Payload )  ;
			uint32_t value_length 		= sizeof( typename MESSAGE::Request ) ;
				
			Payload payload ;

			uint32_t close_tag = 0x0 ;
		} ;

		template< typename MESSAGE >
		typename MESSAGE::Response sendProperyMail( typename MESSAGE::Request const & req ) {
			PropertyMail< MESSAGE > mail ;

			mail.payload.request = req ;

			writeMail( MailChannel::property_tags_arm_to_vc , reinterpret_cast<uint32_t>( &mail ) ) ;
			readMail( MailChannel::property_tags_arm_to_vc ) ;

			return mail.payload.response ;
		}
	}
}

#endif