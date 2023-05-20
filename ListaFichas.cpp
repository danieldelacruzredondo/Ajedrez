#include "ListaFichas.h"
#include "Ficha.h"

void ListaFichas::agregar(Ficha* _ficha)
{
	if (numero < NumMax)
	{
		listafichas[numero++] = _ficha;
	}
}

void ListaFichas::inicializar()
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

void ListaFichas::dibujar()
{
	for (int i = 0; i < NumMax; i++)
	{
		if(listafichas[i]->getvida())
		listafichas[i]->dibuja();
	}
	if (casillafi < NumMax)
	{
		listafichas[casillafi]->getpos();
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
	if (Comprobar_Posicion(cas) < NumMax && listafichas[Comprobar_Posicion(cas)]->getcolor() == turno)
	{
		casillafi = Comprobar_Posicion(cas);
	}
	if (casillafi < NumMax)
	{
			if (listafichas[casillafi]->mueve(cas))
			{
				turno = turno - 1;
				casillafi = NumMax;
			}
	}
	
}

bool ListaFichas::Comprobar_Color(int num)
{
	int i = num;
	return listafichas[i]->getcolor();
}

void ListaFichas::Matar(int num)
{
	int i = num;
	listafichas[i]->morir();
	listafichas[i]->setmorir();
}
