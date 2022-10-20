#include "DxLib.h"
#include"Map.h"

namespace {
	constexpr int mapX = 100;
	constexpr int mapY = 25;
}

Map::Map() {
	m_handle = -1;
	m_backgroundHnadle = -1;
}

Map:: ~Map() {

}

//マップの初期化
void Map::init() {


}

//描画
void Map::draw() {
	DrawGraph(0, 0, m_backgroundHnadle, false);
	DrawGraph(mapX, mapY, m_handle, true);
}