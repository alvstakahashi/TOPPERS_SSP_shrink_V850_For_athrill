/*
 *  TOPPERS/SSP Kernel
 *      Smallest Set Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2010 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *		TOPPERS/ASP�J�[�l�����������W���w�b�_�t�@�C��
 *
 *  ���̃w�b�_�t�@�C���́C�J�[�l�����\������v���O�����̃\�[�X�t�@�C��
 *  �ŕK���C���N���[�h����ׂ��W���w�b�_�t�@�C���ł���D
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă����D����ɂ��C�}�N����`�ȊO��
 *  �����悤�ɂȂ��Ă���D
 */

#ifndef TOPPERS_KERNEL_IMPL_H
#define TOPPERS_KERNEL_IMPL_H

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include "kernel_rename.h"
//#define intnest						_kernel_intnest

/*
 *  �J�[�l�������ԃt���O�istartup.c�j
 */
#include <t_stddef.h>

extern bool_t	kerflg;

extern volatile uint16_t intnest;
/*
 *  �A�v���P�[�V�����Ƌ��ʂ̃w�b�_�t�@�C��
 */
#include <kernel.h>

/*
 *  �^�L���X�g���s���}�N���̒�`
 */
#ifndef CAST
#define CAST(type, val)		((type)(val))
#endif /* CAST */

/*
 *  �^�[�Q�b�g�ˑ����̒�`
 */
//#include "target_config.h"

/*
 *  ���ׂĂ̊֐����R���p�C�����邽�߂̒�`
 */
//#ifdef ALLFUNC
//#include "allfunc.h"
//#endif /* ALLFUNC */

/*
 *  �r�b�g�t�B�[���h�ł̕������������^
 *
 *  8�r�b�g�ȉ��̕��̃r�b�g�t�B�[���h�ŁC�������������l��ێ��������ꍇ
 *  �ɗp����ׂ��f�[�^�^�DANSI C�ł́C�r�b�g�t�B�[���h�̃f�[�^�^�ɂ�
 *  int��unsigned int����������Ȃ����߁C�f�t�H���g�̒�`��unsigned
 *  int�Ƃ��Ă��邪�C�^�[�Q�b�g����уc�[���ˑ��ŁCunsigned char�܂���
 *  unsigned short�ɒ�`���������������ǂ��ꍇ������D
 */
#ifndef BIT_FIELD_UINT
#define BIT_FIELD_UINT		unsigned int
#endif /* BIT_FIELD_UINT */

/*
 *  �r�b�g�t�B�[���h�ł̃u�[���^
 *
 *  1�r�b�g���̃r�b�g�t�B�[���h�ŁC�u�[���l��ێ��������ꍇ�ɗp����ׂ�
 *  �f�[�^�^�D�f�t�H���g�ł�BIT_FIELD_UINT�Ɠ���ɒ�`���Ă��邪�C�u�[
 *  ���l��ێ����邱�Ƃ𖾎����邽�߂ɕʂ̖��̂Ƃ��Ă���D
 */
#ifndef BIT_FIELD_BOOL
#define BIT_FIELD_BOOL		BIT_FIELD_UINT
#endif /* BIT_FIELD_BOOL */

/*
 *  �I�u�W�F�N�gID�̍ŏ��l�̒�`
 */
#define TMIN_TSKID		1		/* �^�X�NID�̍ŏ��l */
#define TMIN_CYCID		1		/* �����n���h��ID�̍ŏ��l */
#define TMIN_ALMID		1		/* �A���[���n���h��ID�̍ŏ��l */

/*
 *  �D��x�̒i�K���̒�`
 */
#define TNUM_TPRI		(TMAX_TPRI - TMIN_TPRI + 1)
#define TNUM_INTPRI		(TMAX_INTPRI - TMIN_INTPRI + 1)

/*
 *  �w�b�_�t�@�C���������Ȃ����W���[���̊֐��E�ϐ��̐錾
 */
#ifndef TOPPERS_MACRO_ONLY

/*
 *  �e���W���[���̏������ikernel_cfg.c�j
 */
extern void	initialize_object(void);

/*
 *  ���������[�`���̎��s�ikernel_cfg.c�j
 */
extern void	call_inirtn(void);

/*
 *  �I���������[�`���̎��s�ikernel_cfg.c�j
 */
extern void	call_terrtn(void);

/*
 *  ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�ikernel_cfg.c�j
 */
extern const SIZE	istksz;		/* �X�^�b�N�̈�̃T�C�Y�i�ۂ߂��l�j */
extern STK_T *const	istk;		/* �X�^�b�N�̈�̐擪�Ԓn */
#ifdef TOPPRES_ISTKPT
extern STK_T *const	istkpt;		/* �X�^�b�N�|�C���^�̏����l */
#endif /* TOPPERS_ISTKPT */




/*
 *  �J�[�l���̋N���istartup.c�j
 */
extern void	sta_ker(void);

/*
 *  �J�[�l���̏I�������istartup.c�j
 */
extern void	exit_kernel(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_KERNEL_IMPL_H */
