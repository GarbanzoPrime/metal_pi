/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_GPU_VCHIQ_DATA_beadda2c_e42a_4b36_b76e_ae654c90df0d
#define RPI_GPU_VCHIQ_DATA_beadda2c_e42a_4b36_b76e_ae654c90df0d

#include "rpi/config.hpp"
#include "rpi/mem/cache.hpp"

#include "kul/array.hpp"

namespace rpi {
	namespace gpu {
		namespace vchiq {
			constexpr int makeFourCC( int a , int b , int c , int d ) {
				return ( a << 24 ) | ( b << 16 ) | ( c << 8 ) | ( d ) ;
			}

			static constexpr uint32_t PAGE_SIZE				= 4096	;
			static constexpr uint32_t MAX_PAGES      		= 128 	;
			static constexpr uint32_t MAX_PAGES_PER_SIDE  	= 64 	;
			static constexpr uint32_t DEBUG_MAX            	= 1 	;


			static constexpr uint32_t CPU_PAGES = 32 ;
			static constexpr uint32_t GPU_PAGES = 32 ;


			//???
			static constexpr uint32_t NUM_CURRENT_BULKS    	= 32 ;
			static constexpr uint32_t MAX_FRAGMENTS    		= NUM_CURRENT_BULKS * 2 ;


			/*
				Events, used to signal data changes between cpu and gpu
			*/
			struct Event {
				int armed				= 0 ;
				int fired				= 0 ;

				//I strongly suspect this has nothing to do with the vchiq itself,
				//but is meant for user-side synchronization, which we don't care about here...					
				//I say this because in the linux driver, this is initialised to a raw user-side pointer
				//so unless the VC applies the arm->vc offset on its end (which would go against conventions)
				//then it can't dereference that pointer sanely				
				void * event   = nullptr ;
			} ;

			struct CommState {
				int            	initialised				= 0 ;
				int            	first_async_page		= 0 ;
				int            	last_async_page			= 0 ;
				int            	sync_page				= 0 ;
				Event 			trigger ;
				int            	tx_pos                   = 0 ;
				Event 			recycle ;
				int            	slot_queue_recycle       = 0 ;
				Event			sync_trigger  ;
				Event 			sync_release ;

				array< int, MAX_PAGES_PER_SIDE > 	page_table = { -1 } ;
				array< int, DEBUG_MAX >      			debug      = { 0 } ;
			} ;

			struct SlotState {
				short use_count = 0 ;
				short release_count = 0 ;
			} ;

			struct alignas(4096) Header {
				int                  magic 						= makeFourCC( 'V' , 'C' , 'H' , 'I' ) ;
				short                version					= 6 ;
				short                version_min				= 3 ;
				int                  header_size				= sizeof( Header ) ;
				int                  page_size					= PAGE_SIZE ;
				int                  max_pages					= MAX_PAGES ;
				int                  max_page_per_side			= MAX_PAGES_PER_SIDE ;
				int					 fragment_offset 			= 0 ;
				int					 fragment_count 			= MAX_FRAGMENTS ;

				CommState            master_state ;
				CommState            slave_state ;

				array< SlotState , MAX_PAGES > page_states ;
			} ;


			struct alignas(4096) Page {
				array<uint8_t, PAGE_SIZE> data ;
			};

			struct Fragment {
				array<uint8_t, mem::CACHE_LINE_LENGTH> head ;
				array<uint8_t, mem::CACHE_LINE_LENGTH> tail ;
			} ;

			struct alignas(4096) Data {
				Header 								head ;
				array<Page, CPU_PAGES + GPU_PAGES > pages ;
				array<Fragment, MAX_FRAGMENTS >     fragments ;

				void init() {
					constexpr int pages_used_by_header = ( sizeof( Header ) + PAGE_SIZE - 1 ) / PAGE_SIZE ;
					int first_master_slot = pages_used_by_header ;
					head.master_state.sync_page  = first_master_slot ;
					head.master_state.first_async_page = first_master_slot + 1;
					head.master_state.last_async_page  = first_master_slot + GPU_PAGES - 1 ;

					int first_slave_slot = first_master_slot + GPU_PAGES ;

					head.slave_state.sync_page   = first_master_slot ;
					head.slave_state.first_async_page  = first_master_slot + 1;
					head.slave_state.last_async_page   = first_master_slot + CPU_PAGES - 1;

					head.fragment_offset = (uint32_t)&fragments - (uint32_t)this ;
				}
			} ;
		}
	}
}

#endif
