#include "Torre.h"
#include "VPosicion.h"

Torre::Torre() {
	posicion.x = 1;
	posicion.y = 0;
}
VPosicion Torre::getPosicion(){
	return posicion;
}
