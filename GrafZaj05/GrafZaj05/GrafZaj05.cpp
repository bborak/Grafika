#include "stdafx.h"

#include <GL/glut.h>
#include "glext.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "colors.h"
#include "materials.h"
#include <math.h>
#include <iostream>




//////////////// 1 PROGRAM ////////////////////////////////////////////////////////////////////////////
PFNGLWINDOWPOS2IPROC glWindowPos2iJEDEN = NULL;
enum
{
	// obiekty
	SPHERE,               // kula
	TEAPOT,               // czajnik
	CONE,                 // sto¿ek
	TORUS,                // torus
	CUBE,                 // szeœcian
	DODECAHEDRON,         // dwunastoœcian
	OCTAHEDRON,           // oœmioœcian
	TETRAHEDRON,          // czworoœcian
	ICOSAHEDRON,          // dwudziestoœcian

						  // materia³y
	BRASS,                // mosi¹dz
	BRONZE,               // br¹z
	POLISHED_BRONZE,      // polerowany br¹z
	CHROME,               // chrom
	COPPER,               // miedŸ
	POLISHED_COPPER,      // polerowana miedŸ
	GOLD,                 // z³oto
	POLISHED_GOLD,        // polerowane z³oto
	PEWTER,               // grafit (cyna z o³owiem)
	SILVER,               // srebro
	POLISHED_SILVER,      // polerowane srebro
	EMERALD,              // szmaragd
	JADE,                 // jadeit
	OBSIDIAN,             // obsydian
	PEARL,                // per³a
	RUBY,                 // rubin
	TURQUOISE,            // turkus
	BLACK_PLASTIC,        // czarny plastik
	BLACK_RUBBER,         // czarna guma

						  // obszar renderingu
	FULL_WINDOW,          // aspekt obrazu - ca³e okno
	ASPECT_1_1,           // aspekt obrazu 1:1
	EXIT                  // wyjœcie
};
int aspectJEDEN = FULL_WINDOW;
const GLdouble leftJEDEN = -2.0;
const GLdouble rightJEDEN = 2.0;
const GLdouble bottomJEDEN = -2.0;
const GLdouble topJEDEN = 2.0;
const GLdouble nearJEDEN = 3.0;
const GLdouble farJEDEN = 7.0;
GLfloat rotatexJEDEN = 0.0;
GLfloat rotateyJEDEN = 0.0;
int button_stateJEDEN = GLUT_UP;
int button_xJEDEN, button_yJEDEN;
GLfloat scaleJEDEN = 1.0;
const GLfloat *ambientJEDEN = BrassAmbient;
const GLfloat *diffuseJEDEN = BrassDiffuse;
const GLfloat *specularJEDEN = BrassSpecular;
GLfloat shininessJEDEN = BrassShininess;
int objectJEDEN = SPHERE;
GLfloat light_positionJEDEN[4] =
{
	0.0,0.0,2.0,0.0
};
GLfloat light_rotatexJEDEN = 0.0;
GLfloat light_rotateyJEDEN = 0.0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 2 PROGRAM //////////////////////////////////////////////////////////////////////////////
int aspectDWA = FULL_WINDOW;
const GLdouble leftDWA = -2.0;
const GLdouble rightDWA = 2.0;
const GLdouble bottomDWA = -2.0;
const GLdouble topDWA = 2.0;
const GLdouble near_DWA = 3.0;
const GLdouble far_DWA = 7.0;
GLfloat rotatexDWA = 0.0;
GLfloat rotateyDWA = 0.0;
int button_stateDWA = GLUT_UP;
int button_xDWA, button_yDWA;
GLfloat ambient_lightDWA[4] =
{
	0.2,0.2,0.2,1.0
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 3 PROGRAM //////////////////////////////////////////////////////////////////////////////
PFNGLWINDOWPOS2IPROC glWindowPos2iTRZY = NULL;
int aspect = FULL_WINDOW;
const GLdouble leftTRZY = -2.0;
const GLdouble rightTRZY = 2.0;
const GLdouble bottomTRZY = -2.0;
const GLdouble topTRZY = 2.0;
const GLdouble nearTRZY = 3.0;
const GLdouble farTRZY = 7.0;
GLfloat rotatexTRZY = 0.0;
GLfloat rotateyTRZY = 0.0;
int button_stateTRZY = GLUT_UP;
int button_xTRZY, button_yTRZY;
GLfloat scaleTRZY = 1.0;
const GLfloat *ambientTRZY = BrassAmbient;
const GLfloat *diffuseTRZY = BrassDiffuse;
const GLfloat *specularTRZY = BrassSpecular;
GLfloat shininessTRZY = BrassShininess;
int objectTRZY = SPHERE;
GLfloat light_positionTRZY[4] =
{
	0.0,0.0,2.0,1.0
};
GLfloat light_rotatexTRZY = 0.0;
GLfloat light_rotateyTRZY = 0.0;
GLfloat spot_directionTRZY[3] =
{
	0.0,0.0,-1.0
};
GLfloat spot_cutoffTRZY = 180.0;
GLfloat spot_exponentTRZY = 128.0;
GLfloat constatn_attentuationTRZY = 1.0;
GLfloat linearTRZY_attenuation = 0.0;
GLfloat quadraticTRZY = 0.0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 4 PROGRAM //////////////////////////////////////////////////////////////////////////////
bool rescaleCZTERY_normal = false;
enum
{
	NORMALS_SMOOTH,       // jeden wektor normalny na wierzcho³ek
	NORMALS_FLAT,         // jeden wektor normalny na œcianê
};
int aspectCZTERY = FULL_WINDOW;
const GLdouble leftCZTERY = -1.0;
const GLdouble rightCZTERY = 1.0;
const GLdouble bottomCZTERY = -1.0;
const GLdouble topCZTERY = 1.0;
const GLdouble nearCZTERY = 3.0;
const GLdouble farCZTERY = 7.0;
GLfloat rotatexCZTERY = 0.0;
GLfloat rotateyCZTERY = 0.0;
int button_stateCZTERY = GLUT_UP;
int button_xCZTERY, button_yCZTERY;
GLfloat scaleCZTERY = 1.0;
const GLfloat *ambientCZTERY = BrassAmbient;
const GLfloat *diffuseCZTERY = BrassDiffuse;
const GLfloat *specularCZTERY = BrassSpecular;
GLfloat shininesCZTERY = BrassShininess;
int normalsCZTERY = NORMALS_FLAT;
GLfloat vertexCZTERY[12 * 3] =
{
	0.000,  0.667,  0.500,   // v0
	0.000,  0.667, -0.500,   // v1
	0.000, -0.667, -0.500,   // v2
	0.000, -0.667,  0.500,   // v3
	0.667,  0.500,  0.000,   // v4
	0.667, -0.500,  0.000,   // v5
	-0.667, -0.500,  0.000,  // v6
	-0.667,  0.500,  0.000,  // v7
	0.500,  0.000,  0.667,   // v8
	-0.500,  0.000,  0.667,  // v9
	-0.500,  0.000, -0.667,  // v10
	0.500,  0.000, -0.667    // v11
};
int trianglesCZTERY[20 * 3] =
{
	2, 10, 11,
	1, 11, 10,
	1, 10,  7,
	1,  4, 11,
	0,  1,  7,
	0,  4,  1,
	0,  9,  8,
	3,  8,  9,
	0,  7,  9,
	0,  8,  4,
	3,  9,  6,
	3,  5,  8,
	2,  3,  6,
	2,  5,  3,
	2,  6, 10,
	2, 11,  5,
	6,  7, 10,
	6,  9,  7,
	4,  5, 11,
	4,  8,  5
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 1 PROGRAM ////////////////////////////////////////////////////////////////////////////
void DrawStringJEDEN(GLint x, GLint y, char *string)
{
	// po³o¿enie napisu
	glWindowPos2iJEDEN(x, y);

	// wyœwietlenie napisu
	int len = strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void DisplaySceneJEDEN()
{
	// kolor t³a - zawartoœ? bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru i bufora g³êbokoœci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// w³¹czenie testu bufora g³êbokoœci
	glEnable(GL_DEPTH_TEST);

	// w³¹czenie oœwietlenia
	glEnable(GL_LIGHTING);

	// w³¹czenie œwiat³a GL_LIGHT0
	glEnable(GL_LIGHT0);

	// w³¹czenie automatycznej normalizacji wektorów normalnych
	glEnable(GL_NORMALIZE);

	// przesuniêcie uk³adu wspó³rzêdnych obiektu do œrodka bry³y odcinania
	glTranslatef(0, 0, -(nearJEDEN + farJEDEN) / 2);

	// obroty obiektu
	glRotatef(rotatexJEDEN, 1.0, 0, 0);
	glRotatef(rotateyJEDEN, 0, 1.0, 0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scaleJEDEN, scaleJEDEN, scaleJEDEN);

	// w³aœciwoœci materia³u
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientJEDEN);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseJEDEN);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularJEDEN);
	glMaterialf(GL_FRONT, GL_SHININESS, shininessJEDEN);

	// zmiana kierunku Ÿród³a œwiat³a jest wykonywana niezale¿nie
	// od obrotów obiektu, st¹d od³o¿enie na stos macierzy modelowania
	glPushMatrix();

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// obroty kierunku Ÿród³a œwiat³a - klawisze kursora
	glRotatef(light_rotatexJEDEN, 1.0, 0, 0);
	glRotatef(light_rotateyJEDEN, 0, 1.0, 0);

	// ustalenie kierunku Ÿród³a œwiat³a
	glLightfv(GL_LIGHT0, GL_POSITION, light_positionJEDEN);

	// przywrócenie pierwotnej macierzy modelowania
	glPopMatrix();

	// rysowanie wybranego obiektu 3D
	switch (objectJEDEN)
	{
		// kula
	case SPHERE:
		glutSolidSphere(1.0, 50, 40);
		break;

		// czajnik
	case TEAPOT:
		glutSolidTeapot(1);
		break;

		// sto¿ek
	case CONE:
		glutSolidCone(1, 1, 50, 40);
		break;

		// torus
	case TORUS:
		glutSolidTorus(0.3, 1, 40, 50);
		break;

		// szeœcian
	case CUBE:
		glutSolidCube(1);
		break;

		// dwunastoœcian
	case DODECAHEDRON:
		glutSolidDodecahedron();
		break;

		// oœmioœcian
	case OCTAHEDRON:
		glutSolidOctahedron();
		break;

		// czworoœcian
	case TETRAHEDRON:
		glutSolidTetrahedron();
		break;

		// dwudziestoœcian
	case ICOSAHEDRON:
		glutSolidIcosahedron();
		break;
	}

	// informacje o modyfikowanych wartoœciach
	// parametrów Ÿród³a œwiata³a GL_LIGHT0
	char string[200];
	GLfloat vec[4];
	glColor3fv(Black);

	// kierunek Ÿród³a œwiat³a
	glGetLightfv(GL_LIGHT0, GL_POSITION, vec);
	sprintf(string, "GL_POSITION = (%f,%f,%f,%f)", vec[0], vec[1], vec[2], vec[3]);
	DrawStringJEDEN(2, 2, string);

	// k¹ty obrotu kierunku Ÿród³a œwiat³a
	sprintf(string, "light_rotatexJEDEN = %f", light_rotatexJEDEN);
	DrawStringJEDEN(2, 16, string);
	sprintf(string, "light_rotateyJEDEN = %f", light_rotateyJEDEN);
	DrawStringJEDEN(2, 30, string);

	// skierowanie poleceñ do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

void ReshapeJEDEN(int width, int height)
{
	// obszar renderingu - ca³e okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bry³y obcinania
	if (aspectJEDEN == ASPECT_1_1)
	{
		// wysokoœ? okna wiêksza od wysokoœci okna
		if (width < height && width > 0)
			glFrustum(leftJEDEN, rightJEDEN, bottomJEDEN*height / width, topJEDEN*height / width, nearJEDEN, farJEDEN);
		else

			// szerokoœ? okna wiêksza lub równa wysokoœci okna
			if (width >= height && height > 0)
				glFrustum(leftJEDEN*width / height, rightJEDEN*width / height, bottomJEDEN, topJEDEN, nearJEDEN, farJEDEN);
	}
	else
		glFrustum(leftJEDEN, rightJEDEN, bottomJEDEN, topJEDEN, nearJEDEN, farJEDEN);

	// generowanie sceny 3D
	DisplaySceneJEDEN();
}

void KeyboardJEDEN(unsigned char key, int x, int y)
{
	switch (key)
	{
		// klawisz "+" - powiêkszenie obiektu
	case '+':
		scaleJEDEN += 0.05;
		break;

		// klawisz "-" - zmniejszenie obiektu
	case '-':
		if (scaleJEDEN > 0.05)
			scaleJEDEN -= 0.05;
		break;
	}

	// narysowanie sceny
	DisplaySceneJEDEN();
}

void MouseButtonJEDEN(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiêtanie stanu lewego przycisku myszki
		button_stateJEDEN = state;

		// zapamiêtanie po³o¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_xJEDEN = x;
			button_yJEDEN = y;
		}
	}
}

