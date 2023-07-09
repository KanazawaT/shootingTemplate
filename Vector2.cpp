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

double Vector2::distance(Vector2* vec) {
	return sqrt((this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y));
}

double Vector2::distance2(Vector2* vec) {
	return (this->x - vec->x) * (this->x - vec->x) + (this->y - vec->y) * (this->y - vec->y);
}

double Vector2::product(Vector2* vec) {
	return this->x * vec->x + this->y * vec->y;
}

void Vector2::set(double x, double y) {
	this->x = x;
	this->y = y;
}