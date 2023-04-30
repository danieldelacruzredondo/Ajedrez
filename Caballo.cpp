#include"Caballo.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite spritec{ "bin/imagenes/caballo_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Caballo::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Caballo::setcolor(bool _color)
{
	color = _color;
}

void Caballo::dibuja()
{

	if (color)
		spritec = { "bin/imagenes/caballo_negras.png", pos.x , pos.y - 0.1f, 11, 3.5 };
	else
		spritec = { "bin/imagenes/caballo_blancas.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritec.draw();
	glPopMatrix();
}

VPosicion getpos();

bool Caballo::movimiento(VPosicion* fin)
{
  
    caballo.getpos();

    //EL CABALLO SE MUEVE EN L, 2 posiciones y despues 1

    //MOVIMIENTO DERECHA  
    if (pos.x + 3 == fin->x)
    {
        // movimiento arriba
        if (pos.y + 2 == fin->y) return true;
        // movimiento abajo
        if (pos.y - 2 == fin->y)return true;
    }

    //MOVIMIENTO IZQUIERDA
    if (pos.x - 3 == fin->x)
    {
        // movimiento arriba
        if (pos.y + 2 == fin->y)return true;
        // movimiento abajo
        if (pos.y - 2 == fin->y)return true;
    }

    //MOVIMIENTO ARRIBA   
    if (pos.y + 3 == fin->y)
    {
        // movimiento derecha
        if (pos.x + 2 == fin->x)return true;
        // movimiento izquierda
        if (pos.x - 2 == fin->x)return true;
    }

    // MOVIMIENTO ABAJO 
    if (pos.y - 3 == fin->y)
    {
        // movimiento derecha
        if (pos.x + 2 == fin->x)return true;
        // movimiento izquierda
        if (pos.x - 2 == fin->x)return true;
    }

    return false;
}
