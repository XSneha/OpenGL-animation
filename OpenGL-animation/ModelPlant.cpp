#include "Resources/Headers/Global.h"

void DrawPlant() {
	//void pot 
	glPushMatrix();
	glColor3f(0.545f, 0.000f, 0.000f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.55f, 0.30f, 0.5f, 10, 10);
	glPopMatrix();

	//stem
	glPushMatrix();
	glColor3f(0.196f, 0.804f, 0.196f);
	glTranslatef(0.0f, 0.5f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(1.0f, 0.03f, 1.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.05, 0.05, 0.5, 10, 10);
	glPopMatrix();

	//leaf1
	glPushMatrix();
	glColor3f(0.678f, 1.000f, 0.184f);
	glTranslatef(-0.18f, 0.35f, 0.0f);
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	glScalef(2.0f, 1.5f, 0.1f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.09, 10, 10);
	glPopMatrix();

	//leaf 2
	glPushMatrix();
	glColor3f(0.678f, 1.000f, 0.184f);
	glTranslatef(0.18f, 0.15f, 0.0f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glScalef(2.0f, 1.5f, 0.1f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.09, 10, 10);
	glPopMatrix();

	// flower 
	glPushMatrix();
	glColor3f(1.000f, 0.000f, 0.000f);
	glTranslatef(0.0f, 0.5f, 0.0f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.05, 10, 10);
	glPopMatrix();

}