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
	this->now = this->startCount;
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
	
	int before,nextTickTime;//現在の時刻カウント,一週前の時刻カウント,その差分,次にreguralyUpdateを動かす時刻
	this->now = this->startCount;//最初現在時刻にはstartCountを入れて置く
	nextTickTime = this->startCount;
	while (TRUE) {
		//不要ログ処理&閉じられてたら終了
		if (ProcessMessage() == -1) {
			return -1;
		}

		//キー入力取得
		GetHitKeyStateAll(keys);
		//経過時間更新
		before = this->now;
		this->now = GetNowCount();

		//時間経過の処理
		if (this->now >= nextTickTime) {//tickの分かれ目をはさむ場合
			update(nextTickTime - before,nextTickTime,keys);
			regularlyUpdate(tick,nextTickTime);
			update(this->now - nextTickTime, this->now, keys);
			nextTickTime += TICK_TIME;
			tick++;
		}
		else {//tickの分かれ目をはさまない場合
			this->update(this->now - before, this->now, keys);//経過時間分の処理
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
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			this->bullets[i]->update(deltaTime, now);
		}
	}
}

//1秒に20回呼び出される時間経過処理
void ShootingScene::regularlyUpdate(int tick, int now) {
	if (tick % 20 == 0) {
		Vector2 a = { 320,100 };
		this->addBullet(new BulletTemplate(320, 100, 0.2, a.getAngleToTarget(this->player.getPosition()), 2));
	}
	for (int i = 0; i < BULLETS_NUM; i++) {
		if (this->bullets[i] != NULL) {
			if (this->bullets[i]->regularlyUpdate(tick, this) == -1) {
				delete this->bullets[i];
				this->bullets[i] == NULL;
			}
		}
	}
}

//色々なオブジェクトを描画する
void ShootingScene::view() {
	ClearDrawScreen();
	this->player.view();
	ScreenFlip();
}

void ShootingScene::addEnemy(Unit* unit) {
	if (this->enemys[this->newEnemyIndex] != NULL) {
		delete this->enemys[this->newEnemyIndex];
	}
	this->enemys[this->newEnemyIndex] = unit;
	unit->setBornTime(this->now,this->tick);
	this->newEnemyIndex = (this->newEnemyIndex + 1) % ENEMYS_NUM;
}

void ShootingScene::addBullet(Object* bullet) {
	if (this->bullets[this->newBulletIndex] != NULL) {
		delete this->bullets[this->newBulletIndex];
	}
	this->bullets[this->newBulletIndex] = bullet;
	bullet->setBornTime(this->now, this->tick);
	this->newBulletIndex = (this->newBulletIndex + 1) % BULLETS_NUM;
}

void ShootingScene::addPlayersBullet(Object* bullet) {
	if (this->playersBullets[this->newPlayersBulletIndex] != NULL) {
		delete this->playersBullets[this->newPlayersBulletIndex];
	}
	this->playersBullets[this->newPlayersBulletIndex] = bullet;
	bullet->setBornTime(this->now, this->tick);
	this->newPlayersBulletIndex = (this->newPlayersBulletIndex + 1) % PLAYER_BULLETS_NUM;
}

