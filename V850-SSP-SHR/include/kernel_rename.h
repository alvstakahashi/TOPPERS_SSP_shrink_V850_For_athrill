/* This file is generated from kernel_rename.def by genrename. */

#ifndef TOPPERS_KERNEL_RENAME_H
#define TOPPERS_KERNEL_RENAME_H

/*
 *  startup.c
 */
#define kerflg						_kernel_kerflg
#define exit_kernel					_kernel_exit_kernel
#define call_exit_kernel			_kernel_call_exit_kernel

/*
 *  task.c
 */
#define runtsk_pri					_kernel_runtsk_pri
#define ready_primap				_kernel_ready_primap
#define reqflg						_kernel_reqflg
#define disdsp						_kernel_disdsp
#define search_schedtsk				_kernel_search_schedtsk
#define test_dormant				_kernel_test_dormant
#define initialize_task				_kernel_initialize_task
#define make_active					_kernel_make_active
#define dispatcher					_kernel_dispatcher
#define run_task					_kernel_run_task
#define bitmap_search_table			_kernel_bitmap_search_table
#define bitmap_search				_kernel_bitmap_search
#define primap_empty				_kernel_primap_empty
#define primap_test					_kernel_primap_test
#define primap_set					_kernel_primap_set
#define primap_clear				_kernel_primap_clear
#define bitmap_search				_kernel_bitmap_search
#define	handler						_kernel_handler
#define	intnest						_kernel_intnest
/*
 *  time_event.c
 */
#define current_time				_kernel_current_time
#define min_time					_kernel_min_time
#define initialize_time_event		_kernel_initialize_time_event
#define time_event_enqueue			_kernel_time_event_enqueue
#define time_event_dequeue			_kernel_time_event_dequeue
#define signal_time					_kernel_signal_time

/*
 *  cyclic.c
 */
#define initialize_cyclic			_kernel_initialize_cyclic
#define call_cychdr					_kernel_call_cychdr

/*
 *  alarm.c
 */
#define initialize_alarm			_kernel_initialize_alarm
#define call_almhdr					_kernel_call_almhdr

/*
 *  interrupt.c
 */
#define initialize_interrupt		_kernel_initialize_interrupt

/*
 *  exception.c
 */
#define initialize_exception		_kernel_initialize_exception

/*
 *  cyclic.c
 */
#define initialize_cyclic			_kernel_initialize_cyclic
#define call_cychdr					_kernel_call_cychdr

/*
 *  alarm.c
 */
#define initialize_alarm			_kernel_initialize_alarm
#define call_almhdr					_kernel_call_almhdr

/*
 *  time_event.c
 */
#define current_time				_kernel_current_time
#define min_time					_kernel_min_time
#define initialize_time_event		_kernel_initialize_time_event
#define time_event_enqueue			_kernel_time_event_enqueue
#define time_event_dequeue			_kernel_time_event_dequeue
#define signal_time					_kernel_signal_time

/*
 *  kernel_cfg.c
 */
