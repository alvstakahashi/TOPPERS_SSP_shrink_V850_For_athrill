/* This file is generated from kernel_rename.def by genrename. */

/* This file is included only when kernel_rename.h has been included. */
#ifdef TOPPERS_KERNEL_RENAME_H
#undef TOPPERS_KERNEL_RENAME_H

/*
 *  startup.c
 */
#undef kerflg
#undef exit_kernel
#undef call_exit_kernel

/*
 *  task.c
 */
#undef runtsk_pri
#undef ready_primap
#undef reqflg
#undef disdsp
#undef search_schedtsk
#undef test_dormant
#undef initialize_task
#undef make_active
#undef dispatcher
#undef run_task
#undef bitmap_search_table
#undef bitmap_search
#undef primap_empty
#undef primap_test
#undef primap_set
#undef primap_clear
#undef bitmap_search
#undef handler
#undef intnest
/*
 *  time_event.c
 */
#undef current_time
#undef min_time
#undef initialize_time_event
#undef time_event_enqueue
#undef time_event_dequeue
#undef signal_time

/*
 *  cyclic.c
 */
#undef initialize_cyclic
#undef call_cychdr

/*
 *  alarm.c
 */
#undef initialize_alarm
#undef call_almhdr

/*
 *  interrupt.c
 */
#undef initialize_interrupt

/*
 *  exception.c
 */
#undef initialize_exception

/*
 *  cyclic.c
 */
#undef initialize_cyclic
#undef call_cychdr

/*
 *  alarm.c
 */
#undef initialize_alarm
#undef call_almhdr

/*
 *  time_event.c
 */
#undef current_time
#undef min_time
#undef initialize_time_event
#undef time_event_enqueue
#undef time_event_dequeue
#undef signal_time

/*
 *  kernel_cfg.c
 */
#undef init_rdypmap
#undef tmax_tskid
#undef tinib_exinf
#undef tinib_task
#undef tinib_epriority
#undef tnum_inhno
#undef inhinib_inhno
#undef inhinib_inhatr
#undef inhinib_entry
#undef tnum_intno
#undef intinib_intno
#undef intinib_intatr
#undef intinib_intpri
#undef tnum_excno
#undef excinib_excno
#undef excinib_excatr
#undef excinib_entry
#undef tmax_cycid
#undef cycinib_cycact
#undef cycinib_cycphs
#undef cycinib_cychdr
#undef cycinib_cyctim
#undef cycinib_exinf
#undef cyccb_cycact
#undef cyccb_evttim
#undef cycevtid_offset
#undef almevtid_offset
#undef almcb_almact
#undef tmax_almid
#undef alminib_almhdr
#undef alminib_exinf
#undef tnum_tmevt_queue
#undef tmevt_queue
#undef tmevt_time
#undef tmevt_callback
#undef tmevt_arg
#undef stksz
#undef stk
#undef istkpt
#undef initialize_object
#undef call_inirtn
#undef call_terrtn
#undef tmax_cycid
#undef cycinib_cycact
#undef cycinib_cychdr
#undef cycinib_cyctim
#undef cycinib_cycphs
#undef cycinib_exinf
#undef cyccb_cycact
#undef cyccb_evttim
#undef cycevtid_offset
#undef tmax_almid
#undef alminib_almhdr
#undef alminib_exinf
#undef almcb_almact
#undef almevtid_offset
#undef tnum_tmevt_queue
#undef tmevt_queue
#undef tmevt_time
#undef tmevt_callback
#undef tmevt_arg


/*
 *  target_config.c
 */
#undef target_initialize
#undef start_dispatch
#undef target_exit




#ifdef TOPPERS_LABEL_ASM

/*
 *  startup.c
 */
#undef _kerflg
#undef _exit_kernel
#undef _call_exit_kernel

/*
 *  task.c
 */
#undef _runtsk_pri
#undef _ready_primap
#undef _reqflg
#undef _disdsp
#undef _search_schedtsk
#undef _test_dormant
#undef _initialize_task
#undef _make_active
#undef _dispatcher
#undef _run_task
#undef _bitmap_search_table
#undef _bitmap_search
#undef _primap_empty
#undef _primap_test
#undef _primap_set
#undef _primap_clear
#undef _bitmap_search

/*
 *  time_event.c
 */
#undef _current_time
#undef _min_time
#undef _initialize_time_event
#undef _time_event_enqueue
#undef _time_event_dequeue
#undef _signal_time

/*
 *  cyclic.c
 */
#undef _initialize_cyclic
#undef _call_cychdr

/*
 *  alarm.c
 */
#undef _initialize_alarm
#undef _call_almhdr

/*
 *  interrupt.c
 */
#undef _initialize_interrupt

/*
 *  exception.c
 */
#undef _initialize_exception

/*
 *  cyclic.c
 */
#undef _initialize_cyclic
#undef _call_cychdr

/*
 *  alarm.c
 */
#undef _initialize_alarm
#undef _call_almhdr

/*
 *  time_event.c
 */
#undef _current_time
#undef _min_time
#undef _initialize_time_event
#undef _time_event_enqueue
#undef _time_event_dequeue
#undef _signal_time

/*
 *  kernel_cfg.c
 */
#undef _init_rdypmap
#undef _tmax_tskid
#undef _tinib_exinf
#undef _tinib_task
#undef _tinib_epriority
#undef _tnum_inhno
#undef _inhinib_inhno
#undef _inhinib_inhatr
#undef _inhinib_entry
#undef _tnum_intno
#undef _intinib_intno
#undef _intinib_intatr
#undef _intinib_intpri
#undef _tnum_excno
#undef _excinib_excno
#undef _excinib_excatr
#undef _excinib_entry
#undef _tmax_cycid
#undef _cycinib_cycact
#undef _cycinib_cycphs
#undef _cycinib_cychdr
#undef _cycinib_cyctim
#undef _cycinib_exinf
#undef _cyccb_cycact
#undef _cyccb_evttim
#undef _cycevtid_offset
#undef _almevtid_offset
#undef _almcb_almact
#undef _tmax_almid
#undef _alminib_almhdr
#undef _alminib_exinf
#undef _tnum_tmevt_queue
#undef _tmevt_queue
#undef _tmevt_time
#undef _tmevt_callback
#undef _tmevt_arg
#undef _stksz
#undef _stk
#undef _istkpt
#undef _initialize_object
#undef _call_inirtn
#undef _call_terrtn
#undef _tmax_cycid
#undef _cycinib_cycact
#undef _cycinib_cychdr
#undef _cycinib_cyctim
#undef _cycinib_cycphs
#undef _cycinib_exinf
#undef _cyccb_cycact
#undef _cyccb_evttim
#undef _cycevtid_offset
#undef _tmax_almid
#undef _alminib_almhdr
#undef _alminib_exinf
#undef _almcb_almact
#undef _almevtid_offset
#undef _tnum_tmevt_queue
#undef _tmevt_queue
#undef _tmevt_time
#undef _tmevt_callback
#undef _tmevt_arg


/*
 *  target_config.c
 */
#undef _target_initialize
#undef _start_dispatch
#undef _target_exit




#endif /* TOPPERS_LABEL_ASM */

//#include "target_unrename.h"

#endif /* TOPPERS_KERNEL_RENAME_H */
