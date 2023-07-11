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
	this->now = this->startCount;
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
	
	int before,nextTickTime;//���݂̎����J�E���g,��T�O�̎����J�E���g,���̍���,����reguralyUpdate�𓮂�������
	this->now = this->startCount;//�ŏ����ݎ����ɂ�startCount�����Ēu��
	nextTickTime = this->startCount;
	while (TRUE) {
		//�s�v���O����&�����Ă���I��
		if (ProcessMessage() == -1) {
			return -1;
		}

		//�L�[���͎擾
		GetHitKeyStateAll(keys);
		//�o�ߎ��ԍX�V
		before = this->now;
		this->now = GetNowCount();

		//���Ԍo�߂̏���
		if (this->now >= nextTickTime) {//tick�̕�����ڂ��͂��ޏꍇ
			update(nextTickTime - before,nextTickTime,keys);
			regularlyUpdate(tick,nextTickTime);
			update(this->now - nextTickTime, this->now, keys);
			nextTickTime += TICK_TIME;
			tick++;
		}
		else {//tick�̕�����ڂ��͂��܂Ȃ��ꍇ
			this->update(this->now - before, this->now, keys);//�o�ߎ��ԕ��̏���
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
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			this->bullets[i]->update(deltaTime, now);
		}
	}
}

//1�b��20��Ăяo����鎞�Ԍo�ߏ���
void ShootingScene::regularlyUpdate(int tick, int now) {
	if (tick % 20 == 0) {
		Vector2 a = { 320,100 };
		this->addBullet(new BulletTemplate(320, 100, 0.2, a.getAngleToTarget(this->player.getPosition()), 2));
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			if (this->bullets[i]->regularlyUpdate(tick, this) == -1) {
				delete this->bullets[i];
				this->bullets[i] == NULL;
			}
		}
	}
}

//�F�X�ȃI�u�W�F�N�g��`�悷��
void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::addEnemy(Unit* unit) {
	if (this->enemys[this->newEnemyIndex] != NULL) {
		delete this->enemys[this->newEnemyIndex];
	}
	this->enemys[this->newEnemyIndex] = unit;
	unit->setBornTime(this->now,this->tick);
	this->newEnemyIndex = (this->newEnemyIndex + 1) % ENEMYS_NUM;
}

void ShootingScene::addBullet(Object* bullet) {
	if (this->bullets[this->newBulletIndex] != NULL) {
		delete this->bullets[this->newBulletIndex];
	}
	this->bullets[this->newBulletIndex] = bullet;
	bullet->setBornTime(this->now, this->tick);
	this->newBulletIndex = (this->newBulletIndex + 1) % BULLETS_NUM;
}

void ShootingScene::addPlayersBullet(Object* bullet) {
	if (this->playersBullets[this->newPlayersBulletIndex] != NULL) {
		delete this->playersBullets[this->newPlayersBulletIndex];
	}
	this->playersBullets[this->newPlayersBulletIndex] = bullet;
	bullet->setBornTime(this->now, this->tick);
	this->newPlayersBulletIndex = (this->newPlayersBulletIndex + 1) % PLAYER_BULLETS_NUM;
}

