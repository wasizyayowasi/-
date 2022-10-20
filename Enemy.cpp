#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "Enemy.h"

namespace
{
	//キャラクターアニメーション1コマ当たりのフレーム数
	constexpr int kAnimeChangeFrame = 8;

}

Enemy::Enemy() {
	for (auto& handle : m_handle) {
		handle = -1;
	}
	enemySpeed = 0.0f;
	playerPosX = 0.0f;
	playerPosY = 0.0f;
	m_waitFrame = 0;
	m_isPush = false;
	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;
}

Enemy::~Enemy() {

}

void Enemy::init() {
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight +32;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	enemySpeed = 3.0f;

	playerPosX = 0;
	playerPosY = 0;

	m_waitFrame = 180;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

	m_isPush = false;

}


//お化けの移動
void Enemy::update(Player& player) {

	if (m_isPush) {
		m_waitFrame = 660;
		m_isPush = false;
	}

	if (m_waitFrame > 0) {
		m_waitFrame--;
		return;
	}
	
	playerPosX = player.getPos().x - m_pos.x;
	playerPosY = player.getPos().y - m_pos.y;

	m_pos.x += playerPosX * enemySpeed / 240;
	m_pos.y += playerPosY * enemySpeed / 240;

	if (player.getPos().x < m_pos.x) {
		m_animeNo = 4;
	}
	else if (player.getPos().x > m_pos.x) {
		m_animeNo = 7;
	}
	else if (static_cast<int>(player.getPos().y) > static_cast<int>(m_pos.y) ) {
		m_animeNo = 0;
	}
	else if (static_cast<int>(player.getPos().y) < static_cast<int>(m_pos.y) ) {
		m_animeNo = 10;
	}

}


//お化けの描画
void Enemy::draw() {
	SetFontSize(13);
	DrawString(700, 0, "お化け待機時間", GetColor(255, 255, 255));
	SetFontSize(20);
	DrawFormatString(750, 20, GetColor(255, 255, 0), "%d", m_waitFrame / 60);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}


//プレイヤーとの接触判定
bool Enemy::isCol(Player& player) {

	float EnemyLeft = getPos().x ;
	float EnemyRight = getPos().x + 28;
	float EnemyTop = getPos().y ;
	float EnemyBottom = getPos().y + 28;

	float playerLeft = player.getPos().x;
	float playerRight = player.getPos().x + 32;
	float playerTop = player.getPos().y;
	float playerBottom = player.getPos().y + 32;

	if (playerRight < EnemyLeft)	return false;
	if (playerLeft > EnemyRight)	return false;
	if (playerBottom < EnemyTop)	return false;
	if (playerTop > EnemyBottom)	return false;

	return true;
}