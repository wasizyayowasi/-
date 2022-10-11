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

//ƒ}ƒbƒv‚Ì‰Šú‰»
void Key::init() {


}

//•`‰æ
void Key::draw() {
	DrawRotaGraph(m_keyX, m_keyY,1, m_keyAngle,m_handle,true,false);
}