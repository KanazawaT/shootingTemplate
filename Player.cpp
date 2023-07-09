#include "Headder.h"
#define PLAYER_SPEED 0.3
//�v���C���[�̃R���X�g���N�^(�g���\��͂Ȃ�)
Player::Player() {
	
}

//�v���C���[��deltaTime���ړ�������up,down���͂��ꂼ��L�[��������Ă��邩
void Player::move(int deltaTime,char up,char down,char left,char right) {
	this->position.x += deltaTime * PLAYER_SPEED * ((right ? 1 : 0) - (left ? 1 : 0));
	this->position.y += deltaTime * PLAYER_SPEED * ((down ? 1 : 0) - (up ? 1 : 0));
}

//�v���C���[�������ʒu�ɖ߂�
void Player::reset() {
	this->img = 0;
	this->angle = 0;
	this->position.set(320, 440);
}

//�v���C���[�̕`��֐�
void Player::view() {
	drawImg(this->position.x, this->position.y, this->img);
}