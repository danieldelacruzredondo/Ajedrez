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
}

bool Peon::movimiento(VPosicion* fin)
{
	// los peones blancos solo se mueven hacia arriba
	if (color == 0)
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
				return true;
			}
		}
		// Movimientos del peon si se ha elegido mover una casilla.
		if (fin.y == pos.y + 2 && fin.x == pos.x)
		{
			if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y + 2) }) < 32)return false;
			pos = fin;
			return true;
		}
		else return false;

		// COMER PIEZAS NEGRAS: en diagonal un único desplazamiento
		//if (fin.y == pos.y + 2 && (fin.x == pos.x + 2 || fin.x == pos.x - 2) && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,(pos.y + 2) })<32 && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,(pos.y + 2) }) < 32)
		{
			//return true;
		}
	}
	//Los peones negros solo se mueven hacia abajo 
	else
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
				return true;
			}
		}
		// Movimiento del peon si se ha elegido mover una casilla.
		if (fin.y == pos.y - 2 && fin.x == pos.x)
		{
			if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,(pos.y - 2) }) < 32)return false;
			pos = fin;
			return true;
		}
		else return false;

		// COMER PIEZAS NEGRAS: en diagonal un único desplazamiento
		//if (fin.y == pos.y - 2 && (fin.x == pos.x + 2 || fin.x == pos.x - 2)/* &&  Ha detectado una pieza negra */)
		{
			//return true;
		}
	}

}
