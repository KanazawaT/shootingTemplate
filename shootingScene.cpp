#include "DxLib.h"
#include "Headder.h"


ShootingScene::ShootingScene() {
	for (int i = 0; i < ENEMYS_NUM; i++) {
		this->enemys[i] = NULL;
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		this->bullets[i] = NULL;
	}
	for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
		this->playersBullets[i] = NULL;
	}
	this->player.reset();//自機の座標などをリセット
	this->tick = 0;//経過時間tickをリセット
	this->startCount = GetNowCount();//ゲーム開始時の時刻カウントを得る
	this->newBulletIndex = 0;
	this->newEnemyIndex = 0;
	this->newPlayersBulletIndex = 0;
}

ShootingScene::~ShootingScene() {
	for (int i = 0; i < ENEMYS_NUM;i++) {
		if (this->enemys[i] != NULL) {
			delete this->enemys[i];
		}
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			delete this->bullets[i];
		}
	}
	for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
		if (this->playersBullets[i] != NULL) {
			delete this->playersBullets[i];
		}
	}
}

int ShootingScene:: main() {
	char keys[256];
	
	int now, before,deltaTime,nextTickTime;//現在の時刻カウント,一週前の時刻カウント,その差分,次にreguralyUpdateを動かす時刻
	now = this->startCount;//最初現在時刻にはstartCountを入れて置く
	nextTickTime = this->startCount;
	while (TRUE) {
		//不要ログ処理&閉じられてたら終了
		if (ProcessMessage() == -1) {
			return -1;
		}

		//キー入力取得
		GetHitKeyStateAll(keys);
		//経過時間更新
		before = now;
		now = GetNowCount();

		//時間経過の処理
		if (now >= nextTickTime) {//tickの分かれ目をはさむ場合
			update(nextTickTime - before,nextTickTime,keys);
			regularlyUpdate(tick,nextTickTime);
			update(now - nextTickTime,now, keys);
			nextTickTime += TICK_TIME;
			tick++;
		}
		else {//tickの分かれ目をはさまない場合
			this->update(now - before, now, keys);//経過時間分の処理
		}
		

		this->view();//描画処理



		//Escキー押下で終了
		if (keys[KEY_INPUT_ESCAPE]) {
			return -2;
		}
	}
}

//毎フレーム呼び出される。deltatime分の時間経過処理
void ShootingScene::update(int deltaTime,int now,char key[]) {
	this->player.move(deltaTime, key[KEY_INPUT_UP], key[KEY_INPUT_DOWN], key[KEY_INPUT_LEFT], key[KEY_INPUT_RIGHT]);//プレイヤーの移動

}

//1秒に20回呼び出される時間経過処理
void ShootingScene::regularlyUpdate(int tick, int now) {

}

//色々なオブジェクトを描画する
void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::addEnemy(Unit* unit) {
	this->enemys[this->newEnemyIndex] = unit;
	this->newEnemyIndex = (this->newEnemyIndex + 1) % ENEMYS_NUM;
}

void ShootingScene::addBullet(Object* bullet) {
	this->bullets[this->newBulletIndex] = bullet;
	this->newBulletIndex = (this->newBulletIndex + 1) % BULLETS_NUM;
}

void ShootingScene::addPlayersBullet(Object* bullet) {
	this->playersBullets[this->newPlayersBulletIndex] = bullet;
	this->newPlayersBulletIndex = (this->newPlayersBulletIndex + 1) % PLAYER_BULLETS_NUM;
}

