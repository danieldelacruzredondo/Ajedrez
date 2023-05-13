#include"Torre.h"
#include"freeglut.h"

void Torre::dibuja()
{

    if (color)
        sprite = { "bin/imagenes/torre_negras.png", pos.x, pos.y - 0.1f, 11, 3.5 };
    else
        sprite = { "bin/imagenes/torre_blancas.png", pos.x, pos.y - 0.2f, 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}



bool Torre::movimiento(VPosicion* fin)
{
    int i;

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
