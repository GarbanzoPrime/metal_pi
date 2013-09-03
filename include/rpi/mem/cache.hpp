/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_MEM_CACHE_cb72fcd2_402b_47b4_a384_2726a9df65b9
#define RPI_MEM_CACHE_cb72fcd2_402b_47b4_a384_2726a9df65b9

#include "rpi/config.hpp"

namespace rpi {
	namespace mem {
		static inline void memoryBarrier()
		{
			int tmp ;
			asm volatile(	"mov %[tmp], #0 ;"
							"mcr p15, #0, %[tmp], c7, c10, #5 ;"
							: [tmp]"=r"(tmp)
							: [tmp] "r"(tmp)
							: );
		}

		static inline void dataCacheFlush()
		{
			int tmp ;
			asm volatile(	"mov %[tmp], #0 ;"
							"mcr p15, #0, %[tmp], c7, c14, #0 ;"
							: [tmp]"=r"(tmp)
							: [tmp] "r"(tmp)
							: );
		}

		static inline void synchronisationBarrier()
		{
			int tmp ;
			asm volatile(	"mov %[tmp], #0 ;"
							"mcr p15, #0, %[tmp], c7, c10, #4 ;"
							: [tmp]"=r"(tmp)
							: [tmp] "r"(tmp)
							: );
		}

		static inline void dataSynchronisationBarrier()
		{
			//not quite sure about this...
			asm volatile(	"stmfd sp!, {r0-r8,r12,lr};"
							"mcr p15, #0, ip, c7, c5, #0;"
							"mcr p15, #0, ip, c7, c5, #6;"
							"mcr p15, #0, ip, c7, c10, #4;"
							"mcr p15, #0, ip, c7, c10, #5;"
							"ldmfd sp!, {r0-r8,r12,pc}");
		}
	}
}

#endif