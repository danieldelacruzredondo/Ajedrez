#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador()
{
	estado = INICIO;
	ETSIDI::playMusica("bin/sonidos/sonidos_Intro.mp3");
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
						ETSIDI::play("bin/sonidos/Fondo2.mp3");
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
		if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tablero.ElegirCasilla(b, state, x, y);

			for (float j = 17.5f; j < 19.0f; j = j + 0.5f)
			{
				for (float i = 25.5f; i < 28.0f; i = i + 0.5f)
				{
					if (_x < i + 0.5f && i < _x && _y < j + 0.5f && j < _y)
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
	else if (estado == SALIR)
	{
		exit(0);
	}
}

void Coordinador::dibujar()
{
	if (estado == INICIO)
	{
		gluLookAt(0.0, 7.5, 40.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("JUGAR", -3, 12.5);
		ETSIDI::printxy("SALIR", -3, 8);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("bin/fuentes/Tablero.ttf", 20);
		ETSIDI::printxy("Enrique Hernandez 54667", 11, -1);
		ETSIDI::printxy("Daniel de la Cruz 54938", 11, -2);
		ETSIDI::printxy("Alberto Escanciano 54946", 11, -3);
		ETSIDI::printxy("Lucia Pardo 55396", 11, -4);

	}
	else if (estado == JUEGO)
	{
		tablero.Pintar();
		
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("bin/fuentes/Tablero.ttf", 36);
		ETSIDI::printxy("A", 1, -1);
		ETSIDI::printxy("B", 3, -1);
		ETSIDI::printxy("C", 5, -1);
		ETSIDI::printxy("D", 7, -1);
		ETSIDI::printxy("E", 9, -1);
		ETSIDI::printxy("F", 11, -1);
		ETSIDI::printxy("G", 13, -1);
		ETSIDI::printxy("H", 15, -1);

		ETSIDI::printxy("A", 1, 16);
		ETSIDI::printxy("B", 3, 16);
		ETSIDI::printxy("C", 5, 16);
		ETSIDI::printxy("D", 7, 16);
		ETSIDI::printxy("E", 9, 16);
		ETSIDI::printxy("F", 11, 16);
		ETSIDI::printxy("G", 13, 16);
		ETSIDI::printxy("H", 15, 16);

		ETSIDI::printxy("1", -1, 0);
		ETSIDI::printxy("2", -1, 2);
		ETSIDI::printxy("3", -1, 4);
		ETSIDI::printxy("4", -1, 6);
		ETSIDI::printxy("5", -1, 8);
		ETSIDI::printxy("6", -1, 10);
		ETSIDI::printxy("7", -1, 12);
		ETSIDI::printxy("8", -1, 14);

		ETSIDI::printxy("1", 16, 0);
		ETSIDI::printxy("2", 16, 2);
		ETSIDI::printxy("3", 16, 4);
		ETSIDI::printxy("4", 16, 6);
		ETSIDI::printxy("5", 16, 8);
		ETSIDI::printxy("6", 16, 10);
		ETSIDI::printxy("7", 16, 12);
		ETSIDI::printxy("8", 16, 14);

		ETSIDI::Sprite sp("bin/imagenes/cerrar_programa.png", 26.0f, 17.8f, 1.0f, 1.0f);
		glPushMatrix();
		glTranslatef(0, 0, 0.002);
		sp.draw();
		glPopMatrix();
	}
}
