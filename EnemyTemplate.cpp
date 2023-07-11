#include "Headder.h"
#include <math.h>

EnemyTemplate::EnemyTemplate(double x, double y, double speed, double angle,double r, int img,int hp) : Unit(x, y, r,img, hp) {
	this->delta.set(speed * cos(angle), speed * sin(angle));
}

void EnemyTemplate::update(int deltaTime, int now) {
	this->position.add(&this->delta);
}

int EnemyTemplate::regularlyUpdate(int tick, ShootingScene* parent) {
	if (tick % 20 == 0) {//1•b‚É1‰ñŽ©‹@‘_‚¢‚Ì3way’e‚ð”­ŽË‚·‚é
		double mainAngle = this->position.getAngleToTarget(parent->getPlayerPosition());
		parent->addBullet(new BulletTemplate(this->position.x, this->position.y, 2, mainAngle, 2, 2));
		parent->addBullet(new BulletTemplate(this->position.x, this->position.y, 2, mainAngle + 0.5, 2, 2));
		parent->addBullet(new BulletTemplate(this->position.x, this->position.y, 2, mainAngle - 0.5, 2, 2));

	}
	return (this->position.x >= 0 && this->position.x < 640 && this->position.y >= 0 && this->position.y < 480) ? 0 : -1;//‰æ–ÊŠO‚Éo‚½‚ç-1‚ð•Ô‚·
}