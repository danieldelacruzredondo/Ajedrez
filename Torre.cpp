#include"Torre.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite spritet{ "bin/imagenes/torre_negras.png", 0.0, 0.0, 0.0, 0.0 };

void Torre::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Torre::setcolor(bool _color)
{
	color = _color;
}

void Torre::dibuja()
{

	if (color)
		spritet = { "bin/imagenes/torre_negras.png", pos.x, pos.y - 0.1f, 11, 3.5 };
	else
		spritet = { "bin/imagenes/torre_blancas.png", pos.x, pos.y - 0.2f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritet.draw();
	glPopMatrix();
}
