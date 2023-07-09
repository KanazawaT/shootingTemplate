#pragma once

class Vector2 {
public :
	double x, y;
	Vector2();
	Vector2(double, double);
	double distance(Vector2*);
	double distance2(Vector2*);
	double product(Vector2 *);
	void set(double, double);
};

class ShootingScene {

};

class Object {
private:
	Vector2 position;
	float  angle;
	int img;
public :
	Object();
	virtual void view();
};

class Player :public Object
{
	Player();
};