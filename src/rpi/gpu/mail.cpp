/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#include "rpi/gpu/mail.hpp"

#include "rpi/mem/cache.hpp"
#include "rpi/io/memory_locations.hpp"

namespace rpi {
	namespace gpu {
		
		constexpr MemReg MEM_START = io::MEM_START + 0xB880 ;
		
		constexpr MemReg MAIL0_DATA 	= MEM_START ;
		constexpr MemReg MAIL0_PEEK 	= MEM_START + 0x10 ;
		constexpr MemReg MAIL0_SENDER 	= MEM_START + 0x14 ;
		constexpr MemReg MAIL0_STATUS 	= MEM_START + 0x18 ;
		constexpr MemReg MAIL0_CONFIG 	= MEM_START + 0x1c ;
		constexpr MemReg MAIL0_WRITE 	= MEM_START + 0x20 ;

		bool Mail0Empty() {
			//kinda debatable
			mem::memoryBarrier() ;
			return MAIL0_STATUS.get() & 0x40000000 ;
		}

		bool Mail0Full() {
			//kinda debatable
			mem::memoryBarrier() ;
			return MAIL0_STATUS.get() & 0x80000000 ;
		}

		uint32_t readMail( MailChannel channel )  {
			while( 1 ) {
				while( Mail0Empty() ) ;
				auto read_data = MAIL0_DATA.get() ;

				if( ( read_data & 0xF ) == static_cast<uint8_t>( channel ) ) {
					return read_data & 0xFFFFFFF0 ;
				}
			}
		}

		void writeMail( MailChannel channel , uint32_t data )  {			
			while( Mail0Full() ) {}
			MAIL0_WRITE.set( ( data & 0xFFFFFFF0 ) | static_cast<uint8_t>(channel) ) ;			
		}
	}
}
