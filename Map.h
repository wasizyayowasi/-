#pragma once

class Map {
public:
	Map();
	virtual ~Map();

	//グラフィックデータの設定
	void setHandle(int handle) { m_handle = handle; }
	void setBackgroundHandle(int handle) { m_backgroundHnadle = handle; }

	//マップの初期化
	void init();

	//描画
	void draw();
private:
	int m_handle;
	int m_backgroundHnadle;
};