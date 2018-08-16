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
 *  Copyright (C) 2010 by Meika Sugimoto
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
#include <stdio.h>

#include "kernel_impl.h"
#include "task.h"

#include "kernel_cfg.h"



/*
 *  トレースログマクロのデフォルト定義
 */

#ifndef LOG_DSP_ENTER
	#define LOG_DSP_ENTER(tskidx)
#endif /* LOG_DSP_ENTER */

#ifndef LOG_DSP_LEAVE
	#define LOG_DSP_LEAVE(tskidx)
#endif /* LOG_DSP_ENTER */


extern const intptr_t	tinib_exinf[];			/* タスクの拡張情報 */
extern const TASK    	tinib_task[];			/* タスクの起動番地 */
extern const uint_t  	tinib_epriority[];		/* タスクの実行時優先度先度（内部表現） */



#define TOPPERS_tskini

#ifdef TOPPERS_tskini
/*-------------------------------------------
 * ディスパッチャーのコンテキスト
 */
jmp_buf disp_ctx;		//ディスパッチャコンテキスト

/*
 * 実行状態タスクの起動時優先度
 */
uint_t runtsk_ipri;

/*
 *  レディキューサーチのためのビットマップ
 */
volatile uint_t	ready_primap;

/*
 *  タスクディスパッチ起動要求フラグ
 */
bool_t	reqflg;

/*
 *  ディスパッチ禁止状態
 */
bool_t	disdsp;

/* 
 * 前回　実行task
 */
intptr_t last_ipri;

/*
 *  read_primapの初期値
 */
extern const uint_t init_rdypmap;

#endif /* TOPPERS_tskini */

#define TOPPERS_get_ipri_self
#ifdef TOPPERS_get_ipri_self

/*
 *  タスクIDから起動時優先度を取り出すためのマクロ
 */
uint_t
get_ipri_self(ID tskid)
{
	uint_t inipri;
	
	if(tskid != TSK_SELF)
	{
		inipri = (uint_t)((tskid) - TMIN_TSKID);
	}
	else
	{
		inipri = runtsk_ipri;
	}
	return inipri;
}

#endif /* TOPPERS_get_ipri_self */

#define TOPPERS_get_ipri
#ifdef TOPPERS_get_ipri

uint_t
get_ipri(ID tskid)
{
	return (uint_t)(tskid - TMIN_TSKID);
}

#endif /* TOPPERS_get_ipri */

/*
 *  ビットマップサーチ関数
 *
 *  bitmap内の1のビットの内，最も下位（右）のものをサーチし，そのビッ
 *  ト番号を返す．ビット番号は，最下位ビットを0とする．bitmapに0を指定
 *  してはならない．この関数では，bitmapが8ビットであることを仮定し，
 *  uint8_t型としている．
 *
 *  ビットサーチ命令を持つプロセッサでは，ビットサーチ命令を使うように
 *  書き直した方が効率が良い場合がある．このような場合には，ターゲット
 *  依存部でビットサーチ命令を使ったbitmap_searchを定義し，
 *  OMIT_BITMAP_SEARCHをマクロ定義すればよい．また，ビットサーチ命令の
 *  サーチ方向が逆などの理由で優先度とビットとの対応を変更したい場合に
 *  は，PRIMAP_BITをマクロ定義すればよい．
 *
 *  また，標準ライブラリにffsがあるなら，次のように定義して標準ライブ
 *  ラリを使った方が効率が良い可能性もある．
 *		#define	bitmap_search(bitmap) (ffs(bitmap) - 1)
 */
#ifndef PRIMAP_BIT
#define	PRIMAP_BIT(pri)		(1U << (pri))
#endif /* PRIMAP_BIT */


#ifndef OMIT_BITMAP_SEARCH




/*
 *  割込み発生回数を保存する変数
 */
volatile  uint16_t	intnest;


static const uint8_t bitmap_search_table[] = { 0U, 1U, 0U, 2U, 0U, 1U, 0U,
												3U, 0U, 1U, 0U, 2U, 0U, 1U, 0U };



#pragma inline (bitmap_search)
static  uint_t bitmap_search(uint_t bitmap)
{
	uint_t	n = 0U;

	if ((bitmap & 0x0fU) == 0U) {
		bitmap >>= 4U;
		n += 4U;
	}
	return (n + bitmap_search_table[(bitmap & 0x0fU) - 1U]);
}

#endif /* OMIT_BITMAP_SEARCH */

/*
 *  優先度ビットマップが空かのチェック
 */
#pragma inline (primap_empty) 
static bool_t primap_empty(void)
{
	return (ready_primap == 0U);
}

/*
 *  指定した優先度の優先度ビットマップがセットされているかどうかのチェック
 */
