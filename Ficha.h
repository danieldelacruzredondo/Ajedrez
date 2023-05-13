#pragma once
#include "VPosicion.h"
#include "ETSIDI.h"
#define numFichas=32

class Ficha
{
protected:
	VPosicion pos;
	bool color;
	ETSIDI::Sprite sprite{ "bin/imagenes/rey_negras.png", 0.0, 0.0, 0.0, 0.0 };

public:
	virtual ~Ficha() {};
	virtual void mueve();
	virtual void destruyeficha();
	
};
