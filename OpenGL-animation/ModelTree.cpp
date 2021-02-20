#include "Resources/Headers/Global.h"

void DrawTree() {
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.1, 0.1, 1.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0f, 0.55f, 0.5f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.3f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0f, 0.52f, 0.5f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.6f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0f, 0.49f, 0.5f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.9f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0f, 0.47f, 0.5f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 1.2f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0f, 0.45f, 0.5f, 10, 10);
	glPopMatrix();
}
