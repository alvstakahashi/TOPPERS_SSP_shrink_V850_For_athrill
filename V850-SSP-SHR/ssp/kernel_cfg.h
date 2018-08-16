/* kernel_cfg.h */
#ifndef TOPPERS_KERNEL_CFG_H
#define TOPPERS_KERNEL_CFG_H


#define TNUM_TSKID	2
#define TNUM_CYCID	1
#define TNUM_ALMID	2

#define TASK1_ID	1
#define TASK2_ID	2

#define MAIN_CYC	1
#define MAIN_ALM	1
#define SUB_ALM		2

#define	TASK_STACKSZ		1024
#define TOPPERS_TASKSTKPT(task_id ) (( STK_T  )(( char * )( task_stack[task_id] ) + ( TASK_STACKSZ )))
//STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_STK, TOPPERS_STKSZ);
extern STK_T	task_stack[TNUM_TSKID][COUNT_STK_T(TASK_STACKSZ)];

extern unsigned char task_wait[TNUM_TSKID];

extern RELTIM	tskTout[TNUM_TSKID];




#endif /* TOPPERS_KERNEL_CFG_H */

