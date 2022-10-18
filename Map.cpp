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

//ƒ}ƒbƒv‚Ì‰Šú‰»
void Map::init() {


}

//•`‰æ
void Map::draw() {
	DrawGraph(0, 0, m_backgroundHnadle, false);
	DrawGraph(mapX, mapY, m_handle, true);
}