#include"Reina.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI::SpriteSequence sprite{ "bin/imagenes/reina_blancas.png", 5 };
ETSIDI:: Sprite spriteq1{ "bin/imagenes/reina_blancas.png", 7.05, 1, 11, 3.5}, spriteq2{ "bin/imagenes/reina_negras.png", 7.05, 15, 11, 3.5 };

void Reina::dibuja()
{
	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spriteq1.draw();
	spriteq2.draw();
	glPopMatrix();
}
