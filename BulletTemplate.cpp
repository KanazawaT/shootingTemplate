#include "Headder.h"
#include <math.h>

BulletTemplate::BulletTemplate(double x,double y,double speed,double angle,double r,int img) : Object(x,y,r,img){
	this->delta.set(speed * cos(angle), speed * sin(angle));
}

void BulletTemplate::update(int deltaTime,int now) {
	this->position.add(&this->delta);
}

int BulletTemplate::regularlyUpdate(int tick,ShootingScene *parent) {
	return (this->position.x >= 0 && this->position.x < 640 && this->position.y >= 0 && this->position.y < 480) ? 0 : -1;//‰æ–ÊŠO‚Éo‚½‚ç-1‚ð•Ô‚·
}