void MouseMotionJEDEN(int x, int y)
{
	if (button_stateJEDEN == GLUT_DOWN)
	{
		rotateyJEDEN += 30 * (rightJEDEN - leftJEDEN) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_xJEDEN);
		button_xJEDEN = x;
		rotatexJEDEN -= 30 * (topJEDEN - bottomJEDEN) / glutGet(GLUT_WINDOW_HEIGHT) * (button_yJEDEN - y);
		button_yJEDEN = y;
		glutPostRedisplay();
	}
}

void SpecialKeysJEDEN(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		light_rotateyJEDEN -= 5;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		light_rotateyJEDEN += 5;
		break;

		// kursor w dó³
	case GLUT_KEY_DOWN:
		light_rotatexJEDEN += 5;
		break;

		// kursor w górê
	case GLUT_KEY_UP:
		light_rotatexJEDEN -= 5;
		break;
	}

	// odrysowanie okna
	DisplaySceneJEDEN();
}

void MenuJEDEN(int value)
{
	switch (value)
	{
		// rysowany obiekt - kula
	case SPHERE:
		objectJEDEN = SPHERE;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - czajnik
	case TEAPOT:
		objectJEDEN = TEAPOT;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - sto¿ek
	case CONE:
		objectJEDEN = CONE;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - torus
	case TORUS:
		objectJEDEN = TORUS;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - szeœcian
	case CUBE:
		objectJEDEN = CUBE;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - dwunastoœcian
	case DODECAHEDRON:
		objectJEDEN = DODECAHEDRON;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - oœmioœcian
	case OCTAHEDRON:
		objectJEDEN = OCTAHEDRON;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - czworoœcian
	case TETRAHEDRON:
		objectJEDEN = TETRAHEDRON;
		DisplaySceneJEDEN();
		break;

		// rysowany obiekt - dwudziestoœcian
	case ICOSAHEDRON:
		objectJEDEN = ICOSAHEDRON;
		DisplaySceneJEDEN();
		break;

		// materia³ - mosi¹dz
	case BRASS:
		ambientJEDEN = BrassAmbient;
		diffuseJEDEN = BrassDiffuse;
		specularJEDEN = BrassSpecular;
		shininessJEDEN = BrassShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - br¹z
	case BRONZE:
		ambientJEDEN = BronzeAmbient;
		diffuseJEDEN = BronzeDiffuse;
		specularJEDEN = BronzeSpecular;
		shininessJEDEN = BronzeShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - polerowany br¹z
	case POLISHED_BRONZE:
		ambientJEDEN = PolishedBronzeAmbient;
		diffuseJEDEN = PolishedBronzeDiffuse;
		specularJEDEN = PolishedBronzeSpecular;
		shininessJEDEN = PolishedBronzeShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - chrom
	case CHROME:
		ambientJEDEN = ChromeAmbient;
		diffuseJEDEN = ChromeDiffuse;
		specularJEDEN = ChromeSpecular;
		shininessJEDEN = ChromeShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - miedŸ
	case COPPER:
		ambientJEDEN = CopperAmbient;
		diffuseJEDEN = CopperDiffuse;
		specularJEDEN = CopperSpecular;
		shininessJEDEN = CopperShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - polerowana miedŸ
	case POLISHED_COPPER:
		ambientJEDEN = PolishedCopperAmbient;
		diffuseJEDEN = PolishedCopperDiffuse;
		specularJEDEN = PolishedCopperSpecular;
		shininessJEDEN = PolishedCopperShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - z³oto
	case GOLD:
		ambientJEDEN = GoldAmbient;
		diffuseJEDEN = GoldDiffuse;
		specularJEDEN = GoldSpecular;
		shininessJEDEN = GoldShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - polerowane z³oto
	case POLISHED_GOLD:
		ambientJEDEN = PolishedGoldAmbient;
		diffuseJEDEN = PolishedGoldDiffuse;
		specularJEDEN = PolishedGoldSpecular;
		shininessJEDEN = PolishedGoldShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - grafit (cyna z o³owiem)
	case PEWTER:
		ambientJEDEN = PewterAmbient;
		diffuseJEDEN = PewterDiffuse;
		specularJEDEN = PewterSpecular;
		shininessJEDEN = PewterShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - srebro
	case SILVER:
		ambientJEDEN = SilverAmbient;
		diffuseJEDEN = SilverDiffuse;
		specularJEDEN = SilverSpecular;
		shininessJEDEN = SilverShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - polerowane srebro
	case POLISHED_SILVER:
		ambientJEDEN = PolishedSilverAmbient;
		diffuseJEDEN = PolishedSilverDiffuse;
		specularJEDEN = PolishedSilverSpecular;
		shininessJEDEN = PolishedSilverShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - szmaragd
	case EMERALD:
		ambientJEDEN = EmeraldAmbient;
		diffuseJEDEN = EmeraldDiffuse;
		specularJEDEN = EmeraldSpecular;
		shininessJEDEN = EmeraldShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - jadeit
	case JADE:
		ambientJEDEN = JadeAmbient;
		diffuseJEDEN = JadeDiffuse;
		specularJEDEN = JadeSpecular;
		shininessJEDEN = JadeShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - obsydian
	case OBSIDIAN:
		ambientJEDEN = ObsidianAmbient;
		diffuseJEDEN = ObsidianDiffuse;
		specularJEDEN = ObsidianSpecular;
		shininessJEDEN = ObsidianShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - per³a
	case PEARL:
		ambientJEDEN = PearlAmbient;
		diffuseJEDEN = PearlDiffuse;
		specularJEDEN = PearlSpecular;
		shininessJEDEN = PearlShininess;
		DisplaySceneJEDEN();
		break;

		// metaria³ - rubin
	case RUBY:
		ambientJEDEN = RubyAmbient;
		diffuseJEDEN = RubyDiffuse;
		specularJEDEN = RubySpecular;
		shininessJEDEN = RubyShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - turkus
	case TURQUOISE:
		ambientJEDEN = TurquoiseAmbient;
		diffuseJEDEN = TurquoiseDiffuse;
		specularJEDEN = TurquoiseSpecular;
		shininessJEDEN = TurquoiseShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - czarny plastik
	case BLACK_PLASTIC:
		ambientJEDEN = BlackPlasticAmbient;
		diffuseJEDEN = BlackPlasticDiffuse;
		specularJEDEN = BlackPlasticSpecular;
		shininessJEDEN = BlackPlasticShininess;
		DisplaySceneJEDEN();
		break;

		// materia³ - czarna guma
	case BLACK_RUBBER:
		ambientJEDEN = BlackRubberAmbient;
		diffuseJEDEN = BlackRubberDiffuse;
		specularJEDEN = BlackRubberSpecular;
		shininessJEDEN = BlackRubberShininess;
		DisplaySceneJEDEN();
		break;

		// obszar renderingu - ca³e okno
	case FULL_WINDOW:
		aspectJEDEN = FULL_WINDOW;
		ReshapeJEDEN(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspectJEDEN = ASPECT_1_1;
		ReshapeJEDEN(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjœcie
	case EXIT:
		exit(0);
	}
}

void ExtensionSetupJEDEN()
{
	// pobranie numeru wersji biblioteki OpenGL
	const char *version = (char*)glGetString(GL_VERSION);

	// odczyt wersji OpenGL
	int major = 0, minor = 0;
	if (sscanf(version, "%d.%d", &major, &minor) != 2)
	{
#ifndef WIN32
		printf("B³êdny format wersji OpenGL\n");
#else

		printf("Bledny format wersji OpenGL\n");
#endif

		exit(0);
	}

	// sprawdzenie czy jest co najmniej wersja 1.4
	if (major > 1 || minor >= 4)
	{
		// pobranie wskaŸnika wybranej funkcji OpenGL 1.4
		glWindowPos2iJEDEN = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
	}
	else
		// sprawdzenie czy jest obs³ugiwane rozszerzenie ARB_window_pos
		if (glutExtensionSupported("GL_ARB_window_pos"))
		{
			// pobranie wskaŸnika wybranej funkcji rozszerzenia ARB_window_pos
			glWindowPos2iJEDEN = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress
				("glWindowPos2iARB");
		}
		else
		{
			printf("Brak rozszerzenia ARB_window_pos!\n");
			exit(0);
		}
}

int mainJEDEN(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// rozmiary g³ównego okna programu
	glutInitWindowSize(500, 500);

	// utworzenie g³ównego okna programu

#ifdef WIN32

	glutCreateWindow("œwiat³o kierunkowe");
#else

	glutCreateWindow("Swiatlo kierunkowe");
#endif

	// do³¹czenie funkcji generuj¹cej scenê 3D
	glutDisplayFunc(DisplaySceneJEDEN);

	// do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
	glutReshapeFunc(ReshapeJEDEN);

	// do³¹czenie funkcji obs³ugi klawiatury
	glutKeyboardFunc(KeyboardJEDEN);

	// do³¹czenie funkcji obs³ugi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeysJEDEN);

	// obs³uga przycisków myszki
	glutMouseFunc(MouseButtonJEDEN);

	// obs³uga ruchu kursora myszki
	glutMotionFunc(MouseMotionJEDEN);

	// utworzenie menu podrêcznego
	glutCreateMenu(MenuJEDEN);

	// utworzenie podmenu - obiekt
	int MenuObject = glutCreateMenu(MenuJEDEN);
	glutAddMenuEntry("Kula", SPHERE);
	glutAddMenuEntry("Czajnik", TEAPOT);

#ifdef WIN32

	glutAddMenuEntry("Sto¿ek", CONE);
	glutAddMenuEntry("Torus", TORUS);
	glutAddMenuEntry("Szeœcian", CUBE);
	glutAddMenuEntry("Dwunastoœcian", DODECAHEDRON);
	glutAddMenuEntry("Oœmioœcian", OCTAHEDRON);
	glutAddMenuEntry("Czworoœcian", TETRAHEDRON);
	glutAddMenuEntry("Dwudziestoœcian", ICOSAHEDRON);
#else

	glutAddMenuEntry("Stozek", CONE);
	glutAddMenuEntry("Torus", TORUS);
	glutAddMenuEntry("Szescian", CUBE);
	glutAddMenuEntry("Dwunastoscian", DODECAHEDRON);
	glutAddMenuEntry("Osmioscian", OCTAHEDRON);
	glutAddMenuEntry("Czworoscian", TETRAHEDRON);
	glutAddMenuEntry("Dwudziestoscian", ICOSAHEDRON);
#endif

	// utworzenie podmenu - Materia³
	int MenuMaterial = glutCreateMenu(MenuJEDEN);
#ifdef WIN32

	glutAddMenuEntry("Mosi¹dz", BRASS);
	glutAddMenuEntry("Br¹z", BRONZE);
	glutAddMenuEntry("Polerowany br¹z", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("MiedŸ", COPPER);
	glutAddMenuEntry("Polerowana miedŸ", POLISHED_COPPER);
	glutAddMenuEntry("Z³oto", GOLD);
	glutAddMenuEntry("Polerowane z³oto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Per³a", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#else

	glutAddMenuEntry("Mosiadz", BRASS);
	glutAddMenuEntry("Braz", BRONZE);
	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedz", COPPER);
	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
	glutAddMenuEntry("Zloto", GOLD);
	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Perla", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#endif

	// utworzenie podmenu - Aspekt obrazu
	int MenuAspect = glutCreateMenu(MenuJEDEN);
#ifdef WIN32

	glutAddMenuEntry("Aspekt obrazu - ca³e okno", FULL_WINDOW);
#else

	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu g³ówne
	glutCreateMenu(MenuJEDEN);
	glutAddSubMenu("Obiekt", MenuObject);

#ifdef WIN32

	glutAddSubMenu("Materia³", MenuMaterial);
#else

	glutAddSubMenu("Material", MenuMaterial);
#endif

	glutAddSubMenu("Aspekt obrazu", MenuAspect);
#ifdef WIN32

	glutAddMenuEntry("Wyjœcie", EXIT);
#else

	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	// okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// sprawdzenie i przygotowanie obs³ugi wybranych rozszerzeñ
	ExtensionSetupJEDEN();

	// wprowadzenie programu do obs³ugi pêtli komunikatów
	glutMainLoop();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 2 PROGRAM ////////////////////////////////////////////////////////////////////////////
void DrawStringDWA(GLfloat x, GLfloat y, char *string)
{
	// po³o?enie napisu
	glRasterPos2f(x, y);

	// wyœwietlenie napisu
	int len = strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void DisplayDWA()
{
	// kolor t³a - zawartoœ? bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru i bufora g³êbokoœci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesuniêcie uk³adu wspó³rzêdnych szeœcianu do œrodka bry³y odcinania
	glTranslatef(0, 0, -(near_DWA + far_DWA) / 2);

	// obroty szeœcianu
	glRotatef(rotatexDWA, 1.0, 0, 0);
	glRotatef(rotateyDWA, 0, 1.0, 0);

	// niewielkie powiêkszenie szeœcianu
	glScalef(1.15, 1.15, 1.15);

	// w³¹czenie oœwietlenia
	glEnable(GL_LIGHTING);

	// parametry globalnego œwiat³a otaczaj¹cego
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_lightDWA);

	// w³¹czenie obs³ugi w³aœciwoœci materia³ów
	glEnable(GL_COLOR_MATERIAL);

	// w³aœciwoœci materia³u okreœlone przez kolor wierzcho³ków
	glColorMaterial(GL_FRONT, GL_AMBIENT);

	// w³¹czenie testu bufora g³êbokoœci
	glEnable(GL_DEPTH_TEST);

	// rysowanie szeœcianu - 12 trójk¹tów
	glBegin(GL_TRIANGLES);
	glColor3fv(Red);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);

	glColor3fv(Magenta);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);

	glColor3fv(Cyan);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glColor3fv(Lime);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);

	glColor3fv(Blue);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);

	glColor3fv(Yellow);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);

	// koniec definicji szeœcianu
	glEnd();

	// wy³¹czenie oœwietlenia
	glDisable(GL_LIGHTING);

	// wy³¹czenie obs³ugi w³aœciwoœci materia³ów
	glDisable(GL_COLOR_MATERIAL);

	// wyœwietlenie sk³adowych globalnego œwiat³a otaczaj¹cego
	char string[100];
	GLfloat rgba[4];
	glColor3fv(Black);

	// pobranie wartoœci sk³adowych œwiat³a otaczaj¹cego
	// (oczywiœcie wartoœci te odpowiadaj¹ tablicy ambient_lightDWA)
	glGetFloatv(GL_LIGHT_MODEL_AMBIENT, rgba);
	sprintf(string, "AMBIENT: R=%f G=%f B=%f A=%f", rgba[0], rgba[1], rgba[2], rgba[3]);

	// trzeba odpowiednio przekszta³ci? uk³ad wspó³rzêdnych
	// aby napis znajdowa³ siê na samej "górze" bry³y obcinania
	glLoadIdentity();
	glTranslatef(0, 0, -near_DWA);

	// narysowanie napisu
	DrawStringDWA(leftDWA, bottomDWA, string);

	// skierowanie polece? do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

void ReshapeDWA(int width, int height)
{
	// obszar renderingu - ca³e okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bry³y obcinania
	if (aspectDWA == ASPECT_1_1)
	{
		// wysokoœ? okna wiêksza od wysokoœci okna
		if (width < height && width > 0)
			glFrustum(leftDWA, rightDWA, bottomDWA*height / width, topDWA*height / width, near_DWA, far_DWA);
		else

			// szerokoœ? okna wiêksza lub równa wysokoœci okna
			if (width >= height && height > 0)
				glFrustum(leftDWA*width / height, rightDWA*width / height, bottomDWA, topDWA, near_DWA, far_DWA);
	}
	else
		glFrustum(leftDWA, rightDWA, bottomDWA, topDWA, near_DWA, far_DWA);

	// generowanie sceny 3D
	DisplayDWA();
}

void KeyboardDWA(unsigned char key, int x, int y)
{
	// zmiana wartoœci sk³adowej R
	if (key == 'R' && ambient_lightDWA[0] < 1.0)
		ambient_lightDWA[0] += 0.05;
	else
		if (key == 'r' && ambient_lightDWA[0] > -1.0)
			ambient_lightDWA[0] -= 0.05;

	// zmiana wartoœci sk³adowej G
	if (key == 'G' && ambient_lightDWA[1] < 1.0)
		ambient_lightDWA[1] += 0.05;
	else
		if (key == 'g' && ambient_lightDWA[1] > -1.0)
			ambient_lightDWA[1] -= 0.05;

	// zmiana wartoœci sk³adowej B
	if (key == 'B' && ambient_lightDWA[2] < 1.0)
		ambient_lightDWA[2] += 0.05;
	else
		if (key == 'b' && ambient_lightDWA[2] > -1.0)
			ambient_lightDWA[2] -= 0.05;

	// narysowanie sceny
	DisplayDWA();
}

void KeyboardDWA(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotateyDWA -= 1;
		break;

		// kursor w górê
	case GLUT_KEY_UP:
		rotatexDWA -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotateyDWA += 1;
		break;

		// kursor w dó³
	case GLUT_KEY_DOWN:
		rotatexDWA += 1;
		break;
	}

	// odrysowanie okna
	ReshapeDWA(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void MouseButtonDWA(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiêtanie stanu lewego przycisku myszki
		button_stateDWA = state;

		// zapamiêtanie po³o?enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_xDWA = x;
			button_yDWA = y;
		}
	}
}

