#include"Torre.h"

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



bool Torre::mueve(VPosicion fin)
{
    float i;

     // MOVIMIENTO DERECHA 
    if (pos.x < fin.x && pos.y == fin.y)
    {
        for (i = 0; i <= fin.x; i += 2)
        {
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 + i,pos.y }) < 32 && VPosicion{ pos.x + 2 + i, pos.y } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 + i,pos.y }) < 32 && VPosicion{ pos.x + 2 + i, pos.y } != fin)return false;
            //Comprobar si puede moverse a la casilla
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
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2 + i,pos.y }) < 32 && VPosicion{ pos.x - 2 + i, pos.y } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2 + i,pos.y }) < 32 && VPosicion{ pos.x - 2 + i, pos.y } != fin)return false;
            //Comprobar si se puede mover a la casilla
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
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y + 2 + i }) < 32 && VPosicion{ pos.x, pos.y + 2 + i } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y + 2 + i }) < 32 && VPosicion{ pos.x, pos.y + 2 + i } != fin)return false;
            //Comprobar si se puede mover a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y + 2 + i }) == 32 && fin == VPosicion{ pos.x, pos.y + 2 + i })
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
            // COMPROBAR SI LA FICHA COME PIEZA.
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y - 2 + i }) < 32 && VPosicion{ pos.x,pos.y - 2 + i } == fin)
            {
                if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
            //Comprobar si la casilla está ocupada
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y - 2 + i }) < 32 && VPosicion{ pos.x,pos.y - 2 + i } != fin)return false;
            //Comprobar si se puede mover a la casilla
            if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y - 2 + i }) == 32 && fin == VPosicion{ pos.x,pos.y - 2 + i })
            {
                pos = fin;
                return true;
            }
        }
        return false;
    }

    else return false;
}
