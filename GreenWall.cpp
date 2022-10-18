#include "DxLib.h"
#include "GreenWall.h"

bool GreenWall::update(Player& player) {
	//プレイヤー情報
	float playerLeft = player.getPos().x;
	float playerRight = player.getPos().x + 32;
	float playerTop = player.getPos().y;
	float playerBottom = player.getPos().y + 32;

	if (playerLeft > 280) return false;
	if (playerRight < 270) return false;
	if (playerTop < 25)return false;
	if (playerBottom > 297)return false;

	/*if (playerLeft > 185)return false;
	if (playerRight < 195)return false;
	if (playerTop < 105)return false;
	if (playerBottom > 265)return false;

	if (playerLeft > 352)return false;
	if (playerRight < 363)return false;
	if (playerTop < 255)return false;
	if (playerBottom > 340)return false;

	if (playerLeft > 352)return false;
	if (playerRight < 530)return false;
	if (playerTop < 330)return false;
	if (playerBottom > 340)return false;*/

	//DrawBox(270, 25, 280, 265, GetColor(0, 255, 0), false);		//左
	//DrawBox(185, 255, 365, 265, GetColor(0, 255, 0), false);	//真ん中
	//DrawBox(185, 105, 195, 265, GetColor(0, 255, 0), false);	//真ん中下
	//DrawBox(352, 255, 363, 340, GetColor(0, 255, 0), false);	//右下縦
	//DrawBox(352, 330, 530, 340, GetColor(0, 255, 0), false);	//右下横

	return true;
}