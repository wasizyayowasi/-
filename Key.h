#pragma once

#include "Vec2.h"
#include "Player.h"

class Key {
public:
	Key();
	virtual ~Key();

	//グラフィックデータの設定
	void setHandle(int handle) { m_handle = handle; }

	//サウンドデータの設定
	void setSound(int sound) { m_keySound = sound; }

	//マップの初期化
	void init();
	
	//描画
	void draw();

	// 鍵の取得
	bool isCol(Player& player);

	//鍵の死亡判定用
	void setDead(bool isDead);
	
	//データの取得
	Vec2 getPos()const { return m_pos; }					//左上座標
	Vec2 getBottomRight()const { return m_pos + m_size; }	//右下座標

private:

	//鍵の座標
	int m_keyX;
	int m_keyY;
	//ハンドル
	int m_handle;
	//鍵取得のサウンドハンドル
	int m_keySound;

	//生死
	bool m_isDead;
	//座標
	Vec2 m_pos;
	//サイズ
	Vec2 m_size;
};