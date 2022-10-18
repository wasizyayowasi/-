#include "DxLib.h"
#include "game.h"
#include "sceneTitle.h"

namespace {
	constexpr int fontSize = 128;
}

SceneTitle::SceneTitle() {
	m_fadeBright = 0;
	m_fadeSpeed = 0;
}

SceneTitle::~SceneTitle() {

}

void SceneTitle::init() {
	m_fadeBright = 0;
	m_fadeSpeed = 8;
}

void SceneTitle::end() {
	SetDrawBright(255, 255, 255);
};

bool SceneTitle::update() {


	// ÉLÅ[ì¸óÕèàóù
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (m_fadeSpeed == 0) {
		if (padState & PAD_INPUT_1)
		{
			return true;
			//m_fadeSpeed = -8;
		}
	//}

	return false;
}

void SceneTitle::draw() {
	SetFontSize(fontSize);
	//SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawString(Game::kScreenWidth / 2 - 185, Game::kScreenHeight / 6, "ÇﬂÇ¢ÇÎ", GetColor(255, 255, 255));
	SetFontSize(60);
	DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 3 + 50, "AÇ≈íßêÌ", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 3 + 120, "BÇ≈èIóπ", GetColor(255, 255, 255));
}