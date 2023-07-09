#include "Headder.h"

//引数無しのコンストラクタ(基本的には使わない)
Unit::Unit() :Object() {
	this->hp = 10;
}

//コンストラクタ
Unit::Unit(double x, double y, double angle, int bornTime, int hp):Object(x,y,angle,bornTime) {
	this->hp = hp;
}