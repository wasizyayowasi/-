#pragma once
#include "Map.h"
#include "Key.h"
#include "Player.h"
#include "Door.h"
#include "GreenWall.h"
#include "Enemy.h"
#include "Botan.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	int update();
	// 毎フレームの描画
	void draw();
private:
	//マップのグラフィックハンドル
	int m_hMap;
	int m_hBackgroundHnadle;
	//鍵のグラフィックハンドル
	int m_hKey;
	//プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	//プレイヤー死亡時の演出のグラフィックハンドル
	int m_hPlayerDead;
	//ドアのグラフィックハンドル
	int m_hDoor;
	//敵のグラフィックハンドル
	int m_hEnemyGraphic[Enemy::kGraphicDivNum];
	//ボタンのグラフィックハンドル
	int m_hBotan;
	//鍵取得のサウンド
	int m_sKeyHandle;
	//ボタンを押した時のサウンド
	int m_sPushBotan;
	//扉を開けるサウンド
	int m_sOpenDoor;
	//死亡フラグ
	int playerDead;

	//死亡演出を流す時間
	int playerDeadTime;

	//マップ
	Map m_map;
	//鍵
	Key m_key;
	//ドア
	Door m_door;
	//プレイヤー
	Player m_player;
	//緑の壁
	GreenWall m_greenWall;
	//敵
	Enemy m_enemy;
	//ボタン
	Botan m_botan;

};