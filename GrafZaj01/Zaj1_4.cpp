// Zaj1_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GL\glut.h"

float katObrotu = 2.0;
void RenderScene(void)
{
	glLoadIdentity();
	glRotatef(katObrotu, 0.0f, 0.0f, 1.0f);
	katObrotu += 0.1;
	glutPostRedisplay();

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);

	glVertex3f(-80.0f , 10.0f , 0.0f);
	glVertex3f(-60.0f , 30.0f , 0.0f);
	glVertex3f(-40.0f , 60.0f , 0.0f);
	glVertex3f(-30.0f , 100.0f , 0.0f);
	glVertex3f(-40.0f , 140.0f , 0.0f);
	glVertex3f(-100.0f,-100.0f , 0.0f);
	glEnd();
	glFlush();
	
}
void ChangeSize(int w, int h) 
{
	GLfloat aspectRatio;
	if (h == 0)h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczajcej (lewy, prawy, dolny, górny, bliski, odleg³y)
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-100.0, 100.0 / aspectRatio, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void SetupRC(void)
{
	glClearColor(0.60f, 0.40f, .12f, 1.0f);

}
int main(int argc,char*argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Rotate");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
   
}

