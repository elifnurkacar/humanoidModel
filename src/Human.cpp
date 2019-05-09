
#include <GL/glut.h>
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int rotate_y = 0;
int rotate_x = 0;
int rotate_1 = 0,rotate_2 = 0, rotate_3 = 0, rotate_4 = 0, rotate_5 = 0, 
rotate_6 = 0, rotate_7 = 0, rotate_8 = 0, rotate_9 = 0, rotate_10 = 0,
rotate_11 = 0, rotate_12 = 0, rotate_13 = 0, rotate_14 = 0, rotate_15 = 0, rotate_16 = 0
;
fstream file;
int pers_ort = 0;
int aniStop = 2;
int w, h;
void display();
void animation(int);
int control1=2, control2=2, control3=2, control4=2, control5 = 2, control6 = 2, control7 = 2, control8 = 2;//ileri gerileri kontrol ediyor.
int count1 = 2, count2 = 2, count3 = 2, count4 = 0, count5 = 0, count6 = 0;
int flag[20] = {
0,0, //sol kolun üstünün animasyonu 
0,0, //sað kolun üstünün animasyonu
0,0,//sol bacaðýn üstünün animasyonu
0,0,//sað bacaðýn üstünün animasyonu
0,0,0,0,0,0,0,0,0,0,0 ,0};
int flagDown[8] = { 0,0,0,0,0,0,0,0 };//kol ve bacaklarýn alt kýsýmlarýnýn hareketleri


  


float torso[8][3] =
{
	{ -2.0,-2.0,1.0 },
	{ -2.0,2.0,1.0 },
	{ 2.0,2.0,1.0 },
	{ 2.0,-2.0,1.0 },
	{ -2.0,-2.0,-1.0 },
	{ -2.0,2.0,-1.0 },
	{ 2.0,2.0,-1.0 },
	{ 2.0,-2.0,-1.0 },
};

float head[8][3] =
{
	{ -0.75,2.0,0.5 },
	{ -0.75,3.5,0.5 },
	{ 0.75,3.5,0.5 },
	{ 0.75,2.0,0.5 },
	{ -0.75,2.0,-0.5 },
	{ -0.75,3.5,-0.5 },
	{ 0.75,2.0,-0.5 },
	{ 0.75,3.5,-0.5 },
};
float rightArm[16][3] =
{

	{ 3.0,-0.0,0.25 },///0
	{ 3.0,2.0,0.25 },
	{ 2.0,2.0,0.25 },
	{ 2.0,-0.0,0.25 },
	{ 3.0,-0.0,-0.25 },
	{ 3.0,2.0,-0.25 },
	{ 2.0,2.0,-0.25 },
	{ 2.0,-0.0,-0.25 },

	{ 2.75,-1.5,0.25 },///8
	{ 2.75,-0.0,0.25 },
	{ 2.25,-0.0,0.25 },
	{ 2.25,-1.5,0.25 },
	{ 2.75,-1.5,-0.25 },
	{ 2.75,-0.0,-0.25 },
	{ 2.25,-1.5,-0.25 },
	{ 2.25,-0.0,-0.25 },


};
float leftArm[16][3] =
{
	{ -3.0,-0.0,0.25 },///0
	{ -3.0,2.0,0.25 },
	{ -2.0,2.0,0.25 },
	{ -2.0,-0.0,0.25 },
	{ -3.0,-0.0,-0.25 },
	{ -3.0,2.0,-0.25 },
	{ -2.0,2.0,-0.25 },
	{ -2.0,-0.0,-0.25 },

	{ -2.75,-1.5,0.25 },///8
	{ -2.75,-0.0,0.25 },
	{ -2.25,-0.0,0.25 },
	{ -2.25,-1.5,0.25 },
	{ -2.75,-1.5,-0.25 },
	{ -2.75,-0.0,-0.25 },
	{ -2.25,-1.5,-0.25 },
	{ -2.25,-0.0,-0.25 },

};
float rightLeg[16][3] =
{

	{ 0.5,-4.0,0.25 },///0
	{ 0.5,-2.0,0.25 },
	{ 1.5,-2.0,0.25 },
	{ 1.5,-4.0,0.25 },
	{ 0.5,-4.0,-0.25 },
	{ 0.5,-2.0,-0.25 },
	{ 1.5,-2.0,-0.25 },
	{ 1.5,-4.0,-0.25 },

	{ 0.75,-5.5,0.25 },///8
	{ 0.75,-4.0,0.25 },
	{ 1.25,-4.0,0.25 },
	{ 1.25,-5.5,0.25 },
	{ 0.75,-5.5,-0.25 },
	{ 0.75,-4.0,-0.25 },
	{ 1.25,-4.0,-0.25 },
	{ 1.25,-5.5,-0.25 },

};

