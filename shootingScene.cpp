#include "DxLib.h"
#include "Headder.h"


int ShootingScene:: main() {
	char keys[256];
	this->startCount = GetNowCount();//�Q�[���J�n���̎����J�E���g�𓾂�
	this->player.reset();//���@�̍��W�Ȃǂ����Z�b�g
	this->tick = 0;//�o�ߎ���tick�����Z�b�g
	int now, befor,deltaTime;//���݂̎����J�E���g,��T�O�̎����J�E���g,���̍���
	now = this->startCount;//�ŏ����ݎ����ɂ�startCount�����Ēu��
	while (TRUE) {
		//�s�v���O����&�����Ă���I��
		if (ProcessMessage() == -1) {
			return -1;
		}

		//�L�[���͎擾
		GetHitKeyStateAll(keys);
		//�o�ߎ��ԍX�V
		befor = now;
		now = GetNowCount();
		deltaTime = now - befor;

		this->update(deltaTime,keys);//�o�ߎ��ԕ��̏���

		this->view();//�`�揈��



		//Esc�L�[�����ŏI��
		if (keys[KEY_INPUT_ESCAPE]) {
			return -2;
		}


	}
}

void ShootingScene::update(int deltaTime,char key[]) {
	this->player.move(deltaTime, key[KEY_INPUT_UP], key[KEY_INPUT_DOWN], key[KEY_INPUT_LEFT], key[KEY_INPUT_RIGHT]);//�v���C���[�̈ړ�

}

void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::regularlyUpdate(int tick) {

}