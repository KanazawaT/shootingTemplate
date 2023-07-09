#pragma once

class ShootingScene {

};

class Object {
private:
	float x, y, angle;
	int img;
public :
	Object();
	virtual void view();
};

class Player :public Object
{
	Player();
};