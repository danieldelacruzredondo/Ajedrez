#include"Peon.h"
#include"freeglut.h"
void Peon::dibuja()
{

	if (color)
		sprite = { "bin/imagenes/peon_negras.png", pos.x + 0.57f, pos.y - 0.1f, 11, 3.5 };
	else
		sprite = { "bin/imagenes/peon_blancas.png", pos.x + 0.67f, pos.y - 0.23f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	sprite.draw();
	glPopMatrix();
}

bool Peon::movimiento(VPosicion* fin)
{
	int i;

	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha / izquierda en caso de haber una pieza negra
	if (color==0)
	{
		// MOVIMIENTO 1: máximo 2 casillas hacia delante 
		if (pos.y == 1 && (fin->y == pos.y + 2 || fin->y == pos.y + 3) && fin->x == pos.x)
		{
			//bucle para comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
			for (i = pos.y + 2; i <= fin->y; i++)
			{
				//Comprobar si la casilla está ocupada
			}
			return true;
		}

		// SIGUIENTES MOVIMIENTOS: una casilla hacia delante
		if (fin->y == pos.y + 2 && fin->x == pos.x)
		{
			//Comprobar si la casilla está ocupada
		}

		// COMER PIEZAS NEGRAS: en diagonal un único desplazamiento
		if (fin->y == pos.y + 2 && (fin->x == pos.x + 2 || fin->x == pos.x - 2) /*&&  Ha detectado una pieza negra */)
		{
			return true;
		}
	}

	//Los peones negros solo se mueven hacia abajo y diagonales de abaj derecha / izquierda
	else
	{
		// MOVIMIENTO 1: máximo 2 casillas hacia delante 
		if (pos.y == 15 && (fin->y == pos.y - 2 || fin->y == pos.y - 3) && fin->x == pos.x)
		{
			//bucle para comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
			for (i = pos.y - 2; i >= fin->y; i--)
			{
				//Comprobar si la casilla está ocupada
			}
			return true;
		}

		// SIGUIENTES MOVIMIENTOS: una casilla hacia delante
		if (fin->y == pos.y - 2 && fin->x == pos.x)
		{
			//Comprobar si la casilla está ocupada
		}

		// COMER PIEZAS NEGRAS: en diagonal un único desplazamiento
		if (fin->y == pos.y - 2 && (fin->x == pos.x + 2 || fin->x == pos.x - 2)/* &&  Ha detectado una pieza negra */)
		{
			return true;
		}

	}
}
