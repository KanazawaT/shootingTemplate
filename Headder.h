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

class Image {
public:
	int hundle;
	int x, y;
};

class ShootingScene {

};

class Object {
protected:
	Vector2 position;
	float  angle;
	int img;
	int bornTime;
public :
	Object();
	Object(double,double,double,int);
	virtual void view();
};

class Unit :public Object {
protected:
	int hp;
protected:
	Unit();
	Unit(double, double, double, int ,int);
};

class Player :public Object
{
private:
	
public:
	Player();
};