void MouseMotionDWA(int x, int y)
{
	if (button_stateDWA == GLUT_DOWN)
	{
		rotateyDWA += 30 * (rightDWA - leftDWA) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_xDWA);
		button_xDWA = x;
		rotatexDWA -= 30 * (topDWA - bottomDWA) / glutGet(GLUT_WINDOW_HEIGHT) * (button_yDWA - y);
		button_yDWA = y;
		glutPostRedisplay();
	}
}

void MenuDWA(int value)
{
	switch (value)
	{
		// obszar renderingu - ca³e okno
	case FULL_WINDOW:
		aspectDWA = FULL_WINDOW;
		ReshapeDWA(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspectDWA = ASPECT_1_1;
		ReshapeDWA(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjœcie
	case EXIT:
		exit(0);
	}
}

int mainDWA(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// rozmiary g³ównego okna programu
	glutInitWindowSize(500, 500);

	// utworzenie g³ównego okna programu
#ifdef WIN32

	glutCreateWindow("Globalne œwiat³o otaczaj¹ce");
#else

	glutCreateWindow("Globalne swiatlo otaczajace");
#endif

	// do³¹czenie funkcji generuj¹cej scenê 3D
	glutDisplayFunc(DisplayDWA);

	// do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
	glutReshapeFunc(ReshapeDWA);

	// do³¹czenie funkcji obs³ugi klawiatury
	glutKeyboardFunc(KeyboardDWA);

	// do³¹czenie funkcji obs³ugi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(KeyboardDWA);

	// obs³uga przycisków myszki
	glutMouseFunc(MouseButtonDWA);

	// obs³uga ruchu kursora myszki
	glutMotionFunc(MouseMotionDWA);

	// utworzenie menu podrêcznego
	glutCreateMenu(MenuDWA);

	// utworzenie podmenu - aspekt obrazu
	int MenuDWAAspect = glutCreateMenu(MenuDWA);
#ifdef WIN32

	glutAddMenuEntry("Aspekt obrazu - ca³e okno", FULL_WINDOW);
#else

	glutAddMenuDWAEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu g³ówne
	glutCreateMenu(MenuDWA);
	glutAddSubMenu("Aspekt obrazu", MenuDWAAspect);
#ifdef WIN32

	glutAddMenuEntry("Wyjœcie", EXIT);
#else

	glutAddMenuDWAEntry("Wyjscie", EXIT);
#endif

	// okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// wprowadzenie programu do obs³ugi pêtli komunikatów
	glutMainLoop();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 3 PROGRAM ////////////////////////////////////////////////////////////////////////////
void DrawStringTRZY(GLint x, GLint y, char *string)
{
	// po³o¿enie napisu
	glWindowPos2iTRZY(x, y);

	// wyœwietlenie napisu
	int len = strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void DisplaySceneTRZY()
{
	// kolor t³a - zawartoœ? bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru i bufora g³?bokoœci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// w³¹czenie testu bufora g³?bokoœci
	glEnable(GL_DEPTH_TEST);

	// w³¹czenie oœwietlenia
	glEnable(GL_LIGHTING);

	// w³¹czenie œwiat³a GL_LIGHT0
	glEnable(GL_LIGHT0);

	// w³¹czenie automatycznej normalizacji wektorów normalnych
	glEnable(GL_NORMALIZE);

	// przesuni?cie uk³adu wspó³rz?dnych obiektu do œrodka bry³y odcinania
	glTranslatef(0, 0, -(nearTRZY + farTRZY) / 2);

	// obroty obiektu
	glRotatef(rotatexTRZY, 1.0, 0, 0);
	glRotatef(rotateyTRZY, 0, 1.0, 0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scaleTRZY, scaleTRZY, scaleTRZY);

	// w³aœciwoœci materia³u
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientTRZY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseTRZY);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularTRZY);
	glMaterialf(GL_FRONT, GL_SHININESS, shininessTRZY);

	// k¹t odci?cia reflektora
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoffTRZY);

	// wyk³adnik t³umienia k¹towego reflektora
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponentTRZY);

	// sta³y wspó³czynnik t³umienia œwiat³a,
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constatn_attentuationTRZY);

	// liniowy wspó³czynnik t³umienia œwiat³a
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linearTRZY_attenuation);

	// kwadratowy wspó³czynnik t³umienia œwiat³a
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticTRZY);

	// zmiana po³o¿enia Ÿród³a œwiat³a jest wykonywana niezale¿nie
	// od obrotów obiektu, st¹d od³o¿enie na stos macierzy modelowania
	glPushMatrix();

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesuni?cie uk³adu wspó³rz?dnych Ÿród³a œwiat³a do œrodka bry³y odcinania
	glTranslatef(0, 0, -(nearTRZY + farTRZY) / 2);

	// obroty po³o¿enia Ÿród³a œwiat³a - klawisze kursora
	glRotatef(light_rotatexTRZY, 1.0, 0, 0);
	glRotatef(light_rotateyTRZY, 0, 1.0, 0);

	// przesuni?cie Ÿród³a œwiat³a
	glTranslatef(light_positionTRZY[0], light_positionTRZY[1], light_positionTRZY[2]);

	// ustalenie pozycji Ÿród³a œwiat³a
	glLightfv(GL_LIGHT0, GL_POSITION, light_positionTRZY);

	// ustalenie kierunku reflektora
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_directionTRZY);

	// od³o¿enie na stos zmiennych stanu zwi¹zanych z oœwietleniem sceny
	glPushAttrib(GL_LIGHTING_BIT);

	// wy³acznie Ÿród³a œwiat³a GL_LIGHT0
	glDisable(GL_LIGHT0);

	// materia³ imituj¹cy œwiecenie kuli na czerwono
	glMaterialfv(GL_FRONT, GL_EMISSION, Red);

	// narysowanie kuli po³o¿onej w pocz¹tku Ÿród³a œwiat³a
	glutSolidSphere(0.1, 30, 20);

	// przywrócenie zmiennych stanu zwi¹zanych z oœwietleniem sceny
	glPopAttrib();

	// przywrócenie pierwotnej macierzy modelowania
	glPopMatrix();

	// rysowanie wybranego obiektu 3D
	switch (objectTRZY)
	{
		// kula
	case SPHERE:
		glutSolidSphere(1.0, 50, 40);
		break;

		// czajnik
	case TEAPOT:
		glutSolidTeapot(1);
		break;

		// sto¿ek
	case CONE:
		glutSolidCone(1, 1, 50, 40);
		break;

		// torus
	case TORUS:
		glutSolidTorus(0.3, 1, 40, 50);
		break;

		// szeœcian
	case CUBE:
		glutSolidCube(1);
		break;

		// dwunastoœcian
	case DODECAHEDRON:
		glutSolidDodecahedron();
		break;

		// oœmioœcian
	case OCTAHEDRON:
		glutSolidOctahedron();
		break;

		// czworoœcian
	case TETRAHEDRON:
		glutSolidTetrahedron();
		break;

		// dwudziestoœcian
	case ICOSAHEDRON:
		glutSolidIcosahedron();
		break;
	}

	// informacje o wartoœciach modyfikowanych
	// parametrów Ÿród³a œwiata³a GL_LIGHT0
	char string[200];
	GLfloat vec[4];
	glColor3fv(Black);

	// kierunek Ÿród³a œwiat³a
	glGetLightfv(GL_LIGHT0, GL_POSITION, vec);
	sprintf(string, "GL_POSITION = (%f,%f,%f,%f)", vec[0], vec[1], vec[2], vec[3]);
	DrawStringTRZY(2, 2, string);

	glGetLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, vec);
	sprintf(string, "GL_SPOT_DIRECTION = (%f,%f,%f)", vec[0], vec[1], vec[2]);
	DrawStringTRZY(2, 16, string);

	// k¹t odci?cia reflektora
	glGetLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, vec);
	sprintf(string, "GL_SPOT_CUTOFF = %f", vec[0]);
	DrawStringTRZY(2, 30, string);

	// wyk³adnik t³umienia k¹towego reflektora
	glGetLightfv(GL_LIGHT0, GL_SPOT_EXPONENT, vec);
	sprintf(string, "GL_SPOT_EXPONENT = %f", vec[0]);
	DrawStringTRZY(2, 44, string);

	// sta³y wspó³czynnik t³umienia œwiat³a,
	glGetLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, vec);
	sprintf(string, "GL_CONSTANT_ATTENUATION = %f", vec[0]);
	DrawStringTRZY(2, 58, string);

	// liniowy wspó³czynnik t³umienia œwiat³a
	glGetLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, vec);
	sprintf(string, "GL_LINEAR_ATTENUATION = %f", vec[0]);
	DrawStringTRZY(2, 72, string);

	// kwadratowy wspó³czynnik t³umienia œwiat³a
	glGetLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, vec);
	sprintf(string, "GL_QUADRATIC_ATTENUATION = %f", vec[0]);
	DrawStringTRZY(2, 86, string);

	// skierowanie polece? do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// obszar renderingu - ca³e okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bry³y obcinania
	if (aspect == ASPECT_1_1)
	{
		// wysokoœ? okna wi?ksza od wysokoœci okna
		if (width < height && width > 0)
			glFrustum(leftTRZY, rightTRZY, bottomTRZY*height / width, topTRZY*height / width, nearTRZY, farTRZY);
		else

			// szerokoœ? okna wi?ksza lub równa wysokoœci okna
			if (width >= height && height > 0)
				glFrustum(leftTRZY*width / height, rightTRZY*width / height, bottomTRZY, topTRZY, nearTRZY, farTRZY);
	}
	else
		glFrustum(leftTRZY, rightTRZY, bottomTRZY, topTRZY, nearTRZY, farTRZY);

	// generowanie sceny 3D
	DisplaySceneTRZY();
}

