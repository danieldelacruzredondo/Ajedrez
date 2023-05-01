#include "freeglut.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include "Tablero.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);

Tablero tablero;

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(900, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//glutSetWindow();

	glutPositionWindow(300, 50);

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(33.0, 900 / 700.0f, 0.1, 150);

	//glutFullScreen();
	tablero.inicializar();

	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	tablero.pintar();

	glutSwapBuffers();
}

void OnMouseClick(int b, int state, int x, int y) 
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
			for (i; i < 16.0f; i = i + 2.0f)
			{
				if (_x < i + 2.0f && i < _x && _y < j + 2.0f && j < _y)
				{
					ce = TRUE;
					break;
				}
			}
			if (ce == TRUE)break;
		}
		tablero.casilla = VPosicion{ i + 1.0f, j + 1.0f };
	}
	glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
	//if(key=='f')tablero.reina0.setpos(VPosicion{ 7,5 });
}

void OnTimer(int value)
{

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
