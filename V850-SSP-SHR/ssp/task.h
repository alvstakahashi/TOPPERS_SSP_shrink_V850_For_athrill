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
 *  Copyright (C) 2011 by Meika Sugimoto
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

#ifndef TOPPERS_TASK_H
#define TOPPERS_TASK_H
#include <setjmp.h>

#include "kernel_impl.h"

//#define run_task					_kernel_run_task

/*
 *  �^�X�N�D��x�̓����\���E�O���\���ϊ��}�N��
 */
#define INT_PRIORITY(x)		((uint_t)((x) - TMIN_TPRI))

/*
 *  �^�X�NID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_tskid;

/*
 *  �^�X�N�̐�
 */
#define tnum_tsk	((uint_t)(tmax_tskid - TMIN_TSKID + 1))

/*
 *  ���s�\��Ԃ̃^�X�N���Ȃ����̎��s�^�X�N�̋N�����D��x
 */
#define IPRI_NULL	(UINT_MAX)


extern uint_t get_ipri_self(ID tskid);
extern uint_t get_ipri(ID tskid);

/*
 *  �f�B�X�p�b�`�^�^�X�N��O�������[�`���N���v���t���O
 *
 *  �����݃n���h���^CPU��O�n���h���̏o�������ɁC�f�B�X�p�b�`�܂���
 *  �^�X�N��O�������[�`���̋N����v�����邱�Ƃ������t���O�D
 */
extern bool_t	reqflg;

/*
 *  �f�B�X�p�b�`�֎~���
 *
 *  �f�B�X�p�b�`�֎~��Ԃł��邱�Ƃ������t���O�D
 */
extern bool_t	disdsp;
extern jmp_buf disp_ctx;		//�f�B�X�p�b�`���R���e�L�X�g

/*
 *  �^�X�N�̏�����
 */
extern void initialize_task(void);
/*
 *  ���s��ԃ^�X�N�̋N�����D��x
 */
extern uint_t runtsk_ipri;

/*
 *  �^�X�N�̋N��
 */
extern bool_t make_active(uint_t ipri);

/*
 *  �^�X�N�̋x�~
 */
extern bool_t test_dormant(uint_t tskid);

/*
 *  �ō��D�揇�ʃ^�X�N�̃T�[�`
 */
extern uint_t search_schedtsk(void);

/*
 *  �^�X�N�̎��s
 */
extern void run_task(uint_t ipri);

/*
 *  �^�X�N�f�B�X�p�b�`��
 */
extern void dispatcher(void);

extern jmp_buf task_ctx[];

extern void dispach(intptr_t task_id);

extern void make_ctx(uint_t ipri);


#endif /* TOPPERS_TASK_H */
