#include "DxLib.h"
#include "Door.h"

namespace {
	constexpr float m_doorX = 360;
	constexpr float m_doorY = 25;

	constexpr float kSizeX = 80.0f;
	constexpr float kSizeY = 14.0f;
}

Door::Door() {
	m_handle = -1;
	m_isDead = false;
	m_isPadlockDead = false;
	
}

Door::~Door() {

}

void Door::init() {
	m_isDead = false;
	m_isPadlockDead = false;
}


//プレイヤーが鍵を持っている状態でドアとの接触すると音を鳴らす
void Door::setDead(bool isDead) {
	m_isDead = isDead;
	if (m_isDead) {
		ChangeVolumeSoundMem(125, m_sound);
		PlaySoundMem(m_sound, DX_PLAYTYPE_BACK, true);
	}
}


//描画
void Door::draw() {
	if (m_isDead) return;
	DrawGraph(static_cast<int>(m_doorX), static_cast<int>(m_doorY), m_handle, true);
}


//プレイヤーとの当たり判定
bool Door::isCol(Player& player) {

	float doorLeft = m_doorX;
	float doorRight =  m_doorX + kSizeX;
	float doorTop = m_doorY;
	float doorBottom = m_doorY + kSizeY;

	DrawFormatString(0, 100, GetColor(255, 255, 255), "%f", doorTop);

	float playerLeft = player.getPos().x;
	float playerRight = player.getPos().x + 32;
	float playerTop = player.getPos().y;
	float playerBottom = player.getPos().y + 32;

	if (playerTop < doorBottom) {
		if (m_isPadlockDead) {
			return true;
		}
	}
	return false;
}