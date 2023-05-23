#include"Rey.h"
#include "ListaFichas.h"
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


bool Rey::mueve(VPosicion fin)
{
    // COMPROBAMOS SI SE QUIERE Y SI SE PUEDE REALIZAR UN ENROQUE CORTO.
    if (fin == VPosicion{ pos.x + 4,pos.y } && (pos.y == 1 || pos.y == 15) && contmov == 0)
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2, pos.y }) == 32 && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4, pos.y }) == 32)
            if (ListaFichas::Enroque_Corto(VPosicion{ pos.x, pos.y }))
             {
                pos = fin;
                contmov++;
                return true;
            }
    }

    // COMPROBAMOS SI SE QUIERE Y SE PUEDE REALIZAR UN ENROQUE LARGO.
    if (fin == VPosicion{ pos.x - 4,pos.y } && (pos.y == 1 || pos.y == 15) && contmov == 0)
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2, pos.y }) == 32 && ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4, pos.y }) == 32)
            if (ListaFichas::Enroque_Largo(VPosicion{ pos.x, pos.y }))
            {
                pos = fin;
                contmov++;
                return true;
            }
    }

    //MOVIMIENTO DERECHA 
    if (fin == (VPosicion{ pos.x + 2,pos.y }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x + 2,pos.y }))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO IZQUIERDA 
    if (fin == (VPosicion{ pos.x - 2,pos.y }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x - 2,pos.y }))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO ARRIBA 
    if (fin == (VPosicion{ pos.x ,pos.y + 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y + 2}) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x, pos.y + 2 })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x, pos.y + 2}))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO ABAJO 
    if (fin == (VPosicion{ pos.x ,pos.y - 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x,pos.y - 2 }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y - 2})) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x ,pos.y - 2}))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                        pos = fin;
                        return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ARRIBA DERECHA
    if (fin == (VPosicion{ pos.x + 2,pos.y + 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 2}) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 2})) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x + 2,pos.y + 2}))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                        pos = fin;
                        return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ARRIBA IZQUIERDA
    if (fin == (VPosicion{ pos.x - 2,pos.y + 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 2 }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 2 })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x - 2,pos.y + 2 }))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ABAJO DERECHA
    if (fin == (VPosicion{ pos.x + 2,pos.y - 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 2 }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 2 })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x + 2,pos.y - 2 }))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }

    //MOVIMIENTO DIAGONAL ABAJO IZQUIERDA
    if (fin == (VPosicion{ pos.x - 2,pos.y - 2 }))
    {
        if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 2 }) < 32)
        {
            if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 2 })) != color)
            {
                if (ListaFichas::JAQUE_AL_REY(VPosicion{ pos.x - 2,pos.y - 2 }))
                {
                    ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
                    pos = fin;
                    return true;
                }
            }
        }
        else
        {
            pos = fin;
            contmov++;
            return true;
        }
    }
    return false;
}
