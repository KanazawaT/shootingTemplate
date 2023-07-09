#include "DxLib.h"
#include "Headder.h"
#define imageNum 1

using namespace std;

Image images[imageNum];
const char* imageNames[imageNum] = {"images/player.png"};

void loadImg();
void drawImg(int,int,int);

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	
	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

void drawImg(int x,int y,int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);

}