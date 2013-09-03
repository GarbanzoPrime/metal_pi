/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_CPU_TIMING_2df76ae3_e4b2_4788_a57e_7a4a096d443b
#define RPI_CPU_TIMING_2df76ae3_e4b2_4788_a57e_7a4a096d443b

#include "rpi/config.hpp"

namespace rpi {
	namespace cpu {
		
		//this will delay the cpu for at least <cycles> cycles
		//depending on compiler inlining and various other factors,
		//it may end up delaying further
		static inline void delay(unsigned int cycles) {
				unsigned int tmp ;
				asm volatile(	
					"mov %[tmp], %[cycles];"
					"1: subs %[tmp], %[tmp], #1;"
					" bne 1b"
					: [tmp]"=r"(tmp)
					: [cycles]"X"(cycles)
					:  );
		}
	}
}

#define