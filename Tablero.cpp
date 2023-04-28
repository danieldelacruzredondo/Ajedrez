include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() {
	x_ojo = 8.0;
	y_ojo = 8.0;
	z_ojo = 28.0;
	r = g = b = 255;
}

void Tablero::inicializar()
{
	alfil11.setpos(VPosicion{5.0,1});
	alfil11.setcolor(FALSE);
	alfil12.setpos(VPosicion{11.0,1});
	alfil12.setcolor(FALSE);
	alfil21.setpos(VPosicion{5.0,15});
	alfil21.setcolor(TRUE);
	alfil22.setpos(VPosicion{11.0,15});
	alfil22.setcolor(TRUE);
	caballo11.setpos(VPosicion{ 3.0,1 });
	caballo11.setcolor(FALSE);
	caballo12.setpos(VPosicion{ 13.0,1 });
	caballo12.setcolor(FALSE);
	caballo21.setpos(VPosicion{ 3.0,15 });
	caballo21.setcolor(TRUE);
	caballo22.setpos(VPosicion{ 13.0,15 });
	caballo22.setcolor(TRUE);
	torre11.setpos(VPosicion{ 1.0,1 });
	torre11.setcolor(FALSE);
	torre12.setpos(VPosicion{ 15.0,1 });
	torre12.setcolor(FALSE);
	torre21.setpos(VPosicion{ 1.0,15 });
	torre21.setcolor(TRUE);
	torre22.setpos(VPosicion{ 15.0,15 });
	torre22.setcolor(TRUE);
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

	reina.dibuja();
	rey.dibuja();
	alfil11.dibuja();
	alfil12.dibuja();
	alfil21.dibuja();
	alfil22.dibuja();
	caballo11.dibuja();
	caballo12.dibuja();
	caballo21.dibuja();
	caballo22.dibuja();
	torre11.dibuja();
	torre12.dibuja();
	torre21.dibuja();
	torre22.dibuja();
}
