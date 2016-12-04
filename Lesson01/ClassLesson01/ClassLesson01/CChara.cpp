/**/
#include "CChara.h"

CChara::CChara(){
	this->pos = {0.0f,0.0f ,0.0f };
	this->str = 20;
}

void CChara::setPos(D3DVECTOR pos) {
	this->pos = pos;
}

D3DVECTOR CChara::getPos(void) {
	return this->pos;
}