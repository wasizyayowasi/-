#pragma once
#include "Map.h"
#include "Key.h"
#include "player.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	bool update();
	// 毎フレームの描画
	void draw();
private:
	//マップのグラフィックハンドル
	int m_hMap;
	//鍵のグラフィックハンドル
	int m_hKey;
	//プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicDivNum];

	//マップ
	Map m_map;
	//鍵
	Key m_key;
	//プレイヤー
	Player m_player;
};