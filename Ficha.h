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
	char identificador; // sirve para diferenciar el tipo de piezas, se inicializan con la primera inicial de las fichas en ingles y mayusculas
	// Peon = 'P'(Pawn), Rey = 'K'(King), Reina = 'Q'(Queen),
	// Alfil = 'B'(Bishop), Torre = 'R'(Rook) y Caballo = 'H'(Horse) aunque seria knight, pero, en español se dice caballo.
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
	void morir(); // se elimina la ficha
	void setmorir() { vida = false; } // se le dice a la ficha que ha muerto
	bool getvida() { return vida; }
	void setidentificador(char a) { identificador = a; }
	char getidentificador() { return identificador; }
	void sumcontmov() { contmov++; }
	int getcontmov() { return contmov; }
};
