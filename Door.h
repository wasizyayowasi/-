#pragma once

#include"Vec2.h"
#include "Player.h"

class Door {
public:
	Door();
	virtual ~Door();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	void setHandle(int handle) { m_handle = handle; }

	//
	void draw();

	//�h�A�̎��S����p
	void setPadlockDead(bool isPadlookDead) { m_isPadlockDead = isPadlookDead; }

	bool isCol(Player& player);

	void setDead(bool isDead) { m_isDead = isDead; }

	//�f�[�^�̎擾
	Vec2 getPos()const { return m_pos; }					//������W
	Vec2 getBottomRight()const { return m_pos + m_size; }	//�E�����W

private:
	//�n���h��
	int m_handle;

	int m_isDead;

	int m_isPadlockDead;

	Vec2 m_pos;

	Vec2 m_size;
};