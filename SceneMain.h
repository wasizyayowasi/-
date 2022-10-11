#pragma once
#include "Map.h"
#include "Key.h"
#include "player.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	bool update();
	// ���t���[���̕`��
	void draw();
private:
	//�}�b�v�̃O���t�B�b�N�n���h��
	int m_hMap;
	//���̃O���t�B�b�N�n���h��
	int m_hKey;
	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicDivNum];

	//�}�b�v
	Map m_map;
	//��
	Key m_key;
	//�v���C���[
	Player m_player;
};