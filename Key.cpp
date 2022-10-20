#include "DxLib.h"
#include"Key.h"

namespace {
	constexpr int m_keyAngle = 45;

	//鍵のサイズ
	constexpr float kSizeX = 20.0f;
	constexpr float kSizeY = 39.0f;
}

Key::Key() {
	m_handle = -1;
	m_keyX = 0;
	m_keyY = 0;
	m_keySound = -1;
	m_isDead = false;
}

Key:: ~Key() {

}

//マップの初期化
void Key::init() {
	m_keyX = 220;
	m_keyY = 200;
	m_isDead = false;
}

//描画
void Key::draw() {
	if (m_isDead) {
		m_keyX = 15;
		m_keyY = 35;
	}
	else {
		m_keyX = 220;
		m_keyY = 200;
		setDead(false);
	}

	DrawGraph(m_keyX, m_keyY, m_handle, true);
}

//鍵の取得で音を鳴らす
void Key::setDead(bool isDead) {
	m_isDead = isDead;
	if (m_isDead) {
		ChangeVolumeSoundMem(125, m_keySound);
		PlaySoundMem(m_keySound, DX_PLAYTYPE_BACK, true);
	}
}


//プレイヤーとの当たり判定
bool Key::isCol(Player& player) {

	if (m_isDead) return false;

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