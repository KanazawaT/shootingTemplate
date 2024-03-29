#include "DxLib.h"
#include "Headder.h"
#define imageNum 6


Image images[imageNum];//読み込んだ画像用

const char* imageNames[imageNum] = {
	"images/player.png",
	"images/enemy.png",
	"images/bullet.png",
	"images/bullet2.png",
	"images/smallBullet.png",
	"images/edgeBullet.png"
};//読み込みたい画像の名前


//メモリに画像を読み込む
void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

//簡易画像描画関数
void drawImg(int x, int y, int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);
}