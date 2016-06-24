
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "BALL.h"

using namespace std;

OBJECT ** obj = 	NULL;
BALL * ball = NULL;
const GLfloat tempo = 0.1f;
GLfloat rotate_dir = 3.0f;
float _angle = 0.0f;

bool keys[8] = {false};

//Called when a key is pressed
void handleKeypressDown(unsigned char key, int x, int y) {

	static bool space = true;

	switch (key) {
	case 27: //Escape key
		exit(0);
		//case UP/DOWN/RIGHT/LEFT
		//paleczka1.move(arg)
	case 'w':
	case 'W':
		keys[_w] = true;
		break;
	case 's':
	case 'S':
		keys[_s] = true;
		break;
	case 'a':
	case 'A':
		keys[_a] = true;
		break;
	case 'd':
	case 'D':
		keys[_d] = true;
		break;
	case 32:
		if(space)
		{
			ball->initSpeed();
			space = false;
		}
		break;
	case 'p':
	case 'P':
		rotate_dir = -rotate_dir;
		break;
	case ';':
		if( (_angle < 0.1f) && (_angle > -0.1f) )
		{
			rotate_dir = 0.0f;
			_angle = 0.0f;
		}
		else
		{
			rotate_dir = 3.0f;
		}
		break;

		//case W/S/A/D
		//paleczka2.move(arg)
	}
}
void handleSpecialKeypressDown(int key, int x, int y) {


	switch (key) {
	//case UP/DOWN/RIGHT/LEFT
	//paleczka1.move(arg)
	case GLUT_KEY_UP:
		keys[_up] = true;
		break;
	case GLUT_KEY_DOWN:
		keys[_down] = true;
		break;
	case GLUT_KEY_LEFT:
		keys[_left] = true;
		break;
	case GLUT_KEY_RIGHT:
		keys[_right] = true;
		break;

		//case W/S/A/D
		//paleczka2.move(arg)
	}
}

void handleKeypressUp(unsigned char key, int x, int y) {


	switch (key) {
	case 27: //Escape key
		exit(0);
		//case UP/DOWN/RIGHT/LEFT
		//paleczka1.move(arg)
	case 'w':
	case 'W':
		keys[_w] = false;
		break;
	case 's':
	case 'S':
		keys[_s] = false;
		break;
	case 'a':
	case 'A':
		keys[_a] = false;
		break;
	case 'd':
	case 'D':
		keys[_d] = false;
		break;
		//case W/S/A/D
		//paleczka2.move(arg)
	}
}

void handleSpecialKeypressUp(int key, int x, int y) {


	switch (key) {
	//case UP/DOWN/RIGHT/LEFT
	//paleczka1.move(arg)
	case GLUT_KEY_UP:
		keys[_up] = false;
		break;
	case GLUT_KEY_DOWN:
		keys[_down] = false;
		break;
	case GLUT_KEY_LEFT:
		keys[_left] = false;
		break;
	case GLUT_KEY_RIGHT:
		keys[_right] = false;
		break;

		//case W/S/A/D
		//paleczka2.move(arg)
	}
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


//Draws the 3D scene
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -16.0f);

	//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glRotatef(20, 1.0f, 0.0f, 0.0f);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);

	//pilka.render()

	glPushMatrix();
	obj[paletkaGracza]->translate();
	obj[paletkaGracza]->render();
	glPopMatrix();

	glPushMatrix();
	obj[paletkaKomputera]->translate();
	obj[paletkaKomputera]->render();
	glPopMatrix();

	glPushMatrix();
	obj[stol]->translate();
	obj[stol]->render();
	glPopMatrix();

	glPushMatrix();
	obj[siatka]->translate();
	obj[siatka]->render();
	glPopMatrix();

	glPushMatrix();
	ball->translate();
	ball->render();
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {

	//iteracja fizyki

	obj[paletkaGracza]->updatePositions(tempo,keys);
	VERTEX3D ballCenter = ball->getCenter();
	obj[paletkaKomputera]->updatePositions(tempo, keys, &ballCenter);
	ball->computeNewCoord(obj,0.025f);

	_angle += rotate_dir;
	if (_angle > 90) {
		_angle = 90;
	}
	else if (_angle < -90) {
		_angle = -90;
	}

	glutPostRedisplay();
	glutTimerFunc( 25, update, 0);
}

int main(int argc, char** argv) {
	VERTEX3D t;
	obj = new OBJECT*[4];

	t.x = -9.0f;	t.y = 0.0f;		t.z = 0.0f;
	obj[paletkaGracza] = new OBJECT(t, 0.05f, 0.7f, 1.0f, paletkaGracza);
	t.r = 1.0f;		t.g = 0.0f;		t.b = 0.0f;
	obj[paletkaGracza]->setColor(t);
	obj[paletkaGracza]->setMinY(-1.0f);

	t.x = 9.0f;		t.y = 0.0f;		t.z = 0.0f;
	obj[paletkaKomputera] = new OBJECT(t, 0.05f, 0.7f, 1.0f, paletkaKomputera);
	t.r = 0.0f;		t.g = 0.0f;		t.b = 1.0f;
	obj[paletkaKomputera]->setColor(t);
	obj[paletkaKomputera]->setMinY(-1.0f);

	t.x = 0.0f;		t.y = -2.0f;	t.z = 0.0f;
	obj[stol] = new OBJECT(t, 10.0f, 0.2f, 7.0f, stol);
	t.r = 0.0f;		t.g = 1.0f;		t.b = 0.0f;
	obj[stol]->setColor(t);

	t.x = 0.0f;		t.y = -1.0f;	t.z = 0.0f;
	obj[siatka] = new OBJECT(t, 0.01f, 1.2f, 7.0f, siatka);
	t.r = 1.0f;		t.g = 1.0f;		t.b = 1.0f;
	obj[siatka]->setColor(t);
	//obj[paletka1]->setTiltRight( -30 );

	t.x = 0.0f;		t.y = 1.8f;	t.z = 0.0f;
	ball = new BALL( t, 0.5f );
	t.r = 1.0f;		t.g = 1.0f;		t.b = 1.0f;
	//ball->initSpeed();

	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 800);

	//Create the window
	glutCreateWindow("ping pong");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypressDown);
	glutKeyboardUpFunc(handleKeypressUp);
	glutSpecialFunc(handleSpecialKeypressDown);
	glutSpecialUpFunc(handleSpecialKeypressUp);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}









