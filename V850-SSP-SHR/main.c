#include <kernel.h>
#include "kernel_cfg.h"

#include <stdio.h>
#include <stdint.h>

#include "kernel_impl.h"
#include "target_kernel.h"

#include "test_serial.h"
#include "test_reg.h"
#include "section.h"
//#include "interrupt.h"
#include <string.h>
#include "timer.h"

#define TAMIYA_NO_IMPREMENT

volatile int count = 0;

unsigned char stack_data[STACK_SIZE] __attribute__ ((section(".bss_noclr")));

unsigned char mmap_data[1024] __attribute__ ((section(".mmap_section")));

static int gl_variable;

int setup(void)
{
	timer_init();

	sta_ker();

	while(1);
}

void task1(intptr_t arg)
{}
void task2(intptr_t arg)
{}

#ifdef TAMIYA_NO_IMPREMENT
void cyclic_handler(intptr_t exinf)
{
}
void alarm_handler(intptr_t exinf)
{
}
void alarm_handler2(intptr_t exinf)
{
}
#endif

int main(void)
{

	printf("Hello World!!\n");

	gl_variable = 10;

#if 0
	mmap_data[0] = 'H';
	mmap_data[1] = 'e';
	mmap_data[2] = 'l';
	mmap_data[3] = 'l';
	mmap_data[4] = 'o';
	mmap_data[5] = ' ';
	mmap_data[6] = 'M';
	mmap_data[7] = 'M';
	mmap_data[8] = 'A';
	mmap_data[9] = 'P';
	mmap_data[10] = '!';
	mmap_data[11] = '!';
	mmap_data[12] = '\n';
#endif	
	while (1) {
		;
	}
}

void bss_clear(void)
{
	unsigned char *p = &_bss_start;
	unsigned char *e = &_bss_end;
	for (;p < e; p++) {
		*p = 0;
	}
	return;
}

void data_init(void)
{
	unsigned char *p_rom = &_idata_start;
	unsigned char *e_rom = &_idata_end;
	unsigned char *p_ram = &_data_start;

	for (;p_rom < e_rom; p_ram++, p_rom++) {
		*p_ram = *p_rom;
	}
}

