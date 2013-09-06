/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_GPU_VCHIQ_7bbb733e_397d_40f4_a40c_004b7c432ef3
#define RPI_GPU_VCHIQ_7bbb733e_397d_40f4_a40c_004b7c432ef3

#include "rpi/config.hpp"
#include "./vchiq_data.hpp"

namespace rpi {
	namespace gpu {
		namespace vchiq {

			class Service ;
			enum class MessageType : int {
				VCHIQ_MSG_PADDING           =  0,
				VCHIQ_MSG_CONNECT           =  1,
				VCHIQ_MSG_OPEN              =  2,
				VCHIQ_MSG_OPENACK           =  3,
				VCHIQ_MSG_CLOSE             =  4,
				VCHIQ_MSG_DATA              =  5,
				VCHIQ_MSG_BULK_RX           =  6,
				VCHIQ_MSG_BULK_TX           =  7,
				VCHIQ_MSG_BULK_RX_DONE      =  8,
				VCHIQ_MSG_BULK_TX_DONE      =  9,
				VCHIQ_MSG_PAUSE             = 10,
				VCHIQ_MSG_RESUME            = 11,
				VCHIQ_MSG_REMOTE_USE        = 12,
				VCHIQ_MSG_REMOTE_RELEASE    = 13,
				VCHIQ_MSG_REMOTE_USE_ACTIVE = 14,
			} ;

			template< typename PAYLOAD_T >
			struct Message {
				MessageType type ;
				unsigned int size ;

				PAYLOAD_T message_data ;
			} ;


			class Connection {
			public:

				void init( Data * target ) ;
				void enableService( Service & service ) ;

				void sendMessage( Service * culprit ) ;
			private:
				Data * shared_data ;
				CommState * cpu_comm_state ;
				CommState * gpu_comm_state ;

				size_t last_available_page ;
			} ;

			class Service {
			public:

			private:
				int _service_id ;
				Connection * _connection ;
			} ;
		}
	}
}

#endif
