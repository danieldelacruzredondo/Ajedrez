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


bool Rey::mueve(VPosicion fin){

    //MOVIMIENTO DERECHA 
    
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y })))
        {
            pos = fin;
            return true;
        }
   

    //MOVIMIENTO ARRIBA 
   
              
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x ,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    
    //MOVIMIENTO ABAJO 
    
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x ,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x ,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
   
    //MOVIMIENTO IZQUIERDA 
   
        
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y })))
        {
            pos = fin;
            return true;
        }
    

    //MOVIMIENTO DIAGONAL ARRIBA DERECHA
    
       
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
    


    //MOVIMIENTO DIAGONAL ARRIBA IZQUIERDA
   
       
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y + 2 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y + 2 })))
        {
            pos = fin;
            return true;
        }
   

    //MOVIMIENTO DIAGONAL ABAJO DERECHA
   
       
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x + 2,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x + 2,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    
    //MOVIMIENTO DIAGONAL ABAJO IZQUIERDA
   
        
        if ((ListaFichas::Comprobar_Posicion(VPosicion{ pos.x - 2,pos.y - 2 }) == 32) && (fin == (VPosicion{ pos.x - 2,pos.y - 2 })))
        {
            pos = fin;
            return true;
        }
    

    return false;

}
