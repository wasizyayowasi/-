#include"DxLib.h"
#include <stdio.h>
#include <cassert>
#include "game.h"
#include "Player.h"




namespace
{
	//�L�����N�^�[�A�j���[�V����1�R�}������̃t���[����
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

	tracePosX = 0;
	tracePosY = 0;

	m_isCanNotMove = false;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

	count = 0;
}

void Player::update()
{

	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;

	

	if (padState & PAD_INPUT_UP)
	{
		if (m_isCanNotMove) {
			m_pos.y = m_pos.y;
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
	else if (padState & PAD_INPUT_DOWN)
	{
		if (m_isCanNotMove) {
			m_pos.y = m_pos.y;
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
	else if (padState & PAD_INPUT_LEFT)
	{
		if (m_isCanNotMove) {
			m_pos.x = m_pos.x - 0.5f;
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
	else if (padState & PAD_INPUT_RIGHT)
	{
		if (m_isCanNotMove) {
			m_pos.x = m_pos.x;
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

	//outerWallCollisionDetection();
	//greenWallCollisionDetection();

	//�L�����N�^�[�̃A�j���[�V����
	if (isKey) m_animeFrame++;

	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame) {
		m_animeFrame = 0;
	}

	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_animeDirections * kGraphicDivX + tempAnimeNo;

	//DrawFormatString(0, 150, GetColor(255, 255, 255), "%f,%f", m_pos.x,m_pos.y);
}

void Player::draw()
{
	SetFontSize(0);
	DrawString(23, 0, "������", GetColor(255, 255, 255));
	DrawBox(0, 30, 50, 80, GetColor(255, 255, 255), true);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
	//�f�o�b�O�p
	//DrawBox(getPos().x, getPos().y, getPos().x + 32, getPos().y + 32, GetColor(0, 0, 0), false);

	//�O�Ǌm�F
	DrawBox(100, 25, 115, 571, GetColor(255, 0, 0), false);		//��
	DrawBox(100, 25, 360, 40, GetColor(255, 0, 0), false);		//����
	DrawBox(440, 25, 700, 40, GetColor(255, 0, 0), false);		//�E��
	DrawBox(685, 25, 700, 571, GetColor(255, 0, 0), false);		//�E
	DrawBox(435, 560, 700, 571, GetColor(255, 0, 0), false);	//�E��
	DrawBox(100, 560, 365, 571, GetColor(255, 0, 0), false);	//����
	//�Γ���
	DrawBox(270, 25, 280, 265, GetColor(0,255, 0), false);		//��
	DrawBox(185, 255, 365, 265, GetColor(0, 255, 0), false);	//�^��
	DrawBox(185, 105, 195, 265, GetColor(0, 255, 0), false);	//�^�񒆉�
	DrawBox(352, 255, 363, 340, GetColor(0, 255, 0), false);	//�E���c
	DrawBox(352, 330, 530, 340, GetColor(0, 255, 0), false);	//�E����
	//���F����   �E�ォ��@
	DrawBox(435, 103, 700, 113, GetColor(0,255, 255), false);	//�@
	DrawBox(352, 103, 362, 190, GetColor(0, 255, 255), false);  //�A
	DrawBox(352, 180, 615, 190, GetColor(0, 255, 255), false);	//�B
	DrawBox(435, 180, 445, 265, GetColor(0, 255, 255), false);	//�C
	DrawBox(435, 255, 530, 265, GetColor(0, 255, 255), false);	//�D
	DrawBox(603, 180, 613, 415, GetColor(0, 255, 255), false);	//�E
	DrawBox(270, 405, 613, 415, GetColor(0, 255, 255), false);	//�F
	DrawBox(270, 330, 280, 415, GetColor(0, 255, 255), false);	//�G
	DrawBox(185, 330, 280, 340, GetColor(0, 255, 255), false);	//�H
	DrawBox(185, 330, 195, 490, GetColor(0, 255, 255), false);	//�I
	//���ǁ@�@�@�@�E����@
	DrawBox(603, 480, 613, 571, GetColor(0,0,255), false);
	DrawBox(520, 405, 530, 490, GetColor(0,0,255), false);	
	DrawBox(437, 480, 447, 571, GetColor(0, 0, 255), false);
	DrawBox(352, 405, 362, 571, GetColor(0, 0,255), false);
	DrawBox(270, 480, 280, 571, GetColor(0, 0, 255), false);
}

bool Player::clear() {

	bool isKey = false;

	m_pos.y -= 0.2;
	if (m_pos.y < -32) {
		m_pos.y = -32;
	}
	m_animeDirections = 3;
	isKey = true;

	//�L�����N�^�[�̃A�j���[�V����
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

void Player::deadDraw() {
	DrawRotaGraph(static_cast<int>(m_pos.x) + 32, static_cast<int>(m_pos.y) + 32, 1, angle, m_handle[4], true, false);
}
void Player::soul() {
	DrawGraph(static_cast<int>(m_pos.x) + 17, static_cast<int>(m_pos.y), m_deadHandle, true);
}


void Player::trace() {
	tracePosX = m_pos.x;
	tracePosY = m_pos.y;

	//DrawFormatString(0, 165, GetColor(255, 255, 255), "%d,%d", tracePosX, tracePosY);
	//DrawFormatString(0, 180, GetColor(255, 255, 255), "%f,%f", m_pos.x, m_pos.y);
}

typedef struct ColData {
	int left;
	int top;
	int right;
	int bottom;
}ColData;

ColData colData[] = {
	//�O�Ǌm�F
	//{685, 38, 115, 560},
	{100, 25, 360, 40},		//����
	//{440, 25, 700, 40},		//�E��
	//{685, 25, 700, 571 },	//�E
	//{435, 560, 700, 571},	//�E��
	//{100, 560, 365, 571 }	//����
};

ColData colData2[] = {

	////�Γ���
	{270, 25, 280, 265 },			//��
	//{185, 255, 365, 265},			//�^��
	//{185, 105, 195, 265},			//�^�񒆉�
	//{352, 255, 363, 340},			//�E���c
	//{352, 330, 530, 340 },			//�E����
	////���F����   �E�ォ��@
	//{435, 103, 700, 113},			//�@
	//{352, 103, 362, 190},			//�A
	//{352, 180, 615, 190},			//�B
	//{435, 180, 445, 265},			//�C
	//{435, 255, 530, 265},			//�D
	//{603, 180, 613, 415},			//�E
	//{270, 405, 613, 415},			//�F
	//{270, 330, 280, 415},			//�G
	//{185, 330, 280, 340},			//�H
	//{185, 330, 195, 490},			//�I
	////���ǁ@�@�@�@�E����@
	//{603, 480, 613, 571},
	//{520, 405, 530, 490},
	//{437, 480, 447, 571},
	//{352, 405, 362, 571},
	//{270, 480, 280, 571}
};


void Player::outerWallCollisionDetection() {
	
	float playerLeft = getPos().x;
	float playerRight = getPos().x + 32;
	float playerTop = getPos().y;
	float playerBottom = getPos().y + 32;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	for (ColData data : colData) {
		DrawFormatString(0, 170, GetColor(255, 255, 255), "%d,%d,%d,%d", data.left, data.top, data.right, data.bottom);
		if (padState & PAD_INPUT_RIGHT) {
			if (playerRight < data.left) {
				m_pos.x = tracePosX;
				break;
			}
		}
		else if (padState & PAD_INPUT_DOWN) {
			if (playerBottom < data.top) {
				m_pos.y = tracePosY;
				break;
			}
		}
		else if (padState & PAD_INPUT_LEFT) {
			if (playerLeft < data.right) {
				if (playerTop < data.bottom) {
					m_pos.x = tracePosX;
					break;
				}
			}
		}
		else if (padState & PAD_INPUT_UP) {
			if (playerTop < data.bottom) {
				m_pos.y = tracePosY;
				break;
			}
		}
	}
}

void Player::greenWallCollisionDetection() {

	float playerLeft = getPos().x;
	float playerRight = getPos().x + 32;
	float playerTop = getPos().y;
	float playerBottom = getPos().y + 32;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	for (ColData data : colData2) {
		DrawFormatString(0, 150, GetColor(255, 255, 255), "%d,%d,%d,%d", data.left, data.top, data.right, data.bottom);
		if (padState & PAD_INPUT_RIGHT) {
			if (playerRight < data.left) {
				if (playerTop < data.bottom) {
					DrawString(0, 90, "HIT", GetColor(255, 255, 255));
					m_pos.x = tracePosX;
					break;
				}
			}
		}
		if (padState & PAD_INPUT_DOWN) {
			if (playerBottom < data.top) {
				DrawString(0, 105, "HIT2", GetColor(255, 255, 255));
				m_pos.y = tracePosY;
				break;
			}
		}
		if (padState & PAD_INPUT_LEFT) {
			if (playerLeft < data.right) {
				if (playerTop < data.bottom) {
					DrawString(0, 120, "HIT3", GetColor(255, 255, 255));
					m_pos.x = tracePosX;
					break;
				}
			}
		}
		if (padState & PAD_INPUT_UP) {
			if (playerTop < data.bottom) {
				DrawString(0, 135, "�˔j", GetColor(255, 255, 255));
				if ((playerLeft < data.right || playerRight < data.left) && (playerLeft > data.right || playerRight > data.left)) {
					DrawString(0, 135, "HIT4", GetColor(255, 255, 255));
					m_pos.y = tracePosY;
					break;
				}
			}
		}
	}
}