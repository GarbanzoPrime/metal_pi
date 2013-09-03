/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "./vchiq.hpp"
namespace rpi {
	namespace gpu {
		namespace vchiq {
			void Connection::init( Data * target ) {
				shared_data 	= target ;
				cpu_comm_state 	= &target->head.slave_state ;
				gpu_comm_state 	= &target->head.master_state ;
			
				last_available_page = 0 ;

				for( auto & page : cpu_comm_state->page_table ) {
					page = last_available_page++ ;
				}
			}
		}
	}
}