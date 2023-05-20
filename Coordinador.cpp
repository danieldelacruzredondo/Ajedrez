#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador()
{
	estado = INICIO;
	ETSIDI::playMusica("bin/sonidos/Intro.mp3");
}

void Coordinador::Elegir_modo_juego(int b, int state, int x, int y)
{
	if (estado == INICIO)
	{

		if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			ETSIDI::stopMusica();
			tablero.Inicializar();
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO)
	{
		ETSIDI::playMusica("bin/sonidos/Fondo.mp3");
		if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tablero.ElegirCasilla(b, state, x, y);
		}
	}

}

void Coordinador::dibujar()
{
	if (estado == INICIO)
	{
		gluLookAt(0.0, 0.0, 0.0,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("JUGAR", 5, 8);

	}
	else if (estado == JUEGO)
	{
		tablero.Pintar();
	}
}
