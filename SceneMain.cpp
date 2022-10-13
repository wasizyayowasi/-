#include "DxLib.h"
#include "SceneMain.h"
#include "Map.h"
#include "Key.h"
#include "Door.h"

namespace {

	//グラフィックファイル名
	const char* const kPlayerGraphicFilename = "data/char.png";
	const char* const kEnemyGraphicFilename = "data/enemy.png";

}

SceneMain::SceneMain() {
	m_hMap = -1;
	m_hKey = -1;
	m_hDoor = -1;

	for (auto& playerHandle : m_hPlayerGraphic) {
		playerHandle = -1;
	}
	for (auto& EnemyHandle : m_hEnemyGraphic) {
		EnemyHandle = -1;
	}
}

SceneMain::~SceneMain() {

}

// 初期化
void SceneMain::init() {
	m_hMap = LoadGraph("data/labyrinth.png");
	m_hKey = LoadGraph("data/kagi.png");
	m_hDoor = LoadGraph("data/door.png");
	
	m_map.setHandle(m_hMap);
	m_key.setHandle(m_hKey);
	m_door.setHandle(m_hDoor);

	LoadDivGraph(kPlayerGraphicFilename, Player::kGraphicDivNum, Player::kGraphicDivX, Player::kGraphicDivY, Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);
	LoadDivGraph(kEnemyGraphicFilename, Enemy::kGraphicDivNum, Enemy::kGraphicDivX, Enemy::kGraphicDivY, Enemy::kGraphicSizeX, Enemy::kGraphicSizeY, m_hEnemyGraphic);

	for (int i = 0; i < Player::kGraphicDivNum; i++) {
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}

	for (int i = 0; i < Enemy::kGraphicDivNum; i++) {
		m_enemy.setHandle(i, m_hEnemyGraphic[i]);
	}

	m_player.init();
	m_enemy.init();
}

// 終了処理
void SceneMain::end() {
	DeleteGraph(m_hMap);
	DeleteGraph(m_hKey);
	DeleteGraph(m_hDoor);
	
	for (auto& playerHandle : m_hPlayerGraphic) {
		DeleteGraph(playerHandle);
	}

	for (auto& EnemyHandle : m_hEnemyGraphic) {
		DeleteGraph(EnemyHandle);
	}
}

// 毎フレームの処理
bool SceneMain::update() {
	if (!m_greenWall.update(m_player)) {
		m_player.update();
	}
	else {
		m_player.setCanNotMove(true);
		m_player.update();
	}

	if (m_enemy.isCol(m_player)) {
		DrawString(0, 60, "HIT", GetColor(0, 0, 0));
	}

	m_enemy.update(m_player);

	if (m_key.isCol(m_player)) {
		m_key.setDead(true);
		m_door.setPadlockDead(true);
	}
	if (m_door.isCol(m_player)) {
		m_door.setDead(true);
	}

	return false;
}

// 毎フレームの描画
void SceneMain::draw() {
	m_map.draw();
	m_key.draw();
	m_player.draw();
	m_door.draw();
	m_enemy.draw();
}