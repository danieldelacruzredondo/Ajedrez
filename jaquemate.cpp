#include "freeglut.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include "Tablero.h"
#include "Coordinador.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);

Coordinador coordinador;

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(900, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	glutFullScreen();

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(33.0, 1250 / 700.0f, 0.1, 150);

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

	coordinador.dibujar();

	glutSwapBuffers();
}

void OnMouseClick(int b, int state, int x, int y) 
{
	coordinador.Elegir_modo_juego(b, state, x, y);
	glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
}

void OnTimer(int value)
{

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
