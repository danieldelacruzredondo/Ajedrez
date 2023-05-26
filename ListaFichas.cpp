#include "ListaFichas.h"
#include "Ficha.h"

void ListaFichas::agregar(Ficha* _ficha)
{
	if (numero < NumMax)
	{
		listafichas[numero++] = _ficha;
	}
}

void ListaFichas::agregarQ(Ficha* _ficha, int n)
{
	listafichas[n] = _ficha;
}
void ListaFichas::inicializar()
{
	float j = 1;
	for (int i = 0; i < NumMax; i++)
	{
		if (i < 8) listafichas[i]->inicializa(VPosicion{ j,1 }, false);
		if (i == 8)j = 1;
		if (i > 7 && i < 16)listafichas[i]->inicializa(VPosicion{ j,3 }, false);
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
		if (listafichas[i]->getpos().y == 7 && turno == false)
			listafichas[i]->sumcontmov();
		if (listafichas[i]->getpos().y == 9 && turno == true)
			listafichas[i]->sumcontmov();
		if (listafichas[i]->getidentificador() == 'P' && listafichas[i]->getcolor() == true)
		{
			if (listafichas[i]->getpos().y == 1)
			{
				VPosicion p = listafichas[i]->getpos();
				delete listafichas[i];
				Reina* auxr = new Reina{};
				auxr->setidentificador('Q');
				auxr->setpos(p);
				auxr->setcolor(true);
				agregarQ(auxr, i);
			}
		}
		if (listafichas[i]->getidentificador() == 'P' && listafichas[i]->getcolor() == false)
		{
			if (listafichas[i]->getpos().y == 15)
			{
				VPosicion p = listafichas[i]->getpos();
				delete listafichas[i];
				Reina* auxr = new Reina{};
				auxr->setidentificador('Q');
				auxr->setpos(p);
				auxr->setcolor(false);
				agregarQ(auxr, i);
			}
		}
	}
	for (int i = 0; i < NumMax; i++)
	{
		if (listafichas[i]->getvida())
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
	if (Comprobar_Posicion(cas) < NumMax && listafichas[Comprobar_Posicion(cas)]->getcolor() == turno)
	{
		if (casillafi < 32) listafichas[casillafi]->setPintarCasilla();
		casillafi = Comprobar_Posicion(cas);
		ETSIDI::playMusica("bin/sonidos/sonidos_Seleccion_casilla.mp3");
		listafichas[Comprobar_Posicion(cas)]->setPintarCasilla();
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

bool ListaFichas::Enroque_Corto(VPosicion enrc)
{
	if (Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y })]->getidentificador() == 'R' && listafichas[Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y })]->getcontmov() == 0)
		{
			listafichas[Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y })]->setpos(VPosicion{ enrc.x + 2, enrc.y });
			//listafichas[Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y })]->sumcontmov();
			return true;
		}
	return false;
}

bool ListaFichas::Enroque_Largo(VPosicion enrl)
{
	if (Comprobar_Posicion(VPosicion{ enrl.x - 8, enrl.y }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ enrl.x - 8, enrl.y })]->getidentificador() == 'R' && listafichas[Comprobar_Posicion(VPosicion{ enrl.x - 8, enrl.y })]->getcontmov() == 0)
		{
			listafichas[Comprobar_Posicion(VPosicion{ enrl.x - 8, enrl.y })]->setpos(VPosicion{ enrl.x - 2, enrl.y });
			//listafichas[Comprobar_Posicion(VPosicion{ enrc.x + 6, enrc.y })]->sumcontmov();
			return true;
		}
	return false;
}

bool ListaFichas::Comer_al_paso1(VPosicion cap)
{
	if (Comprobar_Color(Comprobar_Posicion(cap)) && listafichas[Comprobar_Posicion(cap)]->getidentificador() == 'P' && listafichas[Comprobar_Posicion(cap)]->getcontmov() == 1 && listafichas[Comprobar_Posicion(cap)]->getpos().y == 9)
	{
		return true;
	}
	else return false;
}

bool ListaFichas::Comer_al_paso2(VPosicion cap)
{
	if (Comprobar_Color(Comprobar_Posicion(cap)) == false && listafichas[Comprobar_Posicion(cap)]->getidentificador() == 'P' && listafichas[Comprobar_Posicion(cap)]->getcontmov() == 1 && listafichas[Comprobar_Posicion(cap)]->getpos().y == 7)
	{
		return true;
	}
	else return false;
}

