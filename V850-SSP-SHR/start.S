#include "test_reg.h"
#include "v850asm.inc"



.section	".text" , "ax"
.align	4
.globl	_start, _bss_clear, _data_init,__kernel_istkpt
_start:
	di

	Lea		__kernel_istkpt, sp
	ld.w	0[sp], sp

	jarl _bss_clear, lp
	jarl _data_init, lp

	ei
	jarl	 _setup, r31
	halt
.end