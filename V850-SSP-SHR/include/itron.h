/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: itron.h 1014 2008-05-10 08:28:40Z ertl-hiro $
 */

/*
 *		ITRON�d�l���ʋK��̃f�[�^�^�E�萔�E�}�N��
 *
 *  ���̃w�b�_�t�@�C���́CITRON�d�l���ʋK��̃f�[�^�^�E�萔�E�}�N���̒�
 *  �ŁCTOPPERS���ʃw�b�_�t�@�C���Ɋ܂܂�Ȃ����̂̒�`���܂ށDITRON�d
 *  �l�Ƃ̌݊�����K�v�Ƃ���A�v���P�[�V�������C���N���[�h���邱�Ƃ�z
 *  �肵�Ă���D
 *
 *  �A�Z���u������̃\�[�X�t�@�C�����炱�̃t�@�C�����C���N���[�h���鎞
 *  �́CTOPPERS_MACRO_ONLY���`���Ă����D����ɂ��C�}�N����`�ȊO��
 *  �����悤�ɂȂ��Ă���D
 */

#ifndef TOPPERS_ITRON_H
#define TOPPERS_ITRON_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  TOPPERS���ʃw�b�_�t�@�C��
 */
#include "t_stddef.h"

/*
 *  ITRON�d�l���ʃf�[�^�^
 */
#ifndef TOPPERS_MACRO_ONLY

#ifdef INT8_MAX
typedef	int8_t			B;			/* �����t��8�r�b�g���� */
#endif /* INT8_MAX */

#ifdef UINT8_MAX
typedef	uint8_t			UB;			/* ��������8�r�b�g���� */
typedef	uint8_t			VB;			/* �^����܂�Ȃ�8�r�b�g�̒l */
#endif /* UINT8_MAX */

typedef	int16_t			H;			/* �����t��16�r�b�g���� */
typedef	uint16_t		UH;			/* ��������16�r�b�g���� */
typedef	uint16_t		VH;			/* �^����܂�Ȃ�16�r�b�g�̒l */

typedef	int32_t			W;			/* �����t��32�r�b�g���� */
typedef	uint32_t		UW;			/* ��������32�r�b�g���� */
typedef	uint32_t		VW;			/* �^����܂�Ȃ�32�r�b�g�̒l */

#ifdef INT64_MAX
typedef	int64_t			D;			/* �����t��64�r�b�g���� */
#endif /* INT64_MAX */

#ifdef UINT64_MAX
typedef	uint64_t		UD;			/* ��������64�r�b�g���� */
typedef	uint64_t		VD;			/* �^����܂�Ȃ�64�r�b�g�̒l */
#endif /* UINT64_MAX */

typedef	void			*VP;		/* �^����܂�Ȃ����̂ւ̃|�C���^ */

typedef int_t			INT;		/* ���R�ȃT�C�Y�̕����t������ */
typedef uint_t			UINT;		/* ���R�ȃT�C�Y�̕����������� */

typedef bool_t			BOOL;		/* �^�U�l */

typedef	intptr_t		VP_INT;		/* �|�C���^�܂��͕����t������ */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ITRON�d�l���ʒ萔
 */
#define	TRUE		true			/* �^ */
#define	FALSE		false			/* �U */

/*
 *  �I�u�W�F�N�g�����̒�`
 */
#define TA_HLNG			UINT_C(0x00)	/* ��������p�C���^�t�F�[�X */
#define TA_TFIFO		UINT_C(0x00)	/* �^�X�N�̑҂��s���FIFO���� */
#define TA_MFIFO		UINT_C(0x00)	/* ���b�Z�[�W�L���[��FIFO���� */
#define TA_WSGL			UINT_C(0x00)	/* �҂��^�X�N��1�̂� */
#define TA_DISINT		UINT_C(0x00)	/* �����ݗv���֎~�t���O���Z�b�g */
#define TA_LEVEL		UINT_C(0x00)	/* ���x���g���K */

/*
 *  �l�X�g�񐔂̍ő�l
 */
#define TMAX_SUSCNT		UINT_C(1)		/* �����҂��v���l�X�g���̍ő�l */

/*
 *  �����҂���Ԃ���̋����ĊJ
 */
#define frsm_tsk(tskid)		rsm_tsk(tskid)

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_ITRON_H */
