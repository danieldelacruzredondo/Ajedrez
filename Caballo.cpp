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

    if (pintar) {
        glPushMatrix();
        glColor3ub(25, 150, 100);
        glBegin(GL_POLYGON);
        glVertex3f(pos.x+1,pos.y+1, 0.001f);
        glVertex3f(pos.x+1, pos.y-1, 0.001f);
        glVertex3f(pos.x-1, pos.y-1, 0.001f);
        glVertex3f(pos.x-1, pos.y+1, 0.001f);
        glEnd();
        glPopMatrix();
    }
}

bool Caballo::mueve(VPosicion fin)
{

    //EL CABALLO SE MUEVE EN L, 2 CASILLAS RECTAS Y 1 A UN LADO.

    // MOVIMIENTO DERECHA 2 ARRIBA 1
    // COMPROBAMOS SI PUEDE COMER PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4 ,pos.y + 2 }) < 32 && VPosicion{ pos.x + 4, pos.y + 2 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x + 4,pos.y + 2 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    // MOVIMIENTO DERECHA 1 ARRIBA 2
    // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 ,pos.y + 4 }) < 32 && VPosicion{ pos.x + 2, pos.y + 4 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 4 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y + 4 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    // MOVIMIENTO DERECHA 2 ABAJO 1
    // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4 ,pos.y - 2 }) < 32 && VPosicion{ pos.x + 4, pos.y - 2 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 4,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x + 4,pos.y - 2 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    //MOVIMIENTO DERECHA 1 ABAJO 2
     // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2 ,pos.y - 4 }) < 32 && VPosicion{ pos.x + 2, pos.y - 4 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 4 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y - 4 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    //MOVIMIENTO IZQUIERDA 1 ARRIBA 2
     // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2 ,pos.y + 4 }) < 32 && VPosicion{ pos.x - 2, pos.y + 4 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 4 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y + 4 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    //MOVIMIENTO IZQUIERDA 2 ARRIBA 1  
    // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4 ,pos.y + 2 }) < 32 && VPosicion{ pos.x - 4, pos.y + 2 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SI SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x - 4,pos.y + 2 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    // MOVIMIENTO IZQUIERDA 1 ABAJO 2 
   // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2, pos.y - 4 }) < 32 && VPosicion{ pos.x - 2, pos.y - 4 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 4 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y - 4 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    // MOVIMIENTO IZQUIERDA 2 ABAJO 1 
    // COMPROBAMOS SI COME PIEZA
    if (ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4 ,pos.y - 2 }) < 32 && VPosicion{ pos.x - 4, pos.y - 2 } == fin)
    {
        if (ListaFichas::Comprobar_Color(ListaFichas::Comprobar_Posicion(fin)) != color)
        {
            ListaFichas::Matar(ListaFichas::Comprobar_Posicion(fin));
            pos = fin;
            pintar -= 1;
            return true;
        }
    }
    // SOLO SE MUEVE
    if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 4,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x - 4,pos.y - 2 })))
    {
        pos = fin;
        pintar -= 1;
        return true;
    }

    return false;
}
