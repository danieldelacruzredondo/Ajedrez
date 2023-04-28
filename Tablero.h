#pragma once
#include"Reina.h"
#include"Rey.h"
#include"Alfil.h"
#include"VPosicion.h"

class Tablero
{
public:

	Reina reina;
	Rey rey;
	Alfil alfil11,alfil12,alfil21,alfil22;

	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;
	int r, g, b;
	Tablero();
	void pintar();
	void inicializar();
};
