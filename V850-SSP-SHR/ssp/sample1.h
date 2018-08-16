/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY
extern void	task1(intptr_t arg);
extern void	task2(intptr_t arg);

extern void setup(void);

extern void cyclic_handler(intptr_t exinf);

extern void alarm_handler(intptr_t exinf);		//alvstakahashi
extern void alarm_handler2(intptr_t exinf);		//alvstakahashi


#endif /* TOPPERS_MACRO_ONLY */
