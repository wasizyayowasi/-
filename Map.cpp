#include "DxLib.h"
#include"Map.h"

namespace {
	constexpr int mapX = 100;
	constexpr int mapY = 25;
}

Map::Map() {
	m_handle = -1;

}

Map:: ~Map() {

}

//�}�b�v�̏�����
void Map::init() {


}

//�`��
void Map::draw() {
	DrawGraph(0, 0, m_backgroundHnadle, false);
	DrawGraph(mapX, mapY, m_handle, true);
}