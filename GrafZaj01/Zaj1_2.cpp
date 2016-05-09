// Zaj1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);

	glVertex3f(-80.0f, 10.0f, 0.0f);
	glVertex3f(-60.0f, 30.0f, 0.0f);
	glVertex3f(-40.0f, 60.0f, 0.0f);
	glVertex3f(-30.0f, 100.0f, 0.0f);
	glVertex3f(-40.0f, 140.0f, 0.0f);
	glVertex3f(-100.0f, -100.0f, 0.0f);
	glEnd();
	glFlush();
}
void SetupRc(void) 
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
void Change_Size(int h, int w) 
{
	GLfloat aspectRatio;

	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;

	if (w <= h)glOrtho(-200.0, 200.0, -200.0 / aspectRatio, 200.0 / aspectRatio, 2.0, -2.0);
	else glOrtho(-200.0 *aspectRatio, 200.0*aspectRatio, -200.0, 200.0, 2.0, -2.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("rect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(Change_Size);
	SetupRc();
	glutMainLoop();

	    return 0;
}

