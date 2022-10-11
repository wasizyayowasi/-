#include "DxLib.h"
#include"Map.h"

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
	DrawGraph(100, 25, m_handle, true);
}