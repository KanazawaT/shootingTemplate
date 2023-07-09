#include "Headder.h"

//引数無しのコンストラクタ(基本的には使わない)
Object::Object() {
	this->angle = 0;
	this->img = 0;
	this->position.set(0, 0);
	this->bornTime = 0;
}

//コンストラクタ
Object::Object(double x, double y, double angle,int bornTime) {
	this->position.set(x, y);
	this->angle = angle;
	this->img = 0;
	this->bornTime = bornTime;
}

//基本の描画関数
void Object::view() {
	drawImg(this->position.x, this->position.y, this->img);
}