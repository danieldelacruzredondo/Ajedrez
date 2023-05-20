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

bool Caballo::movimiento(VPosicion fin)
{

    //EL CABALLO SE MUEVE EN L, 2 posiciones y despues 1

    //MOVIMIENTO DERECHA 3 ARRIBA 1
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{pos.x+6,pos.y + 2}) < 32 )return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 6,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x + 6,pos.y + 2 })))
        {
          pos = fin;
          return true;
        }
    }

    //MOVIMIENTO DERECHA 1 ARRIBA 3
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{pos.x+2,pos.y + 6}) < 32 )return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 6 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y + 6 })))
        {
          pos = fin;
          return true;
        }
    }
    //MOVIMIENTO DERECHA 3 ABAJO 1
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 6,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 6,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x + 6,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO DERECHA 1 ABAJO 3
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 6 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 6 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y - 6 })))
        {
            pos = fin;
            return true;
        }
    }
    //MOVIMIENTO IZQUIERDA 1 ARRIBA 3
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 6 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 6 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y + 6 })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO IZQUIERDA 3 ARRIBA 1  
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 6,pos.y + 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 6,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x - 6,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    }

    // MOVIMIENTO IZQUIERDA 1 ABAJO 3 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 6 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 6 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y - 6 })))
        {
            pos = fin;
            return true;
        }
    }
    // MOVIMIENTO IZQUIERDA 3 ABAJO 1 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 6,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 6,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x - 6,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }

    else return false;
}
