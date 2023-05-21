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
	float _x = (float)(x - 422) * 16 / 674;
	float _y = -(float)(y - 768) * 16 / 675;
	bool ce = FALSE;
	bool down = (state == GLUT_DOWN);

	if (estado == INICIO)
	{
		if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for (float j = 12.0f; j < 14.0f; j = j + 2.0f)
			{
				for (float i = 4.0f; i < 12.0f; i = i + 2.0f)
				{
					if (_x < i + 2.0f && i < _x && _y < j + 2.0f && j < _y)
					{
						ce = TRUE;
						ETSIDI::stopMusica();
						tablero.Inicializar();
						estado = JUEGO;
						break;
					}
				}
				if (ce == TRUE) break;
			}

			for (float j = 8.0f; j < 10.0f; j = j + 2.0f)
			{
				for (float i = 3.0f; i < 10.0f; i = i + 2.0f)
				{
					if (_x < i + 2.0f && i < _x && _y < j + 2.0f && j < _y)
					{
						ce = TRUE;
						estado = SALIR;
						break;
					}
				}
				if (ce == TRUE) break;
			}
		}
		
	}
	else if (estado == JUEGO)
	{
		ETSIDI::play("bin/sonidos/Fondo.mp3");
		if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tablero.ElegirCasilla(b, state, x, y);
		}
	}
	else if (estado == SALIR)
	{
		exit(0);
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
		ETSIDI::printxy("SALIR", -5, 8);

	}
	else if (estado == JUEGO)
	{
		tablero.Pintar();
	}
}