float leftLeg[16][3] =
{
	{-1.5,-4.0,0.25 },///0
	{ -1.5,-2.0,0.25 },
	{ -0.5,-2.0,0.25 },
	{ -0.5,-4.0,0.25 },
	{ -1.5,-4.0,-0.25 },
	{ -1.5,-2.0,-0.25 },
	{ -0.5,-2.0,-0.25 },
	{ -0.5,-4.0,-0.25 },

	{ -1.25,-5.5,0.25 },///8
	{ -1.25,-4.0,0.25 },
	{ -0.75,-4.0,0.25 },
	{ -0.75,-5.5,0.25 },
	{ -1.25,-5.5,-0.25 },
	{ -1.25,-4.0,-0.25 },
	{ -0.75,-4.0,-0.25 },
	{ -0.75,-5.5,-0.25 },
	

};
GLfloat color[8][3] =
{
	{ 0.0,0.0,0.0 },
	{ 1.0,0.0,0.0 },
	{ 1.0,1.0,1.0 },
	{ 0.0,1.0,0.0 },
	{ 0.0,0.0,1.0 },
	{ 1.0,0.0,1.0 },
	{ 0.0,1.0,1.0 },
	{ 1.0,1.0,0.0 },
};

void drawtorso(int a, int b, int c, int d)
{       
		glBegin(GL_QUADS);
		glColor3fv(color[1]);
		glVertex3fv(torso[a]);

		glColor3fv(color[1]);
		glVertex3fv(torso[b]);

		glColor3fv(color[1]);
		glVertex3fv(torso[c]);

		glColor3fv(color[1]);
		glVertex3fv(torso[d]);
		glEnd();
	
}
void drawHead(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[4]);
	glVertex3fv(head[a]);

	glColor3fv(color[4]);
	glVertex3fv(head[b]);

	glColor3fv(color[4]);
	glVertex3fv(head[c]);

	glColor3fv(color[4]);
	glVertex3fv(head[d]);
	glEnd();

}

void leftArmTop(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[4]);
	glVertex3fv(leftArm[a]);

	glColor3fv(color[4]);
	glVertex3fv(leftArm[b]);

	glColor3fv(color[4]);
	glVertex3fv(leftArm[c]);

	glColor3fv(color[4]);
	glVertex3fv(leftArm[d]);
	glEnd();
}
void leftArmDown(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[2]);
	glVertex3fv(leftArm[a]);

	glColor3fv(color[2]);
	glVertex3fv(leftArm[b]);

	glColor3fv(color[2]);
	glVertex3fv(leftArm[c]);

	glColor3fv(color[2]);
	glVertex3fv(leftArm[d]);
	glEnd();
}
void rightArmTop(int a, int b, int c, int d)
{
	
		glBegin(GL_QUADS);
		glColor3fv(color[4]);
		glVertex3fv(rightArm[a]);

		glColor3fv(color[4]);
		glVertex3fv(rightArm[b]);

		glColor3fv(color[4]);
		glVertex3fv(rightArm[c]);

		glColor3fv(color[4]);
		glVertex3fv(rightArm[d]);
		glEnd();
	
}
void rightArmDown(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[2]);
	glVertex3fv(rightArm[a]);

	glColor3fv(color[2]);
	glVertex3fv(rightArm[b]);

	glColor3fv(color[2]);
	glVertex3fv(rightArm[c]);

	glColor3fv(color[2]);
	glVertex3fv(rightArm[d]);
	glEnd();
}
void rightLegTop(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[4]);
	glVertex3fv(rightLeg[a]);

	glColor3fv(color[4]);
	glVertex3fv(rightLeg[b]);

	glColor3fv(color[4]);
	glVertex3fv(rightLeg[c]);

	glColor3fv(color[4]);
	glVertex3fv(rightLeg[d]);
	glEnd();
}
	
