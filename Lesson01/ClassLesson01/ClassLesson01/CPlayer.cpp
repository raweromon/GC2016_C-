#include "CPlayer.h"
#include <d3d.h>

void CPlayer::moveX(float posX) {
	this->pos.x += posX;
}

void CPlayer::damage(int hit) {
	this->str -= hit;
}
