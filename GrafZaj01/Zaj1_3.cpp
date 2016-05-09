// Zaj1_3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//prostokat . rozmiar
GLfloat x1=0.0f;
GLfloat y1=0.0f;
GLfloat pozX = - 100.0f;
GLfloat pozy= 0.0f;
GLfloat rsize=60;

//rozmiar kroku

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
 
// dane zmeinaijacych sie rozamiarów okna 
GLfloat widthW;
GLfloat heightW;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);

	glVertex3f(-80.0f+x1, 10.0f+y1, 0.0f);
	glVertex3f(-60.0f+x1, 30.0f+ y1, 0.0f);
	glVertex3f(-40.0f+x1, 60.0f+y1, 0.0f);
	glVertex3f(-30.0f+x1, 100.0f+y1, 0.0f);
	glVertex3f(-40.0f+x1, 140.0f+y1, 0.0f);
	glVertex3f(-100.0f+x1, -100.0f+y1, 0.0f);
	glEnd();
	//glFlush();
	glutSwapBuffers();
}
void TimerFunction(int value) 
{
	//lewa prawa krawedz
	if (x1 + 100 > widthW - rsize || x1 < 0)
		xstep = -xstep;
	//krawedz gora dol
	if (y1 + 100 > heightW - rsize || y1 < 0)
		ystep = -ystep;
	//Kontrola obramowania 

	if (x1 > widthW - rsize)
		x1 = widthW - rsize - 1;

	if (y1 > heightW - rsize)
		y1 = heightW- rsize - 1;

	x1 += xstep;
	y1 += ystep;

	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

void SetupRC(void) 
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
void ChangeSize(GLsizei w, GLsizei h) 
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		heightW = 250.0f*h / w;
		widthW = 250.0f;
	}
	else
	{
		widthW = 250.0f*w / h;
		heightW = 250.0f;
	}

	glOrtho(0.0f, widthW, 0.0f, heightW, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// G³ówny punkt wejcia programu
int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bounce");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
	return 0;

}