void KeyboardTRZY(unsigned char key, int x, int y)
{
	switch (key)
	{
		// klawisz "+" - powi?kszenie obiektu
	case '+':
		scaleTRZY += 0.05;
		break;

		// klawisz "-" - zmniejszenie obiektu
	case '-':
		if (scaleTRZY > 0.05)
			scaleTRZY -= 0.05;
		break;

		// klawisz "S" - zwi?kszenie k¹ta obci?cia reflektora
	case 'S':
		if (spot_cutoffTRZY == 90)
			spot_cutoffTRZY = 180;
		else
			if (spot_cutoffTRZY < 90)
				spot_cutoffTRZY++;
		break;

		// klawisz "s" - zmniejszenie k¹ta obci?cia reflektora
	case 's':
		if (spot_cutoffTRZY == 180)
			spot_cutoffTRZY = 90;
		else
			if (spot_cutoffTRZY > 0)
				spot_cutoffTRZY--;
		break;

		// klawisz "E" - zwi?kszenie wyk³adnika t³umienia k¹towego reflektora
	case 'E':
		if (spot_exponentTRZY < 128)
			spot_exponentTRZY++;
		break;

		// klawisz "e" - zmniejszenie wyk³adnika t³umienia k¹towego reflektora
	case 'e':
		if (spot_exponentTRZY > 0)
			spot_exponentTRZY--;
		break;

		// klawisz "C" - zwi?kszenie sta³ego wspó³czynnika t³umienia œwiat³a
	case 'C':
		constatn_attentuationTRZY += 0.1;
		break;

		// klawisz "c" - zmniejszenie sta³ego wspó³czynnika t³umienia œwiat³a
	case 'c':
		if (constatn_attentuationTRZY > 0)
			constatn_attentuationTRZY -= 0.1;
		break;

		// klawisz "L" - zwi?kszenie liniowego wspó³czynnika t³umienia œwiat³a
	case 'L':
		linearTRZY_attenuation += 0.1;
		break;

		// klawisz "l" - zmniejszenie liniowego wspó³czynnika t³umienia œwiat³a
	case 'l':
		if (linearTRZY_attenuation > 0)
			linearTRZY_attenuation -= 0.1;
		break;

		// klawisz "Q" - zwi?kszenie kwadratowego wspó³czynnika t³umienia œwiat³a
	case 'Q':
		quadraticTRZY += 0.1;
		break;

		// klawisz "q" - zmniejszenie kwadratowego wspó³czynnika t³umienia œwiat³a
	case 'q':
		if (quadraticTRZY > 0)
			quadraticTRZY -= 0.1;
		break;
	}

	// narysowanie sceny
	DisplaySceneTRZY();
}

