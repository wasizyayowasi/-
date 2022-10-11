#include "DxLib.h"
#include "SceneMain.h"
#include "Map.h"

SceneMain::SceneMain() {
	m_hMap = -1;
}

SceneMain::~SceneMain() {

}

// 初期化
void SceneMain::init() {
	m_hMap = LoadGraph("data/labyrinth.png");
	m_map.setHandle(m_hMap);
}

// 終了処理
void SceneMain::end() {
	DeleteGraph(m_hMap);
}

// 毎フレームの処理
void SceneMain::update() {

}

// 毎フレームの描画
void SceneMain::draw() {
	m_map.draw();
}