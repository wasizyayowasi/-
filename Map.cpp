#include "DxLib.h"
#include"Map.h"

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
	DrawGraph(100, 25, m_handle, true);
}