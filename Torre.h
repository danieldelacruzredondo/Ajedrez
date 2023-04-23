#include "Vector2D.h"
class Torre
{
	Torre();
	~Torre();
	bool color; //0 si es blanca y 1 si es negra
	Vector2D posicion;
	void movimiento(float x, float y);
	void comer(float x, float y);
	void comido(float x, float y);
	void dibuja();
};
