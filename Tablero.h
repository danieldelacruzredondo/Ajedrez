#pragma once
#include"VPosicion.h"
#include"Reina.h"
#include"Rey.h"
#include"Alfil.h"
#include"Caballo.h"
#include"Torre.h"
#include"Peon.h"
#include"ListaPeones.h"

class Tablero
{
	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;
	int r, g, b;

	Reina reina0,reina1;
	Rey rey0,rey1;
	Alfil alfil01,alfil02,alfil11,alfil12;
	Caballo caballo01, caballo02, caballo11, caballo12;
	Torre torre01, torre02, torre11, torre12;
	ListaPeones peones;

public:

	VPosicion casilla;

	Tablero();
	void pintar();
	void inicializar();
	void elegirficha(int b, int state, int x, int y);
};
