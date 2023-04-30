#include"Alfil.h"
#include"freeglut.h"
#include"ETSIDI.h"

//ETSIDI_API Sprite(const char *texturePath, float x=0, float y=0, float width=-1, float height=-1);
//ETSIDI::Sprite sprite{"bin/imagenes/alfil_negras.png", 5.35, 0.9, 11, 3.5};
ETSIDI::Sprite sprite1{ "bin/imagenes/alfil_negras.png", 0.0, 0.0, 0.0, 0.0};

void Alfil::setpos(VPosicion _pos)
{
	pos = _pos;
}

void Alfil::setcolor(bool _color)
{
	color = _color;
}

void Alfil::dibuja()
{
	
	if (color)
		sprite1 = {"bin/imagenes/alfil_negras.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };
	else
		sprite1 = {"bin/imagenes/alfil_blancas.png", pos.x + 0.35f, pos.y - 0.1f, 11, 3.5 };
	
	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	sprite1.draw();
	glPopMatrix();
}

VPosicion Alfil::getpos() { return pos; }
