#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() {
	x_ojo = 8.0;
	y_ojo = 8.0;
	z_ojo = 28.0;
	r = g = b = 255;
}

void Tablero::inicializar()
{
	rey0.setpos(VPosicion{9,1});
	rey0.setcolor(FALSE);
	rey1.setpos(VPosicion{9,15});
	rey1.setcolor(TRUE);
	reina0.setpos(VPosicion{ 7, 1 });
	reina0.setcolor(FALSE);
	reina1.setpos(VPosicion{ 7, 15 });
	reina1.setcolor(TRUE);
	alfil01.setpos(VPosicion{5.0,1});
	alfil01.setcolor(FALSE);
	alfil02.setpos(VPosicion{11.0,1});
	alfil02.setcolor(FALSE);
	alfil11.setpos(VPosicion{5.0,15});
	alfil11.setcolor(TRUE);
	alfil12.setpos(VPosicion{11.0,15});
	alfil12.setcolor(TRUE);
	caballo01.setpos(VPosicion{ 3.0,1 });
	caballo01.setcolor(FALSE);
	caballo02.setpos(VPosicion{ 13.0,1 });
	caballo02.setcolor(FALSE);
	caballo11.setpos(VPosicion{ 3.0,15 });
	caballo11.setcolor(TRUE);
	caballo12.setpos(VPosicion{ 13.0,15 });
	caballo12.setcolor(TRUE);
	torre01.setpos(VPosicion{ 1.0,1 });
	torre01.setcolor(FALSE);
	torre02.setpos(VPosicion{ 15.0,1 });
	torre02.setcolor(FALSE);
	torre11.setpos(VPosicion{ 1.0,15 });
	torre11.setcolor(TRUE);
	torre12.setpos(VPosicion{ 15.0,15 });
	torre12.setcolor(TRUE);
	for (int i = 0; i < 2*MAX_PEONES; i++) {
		Peon* aux1 = new Peon{};
		Peon* aux2 = new Peon{};
		peones.agregar(aux1,aux2);
	}
	peones.inicializa();
}

void Tablero::pintar() {

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)Caja caja;

	for (int j = 0,_y = 0; j < 8; j++)
	{
		for (int i = 0,_x = 0; i < 8; i++)
		{
			if (_y == 0 || _y == 4 || _y == 8 || _y == 12) 
			{
				if (_x == 0 || _x == 4 || _x == 8 || _x == 12)r = 15, g = 15, b = 230;
				else r = 230, g = 230, b = 230;
			}
			else 
			{
				if (_x == 0 || _x == 4 || _x == 8 || _x == 12)r = 230, g = 230, b = 230;
				else r = 15, g = 15, b = 230;
			}
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
		glVertex3f(_x,_y,0.0);
		glVertex3f(_x+2.0,_y,0.0);
		glVertex3f(_x+2.0,_y+2.0,0.0);
		glVertex3f(_x,_y+2.0,0.0);
		glEnd();
		glEnable(GL_LIGHTING);
		_x += 2.0;
		}
	_y += 2.0;
	}

	reina0.dibuja();
	reina1.dibuja();
	rey0.dibuja();
	rey1.dibuja();
	alfil01.dibuja();
	alfil02.dibuja();
	alfil11.dibuja();
	alfil12.dibuja();
	caballo01.dibuja();
	caballo02.dibuja();
	caballo11.dibuja();
	caballo12.dibuja();
	torre01.dibuja();
	torre02.dibuja();
	torre11.dibuja();
	torre12.dibuja();
	peones.dibuja();
}

void Tablero::elegirficha(int b, int state, int x, int y)
{
	float _x = (float)(x - 115) / 42;
	float _y = -(float)(y - 691) / 44;
	float j = 0.0, i = 0.0;
	bool ce = FALSE;
	bool down = (state == GLUT_DOWN);
	if (b == GLUT_LEFT_BUTTON && down)
	{
		for (j; j < 16.0f; j = j + 2.0f)
		{
			for (i = 0.0; i < 16.0f; i = i + 2.0f)
			{
				if (_x < i + 2.0f && i < _x && _y < j + 2.0f && j < _y)
				{
					ce = TRUE;
					break;
				}
			}
			if (ce == TRUE)break;
		}
	}
		casilla = VPosicion{ i + 1.0f, j + 1.0f };
	if (reina0.getpos() == casilla)reina0.setpos(VPosicion{13,7});
	if (reina1.getpos() == casilla)reina1.setpos(VPosicion{7,5});
	if (rey0.getpos() == casilla)rey0.setpos(VPosicion{7,5});
	if (rey1.getpos() == casilla)rey1.setpos(VPosicion{ 7,5 });
	if (alfil01.getpos() == casilla)alfil01.setpos(VPosicion{ 7,5 });
	if (alfil02.getpos() == casilla)alfil02.setpos(VPosicion{ 7,5 });
	if (alfil11.getpos() == casilla)alfil11.setpos(VPosicion{ 7,5 });
	if (alfil12.getpos() == casilla)alfil12.setpos(VPosicion{ 7,5 });
}

