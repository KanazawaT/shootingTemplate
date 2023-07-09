#include "Headder.h"

Player::Player() {
	
}

void Player::move(int deltaTime,char up,char down,char left,char right) {

}

void Player::reset() {
	this->img = 0;
	this->angle = 0;
	this->position.set(320, 440);
}

void Player::view() {
	drawImg(this->position.x, this->position.y, this->img);
}