#include "Tablero.h"
#include "ETSIDI.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador() {};

	void Elegir_modo_juego(int b, int state, int x, int y);
	void dibujar();

protected:
	Tablero tablero;
	enum Estado{INICIO, JUEGO, SALIR};
	Estado estado;
};
