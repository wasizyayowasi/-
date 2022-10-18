#pragma once
#include "Vec2.h"
#include "Player.h"

class Botan {
public:
	Botan();
	virtual ~Botan();

	//グラフィックデータの設定
	void setHandle(int handle) { m_handle = handle; }
	//サウンドの設定
	void setSound(int sound) { m_botanSound = sound; }
	//マップの初期化
	void init();

	//描画
	void draw();

	// 鍵の取得
	bool isCol(Player& player);

	//ボタンの切り替え判定用
	void setDead(bool isDead);

	//データの取得
	Vec2 getPos()const { return m_pos; }					//左上座標
	Vec2 getBottomRight()const { return m_pos + m_size; }	//右下座標

private:

	//鍵の座標
	int m_botanX;
	int m_botanY;
	//ハンドル
	int m_handle;
	//サウンド
	int m_botanSound;
	//生死
	bool m_isDead;
	//座標
	Vec2 m_pos;
	//サイズ
	Vec2 m_size;
};