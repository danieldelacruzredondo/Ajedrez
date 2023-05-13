#include"Rey.h"
#include"freeglut.h"

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
    if (fin->x == pos.x + 2 && fin->y == pos.y /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO IZQUIERDA 
    if (fin->x == pos.x - 2 && fin->y == pos.y /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ARRIBA 
    if (fin->x == pos.x && fin->y == pos.y + 2 /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ABAJO
    if (fin->x == pos.x && fin->y == pos.y - 2 /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ARRIBA HACIA DERECHA 
    if (fin->x == pos.x + 2 && fin->y == pos.y + 2 /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ARRIBA HACIA IZQUIERDA 
    if (fin->x == pos.x - 2 && fin->y == pos.y + 2 /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ABAJO HACIA DERECHA 
    if (fin->x == pos.x + 2 && fin->y == pos.y - 2 /* && Ha detectado una pieza */) return true;

    //MOVIMIENTO ABAJO HACIA IZQUIERDA  
    if (fin->x == pos.x - 2 && fin->y == pos.y - 2 /* && Ha detectado una pieza */) return true;

    else return false;

}
