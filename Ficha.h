#pragma once
#include "VPosicion.h"
#define numFichas=32

class Ficha
{
protected:
	VPosicion pos;
	bool color;

public:
	virtual ~Ficha() {};
	virtual void mueve();
	virtual void destruyeficha();
	
};
