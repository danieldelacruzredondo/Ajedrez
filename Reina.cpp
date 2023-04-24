#include "Reina.h"
#include "VPosicion.h"

Reina::Reina() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Reina::getPosicion() {
	return posicion;
}
