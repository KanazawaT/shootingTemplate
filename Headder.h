#pragma once
#define OBJECTS_NUM 256 

//��Ɉʒu���W�p2�����x�N�g��
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

//�摜�̃n���h���ƃI�t�Z�b�g�p�̐��l
class Image {
public:
	int hundle;
	int x, y;
};

//�I�u�W�F�N�g�̐e
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

//�G���j�b�g�p��hp�ǉ�
class Unit :public Object {
protected:
	int hp;
protected:
	Unit();
	Unit(double, double, double, int ,int);
};

//���@�I�u�W�F�N�g�p
class Player :public Object
{
private:
	
public:
	Player();
	void move(int, char, char, char, char);
	void reset();
	void view();
};

//�G�̃X�|�[���Ȃǂ������ǂ�V�[���̐e
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

//�ȈՕ`��֐��̃v���g�^�C�v�錾
void drawImg(int,int,int);