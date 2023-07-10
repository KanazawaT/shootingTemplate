#pragma once
#define ENEMYS_NUM 32
#define BULLETS_NUM 256 
#define PLAYER_BULLETS_NUM 32
#define TICK_TIME 50//1tickの長さミリ秒

void loadImg();//メモリに画像を読み込む
void drawImg(int, int, int);//簡易画像描画関数

//主に位置座標用2次元ベクトル
class Vector2 {
public :
	double x, y;
	Vector2();
	Vector2(double, double);
	double distance(Vector2*);
	double distance2(Vector2*);
	double product(Vector2 *);
	void set(double, double);
};

//画像のハンドルとオフセット用の数値
class Image {
public:
	int hundle;
	int x, y;
};

//オブジェクトの親
class Object {
protected:
	Vector2 position;
	float  angle;
	int img;
	int bornTime;
public :
	Object();
	Object(double,double,double,int);
	virtual void view();
};

//敵ユニット用にhp追加
class Unit :public Object {
protected:
	int hp;//敵ユニットにはhpが設定されている
protected:
	Unit();
	Unit(double, double, double, int ,int);
};

//自機オブジェクト用
class Player :public Object
{
private:
	
public:
	Player();
	void move(int, char, char, char, char);
	void reset();
	void view();
};

//敵のスポーンなどをつかさどるシーンの親
class ShootingScene {
private:
	Player player;
	Unit* enemys[ENEMYS_NUM];
	Object* bullets[BULLETS_NUM];
	Object* playersBullets[PLAYER_BULLETS_NUM];
	int startCount;//ゲームスタート時の時刻
	int tick;//ゲーム開始からの経過時間(単位50ms)
	int newEnemyIndex, newBulletIndex, newPlayersBulletIndex;//次に生成するオブジェクトを配列の何番目に入れるか
public:
	ShootingScene();
	~ShootingScene();
	int main();
	void view();
	void update(int,int, char[]);
	virtual void regularlyUpdate(int,int);
	void addEnemy(Unit*);
	void addBullet(Object *);
	void addPlayersBullet(Object*);
};

//簡易描画関数のプロトタイプ宣言
void drawImg(int,int,int);