void rightLegDown(int a, int b, int c, int d)
	{
	
		

		glBegin(GL_QUADS);
		glColor3fv(color[2]);
		glVertex3fv(rightLeg[a]);

		glColor3fv(color[2]);
		glVertex3fv(rightLeg[b]);

		glColor3fv(color[2]);
		glVertex3fv(rightLeg[c]);

		glColor3fv(color[2]);
		glVertex3fv(rightLeg[d]);
		glEnd();

}

void leftLegTop(int a, int b, int c, int d)
{
	

	glBegin(GL_QUADS);
	glColor3fv(color[4]);
	glVertex3fv(leftLeg[a]);

	glColor3fv(color[4]);
	glVertex3fv(leftLeg[b]);

	glColor3fv(color[4]);
	glVertex3fv(leftLeg[c]);

	glColor3fv(color[4]);
	glVertex3fv(leftLeg[d]);
	glEnd();
}
void leftLegDown(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(color[2]);
	glVertex3fv(leftLeg[a]);

	glColor3fv(color[2]);
	glVertex3fv(leftLeg[b]);

	glColor3fv(color[2]);
	glVertex3fv(leftLeg[c]);

	glColor3fv(color[2]);
	glVertex3fv(leftLeg[d]);
	glEnd();
	}


void Head() {
	drawHead(0, 3, 2, 1);
	drawHead(2, 3, 7, 6);
	drawHead(0, 4, 7, 3);
	drawHead(1, 2, 6, 5);
	drawHead(4, 5, 6, 7);
	drawHead(0, 1, 5, 4);
}
void LArmDown()
{/*
	if (count2) {
		glPushMatrix();
		glTranslatef(0.0,0.0, 0.0);
	    glRotatef(rotate_11, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 0.0);
		glPushMatrix();
		leftArmDown(8, 11, 10, 9);
		leftArmDown(10, 11, 15, 14);
		leftArmDown(8, 12, 15, 11);
		leftArmDown(9, 10, 14, 13);
		leftArmDown(12, 13, 14, 15);
		leftArmDown(8, 12, 13, 9);
		glPopMatrix();
		glPopMatrix();
	}
	else
	{*/
		leftArmDown(8, 11, 10, 9);
		leftArmDown(10, 11, 15, 14);
		leftArmDown(8, 12, 15, 11);
		leftArmDown(9, 10, 14, 13);
		leftArmDown(12, 13, 14, 15);
		leftArmDown(8, 12, 13, 9);
	//}
}
void LArmTop()
{
	//glBindTexture(GL_TEXTURE_2D, texture2);

	glPushMatrix();
	//if (count1 == 0)
	{
		glTranslatef(-2.0, 2.0, 0.0);
		glRotatef(rotate_3, 1.0, 0.0, 0.0);
		glTranslatef(2.0, -2.0, 0.0);
	}
	/*
	else if (count1 == 1)
	{
		glTranslatef(-2.0, 2.0, -0.25);
		glRotatef(rotate_12, 0.0, 0.0, 1.0);
		glTranslatef(2.0, -2.0, 0.25);
	}
	*/
    glPushMatrix();
	leftArmTop(0, 3, 2, 1);
	leftArmTop(2, 3, 7, 6);
	leftArmTop(0, 4, 7, 3);
	leftArmTop(1, 2, 6, 5);
	leftArmTop(4, 5, 6, 7);
	leftArmTop(0, 1, 5, 4);
	glPopMatrix();
    glPushMatrix();
	glTranslatef(1.25, 0.0, 0.0);
	glRotatef(rotate_4, 1.0, 0.0, 0.0);
	glTranslatef(-1.25, 0.0, 0.0);
	LArmDown();
	glPopMatrix();
	glPopMatrix();
}


