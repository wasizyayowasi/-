#pragma once

class SceneEnd {
public:
	SceneEnd();
	virtual ~SceneEnd();

	//�����������A�I������
	void init();
	void end();

	//�Q�[������ �V�[���؂�ւ���Ƃ���true
	bool update();
	//�`��
	void draw();
private:

	//�t�F�[�h����
	int m_fadeBright;
	//�t�F�[�h�̑��x
	int m_fadeSpeed;
};