#include "Alfil.h"
#include "VPosicion.h"

Alfil::Alfil() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Alfil::getPosicion() {
	return posicion;
}
