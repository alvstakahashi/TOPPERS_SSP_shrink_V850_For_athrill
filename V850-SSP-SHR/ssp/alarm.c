/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2011 by Meika Sugimoto
 *  Copyright (C) 2015 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  アラームハンドラ機能
 */

#include "alarm.h"
#include "check.h"
#include "time_event.h"

/*
 *  トレースログマクロのデフォルト定義
 */

#ifndef LOG_ALM_ENTER
#define LOG_ALM_ENTER(almidx)
#endif /* LOG_ALM_ENTER */

#ifndef LOG_ALM_LEAVE
#define LOG_ALM_LEAVE(almidx)
#endif /* LOG_ALM_LEAVE */

#ifndef LOG_STA_ALM_ENTER
#define LOG_STA_ALM_ENTER(almid, almtim)
#endif /* LOG_STA_ALM_ENTER */

#ifndef LOG_STA_ALM_LEAVE
#define LOG_STA_ALM_LEAVE(ercd)
#endif /* LOG_STA_ALM_LEAVE */

#ifndef LOG_ISTA_ALM_ENTER
#define LOG_ISTA_ALM_ENTER(almid, almtim)
#endif /* LOG_ISTA_ALM_ENTER */

#ifndef LOG_ISTA_ALM_LEAVE
#define LOG_ISTA_ALM_LEAVE(ercd)
#endif /* LOG_ISTA_ALM_LEAVE */

#ifndef LOG_STP_ALM_ENTER
#define LOG_STP_ALM_ENTER(almid)
#endif /* LOG_STP_ALM_ENTER */

#ifndef LOG_STP_ALM_LEAVE
#define LOG_STP_ALM_LEAVE(ercd)
#endif /* LOG_STP_ALM_LEAVE */

#ifndef LOG_ISTP_ALM_ENTER
#define LOG_ISTP_ALM_ENTER(almid)
#endif /* LOG_ISTP_ALM_ENTER */

#ifndef LOG_ISTP_ALM_LEAVE
#define LOG_ISTP_ALM_LEAVE(ercd)
#endif /* LOG_ISTP_ALM_LEAVE */


/* 周期ハンドラIDをタイムイベントIDに変換 */
#define ALM_EVTID(almid)	((ID)(INDEX_ALM(almid) + almevtid_offset))
#define INDEX_ALM(almid)	((uint_t)((almid) - TMIN_ALMID))

/* アラームハンドラの個数 */
#define tnum_alm			((uint_t)(tmax_almid - TMIN_ALMID + 1))

/* アラームの動作状態を表すビットマップ */
#define ALMACT_BIT(index)	(1U << (index))


/* アラームハンドラ実行タイムイベント */
void call_almhdr(uintptr_t almidx);


/*
 *  アラームハンドラ機能の初期化
 */

#define TOPPERS_almcal
#ifdef TOPPERS_almcal

void
initialize_alarm(void)
{
	/* 全てのアラームを停止状態にする */
	almcb_almact = 0U;
}

#endif /* TOPPERS_almcal */

/*
 *  アラームの開始
 */

#define TOPPERS_sta_alm
#ifdef TOPPERS_sta_alm

ER
sta_alm(ID almid , RELTIM almtim)
{
	ER ercd;
	uint_t index = INDEX_ALM(almid);
	
	LOG_STA_ALM_ENTER(almid, almtim);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	
	t_lock_cpu();
	
	if((almcb_almact & ALMACT_BIT(index)) != 0U) {
		time_event_dequeue(ALM_EVTID(almid));
	}
	else {
		almcb_almact |= ALMACT_BIT(index);
	}
	
	time_event_enqueue(ALM_EVTID(almid) ,
		current_time + (EVTTIM)almtim , (CBACK)call_almhdr , index);
	
	ercd = E_OK;
	t_unlock_cpu();
	
  error_exit:
	LOG_STA_ALM_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_sta_alm */

/*
 *  アラームの開始(非タスクコンテキスト用)
 */

#define TOPPERS_ista_alm
#ifdef TOPPERS_ista_alm

ER
ista_alm(ID almid , RELTIM almtim)
{
	ER ercd;
	uint_t index = INDEX_ALM(almid);
	
	LOG_ISTA_ALM_ENTER(almid, almtim);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	
	i_lock_cpu();
	
	if((almcb_almact & ALMACT_BIT(index)) != 0U) {
		time_event_dequeue(ALM_EVTID(almid));
	}
	else {
		almcb_almact |= ALMACT_BIT(index);
	}
	
	time_event_enqueue(ALM_EVTID(almid) ,
		current_time + (EVTTIM)almtim , (CBACK)call_almhdr , index);
	
	ercd = E_OK;
	i_unlock_cpu();
	
  error_exit:
	LOG_ISTA_ALM_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_ista_alm */

/*
 *  アラームの停止
 */

#define TOPPERS_stp_alm
#ifdef TOPPERS_stp_alm

ER
stp_alm(ID almid)
{
	ER ercd;
	uint_t index = INDEX_ALM(almid);
	
	LOG_STP_ALM_ENTER(almid);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	
	t_lock_cpu();
	
	if((almcb_almact & ALMACT_BIT(index)) != 0U) {
		almcb_almact &= ~ALMACT_BIT(index);
		time_event_dequeue(ALM_EVTID(almid));
	}
	ercd = E_OK;
	t_unlock_cpu();
	
  error_exit:
	LOG_STP_ALM_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_stp_alm */

/*
 *  アラームの停止(非タスクコンテキスト用)
 */

#define TOPPERS_istp_alm
#ifdef TOPPERS_istp_alm

ER
istp_alm(ID almid)
{
	ER ercd;
	uint_t index = INDEX_ALM(almid);
	
	LOG_ISTP_ALM_ENTER(almid);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	
	i_lock_cpu();
	
	if((almcb_almact & ALMACT_BIT(index)) != 0U) {
		almcb_almact &= ~ALMACT_BIT(index);
		time_event_dequeue(ALM_EVTID(almid));
	}
	ercd = E_OK;
	i_unlock_cpu();
	
  error_exit:
	LOG_ISTP_ALM_LEAVE(ercd);
	return ercd;
}

#endif /* TOPPERS_istp_alm */

/*
 *  アラームハンドラ起動ルーチン
 */

#define TOPPERS_almcal
#ifdef TOPPERS_almcal

void
call_almhdr(uintptr_t almidx)
{
	/* アラームハンドラを停止状態にする */
	almcb_almact &= ~ALMACT_BIT(almidx);
	
	i_unlock_cpu();
	
	/* アラームハンドラの実行 */
	LOG_ALM_ENTER(almidx);
	(*alminib_almhdr[almidx])(alminib_exinf[almidx]);
	LOG_ALM_LEAVE(almidx);
	
	if (!i_sense_lock()) {
		i_lock_cpu();
	}
}

#endif /* TOPPERS_almcal */

