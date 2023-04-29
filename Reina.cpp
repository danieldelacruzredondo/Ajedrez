#include"Reina.h"
#include"freeglut.h"
#include"ETSIDI.h"

ETSIDI::Sprite spriteq{ "bin/imagenes/reina_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Reina::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Reina::setcolor(bool _color)
{
	color = _color;
}

void Reina::dibuja()
{

	if (color)
		spriteq = { "bin/imagenes/reina_negras.png", pos.x + 0.05f, pos.y + 0.075f , 11, 3.5 };
	else
		spriteq = { "bin/imagenes/reina_blancas.png", pos.x + 0.05f, pos.y + 0.12f , 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spriteq.draw();
	glPopMatrix();
}
