#include "DxLib.h"
#include "Headder.h"
#define imageNum 1

Image images[imageNum];//�ǂݍ��񂾉摜�p
const char* imageNames[imageNum] = {"images/player.png"};//�ǂݍ��݂����摜�̖��O

void loadImg();//�������ɉ摜��ǂݍ���
void drawImg(int,int,int);//�ȈՉ摜�`��֐�

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//�E�C���h�E���[�h�ɂ���

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	//DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	SetDrawScreen(DX_SCREEN_BACK);//����ʕ`�惂�[�h�ɕύX

	loadImg();//�������ɉ摜��ǂݍ���

	ShootingScene sc;//�V�[���I�u�W�F�N�g�𐶐�
	
	sc.main();//���C���֐�

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

//�������ɉ摜��ǂݍ���
void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

//�ȈՉ摜�`��֐�
void drawImg(int x,int y,int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);
}