#pragma inline (primap_test) 
static bool_t primap_test(uint_t pri)
{
	return ((ready_primap & PRIMAP_BIT(pri)) != 0U);
}

/*
 *  優先度ビットマップのサーチ
 */
#pragma inline (primap_search) 
static uint_t primap_search(void)
{
	return bitmap_search((uint_t)ready_primap);
}

/*
 *  優先度ビットマップのセット
 */
#pragma inline (primap_set) 
static void primap_set(uint_t pri)
{
	ready_primap |= PRIMAP_BIT(pri);
}

/*
 *  優先度ビットマップのクリア
 */
#pragma inline (primap_clear) 
static void primap_clear(uint_t pri)
{
	ready_primap &= ~PRIMAP_BIT(pri);
}

/*
 *  最高優先順位タスクのサーチ
 */
#define TOPPERS_tsksched

#ifdef TOPPERS_tsksched

uint_t
search_schedtsk(void)
{
	return primap_search();
}

#endif /* TOPPERS_tsksched */

/*
 * 指定した起動時優先度のタスクが実行できる状態かどうかのテスト
 *
 * 実行できる場合はtrueを返す．
 */
bool_t
test_dormant(uint_t ipri)
{
	return !primap_test(ipri);
}

/*
 *  タスク管理モジュールの初期化
 */

#define TOPPERS_tskini

#ifdef TOPPERS_tskini

void
initialize_task(void)
{
	intptr_t ipri;
	/* レディキューのビットマップ初期化 */
	ready_primap = init_rdypmap;
	
	/* 実行時優先度の初期化 */
	runtsk_ipri = IPRI_NULL;
	
	last_ipri = 0xff;		//ありえない値にする
	
	/* タスクコンテキストの設定*/
	for(ipri = 0;ipri <  TNUM_TSKID;ipri++)
	{
		if (primap_test(ipri))
		{
			make_ctx(ipri);
		}
		task_wait[ipri] = 0;
		tskTout[ipri] = 0;
	}
	/* 割込み禁止フラグの初期化 */
	disdsp = false;
}

#endif /* TOPPERS_tskini */

/*-----------------------------------------------------
 *  コンテキストの準備をしておく					takahashi
 */
static jmp_buf jmpp;		//このルーチンのセーブ用
 
void make_ctx(uint_t ipri_prm)
{
	intptr_t debugtemp = 0;
	uint_t ipri = ipri_prm;
	intptr_t task_stackadr;
//	t_lock_cpu();
	if (setjmp(jmpp) == 0)	//ここに戻り用
	{
		if (setjmp(task_ctx[ipri]) == 0)
		{
			/*登録した場合*/
			longjmp(jmpp,1);	//戻る
		}
		else
		{
			t_lock_cpu();
			ipri = runtsk_ipri;			//longjmpで戻って来た時は不定
			/* タスク起動時 */
			ipl_maskClear();

			//続き
			// タスクスタックに切り替える
			task_stackadr = TOPPERS_TASKSTKPT(ipri);
			set_task_stack(task_stackadr);

			t_unlock_cpu();
			/* タスクに来ました*/
			/* タスク実行開始 */
			(*((TASK)(tinib_task[ipri])))(tinib_exinf[ipri]);
   			t_lock_cpu();
			ipri = runtsk_ipri;			//longjmpで戻って来た時は不定
	
			disdsp = false;
			/* ビットマップクリア． */
			primap_clear(ipri);
			//タスクが終わった場合どうするのか？--> このあとは　dispacher()に行く
			longjmp(disp_ctx,1);			//sta_kerの続きに行く
		}
	}
	else
	{
		//登録終了
//		t_unlock_cpu();
	}
}
/*
 *  ipri : 起動対象タスクの起動時優先度(内部表現)
 */
#define TOPPERS_tskact 
#ifdef TOPPERS_tskact

bool_t
make_active(uint_t ipri)
{
	bool_t dsp;
	
	primap_set(ipri);
	
	if(ipri < runtsk_ipri) {
		dsp = !disdsp;
	}
	else {
		dsp = false;
	}
	make_ctx(ipri);	
	return dsp;
}

#endif /* TOPPERS_tskact */


/*
 *  apri : 実行開始タスクの起動時優先度
 *  呼び出し条件： CPUロック
 */
#define TOPPERS_tsk_dsp
#ifdef TOPPERS_tsk_dsp
void dispatch(intptr_t ipri)
{
	last_ipri = ipri;
	runtsk_ipri = ipri;
	longjmp(task_ctx[ipri],1);
}

#define TOPPERS_tskrun

#ifdef TOPPERS_tskrun

void
run_task(uint_t ipri)
{
	dispatch((intptr_t)ipri);
}

#endif /* TOPPERS_tskrun */

