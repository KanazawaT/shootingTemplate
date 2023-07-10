#include "DxLib.h"
#include "Headder.h"
#define imageNum 6


Image images[imageNum];//�ǂݍ��񂾉摜�p

const char* imageNames[imageNum] = {
	"images/player.png",
	"images/enemy.png",
	"images/bullet.png",
	"images/bullet2.png",
	"images/smallBullet.png",
	"images/edgeBullet.png"
};//�ǂݍ��݂����摜�̖��O


//�������ɉ摜��ǂݍ���
void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

//�ȈՉ摜�`��֐�
void drawImg(int x, int y, int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);
}