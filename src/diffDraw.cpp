/*#include <GL/glut.h>
#include<iostream>
int rotate_y = 0;
int rotate_x = 0;
int translate_lArm_1 = 0, translate_lArm_2 = 0;
int count1 = 0;
int w, h;
void display();

void specialKeys(unsigned char key, int x, int y)
{

	if (key == 'd' || key == 'D')
		rotate_y += 5;
	else if (key == 'a' || key == 'A')
		rotate_y -= 5;
	else if (key == 'w' || key == 'W')
		rotate_x -= 5;
	else if (key == 's' || key == 'S')
		rotate_x += 5;
	else if (key == 'l' || key == 'L')
		translate_lArm_1 = 1;
	else if (key == 'p' || key == 'P')
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (count1 == 0)
		{
			glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
			count1 = 1;
		}
		else if (count1 == 1)
		{
			gluPerspective(45.0, 1.0, 0.75, 12.0);
			count1 = 0;
		}
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	rotate_x %= 360;
	rotate_y %= 360;
	glutPostRedisplay();
}
void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (count1 == 0)
		glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
	if (count1 == 1) {
		gluPerspective(55.0, 1.0, 3.0 / 4.0, 12.0);
		double Ex = -6 * sin(0.0174 / 180 * (rotate_x))*cos(0.0174 / 180 * (rotate_y));
		double Ey = +6 * sin(0.0174 / 180 * (rotate_y));
		double Ez = +6 * cos(0.0174 / 180 * (rotate_x))*cos(0.0174 / 180 * (rotate_y));
		gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, cos(0.0174 / 180 * (rotate_y)), 0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glRotatef(rotate_x, 1.0, 0.0, 0.0);//yukarý,aþaðý
	glRotatef(rotate_y, 0.0, 1.0, 0.0);//saða ,sola

	glBegin(GL_QUADS);
	// front
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0, -2.0, 2.0);
	glVertex3f(2.0, -2.0, 2.0);
	glVertex3f(2.0, 2.0, 2.0);
	glVertex3f(-2.0, 2.0, 2.0);

	glEnd();

	glBegin(GL_QUADS);
	// right
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0, 2.0, 2.0);
	glVertex3f(2.0, -2.0, 2.0);
	glVertex3f(2.0, -2.0, -2.0);
	glVertex3f(2.0, 2.0, -2.0);

	glEnd();
	glBegin(GL_QUADS);
	// bottom
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0, -2.0, 2.0);
	glVertex3f(-2.0, -2.0, -2.0);
	glVertex3f(2.0, -2.0, -2.0);
	glVertex3f(2.0, -2.0, 2.0);

	glEnd();
	glBegin(GL_QUADS);
	// top
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0, 2.0, 2.0);
	glVertex3f(2.0, 2.0, 2.0);
	glVertex3f(2.0, 2.0, -2.0);
	glVertex3f(-2.0, 2.0, -2.0);

	glEnd();
	glBegin(GL_QUADS);
	// back
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0, -2.0, -2.0);
	glVertex3f(-2.0, 2.0, -2.0);
	glVertex3f(2.0, 2.0, -2.0);
	glVertex3f(2.0, -2.0, -2.0);

	glEnd();
	glBegin(GL_QUADS);
	// left
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0, -2.0, 2.0);
	glVertex3f(-2.0, 2.0, 2.0);
	glVertex3f(-2.0, 2.0, -2.0);
	glVertex3f(-2.0, -2.0, -2.0);

	glEnd();

  
	glutSwapBuffers();
}
void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
		glViewport((width - height) / 2, 0, height, height);
	else
		glViewport(0, (height - width) / 2, width, width);
	if (count1 == 0)
		glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
	if (count1 == 1) {
		gluPerspective(45.0, 1.0, 3.0 / 4.0, 12.0);
	}
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 150);
	w = glutGet(GLUT_WINDOW_WIDTH);
	h = glutGet(GLUT_WINDOW_HEIGHT);
	glutCreateWindow("Homework 3");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(specialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}*/