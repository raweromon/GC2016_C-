/*�@CChara�N���X: 2016/11/21 */
#pragma once
#include <d3d.h>

class CChara {
protected:
	D3DVECTOR pos;
	int str;

public:
	//�֐��̃v���g�^�C�v�錾
	CChara();
	void setPos(D3DVECTOR);
	D3DVECTOR getPos(void);

	void setStr(int damage) {
		str = damage;
	};

	int getStr(void) {
		return str;
	};
};
