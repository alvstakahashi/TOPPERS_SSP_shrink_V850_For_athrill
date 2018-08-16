/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 */

/*
 *  カーネルのターゲット依存定義（V850用）
 */

/*
 *  このインクルードファイルは，kernel.hでインクルードされる．他のファ
 *  イルから直接インクルードすることはない．このファイルをインクルード
 *  する前に，t_stddef.hがインクルードされるので，それらに依存してもよ
 *  い．
 */

//#ifdef TOPPERS_KERNEL_IMPL_H
#if 1

#ifndef TOPPERS_TARGET_KERNEL_H
#define TOPPERS_TARGET_KERNEL_H

#undef		TOPPERS_RX62N			//RX62N
#undef		TOPPERS_RPI				//Raspberry PI
#define		TOPPERS_V850			// V850

#ifdef TOPPERS_V850
#define Inline	static inline		/* インライン関数 */
#endif

#ifdef TOPPERS_RPI
#define Inline	static __inline__	/* インライン関数 */
#endif

#ifdef TOPPERS_V850
/*
 *  ビットパターンやオブジェクト番号の型定義
 */
typedef	uint_t		INTNO;		/* 割込み番号 */
typedef	uint_t		INHNO;		/* 割込みハンドラ番号 */
typedef	uint_t		EXCNO;		/* CPU例外ハンドラ番号 */
#endif
/*
 *  プロセッサで共通な定義
 */
//#include "rx_rxc/prc_kernel.h"

/*
 *  サポートする機能の定義
 */
#define	TOPPERS_TARGET_SUPPORT_GET_UTM		/* get_utmをサポートする */


/*
 *  タイムティックの定義
 */
#define	TIC_NUME		( 1U )		/* タイムティックの周期の分子 */
#define	TIC_DENO		( 1U )		/* タイムティックの周期の分母 */

/*
 *  割込み番号(INTTAA2CC0)
 */
#define TIMER_DTIM_INTNO  (22)

/*
 *  タイマ割込みハンドラ登録のための定数
 */
#define INHNO_TIMER		TIMER_DTIM_INTNO	/* 割込みハンドラ番号 */
#define INTNO_TIMER		TIMER_DTIM_INTNO	/* 割込み番号 */
//#define INTPRI_TIMER	(TMAX_INTPRI - 1)	/* 割込み優先度 */
//#define INTATR_TIMER	TA_NULL				/* 割込み属性 */

/*
 *	割込み制御レジスタの番地を算出するためのマクロ
 *
 *	割込み制御レジスタは割込み番号順に並んでいるため，
 *	ベースアドレスからのオフセットでアドレスを求めることができる．
 */

#define INTREG_BASE				(0xFFFFF110)
#define INTREG_ADDRESS(intno)	(INTREG_BASE + ((intno) * 2U))


extern uint16_t disint_table[IMR_SIZE];


Inline void
sil_wrb_mem(uint8_t *mem, uint8_t data)
{
	*((volatile uint8_t *) mem) = data;
}
Inline uint8_t
sil_reb_mem(const uint8_t *mem)
{
	uint8_t	data;

	data = *((const volatile uint8_t *) mem);
	return(data);
}
/*
 *  16ビット単位の読出し／書込み
 */

Inline uint16_t
sil_reh_mem(const uint16_t *mem)
{
	uint16_t	data;

	data = *((const volatile uint16_t *) mem);
	return(data);
}
Inline void
sil_wrh_mem(uint16_t *mem, uint16_t data)
{
	*((volatile uint16_t *) mem) = data;
}

/*
 *  割込み要求禁止フラグのセット
 *
 *  割込み属性が設定されていない割込み要求ラインに対して割込み要求禁止
 *  フラグをクリアしようとした場合には，falseを返す．
 */
Inline bool_t
x_disable_int(INTNO intno)
{
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	
//	if(!VALID_INTNO_DISINT(intno))
//	{
//		return false;
//	}
	
	/* 6bit目をセット */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) | (0x01U << 6));
	/* 割込み禁止状態ビットをセット */
	disint_table[(intno / 16u)] |= (1u << (intno % 16u));
	
	return(true);
}


