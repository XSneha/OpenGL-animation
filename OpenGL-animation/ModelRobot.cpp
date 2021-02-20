#include "Resources/Headers/Global.h"

GLuint robot_texture;
GLuint robot_texture_dark;
GLuint robot_body;
GLuint robot_face;

int sholder, elbow, palm;

void DrawRobot() {
	void DrawArm(int side);
	void DrawTorso();
	void DrawFace();
	void DrawNeck();
	void DrawLegs();

	GLfloat width = 0.9f;
	GLfloat facelength = 0.45f;

	//torso

	glPushMatrix();
	//gluLookAt(camerapos[0], camerapos[1], camerapos[2], viewpos1[0], viewpos1[1], viewpos1[2], upVec[0], 1.0f, upVec[2]);
	//glTranslatef(0.0f, 0.0f, -7.0f);
	//glRotatef(angle, 1.0f, 0.0f, 0.0f);

	//DrawTorso();
	glPushMatrix();
	DrawLegs();
	glPopMatrix();
	glPushMatrix();
	DrawTorso();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(width + 0.3f, 0.0f, 0.0f);
	DrawArm(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(width + 0.3f), 0.0f, 0.0f);
	DrawArm(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, width * 2.0f, 0.0f);
	DrawNeck();
	glPopMatrix();
	glPushMatrix();
	DrawFace();
	glColor3f(1.0f, 1.0f, 1.0f);
	glPopMatrix();

	//legs
	//control with keyword c+up,down,left,right and c+z : camera = child view
}

void DrawLegs() {
	GLfloat legLength = 1.5f;
	glPushMatrix();
	glTranslatef(-0.4f, 1.5f, 0.0f);
	glColor3f(0.184f, 0.310f, 0.310f);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2f, 0.2f, 1.5f, 10, 10);
	glPopMatrix();
	glTranslatef(-0.4f, 0.0f, 0.0f);
	glColor3f(0.416f, 0.353f, 0.804f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.3f, 30, 30);

	glPopMatrix();
	glTranslatef(0.4f, 1.5f, 0.0f);
	glColor3f(0.184f, 0.310f, 0.310f);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2f, 0.2f, 1.5f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0f, -1.5f, 0.0f);
	glColor3f(0.416f, 0.353f, 0.804f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.3f, 30, 30);
	glPopMatrix();
}

void DrawNeck() {
	GLfloat height = 2.5f;
	glTranslatef(0.0f, height, 0.0f);
	glColor3f(0.184f, 0.310f, 0.310f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2f, 0.2f, 1.0, 10, 10);
}

void DrawTorso() {
	GLfloat width = 0.9f;
	GLfloat height = 2.5f;
	glPushMatrix();
	glTranslatef(0.0f, height, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, robot_body);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, 1.0f, 1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, 1.0f, 1.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindTexture(GL_TEXTURE_2D, robot_texture);
	glBegin(GL_QUADS);
	//left 
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, 1.0f, -1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -1.0f, -1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-width, 1.0f, 1.0f);

	//right
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(width, 1.0f, 1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -1.0f, -1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, 1.0f, -1.0f);

	//back
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, 1.0f, -1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -1.0f, -1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -1.0f, -1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, 1.0f, -1.0f);

	//top
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, 1.0f, -1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, 1.0f, 1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, 1.0f, 1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, 1.0f, -1.0f);

	//bottom
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, -1.0f, -1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -1.0f, 1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, -1.0f, -1.0f);

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

void DrawFace() {
	GLfloat width = 0.8f;
	GLfloat facelength = 0.45f;
	GLfloat height = 4.2f;
	glTranslatef(0.0f, height + facelength, 0.0f);
	glPushMatrix();
	// GLfloat height = 2.5f;
	// glTranslatef(0.0f, height+ facelength, 0.0f);
	 //glClearColor(0.0f,0.0f,0.0f,1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, robot_face);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, width);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	// glColor3f(1.0f, 1.0f, 1.0f);
	// glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, robot_texture);
	glBegin(GL_QUADS);
	//left 
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, -width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-width, facelength, width);

	//right
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(width, facelength, width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, -width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//back
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, -width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, -width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//top
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, facelength, -width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, facelength, width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, facelength, width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, facelength, -width);

	//bottom
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-width, -facelength, -width);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-width, -facelength, width);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(width, -facelength, width);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(width, -facelength, -width);

	//antrnnas
	glTranslatef(0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);


	//left ear

	//right ear


	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

void DrawArm(int side) {
	glTranslatef(0.0f, 1.0f, 0.0f);
	GLfloat height = 2.5f;
	glTranslatef(0.0f, height, 0.0f);
	//sholder joint
	glColor3f(0.416f, 0.353f, 0.804f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.35f, 30, 30);
	glPushMatrix();
	glRotatef((GLfloat)sholder, 1.0f, 0.0f, 0.0f);
	//glTranslatef( 0.0f, -0.5f, 0.0f);
	glTranslatef(0.0f, -0.2f, 0.0f);

	glPushMatrix();
	//glColor3f(0.5f, 0.35f, 0.05f);
	//glScalef(0.5f, 2.0f, 1.0f);
	//quadric = gluNewQuadric();
	//gluSphere(quadric, 0.5, 10, 10);
	glColor3f(0.184f, 0.310f, 0.310f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2f, 0.2f, 1.0, 10, 10);

	//fore arm 
	glPopMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);

	//ebow joint
	glColor3f(0.416f, 0.353f, 0.804f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2f, 30, 30);
	glRotatef((GLfloat)elbow, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, -0.2f, 0.0f);
	glPushMatrix();

	glColor3f(0.184f, 0.310f, 0.310f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2f, 0.2f, 1.0f, 10, 10);

	//palm
	glPopMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);

	glRotatef((GLfloat)palm, 0.0f, 0.0f, 1.0f);
	// glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	//palm joint
	glColor3f(0.416f, 0.353f, 0.804f);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2f, 30, 30);
	glPopMatrix();
	glPopMatrix();
}
