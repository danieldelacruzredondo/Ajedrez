#include"Peon.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite spritep{ "bin/imagenes/alfil_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Peon::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Peon::setcolor(bool _color)
{
	color = _color;
}

void Peon::dibuja()
{

	if (color)
		spritep = { "bin/imagenes/peon_negras.png", pos.x + 0.57f, pos.y - 0.1f, 11, 3.5 };
	else
		spritep = { "bin/imagenes/peon_blancas.png", pos.x + 0.67f, pos.y - 0.23f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritep.draw();
	glPopMatrix();
}

VPosicion getpos();

	friend class VMovimiento;
