#include"Reina.h"
#include"freeglut.h"
#include <math.h>
#include "ListaFichas.h"

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


bool Reina::mueve(VPosicion fin)
{
    float i, j;

    //MOVIMIENTO DERECHA 
    if (pos.x < fin.x && pos.y == fin.y)
    {
        for (i = 0; i <= fin.x; i += 2)
        {
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 + i,pos.y }) < 32)return false;
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 + i,pos.y }) == 32 && fin == VPosicion{ pos.x + 2 + i,pos.y })
            {
                pos = fin;
                return true;
            }
        }
        return false;
    }

    //MOVIMIENTO IZQUIERDA  
    if (pos.x > fin.x && pos.y == fin.y)
    {
        for (i = 0; i <= fin.x; i -= 2)
        {
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2 + i,pos.y }) < 32)return false;
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2 + i,pos.y }) == 32 && fin == VPosicion{ pos.x - 2 + i, pos.y })
            {
                pos = fin;
                return true;
            }
            
        }
        return false;
    }
        //MOVIMIENTO ARRIBA  
        if (pos.x == fin.x && pos.y < fin.y)
        {
            for (i = 0; i <= fin.y; i += 2)
            {
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y + 2 + i }) < 32)return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y + 2 + i }) == 32 && fin == VPosicion{ pos.x,pos.y + 2 + i })
                {
                    pos = fin;
                    return true;
                }
            }
            return false;
        }

        //MOVIMIENTO ABAJO  
        if (pos.x == fin.x && pos.y > fin.y)
        {
            for (i = 0; i <= fin.y; i -= 2)
            {
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y - 2 + i }) < 32)return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y - 2 + i }) == 32 && fin == VPosicion{ pos.x,pos.y - 2 + i })
                {
                    pos = fin;
                    return true;
                }
            }
            return false;
        }

        //Comprobar si el movimiento es diagonal
        if (abs(fin.x - pos.x) != abs(fin.y - pos.y)) return false; //no es diagonal

        //MOVIMIENTO DERECHA HACIA ARRIBA
        if (pos.x < fin.x && pos.y < fin.y)
        {
            for (i = pos.x + 2, j = pos.y + 2; i <= fin.x && j <= fin.y; i += 2, j += 2)
            {
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) < 32) return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) == 32 && fin == VPosicion{ (i),(j) })
                {
                    pos = fin;
                    return true;
                }

            }
            return false;
        }

        //MOVIMIENTO IZQUIERDA HACIA ARRIBA
        if (pos.x > fin.x && pos.y < fin.y)
        {
            for (i = pos.x - 2, j = pos.y + 2; i >= fin.x && j <= fin.y; i -= 2, j += 2)
            {
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) < 32)return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) == 32 && fin == VPosicion{ (i),(j) })
                {
                    pos = fin;
                    return true;
                }


            }
            return false;
        }

        //MOVIMIENTO DERECHA HACIA ABAJO 
        if (pos.x < fin.x && pos.y > fin.y)
        {
            for (i = pos.x + 2, j = pos.y - 2; i <= fin.x && j >= fin.y; i += 2, j -= 2)
            {
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) < 32)return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) == 32 && fin == VPosicion{ (i),(j) })
                {
                    pos = fin;
                    return true;
                }

            }
            return false;
        }

        //MOVIMIENTO IZQUIERDA HACIA ABAJO 
        if (pos.x > fin.x && pos.y > fin.y)
        {
            for (i = pos.x - 2, j = pos.y - 2; i >= fin.x && j >= fin.y; i -= 2, j -= 2)
            {
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) < 32)return false;
                //Comprobar si la casilla está ocupada
                if (ListaFichas::Comprobar_Posicion(VPosicion{ (i),(j) }) == 32 && fin == VPosicion{ (i),(j) })
                {
                    pos = fin;
                    return true;
                }

            }
            return false;
        }

        else return false;
}
