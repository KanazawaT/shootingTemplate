#include "Headder.h"

//���������̃R���X�g���N�^(��{�I�ɂ͎g��Ȃ�)
Unit::Unit() :Object() {
	this->hp = 10;
}

//�R���X�g���N�^
Unit::Unit(double x, double y, double r,int img,int hp):Object(x,y,r,img) {
	this->hp = hp;
}