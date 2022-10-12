#pragma once

class SceneTitle {
public:
	SceneTitle();
	virtual ~SceneTitle();

	//初期化処理、終了処理
	void init();
	void end();

	//ゲーム処理 シーン切り替えるときはtrue
	bool update();
	//描画
	void draw();
private:

	//フェード処理
	int m_fadeBright;
	//フェードの速度
	int m_fadeSpeed;
};