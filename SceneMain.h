#pragma once
#include "Map.h"

class SceneMain {
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
private:
	//�}�b�v�̃O���t�B�b�N�n���h��
	int m_hMap;
	//�}�b�v
	Map m_map;
};