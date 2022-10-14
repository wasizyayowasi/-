#include "DxLib.h"
#include "game.h"
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneEnd.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//window���[�h�̐ݒ�
	ChangeWindowMode(Game::kWindowMode);
	//window���ݒ�
	SetMainWindowText(Game::kTitleText);
	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth,Game::kScreenHeight, Game::kScreenDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	//�_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);
	int sceneNo = 1;

	SceneMain sceneMain;
	sceneMain.init();

	SceneTitle sceneTitle;

	SceneEnd sceneEnd;

	switch (sceneNo) {
	case 0:
		sceneTitle.init();
		break;
	case 1:
		sceneMain.init();
		break;
	case 2:
		sceneEnd.init();
	}

	while (ProcessMessage() == 0) {

		LONGLONG time = GetNowHiPerformanceCount();
		//��ʂ̃N���A
		ClearDrawScreen();

		bool isChange = false;
		bool isEnd = false;
		switch (sceneNo) {
		case 0:
			isChange = sceneTitle.update();
			sceneTitle.draw();
			if (isChange) {
				sceneTitle.end();

				sceneMain.init();
				sceneNo = 1;
			}
			break;
		case 1:
			isChange = sceneMain.update();
			isEnd = sceneMain.update();
			sceneMain.draw();
			if (isChange) {
				sceneMain.end();
				sceneEnd.init();
				sceneNo = 2;
			}
			else {
				sceneMain.end();

				sceneNo = 3;
			}
		case 2:

			sceneEnd.draw();
			sceneEnd.end();
			break;
		}

		SetBackgroundColor(255, 255, 255);

		//����ʂ�\��ʂɐ؂�ւ���
		ScreenFlip();

		//esc����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;

		//fps��60�ɌŒ�
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
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}