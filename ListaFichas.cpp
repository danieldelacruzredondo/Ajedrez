#include "ListaFichas.h"
#include "Ficha.h"

void ListaFichas::agregar(Ficha* _ficha)
{
	if (numero < NumMax)
	{
		listafichas[numero++] = _ficha;
	}
}

void ListaFichas::inicializa()
{
	float j = 1;
	for (int i = 0; i < NumMax; i++)
	{
		if(i<8) listafichas[i]->inicializa(VPosicion{ j,1 }, false);
		if (i == 8)j = 1;
		if(i > 7 && i < 16)listafichas[i]->inicializa(VPosicion{ j,3 }, false);
		if (i == 16)j = 1;
		if (i > 15 && i < 24)listafichas[i]->inicializa(VPosicion{ j,13 }, true);
		if (i == 24)j = 1;
		if (i > 23)listafichas[i]->inicializa(VPosicion{ j,15 }, true);
		j += 2;
	}
}

void ListaFichas::dibuja()
{
	for (int i = 0; i < NumMax; i++)
	{
		listafichas[i]->dibuja();
	}
}
