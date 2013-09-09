/* Copyright 2013, Garbanzo Prime

    This file is part of metal_pi.
    metal_pi is subject to the license specified in LICENSE.txt
*/
module metal_pi.build ;

import tasel.tasel ;
import tasel.ext.llvm ;
import std.algorithm ;
import std.array ;
import std.path ;

import build_config ;

private {
	immutable string[] abi_src = [
		metal_pi_dir.buildPath( "src/rpi/gpu/mail.cpp" ),
		metal_pi_dir.buildPath( "src/rpi/gpu/clock.cpp" ) ,
		metal_pi_dir.buildPath( "src/rpi/io/uart.cpp" ) ,
		metal_pi_dir.buildPath( "src/rpi/io/gpio.cpp" ) ,
		metal_pi_dir.buildPath( "src/rpi/gpu/vchiq.cpp" ) 
	] ;

	immutable string[] compileFlags = [
		"-m32",
		"-nostdinc",
		"-nostdinc++",
		"-std=c++11" ,
		"-I" ~ metal_pi_dir.buildPath( "include" ),
		"-I" ~ kul_dir.buildPath( "include" ),
		"-I" ~ units_dir.buildPath( "include" ) ,
	] ;
}

Resource buildPiLib(BuildSet tasks) {
	return tasks.addLLVMLib( abi_src , bin_dir ~ "libs/metalpi.bc" , intermediate_dir , compileFlags ) ;	
}