/*
 *  割込み要求禁止フラグの解除
 *
 *  割込み属性が設定されていない割込み要求ラインに対して割込み要求禁止
 *  フラグをクリアしようとした場合には，falseを返す．
 */

Inline bool_t
x_enable_int(INTNO intno)
{
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	
//	if(!VALID_INTNO_DISINT(intno))
//	{
//		return false;
//	}
	
	/* 6bit目をクリア */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) & ~(0x01U << 6));
	/* 割込み禁止状態ビットをクリア */
	disint_table[(intno / 16u)] &= ~(1u << (intno % 16u));
	
	return(true);
}



/*
 *  割込み要求のクリア
 */
Inline void
x_clear_int(INTNO intno)
{
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	
//	if(!VALID_INTNO_DISINT(intno))
//	{
//		return ;
//	}
	
	/* 7bit目をクリア */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) & ~(0x01U << 7));
}

#if 0
//----------------------以下　見直しまだ---------------------------------
#define	set_task_stack(x)	__asm__( "mov sp,%[Rs1]"::[Rs1]"r"(x))

#define	interrpt_IN()		do { \
								__asm__("ldr	r0, =0x000000d3;msr cpsr_c,r0;":::"r0");\
								__asm__("push {lr};":::);\
                               } while(0)


#define interrpt_OUT()		do { \
								__asm__("pop  {lr};":::);\
								__asm__("ldr	r0, =0x000000d2;msr cpsr_c,r0;":::"r0");\
                               } while(0)



#define disable_IRQ()		__asm__("mrs	r0, cpsr;ldr	r1,	=0x80;orr r0, r0, r1;msr	cpsr_c, r0;":::"r0","r1")
#define enable_IRQ()		__asm__("mrs	r0, cpsr;ldr	r1,	=0x80;bic r0, r0, #0x80;;msr	cpsr_c, r0;":::"r0")

#define	ipl_maskClear()	


#define saveCTX()	__asm__("stmfd sp!, {r5-r10};":::)
#define loadCTX()	__asm__("ldmfd sp!, {r5-r10};":::)

Inline int getmode(void)
{
	int status;
	__asm__("mrs	%[Rd], cpsr":[Rd]"=r"(status));
	return(status);
}


Inline bool_t sence_mode(void)		// 割り込みロック（不可）のとき真
{
	return(( bool_t )((getmode() & 0x80) != 0));
}


#define t_lock_cpu()	disable_IRQ()
#define i_lock_cpu()	disable_IRQ()

/*
 *  CPUロック状態の解除
 *
 *  lock_flagをFALSEにし，IPM（ハードウェアの割込み優先度マスク）を，
 *  saved_iipmに保存した値に戻す．
 *
 *  この関数は，CPUロック状態（lock_flagがtrueの状態）でのみ呼ばれるも
 *  のと想定している．
 */

#define t_unlock_cpu()	enable_IRQ()
#define i_unlock_cpu()	enable_IRQ()

/*
 *  デフォルトの非タスクコンテキスト用のスタック領域の定義
 *
 *  スタックサイズを変更する場合は, sectrx.incの_DEFAULT_ISTACK
 *  ラベルの位置にある.blkb命令のサイズと, 以下DEFAULT_ISTKSZの
 *  サイズを合わせて同じ値に変更すること.
 */
extern uint32_t	DEFAULT_ISTACK[];
#define DEFAULT_ISTKSZ		( 0x500U )
#define DEFAULT_ISTK		( (void *)&DEFAULT_ISTACK[0] )



Inline void idle_loop(void)
{
	t_unlock_cpu();
	t_lock_cpu();
}

/*
 *  プロセッサステータスレジスタ(PSW)の現在値の読出し
 */
 

#define t_sense_lock()	sence_mode()
#define i_sense_lock()	sence_mode()


/*
 *  コンテキストの参照
 *
 *  RXでは，割込みの戻り先がタスクかどうかを判断するために intnest
 *  を使用している．これを用いてコンテキストを判断する．
 */

Inline bool_t sense_context( void )
{
	/*  ネストカウンタ0より大なら非タスクコンテキスト  */
	return ( intnest > 0U );
}
#endif


#endif /* TOPPERS_TARGET_KERNEL_H */
#endif
