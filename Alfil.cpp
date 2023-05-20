#include "Alfil.h"

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


bool Alfil::mueve(VPosicion fin)
{
    float i, j;

    // Si no está en la diagonal
    if (fabs(fin.x - pos.x) != fabs(fin.y - pos.y)) return false;

    //MOVIMIENTO DERECHA HACIA ARRIBA
    if (pos.x < fin.x && pos.y < fin.y)
    {
        for (i = 0, j = 0; i <= fin.x && j <= fin.y; i += 2, j += 2)
        {
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) }) < 32 && VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) }) < 32 && VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) } != fin)return false;
            //Comprobar si se puede mover a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) }) == 32 && fin == VPosicion{ (pos.x + 2 + i),(pos.y + 2 + j) })
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
        for (i = 0, j = 0; i <= fin.x && j <= fin.y; i -= 2, j += 2)
        {
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) }) < 32 && VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) }) < 32 && VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) } != fin)return false;
            //Comprobar si se puede move a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) }) == 32 && fin == VPosicion{ (pos.x - 2 + i),(pos.y + 2 + j) })
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
        for (i = 0, j = 0; i <= fin.x && j <= fin.y; i += 2, j -= 2)
        {
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) }) < 32 && VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) }) < 32 && VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) } != fin)return false;
            //Comprobar si se puede move a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) }) == 32 && fin == VPosicion{ (pos.x + 2 + i),(pos.y - 2 + j) })
            {
                pos = fin;
                return true;
            }

        }
        return false;
    }

    // MOVIMIENTO IZQUIERDA HACIA ABAJO 
    if (pos.x > fin.x && pos.y > fin.y)
    {
        for (i = 0, j = 0; i <= fin.x && j <= fin.y; i -= 2, j -= 2)
        {
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) }) < 32 && VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) }) < 32 && VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) } != fin)return false;
            //Comprobar si se puede move a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) }) == 32 && fin == VPosicion{ (pos.x - 2 + i),(pos.y - 2 + j) })
            {
                pos = fin;
                return true;
            }

        }
        return false;
    }


    else return false;
}
