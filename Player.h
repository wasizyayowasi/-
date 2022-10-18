#pragma once
#include "Vec2.h"


class Player{
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
	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }
	void setPlayerDeadHandle(int handle) { m_deadHandle = handle; }
	void setSound(int sound) { m_playerSound = sound; }

	void setCanNotMove(bool isCanNotMove) { m_isCanNotMove = isCanNotMove; }

	// プレイヤーの初期化
	void init();

	//データの取得
	Vec2 getPos()const { return m_pos; }				

	// 処理
	void update();

	////キャラを後退させる
	//void downGrade();

	// 描画
	void draw();

	bool clear();

	void deadDraw();

	void soul();

	void trace();

	void collisionDetection();

private:
	int m_handle[kGraphicDivNum];

	int m_playerSound;

	int m_deadHandle;

	// 表示位置
	Vec2 m_pos;
	//サイズ
	Vec2 m_size;
	// 移動
	Vec2 m_vec;

	//
	bool m_isCanNotMove;

	//キャラクターのアニメーション
	int m_animeNo;			//表示する番号
	int m_animeFrame;
	int m_animeDirections;	//表示する方向

	int tracePosX;
	int tracePosY;

	int count;
};