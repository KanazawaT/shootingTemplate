#include "DxLib.h"
#include "Headder.h"
#define imageNum 1

using namespace std;

Image images[imageNum];
const char* imageNames[imageNum] = {"images/player.png"};

void loadImg();
void drawImg(int,int,int);

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	
	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void loadImg() {
	for (int i = 0; i < imageNum; i++) {
		images[i].hundle = LoadGraph(imageNames[i]);
		GetGraphSize(images[i].hundle, &images[i].x, &images[i].y);
		images[i].x /= 2;
		images[i].y /= 2;

	}
}

void drawImg(int x,int y,int id) {
	DrawGraph(x - images[id].x, y - images[id].y, images[id].hundle, TRUE);

}