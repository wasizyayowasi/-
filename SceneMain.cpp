#include "DxLib.h"
#include "SceneMain.h"
#include "Map.h"

SceneMain::SceneMain() {
	m_hMap = -1;
}

SceneMain::~SceneMain() {

}

// ������
void SceneMain::init() {
	m_hMap = LoadGraph("data/labyrinth.png");
	m_map.setHandle(m_hMap);
}

// �I������
void SceneMain::end() {
	DeleteGraph(m_hMap);
}

// ���t���[���̏���
void SceneMain::update() {

}

// ���t���[���̕`��
void SceneMain::draw() {
	m_map.draw();
}