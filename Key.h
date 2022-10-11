#pragma once

#include "Vec2.h"
#include "Player.h"

class Key {
public:
	Key();
	virtual ~Key();

	//グラフィックデータの設定
	void setHandle(int handle) { m_handle = handle; }
	//マップの初期化
	void init();
	
	//描画
	void draw();

	// 車との衝突判定
	bool isCol(Player& player);

	//鍵の死亡判定用
	void setDead(bool isDead) { m_isDead = isDead; }
	
	//データの取得
	Vec2 getPos()const { return m_pos; }					//左上座標
	Vec2 getBottomRight()const { return m_pos + m_size; }	//右下座標

private:
	//ハンドル
	int m_handle;
	//生死
	bool m_isDead;
	//座標
	Vec2 m_pos;
	//サイズ
	Vec2 m_size;
};