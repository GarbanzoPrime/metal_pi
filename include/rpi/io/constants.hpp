/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
#ifndef RPI_IO_CONSTANTS_6107b1e4_4c19_4bd5_9b38_df56a671ec21
#define RPI_IO_CONSTANTS_6107b1e4_4c19_4bd5_9b38_df56a671ec21

#include "rpi/config.hpp"

#include "kul/cstddef.hpp"
#include "rpi/cpu/timing.hpp"


namespace rpi {
	namespace io {

		enum class GPPIOPUD : uint32_t {
			OFF 		= 0x0 ,
			PULL_DOWN 	= 0x1 ,
			PULL_UP 	= 0x2
		};

		constexpr uint32_t GPPIO_0 = 1U ;
		constexpr uint32_t GPPIO_1 = 1U << 1 ;
		constexpr uint32_t GPPIO_2 = 1U << 2 ;
		constexpr uint32_t GPPIO_3 = 1U << 3 ;
		constexpr uint32_t GPPIO_4 = 1U << 4 ;
		constexpr uint32_t GPPIO_5 = 1U << 5 ;
		constexpr uint32_t GPPIO_6 = 1U << 6 ;
		constexpr uint32_t GPPIO_7 = 1U << 7 ;
		constexpr uint32_t GPPIO_8 = 1U << 8 ;
		constexpr uint32_t GPPIO_9 = 1U << 9 ;
		constexpr uint32_t GPPIO_10 = 1U << 10 ;
		constexpr uint32_t GPPIO_11 = 1U << 11 ;
		constexpr uint32_t GPPIO_12 = 1U << 12 ;
		constexpr uint32_t GPPIO_13 = 1U << 13 ;
		constexpr uint32_t GPPIO_14 = 1U << 14 ;
		constexpr uint32_t GPPIO_15 = 1U << 15 ;
		constexpr uint32_t GPPIO_16 = 1U << 16 ;
		constexpr uint32_t GPPIO_17 = 1U << 17 ;
		constexpr uint32_t GPPIO_18 = 1U << 18 ;
		constexpr uint32_t GPPIO_19 = 1U << 19 ;
		constexpr uint32_t GPPIO_20 = 1U << 20 ;
		constexpr uint32_t GPPIO_21 = 1U << 21 ;
		constexpr uint32_t GPPIO_22 = 1U << 22 ;
		constexpr uint32_t GPPIO_23 = 1U << 23 ;
		constexpr uint32_t GPPIO_24 = 1U << 24 ;
		constexpr uint32_t GPPIO_25 = 1U << 25 ;
		constexpr uint32_t GPPIO_26 = 1U << 26 ;
		constexpr uint32_t GPPIO_27 = 1U << 27 ;
		constexpr uint32_t GPPIO_28 = 1U << 28 ;
		constexpr uint32_t GPPIO_29 = 1U << 29 ;
		constexpr uint32_t GPPIO_30 = 1U << 30 ;
		constexpr uint32_t GPPIO_31 = 1U << 31 ;

		constexpr uint32_t GPPIO_32 = 1U ;
		constexpr uint32_t GPPIO_33 = 1U << 1 ;
		constexpr uint32_t GPPIO_34 = 1U << 2 ;
		constexpr uint32_t GPPIO_35 = 1U << 3 ;
		constexpr uint32_t GPPIO_36 = 1U << 4 ;
		constexpr uint32_t GPPIO_37 = 1U << 5 ;
		constexpr uint32_t GPPIO_38 = 1U << 6 ;
		constexpr uint32_t GPPIO_39 = 1U << 7 ;
		constexpr uint32_t GPPIO_40 = 1U << 8 ;
		constexpr uint32_t GPPIO_41 = 1U << 9 ;
		constexpr uint32_t GPPIO_42 = 1U << 10 ;
		constexpr uint32_t GPPIO_43 = 1U << 11 ;
		constexpr uint32_t GPPIO_44 = 1U << 12 ;
		constexpr uint32_t GPPIO_45 = 1U << 13 ;
		constexpr uint32_t GPPIO_46 = 1U << 14 ;
		constexpr uint32_t GPPIO_47 = 1U << 15 ;
		constexpr uint32_t GPPIO_48 = 1U << 16 ;
		constexpr uint32_t GPPIO_49 = 1U << 17 ;
		constexpr uint32_t GPPIO_50 = 1U << 18 ;
		constexpr uint32_t GPPIO_51 = 1U << 19 ;
		constexpr uint32_t GPPIO_52 = 1U << 20 ;
		constexpr uint32_t GPPIO_53 = 1U << 21 ;
	}
}

#endif