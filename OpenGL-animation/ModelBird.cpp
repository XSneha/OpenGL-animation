#include "Resources/Headers/Global.h"

GLfloat wingAngle = 0.0f;

void UpdateFlyingAction(void) {
	static bool up = true;

	if (wingAngle < 20.0f && up == true) {
		wingAngle += 0.09f;
	}
	else if (wingAngle >= 20.0f && up == true) {
		up = false;
	}

	else if (up == false && wingAngle > 0.0f) {
		wingAngle -= 0.09f;
	}
	else if (wingAngle <= 0.0f && up == false) {
		up = true;
	}
}

void DrawBird() {
	void DrawWing();
	void WingMoment();
	//move from left to right 
	 //body
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(1.000f, 0.271f, 0.000f);
	quadric = gluNewQuadric();
	glScalef(2.5f, 1.5f, 1.5f);
	gluSphere(quadric, 0.15f, 10, 10);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslatef(0.3f, 0.0f, 0.0f);
	glColor3f(1.000f, 0.271f, 0.000f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.0f, 0.1f, 0.4f, 10, 10);
	glPopMatrix();

	//face
	glPushMatrix();
	glTranslatef(-0.45f, 0.0f, 0.0f);
	glColor3f(1.000f, 0.271f, 0.000f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.13, 30, 30);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslatef(-0.3f, 0.0f, 0.0f);
	glColor3f(1.000f, 0.843f, 0.000f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.0f, 0.1f, 0.4f, 10, 10);
	glPopMatrix();


	//eyes
	glPushMatrix();
	glTranslatef(-0.55f, 0.0f, -0.1f);
	glColor3f(0.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.02f, 10, 10);
	//	 gluCylinder(quadric, 0.0f, 0.05f, 0.2f, 10, 10);
	glPopMatrix();
	//eyes
	glPushMatrix();
	glTranslatef(-0.55f, 0.0f, 0.1f);
	glColor3f(0.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.02f, 10, 10);
	//	 gluCylinder(quadric, 0.0f, 0.05f, 0.2f, 10, 10);
	glPopMatrix();

	//beak
	glPushMatrix();
	glTranslatef(-0.70f, 0.0f, 0.0f);
	glColor3f(1.000f, 0.843f, 0.000f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.0f, 0.1f, 0.4f, 10, 10);
	//	 gluCylinder(quadric, 0.0f, 0.05f, 0.2f, 10, 10);
	glPopMatrix();

	//wings
	glPushMatrix();
	//glTranslatef(0.0f, 0.1f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.3f);
	WingMoment();
	glPopMatrix();
	//glPopMatrix();

	glPushMatrix();

	// glTranslatef(0.0f, 0.1f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.3f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	WingMoment();
	glPopMatrix();

	/*glPushMatrix();
	glColor3f(1.000, 0.271, 0.000);
	glTranslatef(0.0f, 0.0f, 0.3f);5
	glRotatef(40.0f, 1.0f, 0.0f, 0.0f);
   // DrawWing();
	glPopMatrix();
	glPushMatrix();
   // glTranslatef(0.0f, 0.0f, -0.3f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.15f);
	glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.3f);
	DrawWing();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.45f);
	glRotatef(-20.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.3f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	*/
}

void WingMoment() {
	void DrawWing();

	//	 glTranslatef(0.0f, 0.0f, -12.0f);
	glPushMatrix();

	glRotatef((GLfloat)wingAngle, 1.0f, 0.0f, 0.0f);
	//	 glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	DrawWing();

	glPopMatrix();
	glTranslatef(0.0f, 0.0f, -0.3f);
	//	 glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef((GLfloat)-(wingAngle * 3), 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.3f);
	//	 glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	glScalef(1.0f, 0.6f, 1.0f);
	DrawWing();

	glPopMatrix();
	glPopMatrix();

}

void DrawWing() {

	glScalef(0.15f, 0.01f, 0.15f);
	GLfloat width = 2.0f, facelength = 3.0f;
	//wings
	glColor3f(1.000f, 0.271f, 0.000f);

	// glBindTexture(GL_TEXTURE_2D, robot_face);
	glBegin(GL_QUADS);
	//front face
   // glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, width);
	// glEnd();
	// glBindTexture(GL_TEXTURE_2D, 0);

	 // glColor3f(1.0f, 1.0f, 1.0f);
	 // glColor3f(1.0f, 1.0f, 1.0f);
	// glBindTexture(GL_TEXTURE_2D, robot_texture);
	// glBegin(GL_QUADS);
	 //left 
	// glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, -width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-width, facelength, width);

	//right
   // glTexCoord2d(0.0f, 1.0f);
	glVertex3f(width, facelength, width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, -width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//back
   // glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, -width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, -width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//top
   // glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, facelength, width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, facelength, width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//bottom
   // glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, -facelength, -width);
	// glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	// glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	// glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, -facelength, -width);

	glEnd();
	//glBindTexture(GL_TEXTURE_2D, 0);

}

