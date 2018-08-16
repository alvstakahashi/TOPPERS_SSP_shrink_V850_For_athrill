/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: t_stddef.h 1513 2009-04-22 07:35:20Z ertl-hiro $
 */

/*
 *		TOPPERS���ʃw�b�_�t�@�C��
 *
 *  TOPPERS�֘A�̂��ׂẴ\�[�X�t�@�C���ŃC���N���[�h���ׂ��w�b�_�t�@�C
 *  ���D�e��̃J�[�l����\�t�g�E�F�A���i�ŋ��ʂɗp���邱�Ƃ�z�肵�Ă�
 *  ��DTOPPERS�̊e��̃J�[�l����\�t�g�E�F�A���i�ŋ��ʂɗp����f�[�^�^�C
 *  �萔�C�}�N���̒�`�Ȃǂ��܂ށD
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă����D����ɂ��C�}�N����`�ȊO��
 *  �����悤�ɂȂ��Ă���D
 *
 *  ���̃t�@�C�����C���N���[�h����O�ɃC���N���[�h���Ă����ׂ��t�@�C��
 *  �͂Ȃ��D
 */

#ifndef TOPPERS_T_STDDEF_H
#define TOPPERS_T_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  �^�[�Q�b�g�ˑ���
 */
//#include "target_stddef.h"
#include <stddef.h>
#include <stdint.h>

/*
 *  C����/EC++��throw()�ɑΏ����邽�߂̒�`
 */
#if !defined(__cplusplus) || defined(__embedded_cplusplus)
#define throw()
#endif

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �^�[�Q�b�g�ˑ��̃f�[�^�^�̃}�N���̃f�t�H���g��`
 */
#ifndef TOPPERS_bool
#define TOPPERS_bool	int				/* �u�[���^ */
#endif /* TOPPERS_bool */

#ifndef TOPPERS_size
#define TOPPERS_size	uintptr_t		/* �T�C�Y�^ */
#endif /* TOPPERS_size */

#ifndef TOPPERS_fp
struct TOPPERS_dummy_t { int TOPPERS_dummy_field; };
typedef	void			(*TOPPERS_fp_t)(struct TOPPERS_dummy_t);
#define TOPPERS_fp		TOPPERS_fp_t	/* �v���O�����̋N���Ԓn */
#endif /* TOPPERS_fp */

/*
 *  ���ʃf�[�^�^
 */
typedef TOPPERS_bool	bool_t;		/* �^�U�l */
typedef unsigned char	char_t;		/* ���������̕����^ */

typedef signed int		int_t;		/* ���R�ȃT�C�Y�̕����t������ */
typedef unsigned int	uint_t;		/* ���R�ȃT�C�Y�̕����������� */

typedef signed long		long_t;		/* ���߂̃T�C�Y�̕����t������ */
typedef unsigned long	ulong_t;	/* ���߂̃T�C�Y�̕����������� */

typedef int_t			FN;			/* �@�\�R�[�h */
typedef	int_t			ER;			/* �G���[�R�[�h */
typedef	int_t			ID;			/* �I�u�W�F�N�g��ID�ԍ� */
typedef	uint_t			ATR;		/* �I�u�W�F�N�g�̑��� */
typedef	uint_t			STAT;		/* �I�u�W�F�N�g�̏�� */
typedef	uint_t			MODE;		/* �T�[�r�X�R�[���̓��샂�[�h */
typedef	int_t			PRI;		/* �D��x */
typedef	TOPPERS_size	SIZE;		/* �������̈�̃T�C�Y */

typedef	int_t			TMO;		/* �^�C���A�E�g�w�� */
typedef	uint_t			RELTIM;		/* ���Ύ��� */
typedef	ulong_t			SYSTIM;		/* �V�X�e������ */
typedef	ulong_t			SYSUTM;		/* ���\�]���p�V�X�e������ */

typedef	TOPPERS_fp		FP;			/* �v���O�����̋N���Ԓn */

typedef	int_t			ER_BOOL;	/* �G���[�R�[�h�܂��͐^�U�l */
typedef	int_t			ER_ID;		/* �G���[�R�[�h�܂���ID�ԍ� */
typedef	int_t			ER_UINT;	/* �G���[�R�[�h�܂��͕����������� */

typedef	uint32_t		ACPTN;		/* �A�N�Z�X���p�^�[�� */
typedef	struct acvct {				/* �A�N�Z�X���x�N�^ */
	ACPTN		acptn1;				/* �ʏ푀��1�̃A�N�Z�X���p�^�[�� */
	ACPTN		acptn2;				/* �ʏ푀��2�̃A�N�Z�X���p�^�[�� */
	ACPTN		acptn3;				/* �Ǘ�����̃A�N�Z�X���p�^�[�� */
	ACPTN		acptn4;				/* �Q�Ƒ���̃A�N�Z�X���p�^�[�� */
} ACVCT;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �����萔�����}�N��
 */
#ifndef UINT_C
#define UINT_C(val)		(val ## U)		/* uint_t�^�̒萔�����}�N�� */
#endif /* UINT_C */

#ifndef ULONG_C
#define ULONG_C(val)	(val ## UL)		/* ulong_t�^�̒萔�����}�N�� */
#endif /* ULONG_C */

/*
 *  ��ʒ萔
 */
#ifndef NULL
#define NULL		0			/* �����|�C���^ */
#endif /* NULL */

#ifndef true
#define true		1			/* �^ */
#endif /* true */

#ifndef false
#define false		0			/* �U */
#endif /* false */

#define E_OK		0			/* ����I�� */

/*
 *  ���C���G���[�R�[�h
 */
#define E_SYS		(-5)		/* �V�X�e���G���[ */
#define E_NOSPT		(-9)		/* ���T�|�[�g�@�\ */
#define E_RSFN		(-10)		/* �\��@�\�R�[�h */
#define E_RSATR		(-11)		/* �\�񑮐� */
#define E_PAR		(-17)		/* �p�����[�^�G���[ */
#define E_ID		(-18)		/* �s��ID�ԍ� */
#define E_CTX		(-25)		/* �R���e�L�X�g�G���[ */
#define E_MACV		(-26)		/* �������A�N�Z�X�ᔽ */
#define E_OACV		(-27)		/* �I�u�W�F�N�g�A�N�Z�X�ᔽ */
#define E_ILUSE		(-28)		/* �T�[�r�X�R�[���s���g�p */
#define E_NOMEM		(-33)		/* �������s�� */
#define E_NOID		(-34)		/* ID�ԍ��s�� */
#define E_NORES		(-35)		/* �����s�� */
#define E_OBJ		(-41)		/* �I�u�W�F�N�g��ԃG���[ */
#define E_NOEXS		(-42)		/* �I�u�W�F�N�g������ */
#define E_QOVR		(-43)		/* �L���[�C���O�I�[�o�[�t���[ */
#define E_RLWAI		(-49)		/* �҂���Ԃ̋������� */
#define E_TMOUT		(-50)		/* �|�[�����O���s�܂��̓^�C���A�E�g */
#define E_DLT		(-51)		/* �҂��I�u�W�F�N�g�̍폜 */
#define E_CLS		(-52)		/* �҂��I�u�W�F�N�g�̏�ԕω� */
#define E_WBLK		(-57)		/* �m���u���b�L���O��t�� */
#define E_BOVR		(-58)		/* �o�b�t�@�I�[�o�[�t���[ */

/*
 *  �I�u�W�F�N�g����
 */
#define TA_NULL		UINT_C(0)	/* �I�u�W�F�N�g�������w�肵�Ȃ� */

/*
 *  �^�C���A�E�g�w��
 */
#define TMO_POL		0			/* �|�[�����O */
#define TMO_FEVR	(-1)		/* �i�v�҂� */
#define TMO_NBLK	(-2)		/* �m���u���b�L���O */

/*
 *  �A�N�Z�X���p�^�[��
 */
#define TACP_KERNEL		(0U)	/* �J�[�l���h���C�������ɃA�N�Z�X������ */
#define TACP_SHARED		(~0U)	/* ���ׂẴh���C������A�N�Z�X������ */

/*
 *  �^�Ɋւ���������o�����߂̃}�N��
 */
#ifndef offsetof
#define	offsetof(structure, field)	((uintptr_t) &(((structure *) 0)->field))
#endif /* offsetof */

#ifndef alignof
#define alignof(type)	offsetof(struct { char field1; type field2; }, field2)
#endif /* alignof */

#ifndef ALIGN_TYPE				/* �A���C�������g�̃`�F�b�N */
#define ALIGN_TYPE(addr, type) \
						((((uintptr_t)(addr)) & (alignof(type) - 1)) == 0U)
#endif /* ALIGN_TYPE */

/*
 *  assert�}�N��
 */
#undef assert
#ifndef NDEBUG
#define assert(exp)		((void)((exp) ? 0 : (TOPPERS_assert_fail(#exp, \
							__FILE__, __LINE__), TOPPERS_assert_abort(), 0)))
