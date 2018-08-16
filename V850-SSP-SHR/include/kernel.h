/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2009 by Embedded and Real-Time Systems Laboratory
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

/*
 *		TOPPERS/SSPカーネル 標準ヘッダファイル
 *
 *  TOPPERS/SSPカーネルがサポートするサービスコールの宣言と，必要なデー
 *  タ型，定数，マクロの定義を含むヘッダファイル．
 *
 *  アセンブリ言語のソースファイルからこのファイルをインクルードする時
 *  は，TOPPERS_MACRO_ONLYを定義しておく．これにより，マクロ定義以外を
 *  除くようになっている．
 *
 *  このファイルをインクルードする前にインクルードしておくべきファイル
 *  はない．
 */

#ifndef TOPPERS_KERNEL_H
#define TOPPERS_KERNEL_H

/*
 *	TOPPERS共通のデータ型・定数・マクロ
 */
#include <t_stddef.h>

/*
 *  ターゲット依存部
 */
#include "target_kernel.h"
#ifndef TOPPERS_MACRO_ONLY

/*
 *  データ型の定義
 */

/*
 *  ビットパターンやオブジェクト番号の型定義
 */
typedef	uint_t		INTNO;		/* 割込み番号 */
typedef	uint_t		INHNO;		/* 割込みハンドラ番号 */
typedef	uint_t		EXCNO;		/* CPU例外ハンドラ番号 */

/*
 *  処理単位の型定義
 */
typedef void	(*TASK)(intptr_t exinf);
typedef void	(*ISR)(intptr_t exinf);
typedef void	(*INTHDR)(void);
typedef void	(*EXCHDR)(void *p_excinf);
typedef void	(*INIRTN)(intptr_t exinf);
typedef void	(*TERRTN)(intptr_t exinf);
typedef void	(*CYCHDR)(intptr_t exinf);
typedef void	(*ALMHDR)(intptr_t exinf);

/*
 *  メモリ領域確保のための型定義
 */
#ifndef TOPPERS_STK_T
#define TOPPERS_STK_T	intptr_t
#endif /* TOPPERS_STK_T */
typedef	TOPPERS_STK_T	STK_T;	/* スタック領域を確保するための型 */


/*
 *  サービスコールの宣言
 */

/*
 *  タスク管理機能
 */
extern ER		act_tsk(ID tskid);
extern ER		iact_tsk(ID tskid);

/*
 *  システム状態管理機能
 */
extern ER		loc_cpu(void);
extern ER		iloc_cpu(void);
extern ER		unl_cpu(void);
extern ER		iunl_cpu(void);
extern ER		dis_dsp(void);
extern ER		ena_dsp(void);
extern bool_t	sns_ctx(void);
extern bool_t	sns_loc(void);
extern bool_t	sns_dsp(void);
extern bool_t	sns_dpn(void);
extern bool_t	sns_ker(void);
extern ER		ext_ker(void);

/*
 *  割込み管理機能
 */
extern ER		dis_int(INTNO intno);
extern ER		ena_int(INTNO intno);

/*
 *  周期ハンドラ機能
 */
extern ER		sta_cyc(ID cycid);
extern ER		stp_cyc(ID cycid);

/*
 *  アラームハンドラ機能
 */
extern ER		sta_alm(ID almid , RELTIM almtim);
extern ER		stp_alm(ID almid);

/*
 *  システム時間管理機能
 */
extern ER		get_tim(SYSTIM *p_systim);

extern ER 		dly_tsk(RELTIM dlytim);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  オブジェクト属性の定義
 */
#define TA_RSTR			UINT_C(0x04)	/* 制約タスク */

#define TA_ACT			UINT_C(0x02)	/* タスクを起動された状態で生成 */

#define TA_STA			UINT_C(0x02)	/* 周期ハンドラを動作状態で生成 */

#define TA_NONKERNEL	UINT_C(0x02)	/* カーネル管理外の割込み */

#define TA_ENAINT		UINT_C(0x01)	/* 割込み要求禁止フラグをクリア */
#define TA_EDGE			UINT_C(0x02)	/* エッジトリガ */

/*
 *  その他の定数の定義
 */
#define TSK_SELF		0			/* 自タスク指定 */
#define TSK_NONE		0			/* 該当するタスクがない */

#define TPRI_INI		0			/* タスクの起動時優先度 */

#define TIPM_ENAALL		0			/* 割込み優先度マスク全解除 */

/*
 *  構成定数とマクロ
 */

/*
 *  優先度の範囲
 */
#define TMIN_TPRI		1			/* タスク優先度の最小値（最高値）*/
#ifndef TMAX_TPRI
	#define TMAX_TPRI		16			/* タスク優先度の最大値（最低値）*/
#elif (TMAX_TPRI != 8) || (TMAX_TPRI != 16)
	#error "TMAX_TPRI must defined 8 or 16."
#endif	/* TMAX_TPRI */

#define TMIN_ISRPRI		1			/* 割込みサービスルーチン優先度の最小値 */
#ifndef TMAX_ISRPRI
	#define TMAX_ISRPRI		16			/* 割込みサービスルーチン優先度の最大値 */
#elif (TMAX_ISRPRI != 8) || (TMAX_ISRPRI != 16)
	#error "TMAX_ISRPRI must defined 8 or 16."
#endif	/* TMAX_ISRPRI */

/*
 *  バージョン情報
 */
#define TKERNEL_MAKER	UINT_C(0x0118)	/* カーネルのメーカーコード */
#define TKERNEL_PRID	UINT_C(0x0007)	/* カーネルの識別番号 */
#define TKERNEL_SPVER	UINT_C(0xf511)	/* カーネル仕様のバージョン番号 */
#define TKERNEL_PRVER	UINT_C(0x1100)	/* カーネルのバージョン番号 */

/*
 *  メモリ領域確保のためのマクロ
 *
 *  以下のTOPPERS_COUNT_SZとTOPPERS_ROUND_SZの定義は，unitが2の巾乗であ
 *  ることを仮定している．
 */
#ifndef TOPPERS_COUNT_SZ
#define TOPPERS_COUNT_SZ(sz, unit)	(((sz) + (unit) - 1) / (unit))
#endif /* TOPPERS_COUNT_SZ */
#ifndef TOPPERS_ROUND_SZ
#define TOPPERS_ROUND_SZ(sz, unit)	(((sz) + (unit) - 1) & ~((unit) - 1))
#endif /* TOPPERS_ROUND_SZ */

#define COUNT_STK_T(sz)		TOPPERS_COUNT_SZ(sz, sizeof(STK_T))
#define ROUND_STK_T(sz)		TOPPERS_ROUND_SZ(sz, sizeof(STK_T))


#endif /* TOPPERS_KERNEL_H */
