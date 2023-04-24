#include "Rey.h"
#include "VPosicion.h"

Rey::Rey() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Rey::getPosicion() {
	return posicion;
}
