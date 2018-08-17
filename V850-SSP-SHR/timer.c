#include "test_serial.h"
#include "interrupt_table.h"
#include "chip_timer.h"

static void timer_interrupt_handler(void)
{
	//printf("timer_interrupt_handler!!\n");
	target_hrt_handler();
	return;
}

void timer_init(void)
{
    register_interrupt_handler(22, timer_interrupt_handler);
    target_hrt_initialize(0);
    x_enable_int(22);
}

