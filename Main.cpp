#include "DxLib.h"
#include "Headder.h"




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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

