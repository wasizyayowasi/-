#pragma once
#include "Map.h"
#include "Key.h"
#include "Player.h"
#include "Door.h"
#include "GreenWall.h"
#include "Enemy.h"
#include "Botan.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	int update();
	// ���t���[���̕`��
	void draw();
private:
	//�}�b�v�̃O���t�B�b�N�n���h��
	int m_hMap;
	int m_hBackgroundHnadle;
	//���̃O���t�B�b�N�n���h��
	int m_hKey;
	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	//�v���C���[���S���̉��o�̃O���t�B�b�N�n���h��
	int m_hPlayerDead;
	//�h�A�̃O���t�B�b�N�n���h��
	int m_hDoor;
	//�G�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic[Enemy::kGraphicDivNum];
	//�{�^���̃O���t�B�b�N�n���h��
	int m_hBotan;
	//���擾�̃T�E���h
	int m_sKeyHandle;
	//�{�^�������������̃T�E���h
	int m_sPushBotan;
	//�����J����T�E���h
	int m_sOpenDoor;
	//���S�t���O
	int playerDead;

	//���S���o�𗬂�����
	int playerDeadTime;

	//�}�b�v
	Map m_map;
	//��
	Key m_key;
	//�h�A
	Door m_door;
	//�v���C���[
	Player m_player;
	//�΂̕�
	GreenWall m_greenWall;
	//�G
	Enemy m_enemy;
	//�{�^��
	Botan m_botan;

};