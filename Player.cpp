#include"DxLib.h"
#include <stdio.h>
#include <cassert>
#include "game.h"
#include "Player.h"


namespace
{
	//キャラクターアニメーション1コマ当たりのフレーム数
	constexpr int kAnimeChangeFrame = 8;

	constexpr double angle = 1.6;
	constexpr int playerDeadTime = 600;

}

Player::Player()
{
	for (auto& handle : m_handle) {
		handle = -1;
	}

	m_playerSound = -1;
	m_deadHandle = -1;
	m_isCanNotMove = false;
	m_animeNo = 0;			
	m_animeFrame = 0;
	m_animeDirections = 0;	
	tracePosX = 0;
	tracePosY = 0;
	count = 0;
}

Player::~Player()
{

}


void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight - kGraphicSizeY;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	tracePosX = 0.0f;
	tracePosY = 0.0f;

	m_isCanNotMove = false;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

	count = 1;
}


//プレイヤーの動き
void Player::update()
{

	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;

	

	if (padState & PAD_INPUT_UP)
	{
		m_pos.y -= 2;
		if (!outerWallCollisionDetection()) {
			if (m_pos.y < 0) {
				m_pos.y = 0;
			}
			m_animeDirections = 3;
			isKey = true;
		}
		else {
			m_pos.y = tracePosY;
		}
		
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y += 2;
		if (!outerWallCollisionDetection()) {
			if (m_pos.y > Game::kScreenHeight - 32) {
				m_pos.y = Game::kScreenHeight - 32;
			}
			m_animeDirections = 0;
			isKey = true;
		}
		else {
			m_pos.y = tracePosY;
		}
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x -= 2;
		if (!outerWallCollisionDetection()) {
			if (m_pos.x < 0) {
				m_pos.x = 0;
			}
			m_animeDirections = 1;
			isKey = true;
		}
		else {
			m_pos.x = tracePosX;
		}
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x += 2;
		if (!outerWallCollisionDetection()) {
			if (m_pos.x > Game::kScreenWidth - 32) {
				m_pos.x = Game::kScreenWidth - 32;
			}
			m_animeDirections = 2;
			isKey = true;
		}
		else {
			m_pos.x = tracePosX;
		}
	}

	//キャラクターのアニメーション
	if (isKey) m_animeFrame++;

	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame) {
		m_animeFrame = 0;
	}

	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_animeDirections * kGraphicDivX + tempAnimeNo;
}


//描画
void Player::draw()
{
	SetFontSize(0);
	DrawString(23, 0, "持ち物", GetColor(255, 255, 255));
	DrawBox(0, 30, 50, 80, GetColor(255, 255, 255), true);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
	
}


//クリア後の移動
bool Player::clear() {

	bool isKey = false;

	m_pos.y -= 0.2;
	if (m_pos.y < -32) {
		m_pos.y = -32;
	}
	m_animeDirections = 3;
	isKey = true;

	//キャラクターのアニメーション
	if (isKey) m_animeFrame++;

	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame) {
		m_animeFrame = 0;
	}

	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_animeDirections * kGraphicDivX + tempAnimeNo;

	if (m_pos.y == -32) {
		return true;
	}
	return false;
}


//死亡した時の演出
void Player::deadDraw() {
	DrawRotaGraph(static_cast<int>(m_pos.x) + 32, static_cast<int>(m_pos.y) + 32, 1, angle, m_handle[4], true, false);
}
void Player::soul() {
	if (count > 0) {
		ChangeVolumeSoundMem(125, m_playerSound);
		PlaySoundMem(m_playerSound, DX_PLAYTYPE_BACK, true);
		count--;
	}
	DrawGraph(static_cast<int>(m_pos.x) + 17, static_cast<int>(m_pos.y), m_deadHandle, true);
}


//ひとつ前の座標を残す
void Player::trace() {
	tracePosX = m_pos.x;
	tracePosY = m_pos.y;
}


//構造体
typedef struct ColData {
	int left;
	int top;
	int right;
	int bottom;
}ColData;
//データ
ColData colData[] = {
	//外壁確認
	{100, 25, 115, 571},		//左
	{100, 25, 360, 42},			//左上
	{440, 25, 700, 40},			//右上
	{685, 25, 700, 571 },		//右
	{435, 560, 700, 571},		//右下
	{100, 560, 365, 571 },		//左下
	//緑内壁
	{270, 25, 280, 265 },			//左
	{185, 255, 365, 265},			//真ん中
	{185, 105, 195, 265},			//真ん中下
	{352, 255, 363, 340},			//右下縦
	{352, 330, 530, 340 },			//右下横
	//水色内壁   右上から①
	{435, 103, 700, 113},			//①
	{352, 103, 362, 190},			//②
	{352, 180, 615, 190},			//③
	{435, 180, 445, 265},			//④
	{435, 255, 530, 265},			//⑤
	{603, 180, 613, 415},			//⑥
	{270, 405, 613, 415},			//⑦
	{270, 330, 280, 415},			//⑧
	{185, 330, 280, 340},			//⑨
	{185, 330, 195, 490},			//⑩
	//青内壁　　　　右から①
	{603, 480, 613, 571},
	{520, 405, 530, 490},
	{437, 480, 447, 571},
	{352, 405, 362, 571},
	{270, 480, 280, 571}
};


//マップの壁との当たり判定
bool Player::outerWallCollisionDetection() {
	
	float playerLeft = getPos().x;
	float playerRight = getPos().x + 32;
	float playerTop = getPos().y;
	float playerBottom = getPos().y + 32;

	for (ColData data : colData) {
		if (playerRight < data.left)continue;
		if (playerLeft > data.right)continue;
		if (playerBottom < data.top)continue;
		if (playerTop > data.bottom)continue;
		return true;
	}
	return false;
}