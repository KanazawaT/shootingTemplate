#include "Headder.h"

//引数無しのコンストラクタ(基本的には使わない)
Unit::Unit() :Object() {
	this->hp = 10;
}

//コンストラクタ
Unit::Unit(double x, double y, double r,int img,int hp):Object(x,y,r,img) {
	this->hp = hp;
}