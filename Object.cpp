#include "Headder.h"

//���������̃R���X�g���N�^(��{�I�ɂ͎g��Ȃ�)
Object::Object() {
	this->img = 0;
	this->r = 0;
	this->position.set(0, 0);
	this->bornTime = 0;
	this->bornTick = 0;
}

//�R���X�g���N�^
Object::Object(double x, double y,double r,int img) {
	this->position.set(x, y);
	this->r = r;
	this->img = img;
	this->bornTime = 0;//bornTime�͌�œo�^����
	this->bornTick = 0;
}

//��{�̕`��֐�
void Object::view() {
	drawImg(this->position.x, this->position.y, this->img);
}

void Object::update(int deltaTime,int now) {

}

int Object::regularlyUpdate(int tick, ShootingScene* parent) {
	return 0;
}

void Object::setBornTime(int bornTime,int borntick) {
	this->bornTime = bornTime;
	this->bornTick = bornTick;
}

Vector2* Object::getPosition() {
	return &this->position;
}