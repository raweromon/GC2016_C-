#include "main.h"

void main() {
	//Player定義
	CPlayer player;
	
	//Player位置保持用変数
	// 初期位置 x=10.0f, y=5.0f, z=0.0f 
	D3DVECTOR pPos={ 10.0f,5.0f,0.0f };

	//Playerに初期位置設定
	player.setPos(pPos);
	//Playerの初期位置をMAPに入力する。
	mapBuf[(int)player.getPos().y][(int)player.getPos().x] = PLAYER;

	
	while ((GetAsyncKeyState(VK_ESCAPE) & 0x8000 )== false) {
		int mdiff=0;
		pPos = player.getPos();

		// 現在位置のPlayer消去
		mapBuf[(int)player.getPos().y][(int)player.getPos().x] = NONE;

		// Playerのキー入力処理
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
			if (pPos.x < (float)(mWidth - 2)) {
				pPos.x += PLAYER_SPEED;
			}
		}
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {
			if (1<pPos.x) {
				pPos.x -= PLAYER_SPEED;
			}
		}
		if ((GetAsyncKeyState(VK_UP) & 0x8000)) {
			if (1<pPos.y) {
				pPos.y -= PLAYER_SPEED;
			}
		}
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) {
			if (pPos.y<(float)(mHeight-2)) {
				pPos.y += PLAYER_SPEED;
			}
		}

		// Player移動後の位置を設定
		player.setPos(pPos);

		mapBuf[(int)player.getPos().y][(int)player.getPos().x] = PLAYER;


		// mapDataとmapBufの比較
		for (int i = 0; i < mHeight; i++) {
			for (int j = 0; j < mWidth; j++) {
				if (mapData[i][j] != mapBuf[i][j])
					break;
				mdiff++;
			}
		}

		// map情報に変化があれば画面描画
		if (mdiff != mWidth*mHeight) {
			//mapBufをmapDataに転送
			memcpy(mapData, mapBuf,sizeof(mapBuf));
			
			// コンソール画面の消去
			CLS;

			//MAPの表示
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 20; j++) {
					switch (mapData[i][j]) {
					case NONE:
						cout << " ";
						break;
					case WALL:
						cout << "ﾛ";
						break;
					case PLAYER:
						cout << "P";
						break;
					case ENEMY:
						cout << "E";
						break;
					}
				}
				cout << endl;
			}
		}
	}
}