void RArmDown() {
	rightArmDown(8, 11, 10, 9);
	rightArmDown(10, 11, 15, 14);
	rightArmDown(8, 12, 15, 11);
	rightArmDown(9, 10, 14, 13);
	rightArmDown(12, 13, 14, 15);
	rightArmDown(8, 12, 13, 9);
}
void RArmTop() {
	glPushMatrix();
	//if (rotate_1 != 0)
	glTranslatef(0.0,2.0,0.0);
	glRotatef(rotate_1,1.0,0.0,0.0);
	glTranslatef(0.0, -2.0, 0.0);
	glPushMatrix();
	rightArmTop(0, 3, 2, 1);
	rightArmTop(2, 3, 7, 6);
	rightArmTop(0, 4, 7, 3);
	rightArmTop(1, 2, 6, 5);
	rightArmTop(4, 5, 6, 7);
	rightArmTop(0, 1, 5, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25, 0.0, 0.0);
	glRotatef(rotate_2, 1.0, 0.0, 0.0);
	glTranslatef(-1.25, 0.0, 0.0);
	RArmDown();
	glPopMatrix();
	glPopMatrix();

}

void RLegDown() {
	rightLegDown(8, 11, 10, 9);
	rightLegDown(10, 11, 15, 14);
	rightLegDown(8, 12, 15, 11);
	rightLegDown(9, 10, 14, 13);
	rightLegDown(12, 13, 14, 15);
	rightLegDown(8, 12, 13, 9);
}
void RLegTop() {
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(rotate_5, 1.0, 0.0, 0.0);
	glTranslatef(0.0, +2.0, 0.0);
	glPushMatrix();
	rightLegTop(0, 3, 2, 1);
	rightLegTop(2, 3, 7, 6);
	rightLegTop(0, 4, 7, 3);
	rightLegTop(1, 2, 6, 5);
	rightLegTop(4, 5, 6, 7);
	rightLegTop(0, 1, 5, 4);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, -4.0, 0.0);
	glRotatef(rotate_6, 1.0, 0.0, 0.0);
	glTranslatef(-1.0, 4.0, 0.0);
	RLegDown();
	glPopMatrix();
	glPopMatrix();
}

