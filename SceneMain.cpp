#include "DxLib.h"
#include "SceneMain.h"
#include "Map.h"
#include "Key.h"
#include "Door.h"

namespace {

	//�O���t�B�b�N�t�@�C����
	const char* const kPlayerGraphicFilename = "data/char.png";

}

SceneMain::SceneMain() {
	m_hMap = -1;
	m_hKey = -1;
	m_hDoor = -1;
	for (auto& handle : m_hPlayerGraphic) {
		handle = -1;
	}
}

SceneMain::~SceneMain() {

}

// ������
void SceneMain::init() {
	m_hMap = LoadGraph("data/labyrinth.png");
	m_hKey = LoadGraph("data/kagi.png");
	m_hDoor = LoadGraph("data/door.png");
	
	m_map.setHandle(m_hMap);
	m_key.setHandle(m_hKey);
	m_door.setHandle(m_hDoor);

	LoadDivGraph(kPlayerGraphicFilename, Player::kGraphicDivNum, Player::kGraphicDivX, Player::kGraphicDivY, Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);
	
	for (int i = 0; i < Player::kGraphicDivNum; i++) {
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}

	m_player.init();
}

// �I������
void SceneMain::end() {
	DeleteGraph(m_hMap);
	DeleteGraph(m_hKey);
	DeleteGraph(m_hDoor);
	for (auto& handle : m_hPlayerGraphic) {
		DeleteGraph(handle);
	}
}

// ���t���[���̏���
bool SceneMain::update() {
	m_player.update();

	if (m_key.isCol(m_player)) {
		m_key.setDead(true);
		m_door.setPadlockDead(true);
	}
	if (m_door.isCol(m_player)) {
		m_door.setDead(true);
	}

	return false;
}

// ���t���[���̕`��
void SceneMain::draw() {
	m_map.draw();
	m_key.draw();
	m_player.draw();
	m_door.draw();
}