#pragma once
#include "Ficha.h"
#define NumMax 32

class VPosicion;

static Ficha* listafichas[NumMax];

class ListaFichas
{
	int numero = 0;
	int casillafi = NumMax;
	bool turno = false;
	
public:
	
	void agregar(Ficha* _ficha);
	void inicializar();
	void dibujar();
	int getnumero() { return numero; }
	static int Comprobar_Posicion(VPosicion cas);
	void ElegirFicha(VPosicion cas);
	//bool DestruirFicha(VPosicion finfi);
	//void PintarCasilla(int _cas);

	friend class Ficha;
};
