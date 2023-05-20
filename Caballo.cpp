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

    //MOVIMIENTO DERECHA 2 ARRIBA 1
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{pos.x+4,pos.y + 2}) < 32 )return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x + 4,pos.y + 2 })))
        {
          pos = fin;
          return true;
        }
    }

    //MOVIMIENTO DERECHA 1 ARRIBA 2
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{pos.x+2,pos.y + 4}) < 32 )return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 4 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y + 4 })))
        {
          pos = fin;
          return true;
        }
    }
    //MOVIMIENTO DERECHA 2 ABAJO 1
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x + 4,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO DERECHA 1 ABAJO 2
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 4 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 4 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y - 4 })))
        {
            pos = fin;
            return true;
        }
    }
    //MOVIMIENTO IZQUIERDA 1 ARRIBA 2
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 4 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 4 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y + 4 })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO IZQUIERDA 2 ARRIBA 1  
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y + 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x - 4,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    }

    // MOVIMIENTO IZQUIERDA 1 ABAJO 2 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 4 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 4 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y - 4 })))
        {
            pos = fin;
            return true;
        }
    }
    // MOVIMIENTO IZQUIERDA 2 ABAJO 1 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x - 4,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }

    else return false;
}
