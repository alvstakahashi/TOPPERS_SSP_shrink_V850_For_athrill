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

#ifndef TOPPERS_CYCLIC_H
#define TOPPERS_CYCLIC_H

/*
 *  周期ハンドラ初期化ブロック
 *
 *  コンフィギュレータによって生成する．
 */

/* 周期ハンドラIDの最大値 */
extern const ID tmax_cycid;

/* 周期ハンドラ属性 */
extern const uint_t cycinib_cycact;

/* 周期ハンドラアドレス */
extern const CYCHDR cycinib_cychdr[];

/* 周期ハンドラ周期 */
extern const RELTIM cycinib_cyctim[];

/* 周期ハンドラ位相 */
extern const RELTIM cycinib_cycphs[];

/* 周期ハンドラ拡張情報 */
extern const intptr_t cycinib_exinf[];

/* 周期ハンドラ動作状態 */
extern uint_t cyccb_cycact;

/* 周期ハンドラの次回起動時刻 */
extern EVTTIM cyccb_evttim[];

/* 周期ハンドラのタイムイベントIDオフセット */
extern const uint_t cycevtid_offset;

#define tnum_cyc	((uint_t)(tmax_cycid - TMIN_CYCID + 1))


/*
 *  周期ハンドラ機能の初期化
 */
extern void
initialize_cyclic(void);


#endif /* TOPPERS_CYCLIC_H */
