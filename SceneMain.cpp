#include "DxLib.h"
#include "SceneMain.h"
#include "Map.h"
#include "Key.h"

namespace {

	//グラフィックファイル名
	const char* const kPlayerGraphicFilename = "data/char.png";

}

SceneMain::SceneMain() {
	m_hMap = -1;
	m_hKey = -1;
	for (auto& handle : m_hPlayerGraphic) {
		handle = -1;
	}
}

SceneMain::~SceneMain() {

}

// 初期化
void SceneMain::init() {
	m_hMap = LoadGraph("data/labyrinth.png");
	m_hKey = LoadGraph("data/kagi.png");
	
	m_map.setHandle(m_hMap);
	m_key.setHandle(m_hKey);

	LoadDivGraph(kPlayerGraphicFilename, Player::kGraphicDivNum, Player::kGraphicDivX, Player::kGraphicDivY, Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);
	
	for (int i = 0; i < Player::kGraphicDivNum; i++) {
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}

	m_player.init();
}

// 終了処理
void SceneMain::end() {
	DeleteGraph(m_hMap);
	DeleteGraph(m_hKey);
	for (auto& handle : m_hPlayerGraphic) {
		DeleteGraph(handle);
	}
}

// 毎フレームの処理
void SceneMain::update() {
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw() {
	m_map.draw();
	m_key.draw();
	m_player.draw();
}