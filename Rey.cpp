#include"Rey.h"

void Rey::dibuja()
{

    if (color)
        sprite = { "bin/imagenes/rey_negras.png", pos.x + 0.32f, pos.y - 0.1f, 11, 3.5 };
    else
        sprite = { "bin/imagenes/rey_blancas.png", pos.x + 0.2f, pos.y - 0.12f, 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}


bool Rey::movimiento(VPosicion* fin)
{
    int i, j;

   //MOVIMIENTO DERECHA 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO ARRIBA 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y + 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x ,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    }
    //MOVIMIENTO ABAJO 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x ,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }
    //MOVIMIENTO IZQUIERDA 
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ARRIBA DERECHA
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    }
    

    //MOVIMIENTO DIAGONAL ARRIBA IZQUIERDA
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ABAJO DERECHA
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }
    //MOVIMIENTO DIAGONAL ABAJO IZQUIERDA
    if (pos.x < fin.x && pos.y < fin.y)
    {
        // movimiento arriba
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 2 }) < 32)return false;
        // movimiento abajo
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    }

    else return false;

}
