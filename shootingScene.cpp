#include "DxLib.h"
#include "Headder.h"


int ShootingScene:: main() {
	char keys[256];
	this->startCount = GetNowCount();//ゲーム開始時の時刻カウントを得る
	this->player.reset();//自機の座標などをリセット
	this->tick = 0;//経過時間tickをリセット
	int now, befor,deltaTime;//現在の時刻カウント,一週前の時刻カウント,その差分
	now = this->startCount;//最初現在時刻にはstartCountを入れて置く
	while (TRUE) {
		//不要ログ処理&閉じられてたら終了
		if (ProcessMessage() == -1) {
			return -1;
		}

		//キー入力取得
		GetHitKeyStateAll(keys);
		//経過時間更新
		befor = now;
		now = GetNowCount();
		deltaTime = now - befor;

		this->update(deltaTime,keys);//経過時間分の処理

		this->view();//描画処理



		//Escキー押下で終了
		if (keys[KEY_INPUT_ESCAPE]) {
			return -2;
		}


	}
}

void ShootingScene::update(int deltaTime,char key[]) {
	this->player.move(deltaTime, key[KEY_INPUT_UP], key[KEY_INPUT_DOWN], key[KEY_INPUT_LEFT], key[KEY_INPUT_RIGHT]);//プレイヤーの移動

}

void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::regularlyUpdate(int tick) {

}