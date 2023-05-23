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
	void agregarQ(Ficha* _ficha,int n);
	void inicializar();
	void dibujar();
	int getnumero() { return numero; }
	void ElegirFicha(VPosicion cas);
	static int Comprobar_Posicion(VPosicion cas);
	static bool Comprobar_Color(int num);
	static void Matar(int num);
	static bool Enroque_Corto(VPosicion enrc);
	static bool Enroque_Largo(VPosicion enrl);
	static bool Comer_al_paso1(VPosicion cap);
	static bool Comer_al_paso2(VPosicion cap);
	static bool JAQUE_AL_REY(VPosicion _cas);
};
