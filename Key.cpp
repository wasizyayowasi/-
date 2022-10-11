#include "DxLib.h"
#include"Key.h"

namespace {
	constexpr int m_keyX = 220;
	constexpr int m_keyY = 200;
	constexpr int m_keyAngle = 45;

	//鍵のサイズ
	constexpr float kSizeX = 20.0f;
	constexpr float kSizeY = 39.0f;
}

Key::Key() {
	m_handle = -1;
	m_isDead = false;
}

Key:: ~Key() {

}

//マップの初期化
void Key::init() {


}

//描画
void Key::draw() {
	if (m_isDead) return;
	
	DrawGraph(m_keyX, m_keyY, m_handle, true);
	//デバッグ用
	/*DrawFormatString(0, 0, GetColor(255, 255, 255), "HIT");
	DrawBox(getPos().x + m_keyX, getPos().y + m_keyY, getPos().x + m_keyX + kSizeX, getPos().y + m_keyY + kSizeY, GetColor(0, 0, 255), false);
	DrawBox(m_keyX, m_keyY, m_keyX + 20, m_keyY + 39, GetColor(255, 0, 0), false);*/
}

bool Key::isCol(Player& player) {

	float keyLeft = getPos().x + m_keyX;
	float keyRight = getPos().x + m_keyX + kSizeX;
	float keyTop = getPos().y + m_keyY;
	float keyBottom = getPos().y + m_keyY + kSizeY;

	float playerLeft = player.getPos().x;
	float playerRight = player.getPos().x + 32;
	float playerTop = player.getPos().y;
	float playerBottom = player.getPos().y + 32;

	if (playerRight < keyLeft)	return false;
	if (playerLeft > keyRight)	return false;
	if (playerBottom < keyTop)	return false;
	if (playerTop > keyBottom)	return false;

	return true;
}