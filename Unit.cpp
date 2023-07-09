#include "Headder.h"

Unit::Unit() :Object() {
	this->hp = 10;
}

Unit::Unit(double x, double y, double angle, int bornTime, int hp):Object(x,y,angle,bornTime) {
	this->hp = hp;
}