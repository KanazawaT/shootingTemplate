#include "Headder.h"
#include <math.h>

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

//他のベクトルとの距離を求める
double Vector2::distance(Vector2* vec) {
	return sqrt((this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y));
}

//他のベクトルとの距離の二乗を求める(計算の簡略化のため当たり判定を調べるときはこちらを使う)
double Vector2::distance2(Vector2* vec) {
	return (this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y);
}

//他のベクトルとの内積を求める
double Vector2::product(Vector2* vec) {
	return this->x * vec->x + this->y * vec->y;
}

//値をセットする
void Vector2::set(double x, double y) {
	this->x = x;
	this->y = y;
}