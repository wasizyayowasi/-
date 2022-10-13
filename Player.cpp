#include"DxLib.h"
#include <cassert>
#include "game.h"
#include "Player.h"

namespace
{
	//キャラクターアニメーション1コマ当たりのフレーム数
	constexpr int kAnimeChangeFrame = 8;

}

Player::Player()
{
	for (auto& handle : m_handle) {
		handle = -1;
	}
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

	m_isCanNotMove = false;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

}

void Player::update()
{

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", m_animeFrame);


	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		if (m_isCanNotMove) {
			m_pos.y = m_pos.y + 4;
			m_isCanNotMove = false;
		}
		else {
			m_pos.y -= 2;
			if (m_pos.y < 0) {
				m_pos.y = 0;
			}
			m_animeDirections = 3;
			isKey = true;
		}
		
	}
	if (padState & PAD_INPUT_DOWN)
	{
		if (m_isCanNotMove) {
			m_pos.y = m_pos.y - 4;
			m_isCanNotMove = false;
		}
		else {
			m_pos.y += 2;
			if (m_pos.y > Game::kScreenHeight - 32) {
				m_pos.y = Game::kScreenHeight - 32;
			}
			m_animeDirections = 0;
			isKey = true;
		}
		
	}
	if (padState & PAD_INPUT_LEFT)
	{
		if (m_isCanNotMove) {
			m_pos.x = m_pos.x + 4;
			m_isCanNotMove = false;
		}
		else {
			m_pos.x -= 2;
			if (m_pos.x < 0) {
				m_pos.x = 0;
			}
			m_animeDirections = 1;
			isKey = true;
		}
		
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		if (m_isCanNotMove) {
			m_pos.x = m_pos.x - 4;
			m_isCanNotMove = false;
		}
		else {
			m_pos.x += 2;
			if (m_pos.x > Game::kScreenWidth - 32) {
				m_pos.x = Game::kScreenWidth - 32;
			}
			m_animeDirections = 2;
			isKey = true;
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

//void Player::downGrade() {
//
//	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	bool isKey = false;
//	if (padState & PAD_INPUT_UP)
//	{
//		//上　73～96
//		m_pos.y += 8;
//		if (m_pos.y < 0) {
//			m_pos.y = 0;
//		}
//		m_animeDirections = 3;
//		isKey = true;
//	}
//	if (padState & PAD_INPUT_DOWN)
//	{
//		//下　1～24
//		m_pos.y -= 8;
//		if (m_pos.y > Game::kScreenHeight - 32) {
//			m_pos.y = Game::kScreenHeight - 32;
//		}
//		m_animeDirections = 0;
//		isKey = true;
//	}
//	if (padState & PAD_INPUT_LEFT)
//	{
//		//左　25～48
//		m_pos.x += 8;
//		if (m_pos.x < 0) {
//			m_pos.x = 0;
//		}
//		m_animeDirections = 1;
//		isKey = true;
//	}
//	if (padState & PAD_INPUT_RIGHT)
//	{
//		//右　49～72
//		m_pos.x -= 8;
//		if (m_pos.x > Game::kScreenWidth - 32) {
//			m_pos.x = Game::kScreenWidth - 32;
//		}
//		m_animeDirections = 2;
//		isKey = true;
//	}
//
//	//キャラクターのアニメーション
//	if (isKey) m_animeFrame++;
//
//}

void Player::draw()
{
	DrawString(0, 0, "持ち物", GetColor(0, 0, 0));
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
	//デバッグ用
	DrawBox(getPos().x, getPos().y, getPos().x + 32, getPos().y + 32, GetColor(0, 0, 0), false);

	//外壁確認
	DrawBox(100, 25, 115, 571, GetColor(255, 0, 0), false);		//左
	DrawBox(100, 25, 360, 40, GetColor(255, 0, 0), false);		//左上
	DrawBox(440, 25, 700, 40, GetColor(255, 0, 0), false);		//右上
	DrawBox(685, 25, 700, 571, GetColor(255, 0, 0), false);		//右
	DrawBox(435, 556, 700, 571, GetColor(255, 0, 0), false);	//右下
	DrawBox(100, 556, 365, 571, GetColor(255, 0, 0), false);	//左下
	//緑内壁
	DrawBox(270, 25, 280, 265, GetColor(0,255, 0), false);		//左
	DrawBox(185, 255, 365, 265, GetColor(0, 255, 0), false);	//真ん中
	DrawBox(185, 105, 195, 265, GetColor(0, 255, 0), false);	//真ん中下
	DrawBox(352, 255, 363, 340, GetColor(0, 255, 0), false);	//右下縦
	DrawBox(352, 330, 530, 340, GetColor(0, 255, 0), false);	//右下横
	//水色内壁   右上から①
	DrawBox(435, 103, 700, 113, GetColor(0,255, 255), false);	//①
	DrawBox(352, 103, 362, 190, GetColor(0, 255, 255), false);  //②
	DrawBox(352, 180, 615, 190, GetColor(0, 255, 255), false);	//③
	DrawBox(435, 180, 445, 265, GetColor(0, 255, 255), false);	//④
	DrawBox(435, 255, 530, 265, GetColor(0, 255, 255), false);	//⑤
	DrawBox(603, 180, 613, 415, GetColor(0, 255, 255), false);	//⑥
	DrawBox(270, 405, 613, 415, GetColor(0, 255, 255), false);	//⑦
	DrawBox(270, 330, 280, 415, GetColor(0, 255, 255), false);	//⑧
	DrawBox(185, 330, 280, 340, GetColor(0, 255, 255), false);	//⑨
	DrawBox(185, 330, 195, 490, GetColor(0, 255, 255), false);	//⑩
	//青内壁　　　　右から①
	DrawBox(603, 480, 613, 571, GetColor(0,0,255), false);
	DrawBox(520, 405, 530, 490, GetColor(0,0,255), false);	
	DrawBox(437, 480, 447, 571, GetColor(0, 0, 255), false);
	DrawBox(352, 405, 362, 571, GetColor(0, 0,255), false);
	DrawBox(270, 480, 280, 571, GetColor(0, 0, 255), false);
}