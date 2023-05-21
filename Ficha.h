#pragma once
#include "VPosicion.h"
#include "ETSIDI.h"

//ETSIDI_API Sprite(const char *texturePath, float x=0, float y=0, float width=-1, float height=-1);

class Ficha
{
protected:
	VPosicion pos;
	bool vida = true;
	bool color;
	char identificador;
	int contmov = 0;
	ETSIDI::Sprite sprite{ "bin/imagenes/rey_negras.png", 0.0, 0.0, 0.0, 0.0 };

public:
	virtual ~Ficha() {}
	virtual void inicializa(VPosicion _pos, bool _color) { pos = _pos, color = _color; }
	virtual void dibuja() {}
	virtual bool mueve(VPosicion) { return false; }
	void setpos(VPosicion _pos) { pos = _pos; }
	void setcolor(bool _color) { color = _color; }
	VPosicion getpos() { return pos; }
	bool getcolor() { return color; }
	void morir();
	void setmorir() { vida = false; }
	bool getvida() { return vida; }
	void setidentificador(char a) { identificador = a; }
	char getidentificador() { return identificador; }
	void sumcontmov() { contmov++; }
	int getcontmov() { return contmov; }
};
