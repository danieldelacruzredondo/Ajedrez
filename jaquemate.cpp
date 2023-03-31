#include "freeglut.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y); 



int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(900, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//glutSetWindow();

	glutPositionWindow(300,50);

	//glutFullScreen();

	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{

}

void OnTimer(int value)
{

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
