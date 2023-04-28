#pragma once
#define MAX_PEONES 8

class Peon;

class ListaPeones
{
	Peon* lista0[MAX_PEONES]{};
	Peon* lista1[MAX_PEONES]{};
	int numero0 = 0, numero1 = 0;
public:
	void agregar(Peon* aux1,Peon* aux2);
	void inicializa();
	void dibuja();
};