void MouseButtonTRZY(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapami?tanie stanu lewego przycisku myszki
		button_stateTRZY = state;

		// zapami?tanie po³o¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_xTRZY = x;
			button_yTRZY = y;
		}
	}
}

void MouseMotionTRZY(int x, int y)
{
	if (button_stateTRZY == GLUT_DOWN)
	{
		rotateyTRZY += 30 * (rightTRZY - leftTRZY) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_xTRZY);
		button_xTRZY = x;
		rotatexTRZY -= 30 * (topTRZY - bottomTRZY) / glutGet(GLUT_WINDOW_HEIGHT) * (button_yTRZY - y);
		button_yTRZY = y;
		glutPostRedisplay();
	}
}

void SpecialKeysTRZY(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		light_rotateyTRZY -= 5;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		light_rotateyTRZY += 5;
		break;

		// kursor w dó³
	case GLUT_KEY_DOWN:
		light_rotatexTRZY += 5;
		break;

		// kursor w gór?
	case GLUT_KEY_UP:
		light_rotatexTRZY -= 5;
		break;
	}

	// odrysowanie okna
	DisplaySceneTRZY();
}

void MenuTRZY(int value)
{
	switch (value)
	{
		// rysowany obiekt - kula
	case SPHERE:
		objectTRZY = SPHERE;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - czajnik
	case TEAPOT:
		objectTRZY = TEAPOT;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - sto¿ek
	case CONE:
		objectTRZY = CONE;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - torus
	case TORUS:
		objectTRZY = TORUS;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - szeœcian
	case CUBE:
		objectTRZY = CUBE;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - dwunastoœcian
	case DODECAHEDRON:
		objectTRZY = DODECAHEDRON;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - oœmioœcian
	case OCTAHEDRON:
		objectTRZY = OCTAHEDRON;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - czworoœcian
	case TETRAHEDRON:
		objectTRZY = TETRAHEDRON;
		DisplaySceneTRZY();
		break;

		// rysowany obiekt - dwudziestoœcian
	case ICOSAHEDRON:
		objectTRZY = ICOSAHEDRON;
		DisplaySceneTRZY();
		break;

		// materia³ - mosi¹dz
	case BRASS:
		ambientTRZY = BrassAmbient;
		diffuseTRZY = BrassDiffuse;
		specularTRZY = BrassSpecular;
		shininessTRZY = BrassShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - br¹z
	case BRONZE:
		ambientTRZY = BronzeAmbient;
		diffuseTRZY = BronzeDiffuse;
		specularTRZY = BronzeSpecular;
		shininessTRZY = BronzeShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - polerowany br¹z
	case POLISHED_BRONZE:
		ambientTRZY = PolishedBronzeAmbient;
		diffuseTRZY = PolishedBronzeDiffuse;
		specularTRZY = PolishedBronzeSpecular;
		shininessTRZY = PolishedBronzeShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - chrom
	case CHROME:
		ambientTRZY = ChromeAmbient;
		diffuseTRZY = ChromeDiffuse;
		specularTRZY = ChromeSpecular;
		shininessTRZY = ChromeShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - miedŸ
	case COPPER:
		ambientTRZY = CopperAmbient;
		diffuseTRZY = CopperDiffuse;
		specularTRZY = CopperSpecular;
		shininessTRZY = CopperShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - polerowana miedŸ
	case POLISHED_COPPER:
		ambientTRZY = PolishedCopperAmbient;
		diffuseTRZY = PolishedCopperDiffuse;
		specularTRZY = PolishedCopperSpecular;
		shininessTRZY = PolishedCopperShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - z³oto
	case GOLD:
		ambientTRZY = GoldAmbient;
		diffuseTRZY = GoldDiffuse;
		specularTRZY = GoldSpecular;
		shininessTRZY = GoldShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - polerowane z³oto
	case POLISHED_GOLD:
		ambientTRZY = PolishedGoldAmbient;
		diffuseTRZY = PolishedGoldDiffuse;
		specularTRZY = PolishedGoldSpecular;
		shininessTRZY = PolishedGoldShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - grafit (cyna z o³owiem)
	case PEWTER:
		ambientTRZY = PewterAmbient;
		diffuseTRZY = PewterDiffuse;
		specularTRZY = PewterSpecular;
		shininessTRZY = PewterShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - srebro
	case SILVER:
		ambientTRZY = SilverAmbient;
		diffuseTRZY = SilverDiffuse;
		specularTRZY = SilverSpecular;
		shininessTRZY = SilverShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - polerowane srebro
	case POLISHED_SILVER:
		ambientTRZY = PolishedSilverAmbient;
		diffuseTRZY = PolishedSilverDiffuse;
		specularTRZY = PolishedSilverSpecular;
		shininessTRZY = PolishedSilverShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - szmaragd
	case EMERALD:
		ambientTRZY = EmeraldAmbient;
		diffuseTRZY = EmeraldDiffuse;
		specularTRZY = EmeraldSpecular;
		shininessTRZY = EmeraldShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - jadeit
	case JADE:
		ambientTRZY = JadeAmbient;
		diffuseTRZY = JadeDiffuse;
		specularTRZY = JadeSpecular;
		shininessTRZY = JadeShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - obsydian
	case OBSIDIAN:
		ambientTRZY = ObsidianAmbient;
		diffuseTRZY = ObsidianDiffuse;
		specularTRZY = ObsidianSpecular;
		shininessTRZY = ObsidianShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - per³a
	case PEARL:
		ambientTRZY = PearlAmbient;
		diffuseTRZY = PearlDiffuse;
		specularTRZY = PearlSpecular;
		shininessTRZY = PearlShininess;
		DisplaySceneTRZY();
		break;

		// metaria³ - rubin
	case RUBY:
		ambientTRZY = RubyAmbient;
		diffuseTRZY = RubyDiffuse;
		specularTRZY = RubySpecular;
		shininessTRZY = RubyShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - turkus
	case TURQUOISE:
		ambientTRZY = TurquoiseAmbient;
		diffuseTRZY = TurquoiseDiffuse;
		specularTRZY = TurquoiseSpecular;
		shininessTRZY = TurquoiseShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - czarny plastik
	case BLACK_PLASTIC:
		ambientTRZY = BlackPlasticAmbient;
		diffuseTRZY = BlackPlasticDiffuse;
		specularTRZY = BlackPlasticSpecular;
		shininessTRZY = BlackPlasticShininess;
		DisplaySceneTRZY();
		break;

		// materia³ - czarna guma
	case BLACK_RUBBER:
		ambientTRZY = BlackRubberAmbient;
		diffuseTRZY = BlackRubberDiffuse;
		specularTRZY = BlackRubberSpecular;
		shininessTRZY = BlackRubberShininess;
		DisplaySceneTRZY();
		break;

		// obszar renderingu - ca³e okno
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjœcie
	case EXIT:
		exit(0);
	}
}

