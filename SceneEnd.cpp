#include "DxLib.h"
#include "game.h"
#include "SceneEnd.h"

namespace {
	constexpr int fontSize = 128;
}

SceneEnd::SceneEnd() {
	m_fadeBright = 0;
	m_fadeSpeed = 0;
}

SceneEnd::~SceneEnd() {

}

void SceneEnd::init() {
	m_fadeBright = 0;
	m_fadeSpeed = 8;
}

void SceneEnd::end() {
	SetDrawBright(255, 255, 255);
}

bool SceneEnd::update() {

	// キー入力処理
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1){
		return true;
	}
	return false;
}

void SceneEnd::draw() {
	SetFontSize(fontSize);
	DrawString(Game::kScreenWidth / 2 - 130, Game::kScreenHeight / 6, "脱出", GetColor(255, 255, 0));
	SetFontSize(60);
	DrawString(Game::kScreenWidth / 2 - 125, Game::kScreenHeight / 3 + 50, "Xで再挑戦", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 3 + 120, "Bで終了", GetColor(255, 255, 255));
}