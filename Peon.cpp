#include "Peon.h"
#include "VPosicion.h"

Peon::Peon() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Peon::getPosicion() {
	return posicion;
}
