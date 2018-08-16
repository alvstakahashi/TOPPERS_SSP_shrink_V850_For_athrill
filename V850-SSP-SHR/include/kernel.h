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
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE
 *  �Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒��쌠
 *      �\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[�X
 *      �R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p�҃}
 *      �j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L�̖���
 *      �؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g�ɕ�
 *        �����邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹�Q
 *      ������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD�܂��C
 *      �{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝�R�Ɋ��
 *      ������������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂���
 *  ��TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI�ɑ΂�
 *  ��K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p
 *  �ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC��
 *  ��Ȃ��D
 * 
 */

/*
 *		TOPPERS/SSP�J�[�l�� �W���w�b�_�t�@�C��
 *
 *  TOPPERS/SSP�J�[�l�����T�|�[�g����T�[�r�X�R�[���̐錾�ƁC�K�v�ȃf�[
 *  �^�^�C�萔�C�}�N���̒�`���܂ރw�b�_�t�@�C���D
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă����D����ɂ��C�}�N����`�ȊO��
 *  �����悤�ɂȂ��Ă���D
 *
 *  ���̃t�@�C�����C���N���[�h����O�ɃC���N���[�h���Ă����ׂ��t�@�C��
 *  �͂Ȃ��D
 */

#ifndef TOPPERS_KERNEL_H
#define TOPPERS_KERNEL_H

/*
 *	TOPPERS���ʂ̃f�[�^�^�E�萔�E�}�N��
 */
#include <t_stddef.h>

/*
 *  �^�[�Q�b�g�ˑ���
 */
#include "target_kernel.h"
#ifndef TOPPERS_MACRO_ONLY

/*
 *  �f�[�^�^�̒�`
 */

/*
 *  �r�b�g�p�^�[����I�u�W�F�N�g�ԍ��̌^��`
 */
typedef	uint_t		INTNO;		/* �����ݔԍ� */
typedef	uint_t		INHNO;		/* �����݃n���h���ԍ� */
typedef	uint_t		EXCNO;		/* CPU��O�n���h���ԍ� */

/*
 *  �����P�ʂ̌^��`
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
 *  �������̈�m�ۂ̂��߂̌^��`
 */
#ifndef TOPPERS_STK_T
#define TOPPERS_STK_T	intptr_t
#endif /* TOPPERS_STK_T */
typedef	TOPPERS_STK_T	STK_T;	/* �X�^�b�N�̈���m�ۂ��邽�߂̌^ */


/*
 *  �T�[�r�X�R�[���̐錾
 */

/*
 *  �^�X�N�Ǘ��@�\
 */
extern ER		act_tsk(ID tskid);
extern ER		iact_tsk(ID tskid);

/*
 *  �V�X�e����ԊǗ��@�\
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
 *  �����݊Ǘ��@�\
 */
extern ER		dis_int(INTNO intno);
extern ER		ena_int(INTNO intno);

/*
 *  �����n���h���@�\
 */
extern ER		sta_cyc(ID cycid);
extern ER		stp_cyc(ID cycid);

/*
 *  �A���[���n���h���@�\
 */
extern ER		sta_alm(ID almid , RELTIM almtim);
extern ER		stp_alm(ID almid);

/*
 *  �V�X�e�����ԊǗ��@�\
 */
extern ER		get_tim(SYSTIM *p_systim);

extern ER 		dly_tsk(RELTIM dlytim);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �I�u�W�F�N�g�����̒�`
 */
#define TA_RSTR			UINT_C(0x04)	/* ����^�X�N */

#define TA_ACT			UINT_C(0x02)	/* �^�X�N���N�����ꂽ��ԂŐ��� */

#define TA_STA			UINT_C(0x02)	/* �����n���h���𓮍��ԂŐ��� */

#define TA_NONKERNEL	UINT_C(0x02)	/* �J�[�l���Ǘ��O�̊����� */

#define TA_ENAINT		UINT_C(0x01)	/* �����ݗv���֎~�t���O���N���A */
#define TA_EDGE			UINT_C(0x02)	/* �G�b�W�g���K */

/*
 *  ���̑��̒萔�̒�`
 */
#define TSK_SELF		0			/* ���^�X�N�w�� */
#define TSK_NONE		0			/* �Y������^�X�N���Ȃ� */

#define TPRI_INI		0			/* �^�X�N�̋N�����D��x */

#define TIPM_ENAALL		0			/* �����ݗD��x�}�X�N�S���� */

/*
 *  �\���萔�ƃ}�N��
 */

/*
 *  �D��x�͈̔�
 */
#define TMIN_TPRI		1			/* �^�X�N�D��x�̍ŏ��l�i�ō��l�j*/
#ifndef TMAX_TPRI
	#define TMAX_TPRI		16			/* �^�X�N�D��x�̍ő�l�i�Œ�l�j*/
#elif (TMAX_TPRI != 8) || (TMAX_TPRI != 16)
	#error "TMAX_TPRI must defined 8 or 16."
#endif	/* TMAX_TPRI */

#define TMIN_ISRPRI		1			/* �����݃T�[�r�X���[�`���D��x�̍ŏ��l */
#ifndef TMAX_ISRPRI
	#define TMAX_ISRPRI		16			/* �����݃T�[�r�X���[�`���D��x�̍ő�l */
#elif (TMAX_ISRPRI != 8) || (TMAX_ISRPRI != 16)
	#error "TMAX_ISRPRI must defined 8 or 16."
#endif	/* TMAX_ISRPRI */

/*
 *  �o�[�W�������
 */
#define TKERNEL_MAKER	UINT_C(0x0118)	/* �J�[�l���̃��[�J�[�R�[�h */
#define TKERNEL_PRID	UINT_C(0x0007)	/* �J�[�l���̎��ʔԍ� */
#define TKERNEL_SPVER	UINT_C(0xf511)	/* �J�[�l���d�l�̃o�[�W�����ԍ� */
#define TKERNEL_PRVER	UINT_C(0x1100)	/* �J�[�l���̃o�[�W�����ԍ� */

/*
 *  �������̈�m�ۂ̂��߂̃}�N��
 *
 *  �ȉ���TOPPERS_COUNT_SZ��TOPPERS_ROUND_SZ�̒�`�́Cunit��2�̋Џ�ł�
 *  �邱�Ƃ����肵�Ă���D
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
