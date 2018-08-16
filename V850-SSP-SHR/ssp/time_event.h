/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2011 by Meika Sugimoto
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件を満たす場合に限り，本ソフトウェ
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

#ifndef TOPPERS_TIME_EVENT_H
#define TOPPERS_TIME_EVENT_H

#include "kernel_impl.h"
#include "queue.h"

/* イベント時刻 */
typedef ulong_t	EVTTIM;

/*
 *  タイムイベントコールバック関数
 */

typedef void (*CBACK)(uintptr_t arg);

/*
 *  タイムイベントブロック
 *
 *  コンフィギュレータによって生成する．
 */

/* タイムイベントブロックのサイズ */
extern const uint_t tnum_tmevt_queue;

/* タイムイベントキュー */
extern QUEUE tmevt_queue[];

/* タイムイベント時間 */
extern EVTTIM tmevt_time[];

/* タイムイベントのコールバック */
extern CBACK tmevt_callback[];

/* タイムイベントコールバックの引数 */
extern uintptr_t tmevt_arg[];


/* 現在のシステム時刻 */
extern EVTTIM current_time;


/*
 *  タイムイベントの初期化
 */
extern void
initialize_time_event(void);

/*
 *  タイムイベントの登録
 */
extern void
time_event_enqueue(ID tmevtid , EVTTIM evttim , CBACK callback , uintptr_t arg);

/*
 *  タイムイベントの削除
 */
extern void
time_event_dequeue(ID tmevtid);

/*
 *  タイムティックの供給
 */
extern void
signal_time(void);


#endif	/* TOPPERS_TIME_EVENT_H */
