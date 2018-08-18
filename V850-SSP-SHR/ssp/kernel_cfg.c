/* kernel_cfg.c */
//#include "kernel_int.h"
#include "kernel_impl.h"
#include "task.h"
#include "kernel_unrename.h"

#include "kernel_cfg.h"
#include "time_event.h"

#include "sample1.h"
#include "target_kernel.h"

/*
 *  Task Management Functions
 */

const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);

const ATR     	_kernel_tinib_tskatr[TNUM_TSKID]    = {(TA_ACT),(TA_ACT)};
const uint_t	_kernel_init_rdypmap = 3U;
const intptr_t	_kernel_tinib_exinf[TNUM_TSKID]     = {(intptr_t)(0),(intptr_t)(0)};
const TASK    	_kernel_tinib_task[TNUM_TSKID]      = {(task1),(task2)};
const uint_t  	_kernel_tinib_epriority[TNUM_TSKID] = {INT_PRIORITY(1),INT_PRIORITY(2)};


/*
 *  Cyclic Handler Functions
 */

const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);
const uint_t _kernel_cycevtid_offset = 0;

const uint_t _kernel_cycinib_cycact = 0;
const intptr_t _kernel_cycinib_exinf[TNUM_CYCID] = {(intptr_t)(NULL)};
const CYCHDR _kernel_cycinib_cychdr[TNUM_CYCID] = {(cyclic_handler)};
const RELTIM _kernel_cycinib_cyctim[TNUM_CYCID] = {(2000)};
const RELTIM _kernel_cycinib_cycphs[TNUM_CYCID] = {(0)};

uint_t _kernel_cyccb_cycact;
EVTTIM _kernel_cyccb_evttim[TNUM_CYCID];


/*
 *  Alarm Handler Functions
 */

const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);
const uint_t _kernel_almevtid_offset = 1;

const ALMHDR _kernel_alminib_almhdr[TNUM_ALMID] = {(alarm_handler),(alarm_handler2)};
const intptr_t _kernel_alminib_exinf[TNUM_ALMID] = {(intptr_t)(NULL),(intptr_t)(NULL)};

uint_t _kernel_almcb_almact;

/*
 *  Time Event Management
 */

#define TNUM_TMEVT 3

const uint_t _kernel_tnum_tmevt_queue = 3;

QUEUE _kernel_tmevt_queue[TNUM_TMEVT+1];
EVTTIM _kernel_tmevt_time[TNUM_TMEVT];
CBACK _kernel_tmevt_callback[TNUM_TMEVT];
uintptr_t _kernel_tmevt_arg[TNUM_TMEVT];


/*
 *  Stack Area for System
 */

#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ
STK_T          		_kernel_stack[COUNT_STK_T(TOPPERS_ISTKSZ)] ISP_ATTRIB;
#define TOPPERS_STK   		_kernel_stack
#define TOPPERS_STKSZ		ROUND_STK_T(TOPPERS_ISTKSZ)


const SIZE		_kernel_stksz = TOPPERS_STKSZ;
STK_T *const	_kernel_stk = TOPPERS_STK;

/*
 *  非タスクコンテキスト用のスタック初期値
 */

#define TOPPERS_ISTKPT( istk, istksz ) (( STK_T * )(( char * )( istk ) + ( istksz )))

#ifdef TOPPERS_ISTKPT
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_STK, TOPPERS_STKSZ);
#endif /* TOPPERS_ISTKPT */

/*-------------------------------------------
 * タスク別スタック領域			takahashi
 */
STK_T	task_stack[TNUM_TSKID][COUNT_STK_T(TASK_STACKSZ)];


/*---------------------------------------------
 * タスク別コンテキスト保存領域		takahashi
 */
jmp_buf task_ctx[TNUM_TSKID];

/*-----------------------------------------------
 *  タスク待ち情報
 */
unsigned char task_wait[TNUM_TSKID];

RELTIM	tskTout[TNUM_TSKID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_time_event();
	_kernel_initialize_task();			//必要
//	_kernel_initialize_interrupt();		
//	_kernel_initialize_exception();		
	_kernel_initialize_cyclic();
	_kernel_initialize_alarm();
}


#ifndef TARGET_COPYRIGHT
#define TARGET_COPYRIGHT
#endif /* TARGET_COPYRIGHT */




