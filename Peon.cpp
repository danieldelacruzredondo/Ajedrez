#include"Peon.h"

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

	if (pintar) {
		glPushMatrix();
		glColor3ub(25, 150, 100);
		glBegin(GL_POLYGON);
		glVertex3f(pos.x + 1, pos.y + 1, 0.001f);
		glVertex3f(pos.x + 1, pos.y - 1, 0.001f);
		glVertex3f(pos.x - 1, pos.y - 1, 0.001f);
		glVertex3f(pos.x - 1, pos.y + 1, 0.001f);
		glEnd();
		glPopMatrix();
	}
}

bool Peon::mueve(VPosicion fin)
{

	// los peones blancos solo se mueven hacia arriba
	if (color == 0)
	{
		// SOLO SE VA A MOVER EL PEON.
		if (ListaFichas::Comprobar_Posicion(VPosicion{ fin }) == 32 && (fin == VPosicion{ pos.x, pos.y + 2 }) || (fin == VPosicion{ pos.x, pos.y + 4 }))
		{
			// MOVIMIENTO 1: máximo 2 casillas hacia delante 
			if (pos.y == 3 && (fin.y == pos.y + 2 || fin.y == pos.y + 4) && fin.x == pos.x)
			{
				//comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y + 2) }) < 32)return false;
				//Movimiento del peon si se ha elegido mover 2 casillas.
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y + 4) }) == 32 && fin == VPosicion{ pos.x,pos.y + 4 })
				{
					pos = fin;
					pintar -= 1;
					contmov++;
					return true;
				}
			}
			// Movimientos del peon si se ha elegido mover una casilla.
			if (fin.y == pos.y + 2 && fin.x == pos.x)
			{
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y + 2) }) < 32)return false;
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
			else return false;
		}

		// COMPROBAMOS SI SE QUIERE COMER AL PASO
		if (fin.y == (pos.y + 2) && fin.x == (pos.x + 2) && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) < 32 && ListaFichas::Comprobar_Posicion(fin) == 32)
		{
			if (ListaFichas::Comer_al_paso1(VPosicion{ pos.x + 2,pos.y }))
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2, pos.y }));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}
		if (fin.y == (pos.y + 2) && fin.x == (pos.x - 2) && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) < 32 && ListaFichas::Comprobar_Posicion(fin) == 32)
		{
			if (ListaFichas::Comer_al_paso1(VPosicion{ pos.x - 2, pos.y }))
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2, pos.y }));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}

		// FICHA BLANCA COME PIEZA NEGRA EN DIAGONAL.
		if (fin.y == (pos.y + 2) && (fin.x == (pos.x + 2) || fin.x == (pos.x - 2)) && ListaFichas::Comprobar_Posicion(fin) < 32)
		{
			// COMPROBAMOS SI PUEDE COMERSE A UNA FICHA DE DIFERENTE COLOR
			if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) == true)
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}
		else return false;
	}
	//Los peones negros solo se mueven hacia abajo 
	else
	{
		// SOLO SE VA A MOVER EL PEON.
		if (ListaFichas::Comprobar_Posicion(VPosicion{ fin }) == 32 && (fin == VPosicion{ pos.x, pos.y - 2 }) || (fin == VPosicion{ pos.x, pos.y - 4 }))
		{
			// MOVIMIENTO 1: máximo 2 casillas hacia delante 
			if (pos.y == 13 && (fin.y == pos.y - 2 || fin.y == pos.y - 4) && fin.x == pos.x)
			{
				//comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y - 2) }) < 32)return false;
				// Movimiento del peon si se ha elegido mover 2 casillas.
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y - 4) }) == 32 && VPosicion{ pos.x,pos.y - 4 } == fin)
				{
					pos = fin;
					pintar -= 1;
					contmov++;
					return true;
				}
			}
			// Movimiento del peon si se ha elegido mover una casilla.
			if (fin.y == pos.y - 2 && fin.x == pos.x)
			{
				if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y - 2) }) < 32)return false;
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
			else return false;
		}

		// COMPROBAMOS SI SE QUIERE COMER AL PASO
		if (fin.y == (pos.y - 2) && fin.x == (pos.x + 2) && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) < 32 && ListaFichas::Comprobar_Posicion(fin) == 32)
		{
			if (ListaFichas::Comer_al_paso2(VPosicion{ pos.x + 2,pos.y }))
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2, pos.y }));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}
		if (fin.y == (pos.y - 2) && fin.x == (pos.x - 2) && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) < 32 && ListaFichas::Comprobar_Posicion(fin) == 32)
		{
			if (ListaFichas::Comer_al_paso2(VPosicion{ pos.x - 2, pos.y }))
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2, pos.y }));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}

		// FICHA NEGRA COME PIEZA NEGRA EN DIAGONAL.
		if (fin.y == (pos.y - 2) && (fin.x == (pos.x + 2) || fin.x == (pos.x - 2)) && ListaFichas::Comprobar_Posicion(fin) < 32)
		{
			if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) == false)
			{
				ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
				pos = fin;
				pintar -= 1;
				contmov++;
				return true;
			}
		}
		else return false;
	}
}
