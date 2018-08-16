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

/*
 *  キュー操作ヘッダ
 *
 *  SSPカーネルではメモリ節約のためにインデックスを使用したキューを用いる
 */

#ifndef TOPPERS_QUEUE_H
#define TOPPERS_QUEUE_H

/* キューのインデックス */
typedef uint8_t QUEIDX;

/* キュー構造体 */
typedef struct
{
	QUEIDX	next;
	QUEIDX	prev;
} QUEUE;


/* キューヘッダの初期化 */
Inline void
queue_initialize(QUEUE *queue , QUEIDX queue_null)
{
	queue->next = queue->prev = queue_null;
}

/* 指定した要素の前に新たな要素を追加 */
Inline void
queue_insert_prev(QUEUE *top , QUEIDX queue , QUEIDX entry)
{
	top[entry].prev = top[queue].prev;
	top[entry].next = queue;
	top[top[queue].prev].next = entry;
	top[queue].prev = entry;
}


/* 指定したキューの次の要素を削除し，そのインデックスを返す */
Inline QUEIDX
queue_delete_next(QUEUE *top , QUEIDX queue)
{
	top[top[queue].next].prev = top[queue].prev;
	top[top[queue].prev].next = top[queue].next;
	
	return top[queue].next;
}


/*
 *  キューが空かどうかのテスト
 *
 *  queueにはキューヘッダを指定すること
 */
Inline bool_t
queue_empty(QUEUE *queue , QUEIDX queue_null)
{
	bool_t empty;
	
	if(queue->next == queue_null)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}
	
	return empty;
}

#endif /* TOPPERS_QUEUE_H */
