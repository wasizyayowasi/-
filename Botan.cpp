#include "DxLib.h"
#include"Botan.h"

namespace {
	constexpr float kSizeX = 32.0f;
	constexpr float kSizeY = 32.0f;
}

Botan::Botan() {
	m_handle = -1;
	m_botanX = 0;
	m_botanY = 0;
	m_botanSound = -1;
	m_isDead = false;
}

Botan:: ~Botan() {

}

//�}�b�v�̏�����
void Botan::init() {
	m_botanX = 218;
	m_botanY = 350;
	m_isDead = false;
}

//�`��
//�{�^���ƃv���C���[���ڐG������{�^����������
void Botan::draw() {

	if (!m_isDead) {
		DrawGraph(m_botanX, m_botanY, m_handle, true);
	}

}


//�{�^���ƃv���C���[���ڐG�����特��炷
void Botan::setDead(bool isDead) {

	m_isDead = isDead;
	if (m_isDead) {
		ChangeVolumeSoundMem(160, m_botanSound);
		PlaySoundMem(m_botanSound, DX_PLAYTYPE_BACK, true);
	}
}


//�v���C���[�Ƃ̓����蔻��
bool Botan::isCol(Player& player) {

	if (m_isDead) return false;

	float botanLeft = getPos().x + m_botanX;
	float botanRight = getPos().x + m_botanX + kSizeX;
	float botanTop = getPos().y + m_botanY;
	float botanBottom = getPos().y + m_botanY + kSizeY;

	float playerLeft = player.getPos().x;
	float playerRight = player.getPos().x + 32;
	float playerTop = player.getPos().y;
	float playerBottom = player.getPos().y + 32;

	if (playerRight < botanLeft)	return false;
	if (playerLeft > botanRight)	return false;
	if (playerBottom < botanTop)	return false;
	if (playerTop > botanBottom)	return false;

	return true;
}