bool ListaFichas::JAQUE_AL_REY(VPosicion _cas)
{
	VPosicion p = _cas;
	bool comida = true;

	// SE COMPRUEBA POR LA DERECHA 
	for (int i = 0; i < 15 - p.x; i += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x + i + 2,p.y }) < 32)
		{
			if (i == 0)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + i + 2,p.y })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + i + 2,p.y })]->getidentificador() == 'R' || listafichas[Comprobar_Posicion(VPosicion{ p.x + i + 2,p.y })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR LA IZQUIERDA 
	for (int i = 0; i < p.x - 1; i += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x - i - 2,p.y }) < 32)
		{
			if (i == 0)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - i - 2, p.y })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - i - 2, p.y })]->getidentificador() == 'R' || listafichas[Comprobar_Posicion(VPosicion{ p.x - i - 2, p.y })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR ARRIBA 
	for (int i = 0; i < 15 - p.y; i += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x, p.y + 2 + i }) < 32)
		{
			if (i == 0)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y + 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y + 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y + i + 2 })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y + 2 + i })]->getidentificador() == 'R' || listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y + 2 + i })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR ABAJO
	for (int i = 0; i < p.y - 1; i += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x, p.y - 2 - i }) < 32)
		{
			if (i == 0)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y - 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y - 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y - i - 2 })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y - 2 - i })]->getidentificador() == 'R' || listafichas[Comprobar_Posicion(VPosicion{ p.x, p.y - 2 - i })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}

	// SE COMPRUEBA POR DIAGONAL DERECHA ARRIBA
	for (int i = 0, j = 0; i < 15 - p.x || j < 15 - p.y; i += 2, j += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y + 2 + i }) < 32)
		{
			if (i == 0)
			{
				if (turno == false)
				{
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 2 })]->getcolor() == true)
						if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 2 })]->getidentificador() == 'P')
						{
							comida = false;
							break;
						}
				}
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y + i + 2 })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y + 2 + i })]->getidentificador() == 'B' || listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y + 2 + i })]->getidentificador() == 'Q')comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR DIAGONAL DERECHA ABAJO
	for (int i = 0, j = 0; i < 15 - p.x || j < p.y - 1; i += 2, j += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y - 2 - i }) < 32)
		{
			if (i == 0)
			{
				if (turno == true)
				{
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 2 })]->getcolor() == false)
						if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 2 })]->getidentificador() == 'P')
						{
							comida = false;
							break;
						}
				}
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y - i - 2 })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y - 2 - i })]->getidentificador() == 'B' || listafichas[Comprobar_Posicion(VPosicion{ p.x + 2 + i, p.y - 2 - i })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR DIAGONAL IZQUIERDA ABAJO
	for (int i = 0, j = 0; i < p.x - 1 || j < p.y - 1; i += 2, j += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y - 2 - i }) < 32)
		{
			if (i == 0)
			{
				if (turno == true)
				{
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 2 })]->getcolor() == false)
						if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 2 })]->getidentificador() == 'P')
						{
							comida = false;
							break;
						}
				}
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			}
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y - i - 2 })]->getcolor() != turno)
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y - 2 - i })]->getidentificador() == 'B' || listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y - 2 - i })]->getidentificador() == 'Q') comida = false;
			break;
		}
	}
	// SE COMPRUEBA POR DIAGONAL IZQUIERDA ARRIBA
	for (int i = 0, j = 0; i < p.x - 1 || j < 15 - p.y; i += 2, j += 2)
	{
		if (Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y + 2 + i }) < 32)
		{
			if (i == 0)
			{
				if (turno == false)
				{
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 2 })]->getcolor() == true)
						if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 2 })]->getidentificador() == 'P')
						{
							comida = false;
							break;
						}
				}
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 2 })]->getidentificador() == 'K')
					{
						comida = false;
						break;
					}
			}
			if (Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y + 2 + i }) < 32)
			{
				if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y + i + 2 })]->getcolor() != turno)
					if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y + 2 + i })]->getidentificador() == 'B' || listafichas[Comprobar_Posicion(VPosicion{ p.x - 2 - i, p.y + 2 + i })]->getidentificador() == 'Q') comida = false;
				break;
			}
		}
	}

	// SE COMPRUEBA EN L PARA COMPROBAR SI UN CABALLO ATACA LA CASILLA
	if (Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 4 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 4 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y + 4 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 4 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 4 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y + 4 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 4 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 4 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 2, p.y - 4 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 4 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 4 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 2, p.y - 4 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x + 4, p.y + 2 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 4, p.y + 2 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 4, p.y + 2 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x + 4, p.y - 2 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 4, p.y - 2 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x + 4, p.y - 2 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x - 4, p.y - 2 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 4, p.y - 2 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 4, p.y - 2 })]->getidentificador() == 'H')comida = false;

	if (Comprobar_Posicion(VPosicion{ p.x - 4, p.y + 2 }) < 32)
		if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 4, p.y + 2 })]->getcolor() != turno)
			if (listafichas[Comprobar_Posicion(VPosicion{ p.x - 4, p.y + 2 })]->getidentificador() == 'H')comida = false;

	return comida;
}
