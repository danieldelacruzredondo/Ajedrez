#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() 
{
	x_ojo = 8.2;
	y_ojo = 8.0;
	z_ojo = 34.5;
	r = g = b = 255;
}

void Tablero::Inicializar()
{
	Torre* auxt1 = new Torre{};
	listafichas.agregar(auxt1);
	Caballo* auxc1 = new Caballo{};
	listafichas.agregar(auxc1);
	Alfil* auxa1 = new Alfil{};
	listafichas.agregar(auxa1);
	Reina* auxq1 = new Reina{};
	listafichas.agregar(auxq1);
	Rey* auxk1 = new Rey{};
	listafichas.agregar(auxk1);
	Alfil* auxa2 = new Alfil{};
	listafichas.agregar(auxa2);
	Caballo* auxc2 = new Caballo{};
	listafichas.agregar(auxc2);
	Torre* auxt2 = new Torre{};
	listafichas.agregar(auxt2);
	for (int i = 0; i < 16; i++)
	{
		Peon* auxp = new Peon{};
		listafichas.agregar(auxp);
	}
	Torre* auxt3 = new Torre{};
	listafichas.agregar(auxt3);
	Caballo* auxc3 = new Caballo{};
	listafichas.agregar(auxc3);
	Alfil* auxa3 = new Alfil{};
	listafichas.agregar(auxa3);
	Reina* auxr2 = new Reina{};
	listafichas.agregar(auxr2);
	Rey* auxk2 = new Rey{};
	listafichas.agregar(auxk2);
	Alfil* auxa4 = new Alfil{};
	listafichas.agregar(auxa4);
	Caballo* auxc4 = new Caballo{};
	listafichas.agregar(auxc4);
	Torre* auxt4 = new Torre{};
	listafichas.agregar(auxt4);

	listafichas.inicializar();
}

void Tablero::Pintar() {

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
	
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(0.0f, 16.0f, 0.0f);
	glColor3ub(0, 0, 0);
	glVertex3f(16.0f, 16.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(17.0f, 17.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(-1.0f, 17.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(16.0f, 16.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(17.0f, 17.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(17.0f, -1.0f, 0.0f);
	glColor3ub(0, 0, 0);
	glVertex3f(16.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(16.0f, 0.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(17.0f, -1.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3ub(0, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(-1.0f, 17.0f, 0.0f);
	glColor3ub(0, 0, 0);
	glVertex3f(0.0f, 16.0f, 0.0f);
	glEnd();

	listafichas.dibujar();
}

void Tablero::ElegirCasilla(int b, int state, int x, int y)
{
	float _x = (float)(x - 422)*16 / 674;
	float _y = -(float)(y - 768)*16 / 675;
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
		casilla = VPosicion{ i + 1.0f, j + 1.0f };
		listafichas.ElegirFicha(casilla);
	}
}
