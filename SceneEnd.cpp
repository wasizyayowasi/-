#include "DxLib.h"
#include "game.h"
#include "sceneEnd.h"

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

	// ƒL[“ü—Íˆ—
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1){
		return true;
	}
	return false;
}

void SceneEnd::draw() {
	SetFontSize(fontSize);
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawString(Game::kScreenWidth / 2 - 185, Game::kScreenHeight / 6, "ƒS[ƒ‹", GetColor(0, 0, 0));
}