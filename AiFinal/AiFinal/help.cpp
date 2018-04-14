#include "help.h"
#include <cstdlib>
#include <iostream>
#include "point.h"
#include "world.h"
#include "myvec.h"
#include "ngon.h"
#include "polyline.h"
#include "Utils.h"
#include <map>
using namespace std;

int refreshMills = 50;
int MY_WIN_H = 0;
int MY_WIN_W = 0;
world myWorld;


#if defined(WIN32)
void delay(int ms) {
	Sleep(ms);
}
#else
void delay(int ms) {
	struct timespec ts;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = 1000000 * (ms % 1000);
	nanosleep(&ts, NULL);
}
#endif

void drawworld() {
	glPointSize(4);
	glColor3f(1.0, 1.0, 1.0);
	myWorld.update();
	myWorld.draw();
	
}

void initworld() {
	myWorld.init(MY_WIN_W, MY_WIN_H, 10, 100, 0);
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawworld();
	glFlush();
	
}
void timer(int value) {
	glutPostRedisplay();     
	glutTimerFunc(refreshMills, timer, 0);
}
void myResize(GLsizei width, GLsizei height) {
}
void myInit(int w, int h) {
	srand(time(0));
	setWorldWin(0, w, 0, h);
	MY_WIN_W = w;
	MY_WIN_H = h;
	glClear(GL_COLOR_BUFFER_BIT); 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	myResize(w, h);
	initworld();
	timer(0);
}
void myMouseFun(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN) {

		
	}
	if (button == GLUT_RIGHT_BUTTON&&state == GLUT_DOWN) {
		
	}
}



void myKeyFun(unsigned char key, int x, int y) {
	switch (key) {
	case'a':
		
		break;
	case'd':
		break;
	case'h':
		break;
	case's':
		refreshMills += 10;
		break;
	case'f':
		if(refreshMills-10>0)refreshMills -= 10;
		else refreshMills = 0;
		break;
	case 'q':
	case '\033':
		exit(0);
	default:
		break;
	}
}