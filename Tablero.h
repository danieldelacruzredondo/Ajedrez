#pragma once
#include"VPosicion.h"
#include"Reina.h"
#include"Rey.h"
#include"Alfil.h"
#include"Caballo.h"
#include"Torre.h"
#include"Peon.h"
#include"ListaFichas.h"

class Tablero
{
	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;
	int r, g, b;

	ListaFichas listafichas;

public:

	VPosicion casilla;

	Tablero();
	void pintar();
	void inicializar();
	void elegirficha(int b, int state, int x, int y);
};
