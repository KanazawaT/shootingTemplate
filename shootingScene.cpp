#include "DxLib.h"

class ShootingScene {
	int main() {
		char keys[256];
		while (TRUE) {
			//不要ログ処理&閉じられてたら終了
			if (ProcessMessage() == -1) {
				return -1;
			}

			//キー入力取得
			GetHitKeyStateAll(keys);

			//Escキー押下で終了
			if (keys[KEY_INPUT_ESCAPE]) {
				return -2;
			}


		}
	}
};