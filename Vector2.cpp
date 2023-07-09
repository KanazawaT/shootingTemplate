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

//���̃x�N�g���Ƃ̋��������߂�
double Vector2::distance(Vector2* vec) {
	return sqrt((this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y));
}

//���̃x�N�g���Ƃ̋����̓������߂�(�v�Z�̊ȗ����̂��ߓ����蔻��𒲂ׂ�Ƃ��͂�������g��)
double Vector2::distance2(Vector2* vec) {
	return (this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y);
}

//���̃x�N�g���Ƃ̓��ς����߂�
double Vector2::product(Vector2* vec) {
	return this->x * vec->x + this->y * vec->y;
}

//�l���Z�b�g����
void Vector2::set(double x, double y) {
	this->x = x;
	this->y = y;
}