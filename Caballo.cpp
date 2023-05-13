#include"Caballo.h"
#include"freeglut.h"

void Caballo::dibuja()
{

    if (color)
        sprite = { "bin/imagenes/caballo_negras.png", pos.x , pos.y - 0.1f, 11, 3.5 };
    else
        sprite = { "bin/imagenes/caballo_blancas.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}

bool Caballo::movimiento(VPosicion* fin)
{

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
