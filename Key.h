#pragma once

class Key {
public:
	Key();
	virtual ~Key();

	//�O���t�B�b�N�f�[�^�̐ݒ�
	void setHandle(int handle) { m_handle = handle; }
	//�}�b�v�̏�����
	void init();

	//�`��
	void draw();
private:
	int m_handle;
};