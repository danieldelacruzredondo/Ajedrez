#pragma once
#include "Ficha.h"
#define NumMax 32

class VPosicion;

class ListaFichas
{
	Ficha* listafichas[NumMax]{};
	int numero = 0;
public:
	void agregar(Ficha* _ficha);
	void inicializa();
	void dibuja();
	int getnumero() { return numero; }
};