void ExtensionSetupTRZY()
{
	// pobranie numeru wersji biblioteki OpenGL
	const char *version = (char*)glGetString(GL_VERSION);

	// odczyt wersji OpenGL
	int major = 0, minor = 0;
	if (sscanf(version, "%d.%d", &major, &minor) != 2)
	{
#ifndef WIN32
		printf("B³?dny format wersji OpenGL\n");
#else

		printf("Bledny format wersji OpenGL\n");
#endif

		exit(0);
	}

	// sprawdzenie czy jest co najmniej wersja 1.4
	if (major > 1 || minor >= 4)
	{
		// pobranie wskaŸnika wybranej funkcji OpenGL 1.4
		glWindowPos2iTRZY = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
	}
	else
		// sprawdzenie czy jest obs³ugiwane rozszerzenie ARB_window_pos
		if (glutExtensionSupported("GL_ARB_window_pos"))
		{
			// pobranie wskaŸnika wybranej funkcji rozszerzenia ARB_window_pos
			glWindowPos2iTRZY = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress
				("glWindowPos2iARB");
		}
		else
		{
			printf("Brak rozszerzenia ARB_window_pos!\n");
			exit(0);
		}
}

int mainTRZY(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// rozmiary g³ównego okna programu
	glutInitWindowSize(500, 500);

	// utworzenie g³ównego okna programu
	glutCreateWindow("Reflektor");

	// do³¹czenie funkcji generuj¹cej scen? 3D
	glutDisplayFunc(DisplaySceneTRZY);

	// do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);

	// do³¹czenie funkcji obs³ugi klawiatury
	glutKeyboardFunc(KeyboardTRZY);

	// do³¹czenie funkcji obs³ugi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeysTRZY);

	// obs³uga przycisków myszki
	glutMouseFunc(MouseButtonTRZY);

	// obs³uga ruchu kursora myszki
	glutMotionFunc(MouseMotionTRZY);

	// utworzenie menu podr?cznego
	glutCreateMenu(MenuTRZY);

	// utworzenie podmenu - obiekt
	int MenuTRZYObject = glutCreateMenu(MenuTRZY);
	glutAddMenuEntry("Kula", SPHERE);
	glutAddMenuEntry("Czajnik", TEAPOT);

#ifdef WIN32

	glutAddMenuEntry("Sto¿ek", CONE);
	glutAddMenuEntry("Torus", TORUS);
	glutAddMenuEntry("Szeœcian", CUBE);
	glutAddMenuEntry("Dwunastoœcian", DODECAHEDRON);
	glutAddMenuEntry("Oœmioœcian", OCTAHEDRON);
	glutAddMenuEntry("Czworoœcian", TETRAHEDRON);
	glutAddMenuEntry("Dwudziestoœcian", ICOSAHEDRON);
#else

	glutAddMenuEntry("Stozek", CONE);
	glutAddMenuEntry("Torus", TORUS);
	glutAddMenuEntry("Szescian", CUBE);
	glutAddMenuEntry("Dwunastoscian", DODECAHEDRON);
	glutAddMenuEntry("Osmioscian", OCTAHEDRON);
	glutAddMenuEntry("Czworoscian", TETRAHEDRON);
	glutAddMenuEntry("Dwudziestoscian", ICOSAHEDRON);
#endif

	// utworzenie podmenu - Materia³
	int MenuTRZYMaterial = glutCreateMenu(MenuTRZY);
#ifdef WIN32

	glutAddMenuEntry("Mosi¹dz", BRASS);
	glutAddMenuEntry("Br¹z", BRONZE);
	glutAddMenuEntry("Polerowany br¹z", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("MiedŸ", COPPER);
	glutAddMenuEntry("Polerowana miedŸ", POLISHED_COPPER);
	glutAddMenuEntry("Z³oto", GOLD);
	glutAddMenuEntry("Polerowane z³oto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Per³a", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#else

	glutAddMenuTRZYEntry("Mosiadz", BRASS);
	glutAddMenuTRZYEntry("Braz", BRONZE);
	glutAddMenuTRZYEntry("Polerowany braz", POLISHED_BRONZE);
	glutAddMenuTRZYEntry("Chrom", CHROME);
	glutAddMenuTRZYEntry("Miedz", COPPER);
	glutAddMenuTRZYEntry("Polerowana miedz", POLISHED_COPPER);
	glutAddMenuTRZYEntry("Zloto", GOLD);
	glutAddMenuTRZYEntry("Polerowane zloto", POLISHED_GOLD);
	glutAddMenuTRZYEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuTRZYEntry("Srebro", SILVER);
	glutAddMenuTRZYEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuTRZYEntry("Szmaragd", EMERALD);
	glutAddMenuTRZYEntry("Jadeit", JADE);
	glutAddMenuTRZYEntry("Obsydian", OBSIDIAN);
	glutAddMenuTRZYEntry("Perla", PEARL);
	glutAddMenuTRZYEntry("Rubin", RUBY);
	glutAddMenuTRZYEntry("Turkus", TURQUOISE);
	glutAddMenuTRZYEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuTRZYEntry("Czarna guma", BLACK_RUBBER);
#endif

	// utworzenie podmenu - Aspekt obrazu
	int MenuTRZYAspect = glutCreateMenu(MenuTRZY);
#ifdef WIN32

	glutAddMenuEntry("Aspekt obrazu - ca³e okno", FULL_WINDOW);
#else

	glutAddMenuTRZYEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu g³ówne
	glutCreateMenu(MenuTRZY);
	glutAddSubMenu("Obiekt", MenuTRZYObject);

#ifdef WIN32

	glutAddSubMenu("Materia³", MenuTRZYMaterial);
#else

	glutAddSubMenu("Material", MenuTRZYMaterial);
#endif

	glutAddSubMenu("Aspekt obrazu", MenuTRZYAspect);
#ifdef WIN32

	glutAddMenuEntry("Wyjœcie", EXIT);
#else

	glutAddMenuTRZYEntry("Wyjscie", EXIT);
#endif

	// okreœlenie przycisku myszki obs³uguj¹cej menu podr?czne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// sprawdzenie i przygotowanie obs³ugi wybranych rozszerze?
	ExtensionSetupTRZY();

	// wprowadzenie programu do obs³ugi p?tli komunikatów
	glutMainLoop();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// 4 PROGRAM ////////////////////////////////////////////////////////////////////////////
void NormalCZTERY(GLfloat *n, int i)
{
	GLfloat v1[3], v2[3];

	// obliczenie wektorów na podstawie wspó³rzêdnych wierzcho³ków trójk¹tów
	v1[0] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 0] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 0] + 0];
	v1[1] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 1] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 0] + 1];
	v1[2] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 2] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 0] + 2];
	v2[0] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 2] + 0] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 0];
	v2[1] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 2] + 1] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 1];
	v2[2] = vertexCZTERY[3 * trianglesCZTERY[3 * i + 2] + 2] - vertexCZTERY[3 * trianglesCZTERY[3 * i + 1] + 2];

	// obliczenie waktora normalnego przy pomocy iloczynu wektorowego
	n[0] = v1[1] * v2[2] - v1[2] * v2[1];
	n[1] = v1[2] * v2[0] - v1[0] * v2[2];
	n[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void NormalizeCZTERY(GLfloat *v)
{
	// obliczenie d³ugoœci wektora
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

	// normalizacja wektora
	if (d)
	{
		v[0] /= d;
		v[1] /= d;
		v[2] /= d;
	}
}

void DisplayCZTERY()
{
	// kolor t³a - zawartoœæ bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru i bufora g³êbokoœci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesuniêcie uk³adu wspó³rzêdnych obiektu do œrodka bry³y odcinania
	glTranslatef(0, 0, -(nearCZTERY + farCZTERY) / 2);

	// obroty obiektu
	glRotatef(rotatexCZTERY, 1.0, 0, 0);
	glRotatef(rotateyCZTERY, 0, 1.0, 0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scaleCZTERY, scaleCZTERY, scaleCZTERY);

	// w³¹czenie testu bufora g³êbokoœci
	glEnable(GL_DEPTH_TEST);

	// w³¹czenie oœwietlenia
	glEnable(GL_LIGHTING);

	// w³¹czenie œwiat³a GL_LIGHT0 z parametrami domyœlnymi
	glEnable(GL_LIGHT0);

	// w³aœciwoœci materia³u
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientCZTERY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseCZTERY);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularCZTERY);
	glMaterialf(GL_FRONT, GL_SHININESS, shininesCZTERY);

	// w³¹czenie automatycznej normalizacji wektorów normalnych
	// lub automatycznego skalowania jednostkowych wektorów normalnych
	if (rescaleCZTERY_normal == true)
		glEnable(GL_RESCALE_NORMAL);
	else
		glEnable(GL_NORMALIZE);

	// pocz¹tek definicji obiektu
	glBegin(GL_TRIANGLES);

	// generowanie obiektu g³adkiego - jeden uœredniony
	// wektor normalny na wierzcho³ek
	if (normalsCZTERY == NORMALS_SMOOTH)
		for (int i = 0; i < 20; i++)
		{
			// obliczanie wektora normalnego dla pierwszego wierzcho³ka
			GLfloat n[3];
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich œcian posiadaj¹cych bie?¹cy wierzcho³ek
			for (int j = 0; j < 20; j++)
				if (3 * trianglesCZTERY[3 * i + 0] == 3 * trianglesCZTERY[3 * j + 0] ||
					3 * trianglesCZTERY[3 * i + 0] == 3 * trianglesCZTERY[3 * j + 1] ||
					3 * trianglesCZTERY[3 * i + 0] == 3 * trianglesCZTERY[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych œcian
					GLfloat nv[3];
					NormalCZTERY(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uœredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obs³uguje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescaleCZTERY_normal == true)
				NormalizeCZTERY(n);
			glNormal3fv(n);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 0]]);

			// obliczanie wektora normalnego dla drugiego wierzcho³ka
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich œcian posiadaj¹cych bie?¹cy wierzcho³ek
			for (int j = 0; j < 20; j++)
				if (3 * trianglesCZTERY[3 * i + 1] == 3 * trianglesCZTERY[3 * j + 0] ||
					3 * trianglesCZTERY[3 * i + 1] == 3 * trianglesCZTERY[3 * j + 1] ||
					3 * trianglesCZTERY[3 * i + 1] == 3 * trianglesCZTERY[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych œcian
					GLfloat nv[3];
					NormalCZTERY(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uœredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obs³uguje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescaleCZTERY_normal == true)
				NormalizeCZTERY(n);
			glNormal3fv(n);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 1]]);

			// obliczanie wektora normalnego dla trzeciego wierzcho³ka
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich œcian posiadaj¹cych bie?¹cy wierzcho³ek
			for (int j = 0; j < 20; j++)
				if (3 * trianglesCZTERY[3 * i + 2] == 3 * trianglesCZTERY[3 * j + 0] ||
					3 * trianglesCZTERY[3 * i + 2] == 3 * trianglesCZTERY[3 * j + 1] ||
					3 * trianglesCZTERY[3 * i + 2] == 3 * trianglesCZTERY[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych œcian
					GLfloat nv[3];
					NormalCZTERY(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uœredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obs³uguje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescaleCZTERY_normal == true)
				NormalizeCZTERY(n);
			glNormal3fv(n);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 2]]);
		}
	else

		// generowanie obiektu "p³askiego" - jeden wektor normalny na œcianê
		for (int i = 0; i < 20; i++)
		{
			GLfloat n[3];
			NormalCZTERY(n, i);

			// uœredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obs³uguje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescaleCZTERY_normal == true)
				NormalizeCZTERY(n);
			glNormal3fv(n);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 0]]);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 1]]);
			glVertex3fv(&vertexCZTERY[3 * trianglesCZTERY[3 * i + 2]]);
		}

	// koniec definicji obiektu
	glEnd();

	// skierowanie polece? do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

