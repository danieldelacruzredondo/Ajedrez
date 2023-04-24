#pragma once
#include "VPosicion.h"
class Rey
{
	Rey();
	~Rey();
	bool color; //0 si es blanca y 1 si es negra
	VPosicion posicion;

	VPosicion getPosicion();
	void movimiento(float x, float y);
	void comer(float x, float y, char);
	void dibuja();
	void enroque(float x, float y);
	void jaque(float x, float y);
	bool jaqueMate();
};
