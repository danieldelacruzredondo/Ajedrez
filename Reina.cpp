#include"Reina.h"
#include"freeglut.h"
#include <math.h>

void Reina::dibuja()
{

    if (color)
        sprite = { "bin/imagenes/reina_negras.png", pos.x + 0.05f, pos.y + 0.075f , 11, 3.5 };
    else
        sprite = { "bin/imagenes/reina_blancas.png", pos.x + 0.05f, pos.y + 0.12f , 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}


bool Reina::movimiento(VPosicion* fin)
{
    int i, j;

    //MOVIMIENTO DERECHA 
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

    //MOVIMIENTO ABAJO  
    if (pos.x == fin->x && pos.y > fin->y)
    {
        for (i = pos.y - 2; i >= fin->y; i--)
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

    //MOVIMIENTO IZQUIERDA HACIA ABAJO 
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
