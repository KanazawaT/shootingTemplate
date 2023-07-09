#pragma once
#define OBJECTS_NUM 256 

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
	int hp;
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
	Object* objects[OBJECTS_NUM];
	int startCount;
	int tick;
public:
	int main();
	void view();
	void update(int, char[]);
	virtual void regularlyUpdate(int);
};

//簡易描画関数のプロトタイプ宣言
void drawImg(int,int,int);