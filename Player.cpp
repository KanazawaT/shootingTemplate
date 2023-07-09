#include "Headder.h"
#define PLAYER_SPEED 0.3
//プレイヤーのコンストラクタ(使う予定はない)
Player::Player() {
	
}

//プレイヤーをdeltaTime分移動させるup,down等はそれぞれキーが押されているか
void Player::move(int deltaTime,char up,char down,char left,char right) {
	this->position.x += deltaTime * PLAYER_SPEED * ((right ? 1 : 0) - (left ? 1 : 0));
	this->position.y += deltaTime * PLAYER_SPEED * ((down ? 1 : 0) - (up ? 1 : 0));
}

//プレイヤーを初期位置に戻す
void Player::reset() {
	this->img = 0;
	this->angle = 0;
	this->position.set(320, 440);
}

//プレイヤーの描画関数
void Player::view() {
	drawImg(this->position.x, this->position.y, this->img);
}