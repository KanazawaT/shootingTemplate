#include "DxLib.h"

class ShootingScene {
	int main() {
		char keys[256];
		while (TRUE) {
			//�s�v���O����&�����Ă���I��
			if (ProcessMessage() == -1) {
				return -1;
			}

			//�L�[���͎擾
			GetHitKeyStateAll(keys);

			//Esc�L�[�����ŏI��
			if (keys[KEY_INPUT_ESCAPE]) {
				return -2;
			}


		}
	}
};