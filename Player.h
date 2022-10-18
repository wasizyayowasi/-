#pragma once
#include "Vec2.h"


class Player{
public:
	//�萔��`

	//�v���C���[�O���t�B�b�N������
	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;

	//�v���C���[�O���t�B�b�N�T�C�Y
	static constexpr int kGraphicSizeX = 32;
	static constexpr int kGraphicSizeY = 32;

public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }
	void setPlayerDeadHandle(int handle) { m_deadHandle = handle; }
	void setSound(int sound) { m_playerSound = sound; }

	void setCanNotMove(bool isCanNotMove) { m_isCanNotMove = isCanNotMove; }

	// �v���C���[�̏�����
	void init();

	//�f�[�^�̎擾
	Vec2 getPos()const { return m_pos; }				

	// ����
	void update();

	////�L��������ނ�����
	//void downGrade();

	// �`��
	void draw();

	bool clear();

	void deadDraw();

	void soul();

	void trace();

	void collisionDetection();

private:
	int m_handle[kGraphicDivNum];

	int m_playerSound;

	int m_deadHandle;

	// �\���ʒu
	Vec2 m_pos;
	//�T�C�Y
	Vec2 m_size;
	// �ړ�
	Vec2 m_vec;

	//
	bool m_isCanNotMove;

	//�L�����N�^�[�̃A�j���[�V����
	int m_animeNo;			//�\������ԍ�
	int m_animeFrame;
	int m_animeDirections;	//�\���������

	int tracePosX;
	int tracePosY;

	int count;
};