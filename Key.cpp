#include "DxLib.h"
#include"Key.h"

namespace {
	constexpr int m_keyX = 230;
	constexpr int m_keyY = 220;
	constexpr int m_keyAngle = 45;
}

Key::Key() {
	m_handle = -1;

}

Key:: ~Key() {

}

//マップの初期化
void Key::init() {


}

//描画
void Key::draw() {
	DrawRotaGraph(m_keyX, m_keyY,1, m_keyAngle,m_handle,true,false);
}