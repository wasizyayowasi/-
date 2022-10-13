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
}

Enemy::~Enemy() {

}

void Enemy::setGraphic(int handle)
{
	m_handle[1] = handle;
	GetGraphSizeF(m_handle[1], &m_graphSize.x, &m_graphSize.y);
	m_colSize = m_graphSize;
}

void Enemy::init() {
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = 0 + kGraphicSizeY;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	enemySpeed = 3.0f;

	playerPosX = 0;
	playerPosY = 0;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

}

void Enemy::update(Player& player) {
	
	playerPosX = player.getPos().x - m_pos.x;
	playerPosY = player.getPos().y - m_pos.y;

	m_pos.x += playerPosX * enemySpeed / 240;
	m_pos.y += playerPosY * enemySpeed / 240;


}

void Enemy::draw() {
	//DrawFormatString(0,575,GetColor(0,0,0),"(%f,%f)",m_pos.x,m_pos.y);
	DrawFormatString(0, 575, GetColor(0, 0, 0), "(%f,%f)", m_graphSize.x, m_graphSize.y);
	DrawBox(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), static_cast<int>(m_pos.x) + 32, static_cast<int>(m_pos.y) + 32,GetColor(0,0,0),true);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}

bool Enemy::isCol(Player& player) {

	float EnemyLeft = getPos().x ;
	float EnemyRight = getPos().x + 32;
	float EnemyTop = getPos().y ;
	float EnemyBottom = getPos().y + 32;

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