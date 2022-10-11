#pragma once

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
private:
	int m_handle;
};