#else /* NDEBUG */
#define assert(exp)		((void) 0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif

/*
 *  �G���[�R�[�h�����E�����}�N��
 *
 *  �ȉ��̃}�N����`�́C�����t��������2�̕␔�ŕ\������Ă���C�E�V�t�g
 *  ���Z�q�i>>�j���Z�p�V�t�g����邱�Ƃ����肵�Ă���D�����łȂ��J����
 *  ���ł́Ctarget_stddef.h�ł����̒�`���㏑�����Ȃ���΂Ȃ�Ȃ��D
 *
 *  MERCD�}�N���̒�`�́C���C���G���[�R�[�h�����ł��邱�Ƃ����肵�Ă���D
 *  �����łȂ��ꍇ�C2�̒�`����v���Ȃ��Ȃ�D
 */
#ifndef ERCD
#define ERCD(mercd, sercd) \
				((ER)((((uint_t) sercd) << 8) | (((uint_t) mercd) & 0xffU)))
#endif /* ERCD */

#ifndef MERCD
#ifdef INT8_MAX
#define MERCD(ercd)		((ER)((int8_t)(ercd)))
#else /* INT8_MAX */
#define MERCD(ercd)		((ER)(((uint_t) ercd) | ~0xffU))
#endif /* INT8_MAX */
#endif /* MERCD */

#ifndef SERCD
#define SERCD(ercd)		((ER)((ercd) >> 8))
#endif /* SERCD */

/*
 *  �A�N�Z�X���p�^�[�������}�N��
 */
#define TACP(domid)		(1U << ((domid) - 1))	/* domid�����ɃA�N�Z�X������ */

/*
 *  ���Ύ��ԁiRELTIM�j�Ɏw��ł���ő�l
 */
#if UINT_MAX < LONG_MAX
#define TMAX_RELTIM		((RELTIM) UINT_MAX)
#else /* UINT_MAX < LONG_MAX */
#define TMAX_RELTIM		((RELTIM) LONG_MAX)
#endif /* UINT_MAX < LONG_MAX */

#endif /* TOPPERS_T_STDDEF_H */
