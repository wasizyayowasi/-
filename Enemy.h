#pragma once

#include "Vec2.h"
#include "Player.h"

class Enemy {
public:
	//定数定義

	//プレイヤーグラフィック分割数
	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;

	//プレイヤーグラフィックサイズ
	static constexpr int kGraphicSizeX = 32;
	static constexpr int kGraphicSizeY = 32;

public:
	Enemy();
	virtual ~Enemy();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// サイズの取得
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }

	void init();

	//データの取得
	Vec2 getPos()const { return m_pos; }					//左上座標

	void update(Player& player);
	void draw();

	bool isCol(Player& player);

private:
	int m_handle[kGraphicDivNum];

	// グラフィックの幅と高さ
	Vec2 m_graphSize;
	// 当たり判定の幅と高さ
	Vec2 m_colSize;

	float enemySpeed;

	float playerPosX;
	float playerPosY;

	int m_waitFrame;

	//キャラクターのアニメーション
	int m_animeNo;			//表示する番号
	int m_animeFrame;
	int m_animeDirections;	//表示する方向

	//座標
	Vec2 m_pos;
	//サイズ
	Vec2 m_size;
	// 移動
	Vec2 m_vec;
};