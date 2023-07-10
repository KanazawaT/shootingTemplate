#include "DxLib.h"
#include "Headder.h"




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

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

