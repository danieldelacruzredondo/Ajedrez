#include"Reina.h"
#include"freeglut.h"
#include"ETSIDI.h"
#include <math.h>

ETSIDI::Sprite spriteq{ "bin/imagenes/reina_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Reina::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Reina::setcolor(bool _color)
{
	color = _color;
}

void Reina::dibuja()
{

	if (color)
		spriteq = { "bin/imagenes/reina_negras.png", pos.x + 0.05f, pos.y + 0.075f , 11, 3.5 };
	else
		spriteq = { "bin/imagenes/reina_blancas.png", pos.x + 0.05f, pos.y + 0.12f , 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spriteq.draw();
	glPopMatrix();
}

VPosicion Reina::getpos() { return pos; }

bool Reina::movimiento(VPosicion* fin)
{
    int i, j;

    reina.getpos();

    //MOVIMIENTO DERECHA 
    if (pos.x < fin->x && pos.y == fin->y)
    {
        for (i = pos.x + 1; i <= fin->x; i++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO IZQUIERDA  
    if (pos.x > fin->x && pos.y == fin->y)
    {
        for (i = pos.x - 1; i >= fin->x; i--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO ARRIBA  
    if (pos.x == fin->x && pos.y < fin->y)
    {
        for (i = pos.y + 1; i <= fin->y; i++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO ABAJO  
    if (pos.x == fin->x && pos.y > fin->y)
    {
        for (i = pos.y - 1; i >= fin->y; i--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //Comprobar si el movimiento es diagonal
    if (abs(fin->x - pos.x) != abs(fin->y - pos.y)) return false; //no es diagonal

    //MOVIMIENTO DERECHA HACIA ARRIBA
    if (pos.x < fin->x && pos.y < fin->y)
    {
        for (i = pos.x + 1, j = pos.y + 1; i <= fin->x && j <= fin->y; i++, j++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO IZQUIERDA HACIA ARRIBA
    if (pos.x > fin->x && pos.y < fin->y)
    {
        for (i = pos.x - 1, j = pos.y + 1; i >= fin->x && j <= fin->y; i--, j++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO DERECHA HACIA ABAJO 
    if (pos.x < fin->x && pos.y > fin->y)
    {
        for (i = pos.x + 1, j = pos.y - 1; i <= fin->x && j >= fin->y; i++, j--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO IZQUIERDA HACIA ABAJO 
    if (pos.x > fin->x && pos.y > fin->y)
    {
        for (i = pos.x - 1, j = pos.y - 1; i >= fin->x && j >= fin->y; i--, j--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    else return false;
}
