/************************************************************************/
/*      GCC/LLCM ARM Baremetal Software / (C) Toshio MURAI  2012-2016   */
/*      This is Free Software.   You can redistribute this software     */
/*      and/or modify it ,under the terms of the GNU General Public     */
/*      License version 3, or (at your option) any later version.       */
/*      or under the terms of the BSD 3-Clause License.	(Dual Licence)  */
/************************************************************************/
#include "rpi.h"
#include "kernel_impl.h"
#include "target_kernel.h"

extern	void _start(void);

extern void _kernel_handler(INTHDR userhandler);
extern void isig_tim(void);

#define CORE0_IRQ_SOURCE 	0x40000060
#define INT_SRC_GPU 		0x00000100			//なぜかタイマー割り込み


#define	NOP	0xe1a00000
#define	JMP	0xe59ff018

extern	void	undefinedInstruction(void);
extern	void	softwareInterrupt(void);
extern	void	prefetchAbort(void);
extern	void	dataAbort(void);
//extern	void	interrupt(void);
extern	void	fastInterrupt(void);
extern void	IRQ_handler(void);

const long int instructionTable[]	/* Address 0x0000 0000 */
	__attribute__ ((section (".rodata.i"))) = {
	JMP,	//0x00:	ldr pc, [pc, #24]	; 0x20	reset
	JMP,	//0x04:				; 0x24 
	JMP,	//0x08:				; 0x28
	JMP,	//0x0c:				; 0x2C
	JMP,	//0x10:				; 0x30
	JMP,	//0x14:				; 0x34
	JMP,	//0x18:				; 0x38	IRQ
	JMP,	//0x1c:				; 0x3C	FIQ
};

void (*const vectorTable[])(void)	/* Address 0x0000 0020*/
	__attribute__ ((section (".rodata.v"))) = {
	_start,			// 0x20	Reset
	undefinedInstruction,	// 0x24 Undefined Instruction
	softwareInterrupt,	// 0x28 Software Interrupt 
	prefetchAbort,		// 0x2C Prefetch Abort
	dataAbort,		// 0x30 Data Abort 
	0x00,			// 0x34 Reserved
	IRQ_handler,		// 0x38 IRQ
	fastInterrupt		// 0x3C FIQ
};



//***********************************************************************/
//*	Interrupt Handler						*/
//***********************************************************************/

void __attribute__((interrupt("UNDEF"))) undefinedInstruction(void)
{
}

void __attribute__((interrupt("SWI"))) softwareInterrupt(void)
{
}

void __attribute__((interrupt("ABORT"))) prefetchAbort(void)
{
}

void __attribute__((interrupt("ABORT"))) dataAbort(void)
{
}

//void __attribute__((interrupt(""))) fastInterrupt(void)
//void __attribute__((interrupt("FIQ"))) fastInterrupt(void)
//{ }
void  fastInterrupt(void)
{ }



// IRQ割り込みハンドラ
void __attribute__((interrupt("IRQ"))) 
IRQ_handler(void)
{
	interrpt_IN();			//割り込み入り口　IRQ --> SVC
//	target_hrt_int_clear();

	// Basic IRQ pendingをチェック
	if(*INTERRUPT_IRQ_BASIC_PENDING & 0x01 != 0)
//	if ((*(unsigned int*)CORE0_IRQ_SOURCE & INT_SRC_GPU) != 0)
	{
		// タイマー割り込み
        // 割り込みフラグクリア
        *TIMER_IRQ_CLR = 0;

		_kernel_handler(isig_tim);
	}
	interrpt_OUT();			//割り込み出口 SVC --> IRQ
}
