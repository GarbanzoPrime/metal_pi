/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_IO_MEMORY_LOCATIONS_13b246e0_eb4a_439e_9343_60656da64157
#define RPI_IO_MEMORY_LOCATIONS_13b246e0_eb4a_439e_9343_60656da64157

#include "rpi/config.hpp"

#include "kul/memory.hpp"

namespace rpi {
	namespace io {
		constexpr MemReg MEM_START = 0x20000000U ;
	
		constexpr MemReg GPIO_START = MEM_START + 0x200000 ;

		constexpr MemReg GPFSEL0 = GPIO_START ;
		constexpr MemReg GPFSEL1 = GPIO_START + 0x4 ;
		constexpr MemReg GPFSEL2 = GPIO_START + 0x8 ;
		constexpr MemReg GPFSEL3 = GPIO_START + 0xC ;
		constexpr MemReg GPFSEL4 = GPIO_START + 0x10 ;
		constexpr MemReg GPFSEL5 = GPIO_START + 0x14 ;

		constexpr MemReg GPSET0 = GPIO_START + 0x1C ;
		constexpr MemReg GPSET1 = GPIO_START + 0x20 ;

		constexpr MemReg GPCLR0 = GPIO_START + 0x28 ;
		constexpr MemReg GPCLR1 = GPIO_START + 0x2C ;

		constexpr MemReg GPLEV0 = GPIO_START + 0x34 ;
		constexpr MemReg GPLEV1 = GPIO_START + 0x38 ;

		constexpr MemReg GPEDS0 = GPIO_START + 0x40 ;
		constexpr MemReg GPEDS1 = GPIO_START + 0x44 ;

		constexpr MemReg GPREN0 = GPIO_START + 0x4C ;
		constexpr MemReg GPREN1 = GPIO_START + 0x50 ;

		constexpr MemReg GPFEN0 = GPIO_START + 0x58 ;
		constexpr MemReg GPFEN1 = GPIO_START + 0x5C ;

		constexpr MemReg GPHEN0 = GPIO_START + 0x64 ;
		constexpr MemReg GPHEN1 = GPIO_START + 0x68 ;

		constexpr MemReg GPLEN0 = GPIO_START + 0x70 ;
		constexpr MemReg GPLEN1 = GPIO_START + 0x74 ;

		constexpr MemReg GPAREN0 = GPIO_START + 0x7C ;
		constexpr MemReg GPAREN1 = GPIO_START + 0x80 ;

		constexpr MemReg GPAFEN0 = GPIO_START + 0x88 ;
		constexpr MemReg GPAFEN1 = GPIO_START + 0x8C ;

		constexpr MemReg GPPUD = GPIO_START + 0x94 ;
		constexpr MemReg GPPUDCLK0 = GPIO_START + 0x98 ;
		constexpr MemReg GPPUDCLK1 = GPIO_START + 0x9C ;
	
		constexpr MemReg UART0_START = GPIO_START + 0x1000 ;

		constexpr MemReg UART0_DR 		= UART0_START + 0x00 ;
		constexpr MemReg UART0_RSRECR 	= UART0_START + 0x04 ;
		constexpr MemReg UART0_FR 		= UART0_START + 0x18 ;
		constexpr MemReg UART0_IBRD 	= UART0_START + 0x24 ;
		constexpr MemReg UART0_FBRD 	= UART0_START + 0x28 ;
		constexpr MemReg UART0_LCRH 	= UART0_START + 0x2C ;
		constexpr MemReg UART0_CR 		= UART0_START + 0x30 ;
		constexpr MemReg UART0_IFLS 	= UART0_START + 0x34 ;
		constexpr MemReg UART0_IMSC 	= UART0_START + 0x38 ;
		constexpr MemReg UART0_RIS 		= UART0_START + 0x3C ;
		constexpr MemReg UART0_MIS 		= UART0_START + 0x40 ;
		constexpr MemReg UART0_ICR 		= UART0_START + 0x44 ;
		constexpr MemReg UART0_DMACR 	= UART0_START + 0x48 ;
		constexpr MemReg UART0_ITCR 	= UART0_START + 0x80 ;
		constexpr MemReg UART0_ITIP 	= UART0_START + 0x84 ;
		constexpr MemReg UART0_ITOP 	= UART0_START + 0x88 ;
		constexpr MemReg UART0_TDR 		= UART0_START + 0x8C ;
		
	}
}

#endif