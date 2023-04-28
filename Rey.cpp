#include"Rey.h"
#include"freeglut.h"
#include"ETSIDI.h"

ETSIDI::Sprite spritek1{ "bin/imagenes/rey_blancas.png", 9.17, 0.9, 11, 3.5 }, spritek2{ "bin/imagenes/rey_negras.png", 9.32, 14.9, 11, 3.5 };

void Rey::dibuja()
{
	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritek1.draw();
	spritek2.draw();
	glPopMatrix();
}
