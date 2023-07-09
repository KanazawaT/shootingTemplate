#include "DxLib.h"
#include "Headder.h"
#define imageNum 1

Image images[imageNum];//読み込んだ画像用
const char* imageNames[imageNum] = {"images/player.png"};//読み込みたい画像の名前

void loadImg();//メモリに画像を読み込む
void drawImg(int,int,int);//簡易画像描画関数

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//ウインドウモードにする

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	//DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	SetDrawScreen(DX_SCREEN_BACK);//裏画面描画モードに変更

	loadImg();//メモリに画像を読み込む

	ShootingScene sc;//シーンオブジェクトを生成
	
	sc.main();//メイン関数

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

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
void drawImg(int x,int y,int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);
}