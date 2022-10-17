#pragma once
#include "Vec2.h"
#include "Player.h"

class Botan {
public:
	Botan();
	virtual ~Botan();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	void setHandle(int handle) { m_handle = handle; }
	//�}�b�v�̏�����
	void init();

	//�`��
	void draw();

	// ���̎擾
	bool isCol(Player& player);

	//�{�^���̐؂�ւ�����p
	void setDead(bool isDead) { m_isDead = isDead; }

	//�f�[�^�̎擾
	Vec2 getPos()const { return m_pos; }					//������W
	Vec2 getBottomRight()const { return m_pos + m_size; }	//�E�����W

private:

	//���̍��W
	int m_botanX;
	int m_botanY;
	//�n���h��
	int m_handle;
	//����
	bool m_isDead;
	//���W
	Vec2 m_pos;
	//�T�C�Y
	Vec2 m_size;
};