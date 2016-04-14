
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <iostream>


using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}


void render()
{
	glBegin(GL_LINES);
	
/* CONSTANT zangu*/
	GLuint x0 = 0, y0 = 0, x1 = 4, y1 = 5, i = 0;
	GLuint deltaX = x1 - x0;
	GLuint deltaY = y1 - y0;
	GLuint p0 = 2 * deltaY - deltaX;

	glVertex2d(x0, y0);
	/*my for loop */

	for (x0; x0 < x1 + 1; x0++) {
		if (p0 > 0) {

			glVertex2d(x0 + 1, y0);
			p0 = p0 + 2 * deltaY;

		}
		else {
			glVertex2d(x0 + 1, y0 + 1);
			p0 = p0 + 2 * deltaY - 2 * deltaX;

		}
	}
	
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnd();
	glutSwapBuffers();
}



int main(int argc, char* argv[]) {

	

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bresenham");
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}