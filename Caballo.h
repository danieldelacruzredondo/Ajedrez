#pragma once
#include "VPosicion.h"
class Caballo
{
	Caballo();
	~Caballo();
	bool color; //0 si es blanca y 1 si es negra
	VPosicion posicion;

	VPosicion getPosicion();
	void movimiento(float x, float y);
	void comer(float x, float y, char);
	void comido(float x, float y, char);
	void dibuja();
};
