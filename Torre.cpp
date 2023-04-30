#include"Torre.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite spritet{ "bin/imagenes/torre_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Torre::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Torre::setcolor(bool _color)
{
	color = _color;
}

void Torre::dibuja()
{

	if (color)
		spritet = { "bin/imagenes/torre_negras.png", pos.x, pos.y - 0.1f, 11, 3.5 };
	else
		spritet = { "bin/imagenes/torre_blancas.png", pos.x, pos.y - 0.2f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritet.draw();
	glPopMatrix();
}

VPosicion Torre::getpos() { return pos; }

bool Torre::movimiento(VPosicion* fin)
{
    int i;

    // Obtener posición pieza
    torre.getpos();

    // MOVIMIENTO DERECHA
    if (pos.x < fin->x && pos.y == fin->y)
    {
        for (i = pos.x + 2; i <= fin->x; i++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO IZQUIERDA
    if (pos.x > fin->x && pos.y == fin->y)
    {
        for (i = pos.x - 2; i >= fin->x; i--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO ARRIBA 
    if (pos.x == fin->x && pos.y < fin->y)
    {
        for (i = pos.y + 2; i <= fin->y; i++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    // MOVIMIENTO ABAJO
    if (pos.x == fin->x && pos.y > fin->y)
    {
        for (i = pos.y - 2; i >= fin->y; i--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    else return false;
}
