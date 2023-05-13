#include"freeglut.h"
#include <math.h>

void Alfil::dibuja()
{

    if (color)
        sprite = { "bin/imagenes/alfil_negras.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };
    else
        sprite = { "bin/imagenes/alfil_blancas.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}


bool Alfil::movimiento(VPosicion* fin)
{
    int i, j;

    

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
