#pragma once

class ShootingScene {

};

class Object {
private:
	float x, y, angle;
	int img;
public :
	Object();
	void view();
};

class Player :public Object
{

};