#include "Headder.h"

//���������̃R���X�g���N�^(��{�I�ɂ͎g��Ȃ�)
Object::Object() {
	this->angle = 0;
	this->img = 0;
	this->position.set(0, 0);
	this->bornTime = 0;
}

//�R���X�g���N�^
Object::Object(double x, double y, double angle,int bornTime) {
	this->position.set(x, y);
	this->angle = angle;
	this->img = 0;
	this->bornTime = bornTime;
}

//��{�̕`��֐�
void Object::view() {
	drawImg(this->position.x, this->position.y, this->img);
}