#define init_rdypmap				_kernel_init_rdypmap
#define tmax_tskid					_kernel_tmax_tskid
#define tinib_exinf					_kernel_tinib_exinf
#define tinib_task					_kernel_tinib_task
#define tinib_epriority				_kernel_tinib_epriority
#define tnum_inhno					_kernel_tnum_inhno
#define inhinib_inhno				_kernel_inhinib_inhno
#define inhinib_inhatr				_kernel_inhinib_inhatr
#define inhinib_entry				_kernel_inhinib_entry
#define tnum_intno					_kernel_tnum_intno
#define intinib_intno				_kernel_intinib_intno
#define intinib_intatr				_kernel_intinib_intatr
#define intinib_intpri				_kernel_intinib_intpri
#define tnum_excno					_kernel_tnum_excno
#define excinib_excno				_kernel_excinib_excno
#define excinib_excatr				_kernel_excinib_excatr
#define excinib_entry				_kernel_excinib_entry
#define tmax_cycid					_kernel_tmax_cycid
#define cycinib_cycact				_kernel_cycinib_cycact
#define cycinib_cycphs				_kernel_cycinib_cycphs
#define cycinib_cychdr				_kernel_cycinib_cychdr
#define cycinib_cyctim				_kernel_cycinib_cyctim
#define cycinib_exinf				_kernel_cycinib_exinf
#define cyccb_cycact				_kernel_cyccb_cycact
#define cyccb_evttim				_kernel_cyccb_evttim
#define cycevtid_offset				_kernel_cycevtid_offset
#define almevtid_offset				_kernel_almevtid_offset
#define almcb_almact				_kernel_almcb_almact
#define tmax_almid					_kernel_tmax_almid
#define alminib_almhdr				_kernel_alminib_almhdr
#define alminib_exinf				_kernel_alminib_exinf
#define tnum_tmevt_queue			_kernel_tnum_tmevt_queue
#define tmevt_queue					_kernel_tmevt_queue
#define tmevt_time					_kernel_tmevt_time
#define tmevt_callback				_kernel_tmevt_callback
#define tmevt_arg					_kernel_tmevt_arg
#define stksz						_kernel_stksz
#define stk							_kernel_stk
#define istkpt						_kernel_istkpt
#define initialize_object			_kernel_initialize_object
#define call_inirtn					_kernel_call_inirtn
#define call_terrtn					_kernel_call_terrtn
#define tmax_cycid					_kernel_tmax_cycid
#define cycinib_cycact				_kernel_cycinib_cycact
#define cycinib_cychdr				_kernel_cycinib_cychdr
#define cycinib_cyctim				_kernel_cycinib_cyctim
#define cycinib_cycphs				_kernel_cycinib_cycphs
#define cycinib_exinf				_kernel_cycinib_exinf
#define cyccb_cycact				_kernel_cyccb_cycact
#define cyccb_evttim				_kernel_cyccb_evttim
#define cycevtid_offset				_kernel_cycevtid_offset
#define tmax_almid					_kernel_tmax_almid
#define alminib_almhdr				_kernel_alminib_almhdr
#define alminib_exinf				_kernel_alminib_exinf
#define almcb_almact				_kernel_almcb_almact
#define almevtid_offset				_kernel_almevtid_offset
#define tnum_tmevt_queue			_kernel_tnum_tmevt_queue
#define tmevt_queue					_kernel_tmevt_queue
#define tmevt_time					_kernel_tmevt_time
#define tmevt_callback				_kernel_tmevt_callback
#define tmevt_arg					_kernel_tmevt_arg


/*
 *  target_config.c
 */
#define target_initialize			_kernel_target_initialize
#define start_dispatch				_kernel_start_dispatch
#define target_exit					_kernel_target_exit




#ifdef TOPPERS_LABEL_ASM

/*
 *  startup.c
 */
#define _kerflg						__kernel_kerflg
#define _exit_kernel				__kernel_exit_kernel
#define _call_exit_kernel			__kernel_call_exit_kernel

/*
 *  task.c
 */
#define _runtsk_pri					__kernel_runtsk_pri
#define _ready_primap				__kernel_ready_primap
#define _reqflg						__kernel_reqflg
#define _disdsp						__kernel_disdsp
#define _search_schedtsk			__kernel_search_schedtsk
#define _test_dormant				__kernel_test_dormant
#define _initialize_task			__kernel_initialize_task
#define _make_active				__kernel_make_active
#define _dispatcher					__kernel_dispatcher
#define _run_task					__kernel_run_task
#define _bitmap_search_table		__kernel_bitmap_search_table
#define _bitmap_search				__kernel_bitmap_search
#define _primap_empty				__kernel_primap_empty
#define _primap_test				__kernel_primap_test
#define _primap_set					__kernel_primap_set
#define _primap_clear				__kernel_primap_clear
#define _bitmap_search				__kernel_bitmap_search

/*
 *  time_event.c
 */
#define _current_time				__kernel_current_time
#define _min_time					__kernel_min_time
#define _initialize_time_event		__kernel_initialize_time_event
#define _time_event_enqueue			__kernel_time_event_enqueue
#define _time_event_dequeue			__kernel_time_event_dequeue
#define _signal_time				__kernel_signal_time

/*
 *  cyclic.c
 */
#define _initialize_cyclic			__kernel_initialize_cyclic
#define _call_cychdr				__kernel_call_cychdr

/*
 *  alarm.c
 */
#define _initialize_alarm			__kernel_initialize_alarm
#define _call_almhdr				__kernel_call_almhdr

/*
 *  interrupt.c
 */
#define _initialize_interrupt		__kernel_initialize_interrupt

/*
 *  exception.c
 */
#define _initialize_exception		__kernel_initialize_exception

/*
 *  cyclic.c
 */
#define _initialize_cyclic			__kernel_initialize_cyclic
#define _call_cychdr				__kernel_call_cychdr

/*
 *  alarm.c
 */
#define _initialize_alarm			__kernel_initialize_alarm
#define _call_almhdr				__kernel_call_almhdr