void ReshapeCZTERY(int width, int height)
{
	// obszar renderingu - ca³e okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bry³y obcinania
	if (aspectCZTERY == ASPECT_1_1)
	{
		// wysokoœæ okna wiêksza od wysokoœci okna
		if (width < height && width > 0)
			glFrustum(leftCZTERY, rightCZTERY, bottomCZTERY*height / width, topCZTERY*height / width, nearCZTERY, farCZTERY);
		else

			// szerokoœæ okna wiêksza lub równa wysokoœci okna
			if (width >= height && height > 0)
				glFrustum(leftCZTERY*width / height, rightCZTERY*width / height, bottomCZTERY, topCZTERY, nearCZTERY, farCZTERY);
	}
	else
		glFrustum(leftCZTERY, rightCZTERY, bottomCZTERY, topCZTERY, nearCZTERY, farCZTERY);

	// generowanie sceny 3D
	DisplayCZTERY();
}

void KeyboardCZTERY(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scaleCZTERY += 0.05;
	else

		// klawisz -
		if (key == '-' && scaleCZTERY > 0.05)
			scaleCZTERY -= 0.05;

	// narysowanie sceny
	DisplayCZTERY();
}

void SpecialKeysCZTERY(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotateyCZTERY -= 1;
		break;

		// kursor w górê
	case GLUT_KEY_UP:
		rotatexCZTERY -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotateyCZTERY += 1;
		break;

		// kursor w dó³
	case GLUT_KEY_DOWN:
		rotatexCZTERY += 1;
		break;
	}

	// odrysowanie okna
	ReshapeCZTERY(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void MouseButtonCZTERY(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiêtanie stanu lewego przycisku myszki
		button_stateCZTERY = state;

		// zapamiêtanie po³o?enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_xCZTERY = x;
			button_yCZTERY = y;
		}
	}
}

void MouseMotionCZTERY(int x, int y)
{
	if (button_stateCZTERY == GLUT_DOWN)
	{
		rotateyCZTERY += 30 * (rightCZTERY - leftCZTERY) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_xCZTERY);
		button_xCZTERY = x;
		rotatexCZTERY -= 30 * (topCZTERY - bottomCZTERY) / glutGet(GLUT_WINDOW_HEIGHT) * (button_yCZTERY - y);
		button_yCZTERY = y;
		glutPostRedisplay();
	}
}