/*
 *  この関数は全割込みロック状態と同等の状態で sta_ker から呼ばれる
 */


void
dispatcher(void)
{
	do {
		if(!primap_empty()) {
			/* タスクの開始 */
			//run_task(search_schedtsk());
			dispatch(search_schedtsk());		//これからは帰ってこない
		}
		else {
			last_ipri = 0xff;
			idle_loop();
		}
	} while(true);
}
ER
wai_tsk(void)
{
	ER		ercd;
	uint_t	tskpri;
	
//	LOG_ACT_TSK_ENTER(tskid);
//	CHECK_TSKCTX_UNL();
//	CHECK_TSKID_SELF(tskid);
	
	tskpri = get_ipri_self(TSK_SELF);
	//tskpri = runtsk_ipri;
	t_lock_cpu();
	task_wait[tskpri] = 1;		//wait状態
	primap_clear(tskpri);		//レディQから削除
	
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
		t_unlock_cpu();
		return(ercd);
	}	

	t_unlock_cpu();


	return(ercd);
}

ER
go_tsk(ID tskid)
{
	ER		ercd;
	uint_t	self_tskpri;	//呼び出しタスク
	uint_t	ipri;			//go するタスク
	
	
//	LOG_ACT_TSK_ENTER(tskid);
//	CHECK_TSKCTX_UNL();
//	CHECK_TSKID_SELF(tskid);
	
	ipri = get_ipri(tskid);
	self_tskpri = get_ipri_self(TSK_SELF);	
	t_lock_cpu();
	if (task_wait[ipri] == 0)
	{
		t_unlock_cpu();
		return(E_OBJ);
	}

	task_wait[ipri] = 0;		//wait状態解除
	primap_set(ipri);		//レディQ追加
	


	//ここのコンテキクストを登録
	if (setjmp(task_ctx[self_tskpri]) == 0)
	{
		/*登録した場合*/
		longjmp(disp_ctx,1);			//sta_kerの続きに行く
	}
	else
	{
		// タスク復帰した場合
		ipl_maskClear();
		t_unlock_cpu();
		return(ercd);
	}	

	t_unlock_cpu();


	return(ercd);
}

#endif /* TOPPERS_tsk_dsp */


extern void signal_time(void);

void isig_tim()
{
	int tskid;

//	i_lock_cpu();

	signal_time();						//周期管理処理呼び出し

	for(tskid = 0 ; tskid < TNUM_TSKID; tskid++)
	{
		if (tskTout[tskid] != 0)
		{
			if (--tskTout[tskid] == 0)
			{
				task_wait[tskid] = 0;		//wait状態解除
				primap_set(tskid);		//レディQ追加
				reqflg = 1;
			}
		}
	}
//	i_unlock_cpu();
}

#define MAXTOUT 0xfffffffe

ER
dly_tsk(RELTIM dlytim)
{

	ER		ercd;
	uint_t	tskpri;
	
	if (dlytim > MAXTOUT)
	{
		return(E_PAR);
	}
	
//	LOG_ACT_TSK_ENTER(tskid);
//	CHECK_TSKCTX_UNL();
//	CHECK_TSKID_SELF(tskid);
	
	tskpri = get_ipri_self(TSK_SELF);
	//tskpri = runtsk_ipri;
	t_lock_cpu();
	task_wait[tskpri] = 1;		//wait状態
	primap_clear(tskpri);		//レディQから削除
	tskTout[tskpri] = dlytim+1;
	
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
		t_unlock_cpu();
#if 0
		printf("dly_tsk End\n");
#endif
		return(ercd);
	}	

	t_unlock_cpu();


	return(ercd);
}

void handler(INTHDR userhandler)
{
	volatile static intptr_t newtskipi;
	
	intnest++;						//割り込みネスト数インクリメント
//	i_unlock_cpu();					//割り込み許可
	(*userhandler)();				//ユーザーハンドラ呼び出し
//	i_lock_cpu();					//割り込み不可
	intnest--;						//割り込みネスト数デクリメント

	if (intnest == 0)				//多重割り込み中でない
	{
		if (reqflg !=0)				//スケジュール必要
		{
			reqflg = 0;
			newtskipi = search_schedtsk();			//次にディスパッチされるタスクID
			if ((last_ipri != 0xff) && (last_ipri != newtskipi))
			{
				//ここでコンテキスト、正確には、calleeセーブレジスタの保存
				saveCTX();
				// RUN中に高優先度のタスクに切り替わる場合
				if (setjmp(task_ctx[last_ipri]) == 0)
				{
					// 高優先度のタスクにディスパッチ
					dispatch(newtskipi);	//これはリターンしない
				}
				//コンテキスト　calleeセーブレジスタ復帰
				loadCTX();
			}
		}
	}
}
