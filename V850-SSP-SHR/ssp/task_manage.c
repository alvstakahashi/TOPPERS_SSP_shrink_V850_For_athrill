/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
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
#include <stddef.h>
#include <limits.h>

/*
 *		タスク管理機能
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"



/*
 *  トレースログマクロのデフォルト定義
 */
#ifndef LOG_ACT_TSK_ENTER
#define LOG_ACT_TSK_ENTER(tskid)
#endif /* LOG_ACT_TSK_ENTER */

#ifndef LOG_ACT_TSK_LEAVE
#define LOG_ACT_TSK_LEAVE(ercd)
#endif /* LOG_ACT_TSK_LEAVE */

#ifndef LOG_IACT_TSK_ENTER
#define LOG_IACT_TSK_ENTER(tskid)
#endif /* LOG_IACT_TSK_ENTER */

#ifndef LOG_IACT_TSK_LEAVE
#define LOG_IACT_TSK_LEAVE(ercd)
#endif /* LOG_IACT_TSK_LEAVE */


/*
 *  タスクの起動
 */

#define  TOPPERS_act_tsk
#ifdef TOPPERS_act_tsk

ER
act_tsk(ID tskid)
{
	ER		ercd;
	uint_t	tskpri;
	
	LOG_ACT_TSK_ENTER(tskid);
//	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	
	tskpri = get_ipri_self(tskid);
	
	t_lock_cpu();
	if (test_dormant(tskpri)) {
		if(make_active(tskpri)) {
#if 1
			//ここのコンテキクストを登録
			if (setjmp(task_ctx[tskpri]) == 0)
			{
				/*登録した場合*/
				longjmp(disp_ctx,1);			//sta_kerの続きに行く
			}
			else
			{
				// タスク復帰した場合
				ipl_maskClear();
				//t_unlock_cpu();
				//return(ercd);
			}	
#endif
			//run_task(tskpri);
		}
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	t_unlock_cpu();

  error_exit:
	LOG_ACT_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_act_tsk */

/*
 *  タスクの起動（非タスクコンテキスト用）
 */
#define TOPPERS_iact_tsk
#ifdef TOPPERS_iact_tsk

ER
iact_tsk(ID tskid)
{
	ER		ercd;
	uint_t	ipri;
	
	LOG_IACT_TSK_ENTER(tskid);
//	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	ipri = get_ipri(tskid);

	i_lock_cpu();
	if (test_dormant(ipri)) {
		if(make_active(ipri)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IACT_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iact_tsk */
