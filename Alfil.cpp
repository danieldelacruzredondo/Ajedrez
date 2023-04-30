#include"Alfil.h"
#include"freeglut.h"
#include"ETSIDI.h"
#include <math.h>

//ETSIDI_API Sprite(const char *texturePath, float x=0, float y=0, float width=-1, float height=-1);
//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite sprite1{ "bin/imagenes/alfil_negras.png", 0.0, 0.0, 0.0, 0.0};

void Alfil::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Alfil::setcolor(bool _color)
{
	color = _color;
}

void Alfil::dibuja()
{
	
	if (color)
		sprite1 = {"bin/imagenes/alfil_negras.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };
	else
		sprite1 = {"bin/imagenes/alfil_blancas.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };
	
	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	sprite1.draw();
	glPopMatrix();
}

VPosicion Alfil::getpos() { return pos; }

bool Alfil::movimiento(VPosicion* fin) 
{
    int i, j;

    alfil.getpos();

    // Si no está en la diagonal
    if (fabs(fin->x - pos.x) != fabs(fin->y - pos.y)) return false;

    //MOVIMIENTO DERECHA HACIA ARRIBA
    if (pos.x < fin->x && pos.y < fin->y)
    {
        for (i = pos.x + 2, j = pos.y + 2; i <= fin->x && j <= fin->y; i++, j++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO IZQUIERDA HACIA ARRIBA    
    if (pos.x > fin->x && pos.y < fin->y)
    {
        for (i = pos.x - 2, j = pos.y + 2; i >= fin->x && j <= fin->y; i--, j++)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    //MOVIMIENTO DERECHA HACIA ABAJO
    if (pos.x < fin->x && pos.y > fin->y)
    {
        for (i = pos.x + 2, j = pos.y - 2; i <= fin->x && j >= fin->y; i++, j--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    // MOVIMIENTO IZQUIERDA HACIA ABAJO 
    if (pos.x > fin->x && pos.y > fin->y)
    {
        for (i = pos.x - 2, j = pos.y - 2; i >= fin->x && j >= fin->y; i--, j--)
        {
            //Comprobar si la casilla está ocupada
        }
        return true;
    }

    else return false;
}
