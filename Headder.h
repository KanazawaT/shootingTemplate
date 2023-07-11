#pragma once
#define ENEMYS_NUM 32
#define BULLETS_NUM 256 
#define PLAYER_BULLETS_NUM 32
#define TICK_TIME 50//1tick�̒����~���b

void loadImg();//�������ɉ摜��ǂݍ���
void drawImg(int, int, int);//�ȈՉ摜�`��֐�

//��Ɉʒu���W�p2�����x�N�g��
class Vector2 {
public :
	double x, y;
	Vector2();
	Vector2(double, double);
	double distance(Vector2*);
	double distance2(Vector2*);
	double product(Vector2 *);
	double getAngleToTarget(Vector2 *);
	void set(double, double);
	void add(Vector2*);
};

//�摜�̃n���h���ƃI�t�Z�b�g�p�̐��l
class Image {
public:
	int hundle;
	int x, y;
};

class ShootingScene;

//�I�u�W�F�N�g�̐e
class Object {
protected:
	Vector2 position;
	int img;
	int bornTime;
	int bornTick;
public :
	Object();
	Object(double,double,int);
	virtual void view();
	virtual void update(int,int);
	virtual int regularlyUpdate(int,ShootingScene *);
	void setBornTime(int,int);
	Vector2* getPosition();
};

//�G���j�b�g�p��hp�ǉ�
class Unit :public Object {
protected:
	int hp;//�G���j�b�g�ɂ�hp���ݒ肳��Ă���
protected:
	Unit();
	Unit(double, double, double,int);
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
	Unit* enemys[ENEMYS_NUM];
	Object* bullets[BULLETS_NUM];
	Object* playersBullets[PLAYER_BULLETS_NUM];
	int startCount;//�Q�[���X�^�[�g���̎���
	int now;
	int tick;//�Q�[���J�n����̌o�ߎ���(�P��50ms)
	int newEnemyIndex, newBulletIndex, newPlayersBulletIndex;//���ɐ�������I�u�W�F�N�g��z��̉��Ԗڂɓ���邩
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

//�ȈՕ`��֐��̃v���g�^�C�v�錾
void drawImg(int,int,int);

class BulletTemplate :public Object{
private:
	Vector2 delta;
public:
	BulletTemplate(double, double, double, double, int);
	void update(int,int);
	int regularlyUpdate(int, ShootingScene *);
};