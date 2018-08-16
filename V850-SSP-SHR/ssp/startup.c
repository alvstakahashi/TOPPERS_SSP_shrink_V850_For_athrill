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
 *  Copyright (C) 2010-2011 by Meika Sugimoto
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
 *		カーネルの初期化と終了処理
 */

#include "task.h"
#include "t_stddef.h"
#include "kernel_impl.h"

/*
 *	RAM エリアを確保しておく
 */
#define		SIZEOF_NOUSE	0x500
STK_T       _kernel_No_USE[COUNT_STK_T(SIZEOF_NOUSE)] = { 0 };
/*
 *  カーネル動作状態フラグ
 *
 *  スタートアップルーチンで，false（＝0）に初期化されることを期待して
 *  いる．
 */
bool_t	kerflg = false;


/*
 *  カーネルの起動
 *    NMIを除く全ての割込みがマスクされた状態(全割込みロック状態に相当)で呼び出される．
 *  パワーオンからコールされる　スタックは4バイト消費されている　takahashi
 *  割り込みベクタ初期化済み、ハードウエア初期化済み、RAM初期化済みで呼び出される
 
 */
void
sta_ker(void)
{
	initialize_object();			//必要
	kerflg = true;
	intnest = 0;
	setjmp(disp_ctx);	//登録時もjumpしてもいずれも次へ行く
	dispatcher();
}


/*
 *  カーネルの終了
一旦以下全部削除

 */

