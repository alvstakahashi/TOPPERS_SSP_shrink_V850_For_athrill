/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
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

/*
 *  周期ハンドラ機能
 */

#include "kernel_impl.h"
#include "check.h"
#include "time_event.h"
#include "cyclic.h"

/*
 *  トレースログマクロのデフォルト定義
 */
#ifndef LOG_CYC_ENTER
#define LOG_CYC_ENTER(cycidx)
#endif /* LOG_CYC_ENTER */

#ifndef LOG_CYC_LEAVE
#define LOG_CYC_LEAVE(cycidx)
#endif /* LOG_CYC_LEAVE */

#ifndef LOG_STA_CYC_ENTER
#define LOG_STA_CYC_ENTER(cycid)
#endif /* LOG_STA_CYC_ENTER */

#ifndef LOG_STA_CYC_LEAVE
#define LOG_STA_CYC_LEAVE(ercd)
#endif /* LOG_STA_CYC_LEAVE */

#ifndef LOG_STP_CYC_ENTER
#define LOG_STP_CYC_ENTER(cycid)
#endif /* LOG_STP_CYC_ENTER */

#ifndef LOG_STP_CYC_LEAVE
#define LOG_STP_CYC_LEAVE(ercd)
#endif /* LOG_STP_CYC_LEAVE */


/* 周期ハンドラIDをタイムイベントIDに変換 */
#define CYC_EVTID(cycidx)	((ID)((cycidx) + cycevtid_offset))
#define INDEX_CYC(cycid)	((uint_t)((cycid) - TMIN_CYCID))


/* 周期ハンドラの動作状態を表すビットマップ */
#define CYCACT_BIT(index)	(1U << (index))

/*
 *  周期ハンドラ起動ルーチン
 */
void call_cychdr(uintptr_t cycidx);

/*
 *  周期ハンドラ機能の初期化
 */

#define TOPPERS_cycini
#ifdef TOPPERS_cycini

void
initialize_cyclic(void)
{
	uint_t i;
	
	/* 周期ハンドラの状態設定 */
	cyccb_cycact = cycinib_cycact;
	
	for(i = 0U ; i < tnum_cyc ; i++) {
		cyccb_evttim[i] = 0U;
		
		/* 周期ハンドラの初期起動 */
		if((cycinib_cycact & CYCACT_BIT(i)) != 0U) {
			time_event_enqueue(CYC_EVTID(i) ,
				(EVTTIM)cycinib_cycphs[i] , call_cychdr , i);
			cyccb_evttim[i] = cycinib_cycphs[i];
		}
	}
}

#endif /* TOPPERS_cycini */

#define TOPPERS_sta_cyc
#ifdef TOPPERS_sta_cyc

ER
sta_cyc(ID cycid)
{
	ER ercd;
	uint_t index = INDEX_CYC(cycid);
	EVTTIM evttim;
	
	LOG_STA_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	
	t_lock_cpu();
	
	if((cyccb_cycact & CYCACT_BIT(index)) != 0U) {
		time_event_dequeue(CYC_EVTID(index));
	}
	else {
		cyccb_cycact |= CYCACT_BIT(index);
	}

	evttim = current_time + cycinib_cycphs[index];
	time_event_enqueue(CYC_EVTID(index) ,
		 evttim , call_cychdr , index);
	cyccb_evttim[index] = evttim;
	
	ercd = E_OK;
	t_unlock_cpu();
	
  error_exit:
	LOG_STA_CYC_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_sta_cyc */


#define TOPPERS_stp_cyc
#ifdef TOPPERS_stp_cyc

ER
stp_cyc(ID cycid)
{
	ER ercd;
	uint_t index = INDEX_CYC(cycid);
	
	LOG_STP_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	
	t_lock_cpu();
	
	if((cyccb_cycact & CYCACT_BIT(index)) != 0U) {
		cyccb_cycact &= ~CYCACT_BIT(index);
		time_event_dequeue(CYC_EVTID(index));
	}
	ercd = E_OK;
	t_unlock_cpu();
	
  error_exit:
	LOG_STA_CYC_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_stp_cyc */

#define TOPPERS_cyccal
#ifdef TOPPERS_cyccal

void
call_cychdr(uintptr_t cycidx)
{
	cyccb_evttim[cycidx] += cycinib_cyctim[cycidx];

	/* 次周期のタイムイベントを登録 */
	time_event_enqueue((ID)cycidx ,
		cyccb_evttim[cycidx] , call_cychdr , cycidx);
	
	i_unlock_cpu();
	
	/* 周期ハンドラを実行 */
	LOG_CYC_ENTER(cycidx);
	(*cycinib_cychdr[cycidx])(cycinib_exinf[cycidx]);
	LOG_CYC_LEAVE(cycidx);
	
	if (!i_sense_lock()) {
		i_lock_cpu();
	}
}

#endif /* TOPPERS_cyccal */
