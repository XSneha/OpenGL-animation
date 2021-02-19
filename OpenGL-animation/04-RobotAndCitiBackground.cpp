#include "Global.h"

GLuint bg_texture;
GLuint ground_texture;
GLuint robot_texture;
GLuint robot_texture_dark;
GLuint robot_body;
GLuint robot_face;
int sholder, elbow, palm;

GLUquadric* quadric = NULL;
GLfloat angle = 0.00f;

GLfloat wingAngle = 0.0f;

// Display robot comming out from the city
void DisplayRobotS3(void) {
	fprintf(gpFile, "Display Robot with skyline in backgroud S3\n");

	void DrawRobot();
	void DrawTree();
	void DrawBird();
	void Box();
	void DrawPlant();
	void Skyline(void);
	//void Update();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// gluLookAt(0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// glRotatef(angle, 0.0f, 1.0f, 0.0f);
//	 glRotatef(angle,1.0f,0.0f,0.0f);
//	Box();
//	Camera();

	Skyline();
	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, -10.0f);
	//	glRotatef(angle,1.0f,0.0f,0.0f);

	/*Properties properties;
	properties.pos.x = -1.0f;
	properties.pos.y = -1.0f;
	properties.pos.z = -1.0f;

	//DataPropertyInterface propertyMap = DataPropertyInterface();
	//propertyMap.put(BIRD, properties);

	Properties currentProperties = {};
	//propertyMap.get(BIRD, currentProperties);*/

	//fprintf(gpFile, "object : BIRD = position : x= %f , %f, %f", currentProperties.pos.x, currentProperties.pos.y, currentProperties.pos.z);


	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	DrawBird();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.02f, 0.02f, 0.02f);
	glTranslatef(0.0f, -4.8f, -20.0f);
	//glTranslatef(0.0f, -5.0f, -720.0f);
	//glRotatef(angle,0.0f,1.0f,0.0f);
	DrawRobot();
	//glPopMatrix();

	//glPushMatrix();
	//glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(0.0f, 3.0f, 1.8f);
	glScalef(1.4f, 1.4f, 1.4f);

	DrawPlant();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(-1.5f, 0.8f, -40.0f);
	//	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	DrawTree();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(-2.7f, 0.2f, -10.0f);
	//	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	DrawTree();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(2.5f, 0.2f, -10.0f);
	//	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	DrawTree();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(3.5f, 0.2f, -7.0f);
	//	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	DrawTree();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(-2.7f, 12.2f, -2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	//	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	DrawTree();
	glPopMatrix();
	//	DrawTree();
		//DrawBird();
		//DrawGallary();
}

void UpdateRobotS3(void) {
	static bool up = true;

	angle = angle + 0.1f;
	if (angle >= 360.0f) {
		angle = 0.0f;
	}

	/*lightAngle0 = lightAngle0 + 0.2f;
	if (lightAngle0 >= 360.0f) {
		lightAngle0 = 0.0f;
	}*/

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

void InitalizeRobotS3(void) {


}


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

void Skyline(void) {
	GLfloat bgHeight = 40.0f;
	GLfloat bgWidth = 25.0f;
	GLfloat gLength = 10.0f;
	GLfloat gWidth = 30.0f;

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -gWidth);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, bg_texture);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-bgWidth, bgHeight, 0);

	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-bgWidth, 0, 0);

	glTexCoord2d(2.0f, 0.0f);
	glVertex3f(bgWidth, 0, 0);

	glTexCoord2d(2.0f, 1.0f);
	glVertex3f(bgWidth, bgHeight, 0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, ground_texture);
	glBegin(GL_QUADS);
	//ground
	glTexCoord2d(0.0f, 90.0f);
	glVertex3f(-gLength, 0.01f, -gWidth);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-gLength, -0.2f, gWidth);
	glTexCoord2d(90.0f, 0.0f);
	glVertex3f(gLength, -0.2f, gWidth);
	glTexCoord2d(90.0f, 90.0f);
	glVertex3f(gLength, 0.01, -gWidth);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}


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
	glTranslatef(width + 0.3, 0.0f, 0.0f);
	DrawArm(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(width + 0.3), 0.0f, 0.0f);
	DrawArm(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, width * 2, 0.0f);
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
	glColor3f(0.184, 0.310, 0.310);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2, 0.2, 1.5, 10, 10);
	glPopMatrix();
	glTranslatef(-0.4f, 0.0f, 0.0f);
	glColor3f(0.416, 0.353, 0.804);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.3, 30, 30);

	glPopMatrix();
	glTranslatef(0.4f, 1.5f, 0.0f);
	glColor3f(0.184, 0.310, 0.310);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2, 0.2, 1.5, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0f, -1.5f, 0.0f);
	glColor3f(0.416, 0.353, 0.804);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.3, 30, 30);
	glPopMatrix();
}

void DrawNeck() {
	GLfloat height = 2.5f;
	glTranslatef(0.0f, height, 0.0f);
	glColor3f(0.184, 0.310, 0.310);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2, 0.2, 1.0, 10, 10);
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
	glColor3f(0.416, 0.353, 0.804);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.35, 30, 30);
	glPushMatrix();
	glRotatef((GLfloat)sholder, 1.0f, 0.0f, 0.0f);
	//glTranslatef( 0.0f, -0.5f, 0.0f);
	glTranslatef(0.0f, -0.2f, 0.0f);

	glPushMatrix();
	//glColor3f(0.5f, 0.35f, 0.05f);
	//glScalef(0.5f, 2.0f, 1.0f);
	//quadric = gluNewQuadric();
	//gluSphere(quadric, 0.5, 10, 10);
	glColor3f(0.184, 0.310, 0.310);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2, 0.2, 1.0, 10, 10);

	//fore arm 
	glPopMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);

	//ebow joint
	glColor3f(0.416, 0.353, 0.804);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2, 30, 30);
	glRotatef((GLfloat)elbow, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, -0.2f, 0.0f);
	glPushMatrix();

	glColor3f(0.184, 0.310, 0.310);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.2, 0.2, 1.0, 10, 10);

	//palm
	glPopMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);

	glRotatef((GLfloat)palm, 0.0f, 0.0f, 1.0f);
	// glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	//palm joint
	glColor3f(0.416, 0.353, 0.804);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2, 30, 30);
	glPopMatrix();
	glPopMatrix();
}


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

void DrawBird() {
	void DrawWing();
	void WingMoment();
	//move from left to right 
	 //body
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(1.000, 0.271, 0.000);
	quadric = gluNewQuadric();
	glScalef(2.5f, 1.5f, 1.5f);
	gluSphere(quadric, 0.15f, 10, 10);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslatef(0.3f, 0.0f, 0.0f);
	glColor3f(1.000, 0.271, 0.000);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	quadric = gluNewQuadric();
	gluCylinder(quadric, 0.0f, 0.1f, 0.4f, 10, 10);
	glPopMatrix();

	//face
	glPushMatrix();
	glTranslatef(-0.45f, 0.0f, 0.0f);
	glColor3f(1.000, 0.271, 0.000);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.13, 30, 30);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslatef(-0.3f, 0.0f, 0.0f);
	glColor3f(1.000, 0.843, 0.000);
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
	glColor3f(1.000, 0.843, 0.000);
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

	glScalef(0.15, 0.01, 0.15);
	GLfloat width = 2.0f, facelength = 3.0f;
	//wings
	glColor3f(1.000, 0.271, 0.000);

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