void MenuCZTERY(int value)
{
	switch (value)
	{
		// materia³ - mosi¹dz
	case BRASS:
		ambientCZTERY = BrassAmbient;
		diffuseCZTERY = BrassDiffuse;
		specularCZTERY = BrassSpecular;
		shininesCZTERY = BrassShininess;
		DisplayCZTERY();
		break;

		// materia³ - br¹z
	case BRONZE:
		ambientCZTERY = BronzeAmbient;
		diffuseCZTERY = BronzeDiffuse;
		specularCZTERY = BronzeSpecular;
		shininesCZTERY = BronzeShininess;
		DisplayCZTERY();
		break;

		// materia³ - polerowany br¹z
	case POLISHED_BRONZE:
		ambientCZTERY = PolishedBronzeAmbient;
		diffuseCZTERY = PolishedBronzeDiffuse;
		specularCZTERY = PolishedBronzeSpecular;
		shininesCZTERY = PolishedBronzeShininess;
		DisplayCZTERY();
		break;

		// materia³ - chrom
	case CHROME:
		ambientCZTERY = ChromeAmbient;
		diffuseCZTERY = ChromeDiffuse;
		specularCZTERY = ChromeSpecular;
		shininesCZTERY = ChromeShininess;
		DisplayCZTERY();
		break;

		// materia³ - miedŸ
	case COPPER:
		ambientCZTERY = CopperAmbient;
		diffuseCZTERY = CopperDiffuse;
		specularCZTERY = CopperSpecular;
		shininesCZTERY = CopperShininess;
		DisplayCZTERY();
		break;

		// materia³ - polerowana miedŸ
	case POLISHED_COPPER:
		ambientCZTERY = PolishedCopperAmbient;
		diffuseCZTERY = PolishedCopperDiffuse;
		specularCZTERY = PolishedCopperSpecular;
		shininesCZTERY = PolishedCopperShininess;
		DisplayCZTERY();
		break;

		// materia³ - z³oto
	case GOLD:
		ambientCZTERY = GoldAmbient;
		diffuseCZTERY = GoldDiffuse;
		specularCZTERY = GoldSpecular;
		shininesCZTERY = GoldShininess;
		DisplayCZTERY();
		break;

		// materia³ - polerowane z³oto
	case POLISHED_GOLD:
		ambientCZTERY = PolishedGoldAmbient;
		diffuseCZTERY = PolishedGoldDiffuse;
		specularCZTERY = PolishedGoldSpecular;
		shininesCZTERY = PolishedGoldShininess;
		DisplayCZTERY();
		break;

		// materia³ - grafit (cyna z o³owiem)
	case PEWTER:
		ambientCZTERY = PewterAmbient;
		diffuseCZTERY = PewterDiffuse;
		specularCZTERY = PewterSpecular;
		shininesCZTERY = PewterShininess;
		DisplayCZTERY();
		break;

		// materia³ - srebro
	case SILVER:
		ambientCZTERY = SilverAmbient;
		diffuseCZTERY = SilverDiffuse;
		specularCZTERY = SilverSpecular;
		shininesCZTERY = SilverShininess;
		DisplayCZTERY();
		break;

		// materia³ - polerowane srebro
	case POLISHED_SILVER:
		ambientCZTERY = PolishedSilverAmbient;
		diffuseCZTERY = PolishedSilverDiffuse;
		specularCZTERY = PolishedSilverSpecular;
		shininesCZTERY = PolishedSilverShininess;
		DisplayCZTERY();
		break;

		// materia³ - szmaragd
	case EMERALD:
		ambientCZTERY = EmeraldAmbient;
		diffuseCZTERY = EmeraldDiffuse;
		specularCZTERY = EmeraldSpecular;
		shininesCZTERY = EmeraldShininess;
		DisplayCZTERY();
		break;

		// materia³ - jadeit
	case JADE:
		ambientCZTERY = JadeAmbient;
		diffuseCZTERY = JadeDiffuse;
		specularCZTERY = JadeSpecular;
		shininesCZTERY = JadeShininess;
		DisplayCZTERY();
		break;

		// materia³ - obsydian
	case OBSIDIAN:
		ambientCZTERY = ObsidianAmbient;
		diffuseCZTERY = ObsidianDiffuse;
		specularCZTERY = ObsidianSpecular;
		shininesCZTERY = ObsidianShininess;
		DisplayCZTERY();
		break;

		// materia³ - per³a
	case PEARL:
		ambientCZTERY = PearlAmbient;
		diffuseCZTERY = PearlDiffuse;
		specularCZTERY = PearlSpecular;
		shininesCZTERY = PearlShininess;
		DisplayCZTERY();
		break;

		// metaria³ - rubin
	case RUBY:
		ambientCZTERY = RubyAmbient;
		diffuseCZTERY = RubyDiffuse;
		specularCZTERY = RubySpecular;
		shininesCZTERY = RubyShininess;
		DisplayCZTERY();
		break;

		// materia³ - turkus
	case TURQUOISE:
		ambientCZTERY = TurquoiseAmbient;
		diffuseCZTERY = TurquoiseDiffuse;
		specularCZTERY = TurquoiseSpecular;
		shininesCZTERY = TurquoiseShininess;
		DisplayCZTERY();
		break;

		// materia³ - czarny plastik
	case BLACK_PLASTIC:
		ambientCZTERY = BlackPlasticAmbient;
		diffuseCZTERY = BlackPlasticDiffuse;
		specularCZTERY = BlackPlasticSpecular;
		shininesCZTERY = BlackPlasticShininess;
		DisplayCZTERY();
		break;

		// materia³ - czarna guma
	case BLACK_RUBBER:
		ambientCZTERY = BlackRubberAmbient;
		diffuseCZTERY = BlackRubberDiffuse;
		specularCZTERY = BlackRubberSpecular;
		shininesCZTERY = BlackRubberShininess;
		DisplayCZTERY();
		break;

		// wektory normalne - GLU_SMOOTH
	case NORMALS_SMOOTH:
		normalsCZTERY = NORMALS_SMOOTH;
		DisplayCZTERY();
		break;

		// wektory normalne - GLU_FLAT
	case NORMALS_FLAT:
		normalsCZTERY = NORMALS_FLAT;
		DisplayCZTERY();
		break;

		// obszar renderingu - ca³e okno
	case FULL_WINDOW:
		aspectCZTERY = FULL_WINDOW;
		ReshapeCZTERY(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspectCZTERY = ASPECT_1_1;
		ReshapeCZTERY(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjœcie
	case EXIT:
		exit(0);
	}
}

void ExtensionSetupCZTERY()
{
	// pobranie numeru wersji biblioteki OpenGL
	const char *version = (char*)glGetString(GL_VERSION);

	// odczyt wersji OpenGL
	int major = 0, minor = 0;
	if (sscanf(version, "%d.%d", &major, &minor) != 2)
	{
#ifndef WIN32
		printf("B³êdny format wersji OpenGL\n");
#else

		printf("Bledny format wersji OpenGL\n");
#endif

		exit(0);
	}

	// sprawdzenie czy jest co najmniej wersja 1.2
	if (major > 1 || minor >= 2)
		rescaleCZTERY_normal = true;
	else
		// sprawdzenie czy jest obs³ugiwane rozszerzenie EXT_rescaleCZTERY_normal
		if (glutExtensionSupported("GL_EXT_rescaleCZTERY_normal"))
			rescaleCZTERY_normal = true;
}

int mainCZTERY(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Wektory normalne");
	glutDisplayFunc(DisplayCZTERY);
	glutReshapeFunc(ReshapeCZTERY);
	glutKeyboardFunc(KeyboardCZTERY);
	glutSpecialFunc(SpecialKeysCZTERY);
	glutMouseFunc(MouseButtonCZTERY);
	glutMotionFunc(MouseMotionCZTERY);
	glutCreateMenu(MenuCZTERY);
	int MenuMaterial = glutCreateMenu(MenuCZTERY);
#ifdef WIN32

	glutAddMenuEntry("Mosi¹dz", BRASS);
	glutAddMenuEntry("Br¹z", BRONZE);
	glutAddMenuEntry("Polerowany br¹z", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("MiedŸ", COPPER);
	glutAddMenuEntry("Polerowana miedŸ", POLISHED_COPPER);
	glutAddMenuEntry("Z³oto", GOLD);
	glutAddMenuEntry("Polerowane z³oto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Per³a", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#else

	glutAddMenuEntry("Mosiadz", BRASS);
	glutAddMenuEntry("Braz", BRONZE);
	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedz", COPPER);
	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
	glutAddMenuEntry("Zloto", GOLD);
	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z o³owiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Perla", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#endif

	// utworzenie podmenu - Wektory normalne
	int MenuNormalCZTERYs = glutCreateMenu(MenuCZTERY);
#ifndef WIN32

	glutAddMenuEntry("Jeden wektor normalny na wierzcholek", NORMALS_SMOOTH);
	glutAddMenuEntry("Jeden wektor normalny na sciane", NORMALS_FLAT);
#else

	glutAddMenuEntry("Jeden wektor normalny na wierzcho³ek", NORMALS_SMOOTH);
	glutAddMenuEntry("Jeden wektor normalny na œcianê", NORMALS_FLAT);
#endif

	// utworzenie podmenu - aspekt obrazu
	int MenuAspect = glutCreateMenu(MenuCZTERY);
#ifndef WIN32

	glutAddMenuEntry("Aspekt obrazu - ca³e okno", FULL_WINDOW);
#else

	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu g³ówne
	glutCreateMenu(MenuCZTERY);

#ifdef WIN32

	glutAddSubMenu("Materia³", MenuMaterial);
#else

	glutAddSubMenu("Material", MenuMaterial);
#endif

	glutAddSubMenu("Wektory normalne", MenuNormalCZTERYs);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
#ifndef WIN32

	glutAddMenuEntry("Wyjœcie", EXIT);
#else

	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	// okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// sprawdzenie i przygotowanie obs³ugi wybranych rozszerze?
	ExtensionSetupCZTERY();

	// wprowadzenie programu do obs³ugi pêtli komunikatów
	glutMainLoop();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[])
{
	int zmienna = 0;
	while (true)
	{
		zmienna = 0;
		while (zmienna < 1)
		{
			std::cout << "Podaj ktory program chcesz uruchomic:" << std::endl;
			std::cout << "1 - > Swiatlo kierunkowe " << std::endl;
			std::cout << "2 - > GLobalne swiatlo otaczajace " << std::endl;
			std::cout << "3 - > Reflektor " << std::endl;
			std::cout << "4 - > Wektory normalne " << std::endl << std::endl;
			std::cout << "5 - > Wyjscie " << std::endl;
			std::cin >> zmienna;
		}


		switch (zmienna)
		{
		case 1:
		{
			mainJEDEN(argc, argv);
			break;
		}
		case 2:
		{
			mainDWA(argc, argv);
			break;
		}
		case 3:
		{
			mainTRZY(argc, argv);
			break;
		}
		case 4:
		{
			mainCZTERY(argc, argv);
			break;
		}
		case 5:
		{
			exit;
		}
		}
	}


	return 0;
}