/*
 *  time_event.c
 */
#define _current_time				__kernel_current_time
#define _min_time					__kernel_min_time
#define _initialize_time_event		__kernel_initialize_time_event
#define _time_event_enqueue			__kernel_time_event_enqueue
#define _time_event_dequeue			__kernel_time_event_dequeue
#define _signal_time				__kernel_signal_time

/*
 *  kernel_cfg.c
 */
#define _init_rdypmap				__kernel_init_rdypmap
#define _tmax_tskid					__kernel_tmax_tskid
#define _tinib_exinf				__kernel_tinib_exinf
#define _tinib_task					__kernel_tinib_task
#define _tinib_epriority			__kernel_tinib_epriority
#define _tnum_inhno					__kernel_tnum_inhno
#define _inhinib_inhno				__kernel_inhinib_inhno
#define _inhinib_inhatr				__kernel_inhinib_inhatr
#define _inhinib_entry				__kernel_inhinib_entry
#define _tnum_intno					__kernel_tnum_intno
#define _intinib_intno				__kernel_intinib_intno
#define _intinib_intatr				__kernel_intinib_intatr
#define _intinib_intpri				__kernel_intinib_intpri
#define _tnum_excno					__kernel_tnum_excno
#define _excinib_excno				__kernel_excinib_excno
#define _excinib_excatr				__kernel_excinib_excatr
#define _excinib_entry				__kernel_excinib_entry
#define _tmax_cycid					__kernel_tmax_cycid
#define _cycinib_cycact				__kernel_cycinib_cycact
#define _cycinib_cycphs				__kernel_cycinib_cycphs
#define _cycinib_cychdr				__kernel_cycinib_cychdr
#define _cycinib_cyctim				__kernel_cycinib_cyctim
#define _cycinib_exinf				__kernel_cycinib_exinf
#define _cyccb_cycact				__kernel_cyccb_cycact
#define _cyccb_evttim				__kernel_cyccb_evttim
#define _cycevtid_offset			__kernel_cycevtid_offset
#define _almevtid_offset			__kernel_almevtid_offset
#define _almcb_almact				__kernel_almcb_almact
#define _tmax_almid					__kernel_tmax_almid
#define _alminib_almhdr				__kernel_alminib_almhdr
#define _alminib_exinf				__kernel_alminib_exinf
#define _tnum_tmevt_queue			__kernel_tnum_tmevt_queue
#define _tmevt_queue				__kernel_tmevt_queue
#define _tmevt_time					__kernel_tmevt_time
#define _tmevt_callback				__kernel_tmevt_callback
#define _tmevt_arg					__kernel_tmevt_arg
#define _stksz						__kernel_stksz
#define _stk						__kernel_stk
#define _istkpt						__kernel_istkpt
#define _initialize_object			__kernel_initialize_object
#define _call_inirtn				__kernel_call_inirtn
#define _call_terrtn				__kernel_call_terrtn
#define _tmax_cycid					__kernel_tmax_cycid
#define _cycinib_cycact				__kernel_cycinib_cycact
#define _cycinib_cychdr				__kernel_cycinib_cychdr
#define _cycinib_cyctim				__kernel_cycinib_cyctim
#define _cycinib_cycphs				__kernel_cycinib_cycphs
#define _cycinib_exinf				__kernel_cycinib_exinf
#define _cyccb_cycact				__kernel_cyccb_cycact
#define _cyccb_evttim				__kernel_cyccb_evttim
#define _cycevtid_offset			__kernel_cycevtid_offset
#define _tmax_almid					__kernel_tmax_almid
#define _alminib_almhdr				__kernel_alminib_almhdr
#define _alminib_exinf				__kernel_alminib_exinf
#define _almcb_almact				__kernel_almcb_almact
#define _almevtid_offset			__kernel_almevtid_offset
#define _tnum_tmevt_queue			__kernel_tnum_tmevt_queue
#define _tmevt_queue				__kernel_tmevt_queue
#define _tmevt_time					__kernel_tmevt_time
#define _tmevt_callback				__kernel_tmevt_callback
#define _tmevt_arg					__kernel_tmevt_arg


/*
 *  target_config.c
 */
#define _target_initialize			__kernel_target_initialize
#define _start_dispatch				__kernel_start_dispatch
#define _target_exit				__kernel_target_exit

#define	default_int_handler_entry	__kernel_default_int_handler_entry


#endif /* TOPPERS_LABEL_ASM */

#include <stddef.h>

#endif /* TOPPERS_KERNEL_RENAME_H */
