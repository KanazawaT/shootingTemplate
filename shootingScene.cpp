#include "DxLib.h"
#include "Headder.h"


ShootingScene::ShootingScene() {
	for (int i = 0; i < ENEMYS_NUM; i++) {
		this->enemys[i] = NULL;
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		this->bullets[i] = NULL;
	}
	for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
		this->playersBullets[i] = NULL;
	}
	this->player.reset();//���@�̍��W�Ȃǂ����Z�b�g
	this->tick = 0;//�o�ߎ���tick�����Z�b�g
	this->startCount = GetNowCount();//�Q�[���J�n���̎����J�E���g�𓾂�
	this->newBulletIndex = 0;
	this->newEnemyIndex = 0;
	this->newPlayersBulletIndex = 0;
}

ShootingScene::~ShootingScene() {
	for (int i = 0; i < ENEMYS_NUM;i++) {
		if (this->enemys[i] != NULL) {
			delete this->enemys[i];
		}
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			delete this->bullets[i];
		}
	}
	for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
		if (this->playersBullets[i] != NULL) {
			delete this->playersBullets[i];
		}
	}
}

int ShootingScene:: main() {
	char keys[256];
	
	int now, before,deltaTime,nextTickTime;//���݂̎����J�E���g,��T�O�̎����J�E���g,���̍���,����reguralyUpdate�𓮂�������
	now = this->startCount;//�ŏ����ݎ����ɂ�startCount�����Ēu��
	nextTickTime = this->startCount;
	while (TRUE) {
		//�s�v���O����&�����Ă���I��
		if (ProcessMessage() == -1) {
			return -1;
		}

		//�L�[���͎擾
		GetHitKeyStateAll(keys);
		//�o�ߎ��ԍX�V
		before = now;
		now = GetNowCount();

		//���Ԍo�߂̏���
		if (now >= nextTickTime) {//tick�̕�����ڂ��͂��ޏꍇ
			update(nextTickTime - before,nextTickTime,keys);
			regularlyUpdate(tick,nextTickTime);
			update(now - nextTickTime,now, keys);
			nextTickTime += TICK_TIME;
			tick++;
		}
		else {//tick�̕�����ڂ��͂��܂Ȃ��ꍇ
			this->update(now - before, now, keys);//�o�ߎ��ԕ��̏���
		}
		

		this->view();//�`�揈��



		//Esc�L�[�����ŏI��
		if (keys[KEY_INPUT_ESCAPE]) {
			return -2;
		}
	}
}

//���t���[���Ăяo�����Bdeltatime���̎��Ԍo�ߏ���
void ShootingScene::update(int deltaTime,int now,char key[]) {
	this->player.move(deltaTime, key[KEY_INPUT_UP], key[KEY_INPUT_DOWN], key[KEY_INPUT_LEFT], key[KEY_INPUT_RIGHT]);//�v���C���[�̈ړ�

}

//1�b��20��Ăяo����鎞�Ԍo�ߏ���
void ShootingScene::regularlyUpdate(int tick, int now) {

}

//�F�X�ȃI�u�W�F�N�g��`�悷��
void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::addEnemy(Unit* unit) {
	this->enemys[this->newEnemyIndex] = unit;
	this->newEnemyIndex = (this->newEnemyIndex + 1) % ENEMYS_NUM;
}

void ShootingScene::addBullet(Object* bullet) {
	this->bullets[this->newBulletIndex] = bullet;
	this->newBulletIndex = (this->newBulletIndex + 1) % BULLETS_NUM;
}

void ShootingScene::addPlayersBullet(Object* bullet) {
	this->playersBullets[this->newPlayersBulletIndex] = bullet;
	this->newPlayersBulletIndex = (this->newPlayersBulletIndex + 1) % PLAYER_BULLETS_NUM;
}

