#include "DxLib.h"
#include "Headder.h"
#define imageNum 6


Image images[imageNum];//“Ç‚İ‚ñ‚¾‰æ‘œ—p

const char* imageNames[imageNum] = {
	"images/player.png",
	"images/enemy.png",
	"images/bullet.png",
	"images/bullet2.png",
	"images/smallBullet.png",
	"images/edgeBullet.png"
};//“Ç‚İ‚İ‚½‚¢‰æ‘œ‚Ì–¼‘O


//ƒƒ‚ƒŠ‚É‰æ‘œ‚ğ“Ç‚İ‚Ş
void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

//ŠÈˆÕ‰æ‘œ•`‰æŠÖ”
void drawImg(int x, int y, int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);
}