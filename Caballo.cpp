#include "Caballo.h"
#include "VPosicion.h"

Caballo::Caballo() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Caballo::getPosicion() {
	return posicion;
}
