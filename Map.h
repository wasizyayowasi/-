#pragma once

class Map {
public:
	Map();
	virtual ~Map();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	void setHandle(int handle) { m_handle = handle; }
	//�}�b�v�̏�����
	void init();

	//�`��
	void draw();
private:
	int m_handle;
};