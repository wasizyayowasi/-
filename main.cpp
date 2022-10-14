#include "DxLib.h"
#include "game.h"
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneEnd.h"
#include "SceneDead.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//windowモードの設定
	ChangeWindowMode(Game::kWindowMode);
	//window名設定
	SetMainWindowText(Game::kTitleText);
	//画面サイズの設定
	SetGraphMode(Game::kScreenWidth,Game::kScreenHeight, Game::kScreenDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ

	
	//ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);
	int sceneNo = 0;

	SceneMain sceneMain;
	sceneMain.init();

	SceneTitle sceneTitle;

	SceneEnd sceneEnd;

	SceneDead sceneDead;

	switch (sceneNo) {
	case 0:
		sceneTitle.init();
		break;
	case 1:
		sceneMain.init();
		break;
	case 2:
		sceneEnd.init();
		break;
	case 3:
		sceneDead.init();
		break;
	}
	

	while (ProcessMessage() == 0) {

		LONGLONG time = GetNowHiPerformanceCount();
		//画面のクリア
		ClearDrawScreen();

		bool isChange = false;
		int endChange = 0;

		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		switch (sceneNo) {
		case 0:
			isChange = sceneTitle.update();
			sceneTitle.draw();
			if (isChange) {
				InitFontToHandle();
				sceneTitle.end();

				sceneMain.init();
				sceneNo = 1;
			}
			break;
		case 1:
			endChange = sceneMain.update();
			sceneMain.draw();
			if (endChange == 1) {
				sceneMain.end();
				sceneEnd.init();
				sceneNo = 2;
				break;
			}
			else if(endChange == 2){
				sceneMain.end();
				sceneDead.init();
				sceneNo = 3;
				break;
			}
			break;
		case 2:
			sceneEnd.draw();
			sceneEnd.end();
			if (padState & PAD_INPUT_3) {
				//sceneMain.init();
				sceneMain.end();
				sceneNo = 0;
			}
			break;
		case 3:
			sceneDead.draw();
			sceneDead.end();
			if (padState & PAD_INPUT_3) {
				//sceneMain.init();
				sceneMain.end();
				sceneNo = 0;
			}
			break;
		}

		SetBackgroundColor(255, 255, 255);

		//裏画面を表画面に切り替える
		ScreenFlip();

		//escを押したら終了する
		if (padState & PAD_INPUT_2)break;

		//fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667) {

		}

	}

	switch (sceneNo) {
	case 0:
		sceneTitle.end();
		break;
	case 1:
		sceneMain.end();
		break;
	case 2:
		sceneEnd.end();
		break;
	case 3:
		sceneDead.end();
		break;
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}