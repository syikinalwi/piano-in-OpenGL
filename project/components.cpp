#include "initials.h"
#include "classes.h"

Piano::Piano()
{
}

void Piano::whiteKey(double nextkey) //white keys
{
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
	glTranslatef(nextkey, 0.0, 0.0);
	glutSolidCube(0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(nextkey, 0.0, 0.7);
	glutSolidCube(0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(nextkey, 0.0, 1.4);
	glutSolidCube(0.8);
	glPopMatrix();
}

void Piano::blackKey(double nextkey)  //black keys
{
	glColor3f(0.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(nextkey, 0.5, -0.15);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(nextkey, 0.5, 0.35);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(nextkey, 0.5, 0.85);
	glutSolidCube(0.5);
	glPopMatrix();
	glEnd();
}

void Piano::movePiano()
{

}

Hand::Hand()
{

}

void Hand::drawHandLeft()
{
	glColor3f(0.647059f, 0.164706f, 0.164706f);


	//*****************palm
	//glColor3f(0.647059f, 0.164706f, 0.164706f);
	//front face cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 0.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//back face cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(0.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);//
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glVertex3f(-3.0, -2.5f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//top face of cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(0.0, 0.0, 1.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);// It will take the vertices in order
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	// Bottom face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);// It will take the vertices in order
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, -1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);


	// Left side face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS); // It will take the vertices in order
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, -1.0f);
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	// Right side face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS); // It will take the vertices in order
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//glPopMatrix();

	//***************
	//*******fingers-cylinder


}
void Hand::drawHandRight()
{
	glColor3f(0.647059f, 0.164706f, 0.164706f);


	//*****************palm
	//glColor3f(0.647059f, 0.164706f, 0.164706f);
	//front face cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 0.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//back face cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(0.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);//
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glVertex3f(-3.0, -2.5f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//top face of cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(0.0, 0.0, 1.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);// It will take the vertices in order
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	// Bottom face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS);// It will take the vertices in order
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, -1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);


	// Left side face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS); // It will take the vertices in order
	glVertex3f(-3.0f, -2.5f, 1.0f);
	glVertex3f(-3.0f, -2.5f, -1.0f);
	glVertex3f(-3.0f, 3.0f, -1.0f);
	glVertex3f(-3.0f, 3.0f, 1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	// Right side face of the cube
	//glEnable(GL_CULL_FACE);
	//glColor3f(1.0, 1.0, 0.0);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_QUADS); // It will take the vertices in order
	glVertex3f(2.5f, 3.0f, 1.0f);
	glVertex3f(2.5f, -2.5f, 1.0f);
	glVertex3f(2.5f, -2.5f, -1.0f);
	glVertex3f(2.5f, 3.0f, -1.0f);
	glEnd();
	//glDisable(GL_CULL_FACE);

	//glPopMatrix();

	//***************
	//*******fingers-cylinder


}


void Hand::leftFingers1()
{
	static float Ltheta1 = -10;
	static float Ltheta2 = -10;
	static float Ltheta3 = -10;
	// Little Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *lpm = gluNewQuadric();
	glTranslatef(-2.5, 3, 0);
	glRotatef(-(90 - Ltheta1), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(lpm, 0.5, 0.4, 1.0, 10, 10);
	gluDeleteQuadric(lpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *ldp = gluNewQuadric();
	glTranslatef(-2.5, (3 + cos((float)(Ltheta1)* 22 / (7 * 180))), sin((float)(Ltheta1)* 22 / (7 * 180)));
	glRotatef(-(90 - Ltheta1 - Ltheta2), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(ldp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(ldp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *ltd = gluNewQuadric();
	glTranslatef(-2.5, (3 + cos((float)(Ltheta1)* 22 / (7 * 180)) + cos((float)(Ltheta1 + Ltheta2) * 22 / (7 * 180))), (sin((float)(Ltheta1)* 22 / (7 * 180)) + sin((float)(Ltheta1 + Ltheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Ltheta1 - Ltheta2 - Ltheta3), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(ltd, 0.3, 0.2, 1.0, 10, 10);
	gluDeleteQuadric(ltd);
	glPopMatrix();

	//**********






	// Thumb Finger
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *tpm = gluNewQuadric();
	glTranslatef(2.5, -1, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(tpm, 0.5, 0.4, 1.25, 10, 10);
	gluDeleteQuadric(tpm);
	glPopMatrix();

	//glColor3f(0.7f, 0.5f, 0.3f);
	glPushMatrix();
	GLUquadricObj *tdp = gluNewQuadric();
	glTranslatef(3.75, -1, 0);
	glRotatef(-45, 0, 0, 1);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(tdp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(tdp);
	glPopMatrix();
}

void Hand::rightFingers1()
{
	static float Ltheta1 = -10;
	static float Ltheta2 = -10;
	static float Ltheta3 = -10;
	// Little Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *lpm = gluNewQuadric();
	glTranslatef(-2.5, 3, 0);
	glRotatef(-(90 - Ltheta1), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(lpm, 0.5, 0.4, 1.0, 10, 10);
	gluDeleteQuadric(lpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *ldp = gluNewQuadric();
	glTranslatef(-2.5, (3 + cos((float)(Ltheta1)* 22 / (7 * 180))), sin((float)(Ltheta1)* 22 / (7 * 180)));
	glRotatef(-(90 - Ltheta1 - Ltheta2), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(ldp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(ldp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *ltd = gluNewQuadric();
	glTranslatef(-2.5, (3 + cos((float)(Ltheta1)* 22 / (7 * 180)) + cos((float)(Ltheta1 + Ltheta2) * 22 / (7 * 180))), (sin((float)(Ltheta1)* 22 / (7 * 180)) + sin((float)(Ltheta1 + Ltheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Ltheta1 - Ltheta2 - Ltheta3), 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(ltd, 0.3, 0.2, 1.0, 10, 10);
	gluDeleteQuadric(ltd);
	glPopMatrix();

	//**********






	// Thumb Finger
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *tpm = gluNewQuadric();
	glTranslatef(-3.0, -1, 0);
	glRotatef(90, 0, 1, 0);	
	glRotatef(-180, 0, 1, 0);
	gluCylinder(tpm, 0.5, 0.4, 1.25, 10, 10);
	gluDeleteQuadric(tpm);
	glPopMatrix();

	//glColor3f(0.7f, 0.5f, 0.3f);
	glPushMatrix();
	GLUquadricObj *tdp = gluNewQuadric();
	glTranslatef(-4.25, -1, 0);
	glRotatef(45, 0, 0, 1);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(tdp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(tdp);
	glPopMatrix();
}


void Hand::leftFingers2()
{

	static float Rtheta1 = -10;
	static float Rtheta2 = -10;
	static float Rtheta3 = -10;
	//Ring Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *rpm = gluNewQuadric();
	glTranslatef(-1, 3, 0);
	glRotatef(-(90 - Rtheta1), 1, 0, 0);
	gluCylinder(rpm, 0.5, 0.4, 1.5, 10, 10);
	gluDeleteQuadric(rpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *rdp = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1 * 22 / (7 * 180))), 1.5*sin((float)Rtheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Rtheta1 - Rtheta2), 1, 0, 0);
	gluCylinder(rdp, 0.4, 0.3, 1.5, 10, 10);
	gluDeleteQuadric(rdp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *rtd = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1 * 22 / (7 * 180)) + 1.5*cos((float)(Rtheta1 + Rtheta2) * 22 / (7 * 180))), (1.5*sin((float)Rtheta1 * 22 / (7 * 180)) + 1.5*sin((float)(Rtheta1 + Rtheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Rtheta1 - Rtheta2 - Rtheta3), 1, 0, 0);
	gluCylinder(rtd, 0.3, 0.2, 1.5, 10, 10);
	gluDeleteQuadric(rtd);
	glPopMatrix();
	//-------------------------------------------------------------
}

void Hand::leftFingers3()
{

	static float Mtheta1 = -10;
	static float Mtheta2 = -10;
	static float Mtheta3 = -10;
	//Middle Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *mpm = gluNewQuadric();
	glTranslatef(0.5, 3, 0);
	glRotatef(-(90 - Mtheta1), 1, 0, 0);
	gluCylinder(mpm, 0.5, 0.4, 1.75, 10, 10);
	gluDeleteQuadric(mpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *mdp = gluNewQuadric();
	glTranslatef(0.5, (3 + 1.75*cos((float)Mtheta1 * 22 / (7 * 180))), 1.75*sin((float)Mtheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Mtheta1 - Mtheta2), 1, 0, 0);
	gluCylinder(mdp, 0.4, 0.3, 1.75, 10, 10);
	gluDeleteQuadric(mdp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *mtd = gluNewQuadric();
	glTranslatef(0.5, (3 + 1.75*cos((float)Mtheta1 * 22 / (7 * 180)) + 1.75*cos((float)(Mtheta1 + Mtheta2) * 22 / (7 * 180))), (1.75*sin((float)Mtheta1 * 22 / (7 * 180)) + 1.75*sin((float)(Mtheta1 + Mtheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Mtheta1 - Mtheta2 - Mtheta3), 1, 0, 0);
	gluCylinder(mtd, 0.3, 0.2, 1.75, 10, 10);
	gluDeleteQuadric(mtd);
	glPopMatrix();

	/*	glColor3f(1, 1, 1);
	glPushMatrix();
	GLUquadricObj *mtdisk = gluNewQuadric();
	gluDisk( mtdisk, 0, 1, 20, 20 );
	gluDeleteQuadric(mtdisk);
	glPopMatrix(); */
	//-------------------------------------------------------------
}

void Hand::rightFingers2()
{

	static float Rtheta1 = -10;
	static float Rtheta2 = -10;
	static float Rtheta3 = -10;
	//Ring Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *rpm = gluNewQuadric();
	glTranslatef(-1, 3, 0);
	glRotatef(-(90 - Rtheta1), 1, 0, 0);
	gluCylinder(rpm, 0.5, 0.4, 1.5, 10, 10);
	gluDeleteQuadric(rpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *rdp = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1 * 22 / (7 * 180))), 1.5*sin((float)Rtheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Rtheta1 - Rtheta2), 1, 0, 0);
	gluCylinder(rdp, 0.4, 0.3, 1.5, 10, 10);
	gluDeleteQuadric(rdp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *rtd = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1 * 22 / (7 * 180)) + 1.5*cos((float)(Rtheta1 + Rtheta2) * 22 / (7 * 180))), (1.5*sin((float)Rtheta1 * 22 / (7 * 180)) + 1.5*sin((float)(Rtheta1 + Rtheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Rtheta1 - Rtheta2 - Rtheta3), 1, 0, 0);
	gluCylinder(rtd, 0.3, 0.2, 1.5, 10, 10);
	gluDeleteQuadric(rtd);
	glPopMatrix();
	//-------------------------------------------------------------
}

void Hand::rightFingers3()
{

	static float Mtheta1 = -10;
	static float Mtheta2 = -10;
	static float Mtheta3 = -10;
	//Middle Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *mpm = gluNewQuadric();
	glTranslatef(0.5, 3, 0);
	glRotatef(-(90 - Mtheta1), 1, 0, 0);
	gluCylinder(mpm, 0.5, 0.4, 1.75, 10, 10);
	gluDeleteQuadric(mpm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *mdp = gluNewQuadric();
	glTranslatef(0.5, (3 + 1.75*cos((float)Mtheta1 * 22 / (7 * 180))), 1.75*sin((float)Mtheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Mtheta1 - Mtheta2), 1, 0, 0);
	gluCylinder(mdp, 0.4, 0.3, 1.75, 10, 10);
	gluDeleteQuadric(mdp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *mtd = gluNewQuadric();
	glTranslatef(0.5, (3 + 1.75*cos((float)Mtheta1 * 22 / (7 * 180)) + 1.75*cos((float)(Mtheta1 + Mtheta2) * 22 / (7 * 180))), (1.75*sin((float)Mtheta1 * 22 / (7 * 180)) + 1.75*sin((float)(Mtheta1 + Mtheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Mtheta1 - Mtheta2 - Mtheta3), 1, 0, 0);
	gluCylinder(mtd, 0.3, 0.2, 1.75, 10, 10);
	gluDeleteQuadric(mtd);
	glPopMatrix();

	/*	glColor3f(1, 1, 1);
	glPushMatrix();
	GLUquadricObj *mtdisk = gluNewQuadric();
	gluDisk( mtdisk, 0, 1, 20, 20 );
	gluDeleteQuadric(mtdisk);
	glPopMatrix(); */
	//-------------------------------------------------------------
}

void Hand::leftFingers4()
{

	static float Itheta1 = -10;
	static float Itheta2 = -10;
	static float Itheta3 = -10;
	//Index Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *ipm = gluNewQuadric();
	glTranslatef(2, 3, 0);
	glRotatef(-(90 - Itheta1), 1, 0, 0);
	gluCylinder(ipm, 0.5, 0.4, 1.35, 10, 10);
	gluDeleteQuadric(ipm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *idp = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1 * 22 / (7 * 180))), 1.35*sin((float)Itheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Itheta1 - Itheta2), 1, 0, 0);
	gluCylinder(idp, 0.4, 0.3, 1.35, 10, 10);
	gluDeleteQuadric(idp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *itd = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1 * 22 / (7 * 180)) + 1.35*cos((float)(Itheta1 + Itheta2) * 22 / (7 * 180))), (1.35*sin((float)Itheta1 * 22 / (7 * 180)) + 1.35*sin((float)(Itheta1 + Itheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Itheta1 - Itheta2 - Itheta3), 1, 0, 0);
	gluCylinder(itd, 0.3, 0.2, 1.35, 10, 10);
	gluDeleteQuadric(itd);
	glPopMatrix();
	//------------------------------------------------------------
}

void Hand::rightFingers4()
{

	static float Itheta1 = -10;
	static float Itheta2 = -10;
	static float Itheta3 = -10;
	//Index Finger ----------------------------
	// P-M cylinder
	//glColor3f(0.3, 0.5, 0.7);
	glPushMatrix();
	GLUquadricObj *ipm = gluNewQuadric();
	glTranslatef(2, 3, 0);
	glRotatef(-(90 - Itheta1), 1, 0, 0);
	gluCylinder(ipm, 0.5, 0.4, 1.35, 10, 10);
	gluDeleteQuadric(ipm);
	glPopMatrix();

	// D-P cylinder
	//glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *idp = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1 * 22 / (7 * 180))), 1.35*sin((float)Itheta1 * 22 / (7 * 180)));
	glRotatef(-(90 - Itheta1 - Itheta2), 1, 0, 0);
	gluCylinder(idp, 0.4, 0.3, 1.35, 10, 10);
	gluDeleteQuadric(idp);
	glPopMatrix();

	// T-D cylinder
	//glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *itd = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1 * 22 / (7 * 180)) + 1.35*cos((float)(Itheta1 + Itheta2) * 22 / (7 * 180))), (1.35*sin((float)Itheta1 * 22 / (7 * 180)) + 1.35*sin((float)(Itheta1 + Itheta2) * 22 / (7 * 180))));
	glRotatef(-(90 - Itheta1 - Itheta2 - Itheta3), 1, 0, 0);
	gluCylinder(itd, 0.3, 0.2, 1.35, 10, 10);
	gluDeleteQuadric(itd);
	glPopMatrix();
	//------------------------------------------------------------
}