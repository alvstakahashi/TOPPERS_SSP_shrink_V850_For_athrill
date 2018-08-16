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
 */

/*
 *  �J�[�l���̃^�[�Q�b�g�ˑ���`�iFRK-RX62N�p�j
 */

/*
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h�ŃC���N���[�h�����D���̃t�@
 *  �C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C���N���[�h
 *  ����O�ɁCt_stddef.h���C���N���[�h�����̂ŁC�����Ɉˑ����Ă���
 *  ���D
 */

#ifdef TOPPERS_KERNEL_IMPL_H

#ifndef TOPPERS_TARGET_KERNEL_H
#define TOPPERS_TARGET_KERNEL_H

/*
 *  �v���Z�b�T�ŋ��ʂȒ�`
 */
//#include "rx_rxc/prc_kernel.h"

/*
 *  I�t���O, IPL���擾���邽�߂̃}�N����`
 */
#define PSW_I_MASK		( 0x00010000UL )
#define PSW_IPL_MASK	( 0x07000000UL )

/*
 *  �T�|�[�g����@�\�̒�`
 */
#define	TOPPERS_TARGET_SUPPORT_GET_UTM		/* get_utm���T�|�[�g���� */


/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME		( 1U )		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO		( 1U )		/* �^�C���e�B�b�N�̎����̕��� */




/*
 *  NMI���������ׂĂ̊����݂̋֎~
 */
#pragma inline_asm	disint
static void
disint( void )
{
	clrpsw	i
}

#pragma inline_asm	ipl_maskClear
static void 
ipl_maskClear(void)
{
	MVTIPL	#0
}
/*
 *  NMI���������ׂĂ̊����݂̋���
 */
#pragma inline_asm	enaint
static void
enaint( void )
{
	setpsw	i
}

/*
 *  CPU���b�N��Ԃւ̈ڍs
 *
 *  IPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���Csaved_iipm�ɕۑ����C�J�[
 *  �l���Ǘ��O�̂��̂��������ׂĂ̊����ݗv�����}�X�N����l�iTIPM_LOCK�j
 *  �ɐݒ肷��D�܂��Clock_flag��TRUE�ɂ���D
 *
 *  IPM���C�ŏ�����TIPM_LOCK�Ɠ����������荂���ꍇ�ɂ́C�����
 *  saved_iipm�ɕۑ�����݂̂ŁCTIPM_LOCK�ɂ͐ݒ肵�Ȃ��D����́C���f��
 *  ��̊����ݗD��x�}�X�N���CTIPM_LOCK�Ɠ����������荂�����x���ɐݒ�
 *  ����Ă����Ԃɂ�����D
 *
 *  ���̊֐��́CCPU���b�N��ԁilock_flag��TRUE�̏�ԁj�ŌĂ΂�邱�Ƃ�
 *  �Ȃ����̂Ƒz�肵�Ă���D
 */
#pragma inline  (x_lock_cpu)
static void x_lock_cpu( void ) 
{	
	disint();
}

#define t_lock_cpu()	x_lock_cpu()
#define i_lock_cpu()	x_lock_cpu()


/*
 *  CPU���b�N��Ԃ̉���
 *
 *  lock_flag��FALSE�ɂ��CIPM�i�n�[�h�E�F�A�̊����ݗD��x�}�X�N�j���C
 *  saved_iipm�ɕۑ������l�ɖ߂��D
 *
 *  ���̊֐��́CCPU���b�N��ԁilock_flag��true�̏�ԁj�ł̂݌Ă΂���
 *  �̂Ƒz�肵�Ă���D
 */
#pragma inline (x_unlock_cpu)
static void
x_unlock_cpu( void )
{
	enaint();
}

#define t_unlock_cpu()	x_unlock_cpu()
#define i_unlock_cpu()	x_unlock_cpu()

/*
 *  �f�t�H���g�̔�^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�̒�`
 *
 *  �X�^�b�N�T�C�Y��ύX����ꍇ��, sectrx.inc��_DEFAULT_ISTACK
 *  ���x���̈ʒu�ɂ���.blkb���߂̃T�C�Y��, �ȉ�DEFAULT_ISTKSZ��
 *  �T�C�Y�����킹�ē����l�ɕύX���邱��.
 */
extern uint32_t	DEFAULT_ISTACK[];
#define DEFAULT_ISTKSZ		( 0x500U )
#define DEFAULT_ISTK		( (void *)&DEFAULT_ISTACK[0] )

#pragma inline (idle_loop)
static  void
idle_loop(void)
{
	t_unlock_cpu();
	ipl_maskClear();
	t_lock_cpu();
}


/*
 *  �v���Z�b�T�X�e�[�^�X���W�X�^(PSW)�̌��ݒl�̓Ǐo��
 */
#pragma inline_asm	current_psw
static uint32_t
current_psw( void )
{
	mvfc	psw, r1
}
/*
 *  CPU���b�N��Ԃ̎Q��
 */
#pragma inline (x_sense_lock)
static  bool_t
x_sense_lock( void )
{
	return (( bool_t )(( current_psw() & PSW_I_MASK) == 0 ));
}

#define t_sense_lock()	x_sense_lock()
#define i_sense_lock()	x_sense_lock()


/*
 *  �R���e�L�X�g�̎Q��
 *
 *  RX�ł́C�����݂̖߂�悪�^�X�N���ǂ����𔻒f���邽�߂� intnest
 *  ���g�p���Ă���D�����p���ăR���e�L�X�g�𔻒f����D
 */
#pragma inline (sense_context) 
static bool_t sense_context( void )
{
	/*  �l�X�g�J�E���^0����Ȃ��^�X�N�R���e�L�X�g  */
	return ( intnest > 0U );
}

#pragma inline_asm	set_task_stack
static void
set_task_stack( intptr_t stkp )
{
	MVTC	R1,isp
}


#endif /* TOPPERS_TARGET_KERNEL_H */
#endif