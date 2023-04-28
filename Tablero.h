#pragma once
#include"VPosicion.h"
#include"Reina.h"
#include"Rey.h"
#include"Alfil.h"
#include"Caballo.h"
#include"Torre.h"

class Tablero
{
public:

	Reina reina;
	Rey rey;
	Alfil alfil01,alfil02,alfil11,alfil12;
	Caballo caballo01, caballo02, caballo11, caballo12;
	Torre torre01, torre02, torre11, torre12;

	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;
	int r, g, b;
	Tablero();
	void pintar();
	void inicializar();
};
