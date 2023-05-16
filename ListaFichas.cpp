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

int ListaFichas::Comprobar_Posicion(VPosicion cas)
{
	for (int i = 0; i < NumMax; i++)
	{
		if (listafichas[i]->getpos() == cas) return i;
	}
	return (NumMax);
}

void ListaFichas::ElegirFicha(VPosicion cas)
{
	if (Comprobar_Posicion(cas) < NumMax)
	{
		casillafi = Comprobar_Posicion(cas);
	}
	else
	{
		if (casillafi < NumMax && listafichas[casillafi]->getcolor() == turno)
		{
			listafichas[casillafi]->mueve(cas);
			turno = turno - 1;
		}
	}
}
