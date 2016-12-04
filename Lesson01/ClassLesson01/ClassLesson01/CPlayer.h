#pragma once
#include "CChara.h"

class CPlayer :	public CChara {
private:

public:
	void moveX(float);
	void damage(int);
};
