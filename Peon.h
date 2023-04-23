#include "Vector2D.h"
class Peon
{
	Peon();
	~Peon();
	bool color; //0 si es blanca y 1 si es negra
	Vector2D posicion;
	
	void movimiento(float x, float y);
	void comer(float x, float y, char);
	void comido(float x, float y, char);
	void dibuja();
};
