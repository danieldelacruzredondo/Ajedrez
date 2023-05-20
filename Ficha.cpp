#include "Ficha.h"

void Ficha::morir()
{
	ETSIDI::playMusica("bin/sonidos/Comer_pieza.mp3");
	delete this;
}
