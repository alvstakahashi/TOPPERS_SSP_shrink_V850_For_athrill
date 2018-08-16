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

#include "kernel_impl.h"

#include "time_event.h"


/*
 *  現在のシステム時刻（単位: 1ミリ秒）
 *
 *  厳密には，前のタイムティックのシステム時刻．
 */
EVTTIM	current_time;

/*
 *  タイムイベントヒープ中で有効な最小のシステム時刻（単位: 1ミリ秒）
 */
EVTTIM	min_time;


/*
 *  タイムイベントキューのキューヘッダ
 *
 *  タイムイベントキューブロックの終端に確保する．
 */
#define TMEVT_HEAD()	(tmevt_queue[tnum_tmevt_queue])
#define TMEVT_NULL		((QUEIDX)tnum_tmevt_queue)

/*
 *  イベント発生時刻比較マクロ
 *
 *  イベント発生時刻は，min_timeからの相対値で比較する．すなわち，
 *  min_timeを最小値（最も近い時刻），mit_time-1が最大値（最も遠い時刻）
 *  とみなして比較する．
 */
#define	EVTTIM_LT(t1, t2) (((t1) - min_time) < ((t2) - min_time))
#define	EVTTIM_LE(t1, t2) (((t1) - min_time) <= ((t2) - min_time))

/*
 *  タイムイベントの初期化
 */

#define TOPPERS_tmevtini
#ifdef TOPPERS_tmevtini

void
initialize_time_event(void)
{
	/* 変数の初期化 */
	current_time = 0U;
	min_time = 0U;
	
	/* タイムイベントキューの初期化 */
	queue_initialize(&TMEVT_HEAD() , (QUEIDX)tnum_tmevt_queue);
}

#endif /* TOPPERS_tmevtini */

/*
 *  タイムイベントの登録
 */

#define TOPPERS_tmevtenq
#ifdef TOPPERS_tmevtenq

void
time_event_enqueue(ID tmevtid , EVTTIM evttim , CBACK callback , uintptr_t arg)
{
	QUEIDX pos = TMEVT_HEAD().next;
	
	/* 挿入位置を検索 */
	while((pos != TMEVT_NULL)
			&& (EVTTIM_LE(tmevt_time[pos] , evttim))) {
		pos = tmevt_queue[pos].next;
	}
	
	/* キューに挿入 */
	queue_insert_prev(&(tmevt_queue[0]) , pos , (QUEIDX)tmevtid);
	tmevt_callback[tmevtid] = (CBACK)callback;
	tmevt_arg[tmevtid] = arg;
	tmevt_time[tmevtid] = evttim;
}

#endif /* TOPPERS_tmevtenq */

/*
 *  タイムイベントの削除
 */

#define TOPPERS_tmevtdeq
#ifdef TOPPERS_tmevtdeq

void
time_event_dequeue(ID tmevtid)
{
	/* キューから削除 */
	(void)queue_delete_next(&(tmevt_queue[0]) , (QUEIDX)tmevtid);
}

#endif /* TOPPERS_tmevtdeq */

/*
 *  システム時刻の通知
 */

#define TOPPERS_sig_tim
#ifdef TOPPERS_sig_tim

void
signal_time(void)
{
	QUEIDX pos = TMEVT_HEAD().next , evtid;
	
//	i_lock_cpu();
	
	/* 現在時刻の更新 */
	current_time += (EVTTIM)TIC_NUME;
	
	/* コールバックの実行 */
	while((pos != TMEVT_NULL)
			&& EVTTIM_LT(tmevt_time[pos] , current_time)) {
		(void)queue_delete_next(&(tmevt_queue[0]) , pos);
		evtid = pos;
		pos = tmevt_queue[pos].next;
		(*tmevt_callback[evtid])(tmevt_arg[evtid]);
	}

	/* min_timeの更新 */
	min_time = current_time;
	
//	i_unlock_cpu();
}

#endif /* TOPPERS_sig_tim */
