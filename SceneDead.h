#pragma once

class SceneDead {
public:
	SceneDead();
	virtual ~SceneDead();

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