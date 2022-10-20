#include "DxLib.h"
#include "Door.h"

namespace {
	constexpr int m_doorX = 360;
	constexpr int m_doorY = 25;

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

void Door::draw() {
	if (m_isDead) return;
	DrawBox(getPos().x + m_doorX, getPos().y + m_doorY, getPos().x + m_doorX + kSizeX, getPos().y + m_doorY + kSizeY, GetColor(0, 0, 0), false);
	DrawGraph(m_doorX, m_doorY, m_handle, true);
}

bool Door::isCol(Player& player) {

	float doorLeft = getPos().x + m_doorX;
	float doorRight = getPos().x + m_doorX + kSizeX;
	float doorTop = getPos().y + m_doorY;
	float doorBottom = getPos().y + m_doorY + kSizeY;

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