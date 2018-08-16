/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2010 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2011 by Meika Sugimoto
 * 
 *  上記著作権者は，以下の (1)～(4) の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改変・
 *  再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作権
 *      表示，この利用条件および下記の無保証規定が，そのままの形でソース
 *      コード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使用
 *      できる形で再配布する場合には，再配布に伴うドキュメント（利用者マ
 *      ニュアルなど）に，上記の著作権表示，この利用条件および下記の無保
 *      証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使用
 *      できない形で再配布する場合には，次のいずれかの条件を満たすこと．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに報
 *        告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損害
 *      からも，上記著作権者およびTOPPERSプロジェクトを免責すること．また，
 *      本ソフトウェアのユーザまたはエンドユーザからのいかなる理由に基づ
 *      く請求からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者およ
 *  びTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的に対す
 *  る適合性も含めて，いかなる保証も行わない．また，本ソフトウェアの利用
 *  により直接的または間接的に生じたいかなる損害に関しても，その責任を負
 *  わない．
 * 
 */

#ifndef TOPPERS_TASK_H
#define TOPPERS_TASK_H
#include <setjmp.h>

#include "kernel_impl.h"

//#define run_task					_kernel_run_task

/*
 *  タスク優先度の内部表現・外部表現変換マクロ
 */
#define INT_PRIORITY(x)		((uint_t)((x) - TMIN_TPRI))

/*
 *  タスクIDの最大値（kernel_cfg.c）
 */
extern const ID	tmax_tskid;

/*
 *  タスクの数
 */
#define tnum_tsk	((uint_t)(tmax_tskid - TMIN_TSKID + 1))

/*
 *  実行可能状態のタスクがない時の実行タスクの起動時優先度
 */
#define IPRI_NULL	(UINT_MAX)


extern uint_t get_ipri_self(ID tskid);
extern uint_t get_ipri(ID tskid);

/*
 *  ディスパッチ／タスク例外処理ルーチン起動要求フラグ
 *
 *  割込みハンドラ／CPU例外ハンドラの出口処理に，ディスパッチまたは
 *  タスク例外処理ルーチンの起動を要求することを示すフラグ．
 */
extern bool_t	reqflg;

/*
 *  ディスパッチ禁止状態
 *
 *  ディスパッチ禁止状態であることを示すフラグ．
 */
extern bool_t	disdsp;
extern jmp_buf disp_ctx;		//ディスパッチャコンテキスト

/*
 *  タスクの初期化
 */
extern void initialize_task(void);
/*
 *  実行状態タスクの起動時優先度
 */
extern uint_t runtsk_ipri;

/*
 *  タスクの起動
 */
extern bool_t make_active(uint_t ipri);

/*
 *  タスクの休止
 */
extern bool_t test_dormant(uint_t tskid);

/*
 *  最高優先順位タスクのサーチ
 */
extern uint_t search_schedtsk(void);

/*
 *  タスクの実行
 */
extern void run_task(uint_t ipri);

/*
 *  タスクディスパッチャ
 */
extern void dispatcher(void);

extern jmp_buf task_ctx[];

extern void dispach(intptr_t task_id);

extern void make_ctx(uint_t ipri);


#endif /* TOPPERS_TASK_H */
