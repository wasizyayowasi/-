#pragma once

#include "Vec2.h"
#include "Player.h"

class Enemy {
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
	Enemy();
	virtual ~Enemy();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// �T�C�Y�̎擾
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }

	void init();

	//�f�[�^�̎擾
	Vec2 getPos()const { return m_pos; }					//������W

	void update(Player& player);
	void draw();

	bool isCol(Player& player);

private:
	int m_handle[kGraphicDivNum];

	// �O���t�B�b�N�̕��ƍ���
	Vec2 m_graphSize;
	// �����蔻��̕��ƍ���
	Vec2 m_colSize;

	float enemySpeed;

	float playerPosX;
	float playerPosY;

	int m_waitFrame;

	//�L�����N�^�[�̃A�j���[�V����
	int m_animeNo;			//�\������ԍ�
	int m_animeFrame;
	int m_animeDirections;	//�\���������

	//���W
	Vec2 m_pos;
	//�T�C�Y
	Vec2 m_size;
	// �ړ�
	Vec2 m_vec;
};