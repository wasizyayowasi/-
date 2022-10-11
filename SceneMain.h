#pragma once
#include "Map.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
private:
	//マップのグラフィックハンドル
	int m_hMap;
	//マップ
	Map m_map;
};