void LLegDown() {
	leftLegDown(8, 11, 10, 9);
	leftLegDown(10, 11, 15, 14);
	leftLegDown(8, 12, 15, 11);
	leftLegDown(9, 10, 14, 13);
	leftLegDown(12, 13, 14, 15);
	leftLegDown(8, 12, 13, 9);
}
void LLegTop() {
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(rotate_7, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
	leftLegTop(0, 3, 2, 1);
	leftLegTop(2, 3, 7, 6);
	leftLegTop(0, 4, 7, 3);
	leftLegTop(1, 2, 6, 5);
	leftLegTop(4, 5, 6, 7);
	leftLegTop(0, 1, 5, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, -4.0, 0.0);
	glRotatef(rotate_8, 1.0, 0.0, 0.0);
	glTranslatef(-1.0, 4.0, 0.0);
	LLegDown();
	glPopMatrix();
	glPopMatrix();
}
void drawHuman()
{
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0,-2.0,0.0);
	glRotatef(rotate_10, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
	drawtorso(0, 3, 2, 1);
	drawtorso(2, 3, 7, 6);
	drawtorso(0, 4, 7, 3);
	drawtorso(1, 2, 6, 5);
	drawtorso(4, 5, 6, 7);
	drawtorso(0, 1, 5, 4);
	
	glPushMatrix();
	glRotatef(rotate_9, 1.0, 0.0, 0.0);
	glPushMatrix();
    Head();
	glPopMatrix();
	glPopMatrix();
	LArmTop();
    RArmTop();
	
	glPopMatrix();
	glPopMatrix();
	LLegTop();
    RLegTop();
}
void animation(int)
{
	
	//cout << control1<<endl;
	//cout << flag[3];
	//sol kolun üst ileri-geri animasyonu
	if (control1==1) {
		rotate_3 -= 5.0;
	}
	else if (control1 == 0) {
		rotate_3 += 5.0;
	}
	if (rotate_3 < flag[0]) control1 = 0;
	if (rotate_3 > flag[1])  control1 = 1;
	
	//sað kolun üst ileri-geri animasyonu
	if (control2 == 1) {
		rotate_1 -= 5.0;
	}
	else if (control2 == 0) {
		rotate_1 += 5.0;
	}
	if (rotate_1 < flag[2]) control2 = 0;
	if (rotate_1 > flag[3])  control2 = 1;
	
	//sol bacak üst ileri-geri animasyonu
	if (control3==1) {
		rotate_7 -= 5.0;
	}
	else if (control3 == 0) {
		rotate_7 += 5.0;
	}
	if (rotate_7 < flag[4]) control3 = 0;
	if (rotate_7 > flag[5]) control3 = 1;

	//sað bacak üst ileri-geri animasyonu
	if (control4==1) {
		rotate_5 -= 5.0;
	}
	else if (control4 == 0) {
		rotate_5 += 5.0;
	}
	if (rotate_5 < flag[6]) control4 = 0;
	if (rotate_5 > flag[7]) control4 = 1;
	
	if (aniStop%2 == 1) {

		glutPostRedisplay();
        glutTimerFunc(100, animation, 0);
	}
	else if (aniStop % 2 == 0)
	{
		;
	}
}
void specialKeys(unsigned char key, int x, int y)
{///////////////Y EKSENÝNE GÖRE HAREKET ETTÝRMELER EKLENECEK

	if (key == 'd' || key == 'D')
		rotate_y += 5;
	else if (key == 'a' || key == 'A')
		rotate_y -= 5;
	else if (key == 'w' || key == 'W')
		rotate_x -= 5;
	else if (key == 's' || key == 'S')
		rotate_x += 5;
	else if (key == 'u' || key == 'U')//sað kol üst ileri
	{
		if (rotate_1 !=- 180)
			rotate_1 -= 5;
		control2= 1;
		flag[2] = rotate_1;
	}
	else if (key == 'J' || key == 'j')//sað kol üst geri
	{
		if (rotate_1 != 45)
			rotate_1 += 5;
		control2 =0;
		flag[3] = rotate_1;
	}
	else if (key == 'y' || key == 'Y')//sað kol alt ileri
	{
		if (rotate_2 != -150)
			rotate_2 -= 5;
		control6 = 1;
		flagDown[2] = rotate_2;
	}
	
	else if (key == 'h' || key == 'H')//sað kol alt geri
	{
		if (rotate_2 != 0)
			rotate_2 += 5;
		control6 = 0;
		flagDown[3] = rotate_2;
	}
	else if (key == 't' || key == 'T')//sol kol üst ileri
	{
		if (rotate_3 != -180)
			rotate_3 -= 5;
		control1 =1;
		flag[0] = rotate_3;
		count1 = 0;
	}
	else if (key == '<')//sol kol üst ileri
	{
		if (rotate_12 != -90)
			rotate_12 -= 5;
			count1 = 1;
		//control1 = 1;
		//flag[0] = rotate_3;
	}
	else if (key == 'g' || key == 'G')//sol kol üst geri
	{
		if (rotate_3 != 45)
			rotate_3 += 5;
		control1 = 0;
		flag[1] = rotate_3;
	}
	else if (key == 'R' || key == 'r')//sol kol alt ileri
	{
		if (rotate_4 != -150)
			rotate_4 -= 5;
		control5 = 1;
		flagDown[0] = rotate_4;
	}
	
	else if (key == 'f' || key == 'F')//sol kol alt geri
	{
		if (rotate_4 != 0)
			rotate_4 += 5;
		control5 =0;
		flagDown[1] = rotate_4;
	}
	else if (key == 'c' || key == 'C')//sað bacak üst ileri
	{
		if (rotate_5 != -90)
			rotate_5 -= 5;
		control4= true;
		flag[6] = rotate_5;
	}
	else if (key == 'v' || key == 'V')//sað bacak üst geri
	{
		if (rotate_5 != 45)
			rotate_5 += 5;
		control4 = false;
		flag[7] = rotate_5;
	}
	else if (key == 'x' || key == 'X')//sað bacak alt ileri
	{
		if (rotate_6 != -0)
			rotate_6 -= 5;
		control8 = 1;
		flagDown[6] = rotate_6;
		//cout<< "rotate6" << rotate_6 << "\n";
	}

	else if (key == 'Z' || key == 'z')//sað bacak alt geri
	{
		if (rotate_6 != 150)
			rotate_6 += 5;
		control8 = 0;
		flagDown[7] = rotate_6;
		//cout << "rotate6" << rotate_6 << "\n";
	}
	else if (key == 'k' || key == 'K')//sol bacak üst ileri
	{
		if (rotate_7 != -90)
			rotate_7 -= 5;
		control3 = true;
		flag[4] = rotate_7;
	}
	else if (key == 'l' || key == 'L')//sol bacak üst geri
	{
		if (rotate_7 != 45)
			rotate_7 += 5;
		control3 =false;
		flag[5] = rotate_7;
	}
	else if (key == 'M' || key == 'm')//sol bacak alt ileri
	{
		if (rotate_8 != -0)
			rotate_8 -= 5;
		control7 = 1;
		flagDown[4]=rotate_8;
	}

	else if (key == 'N' || key == 'n') //sol bacak alt geri
	{
		if (rotate_8 != 150)
			rotate_8 += 5;
		control7 = 0;
		flagDown[5] = rotate_8;
	}
	else if (key == 'Q' || key == 'q')
	{
		if (rotate_9 != -10)
			rotate_9 -= 5;
	}
	else if (key == 'e' || key == 'E')
	{
		if (rotate_9 != 10)
			rotate_9 += 5;
	}
	else if (key == 'O' || key == 'o')
	{
		if (rotate_10 != -10)
			rotate_10 -= 5;
	}

	else if (key == 'p' || key == 'P')
	{
		if (rotate_10 != 130)
			rotate_10 += 5;
	}
	else if (key == '+' )
	{
		
		if (rotate_11 != -40)
			rotate_11 -= 5;

	}
	else if (key ==	GLUT_KEY_RIGHT)
	{

		;

	}

	else if (key == '/') { 
		string line;
		file.open("input.txt");
		while (!file.eof()) {
			if (!file.eof()) {
				for (int i = 0; i < 8; i++) {

					getline(file, line);
					stringstream ss(line);//stringi int e çevirir.
					ss >> flag[i];
				}
				for (int i = 0; i < 8; i++) {

					getline(file, line);
					stringstream ss(line);//stringi int e çevirir.
					ss >> flagDown[i];
				}
			}
			else break;
			
		}
		//for (int i = 0; i < 8; i++) {
		//	cout << flagDown[i]<<endl;
		//}
		if (flag[0] < 0)
			control1 = 1;
		else if (flag[1] > 0)
			control1 = 0;
		if (flag[2] < 0)
			control2 = 1;
		else if (flag[3] > 0)
			control2 = 0;
		if (flag[4] < 0)
			control3 = 1;
		else if (flag[5] > 0)
			control3 = 0;
		if (flag[6] < 0)
			control4 = 1;
		else if (flag[7] > 0)
			control4 = 0;
		
		file.close();
		aniStop++;
		if (aniStop % 2 == 1)
		{
			if(control5==1)
			rotate_4 = flagDown[0];
			else if (control5 == 0)
			rotate_4 = flagDown[1];

			if (control6 == 1)
				rotate_2 = flagDown[2];
			else if (control6 == 0)
				rotate_2 = flagDown[3];

			if (control7 == 1)
				rotate_8 = flagDown[4];
			else if (control7 == 0)
				rotate_8 = flagDown[5];

			if (control8 == 1)
				rotate_6 = flagDown[6];
			else if (control8 == 0)
				rotate_6 = flagDown[7];

			glutTimerFunc(100, animation, 0);
		}
		else if (aniStop % 2 == 0)
		{
			;
		}
		
	}	//animation walk
	/*
	else if (key == '-' )
	{
		if (rotate_11 != 40)
			rotate_11 += 5;
	}*/
	else if (key == '.')
	{
		
		file.open("input.txt");
		ofstream ofs("input.txt", std::ios::out | std::ios::trunc);
		for (int i = 0; i < 8; i++) {
			file << flag[i] <<endl;
		}
		for (int i = 0; i < 8; i++) {
			file << flagDown[i] << endl;
		}
		file.close();
		
	}
	
	else if (key == ',')
	{
		aniStop = 2;
		rotate_1 = 0;
		rotate_2 = 0;
		rotate_3 = 0;
		rotate_4 = 0;
		rotate_5 = 0;
		rotate_6 = 0;
		rotate_7 = 0;
		rotate_8 = 0;
		rotate_9 = 0;
		rotate_10 = 0;
		rotate_11 = 0;
		rotate_12 = 0;
		
    	control1 = 2;
		control2 = 2;
		control3 = 2;
		control4= 2;
		control5 = 2;
		control6 = 2;
		control7 = 2;
		control8 = 2;
	}


	else if (key == '*' )
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (pers_ort == 0)
		{
			glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
			pers_ort = 1;
		}
		else if (pers_ort == 1)
		{
			gluPerspective(45.0, 1.0, 0.75, 12.0);
			pers_ort = 0;
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
	if (pers_ort == 0) {
		glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
		glRotatef(rotate_x, 1.0, 0.0, 0.0);//yukarý,aþaðý
		glRotatef(rotate_y, 0.0, 1.0, 0.0);//saða ,sola
	}
	if (pers_ort == 1) {
		gluPerspective(55.0, 1.0, 3.0 / 4.0, 12.0);
		double Ex = -6 * sin(0.0174 / 180 * (rotate_x))*cos(0.0174 / 180 * (rotate_y));
		double Ey = +6 * sin(0.0174 / 180 * (rotate_y));
		double Ez = +6 * cos(0.0174 / 180 * (rotate_x))*cos(0.0174 / 180 * (rotate_y));
		gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, cos(0.0174 / 180 * (rotate_y)), 0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	
    drawHuman();
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
	if (pers_ort == 0)
		glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
	if (pers_ort == 1) {
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

	cout << "                           FORTH     BACK" << endl;
	cout << "Left-Arm Upper Movement :   't'      'g' " << endl;
	cout << "Left-Arm Under Movement :   'r'      'f' " << endl << endl;

	cout << "Right-Arm Upper Movement :  'u'      'j' " << endl;
	cout << "Right-Arm Under Movement :  'y'      'h' " << endl << endl;

	cout << "Left-Leg Upper Movement :   'k'      'l' " << endl;
	cout << "Left-Leg Under Movement :   'm'      'n' " << endl << endl;

	cout << "Right-Leg Upper Movement :  'c'      'v' " << endl;
	cout << "Right-Leg Under Movement :  'x'      'z' " << endl << endl;


	glutMainLoop();
	return 0;
}