#include "Resources/Headers/Global.h"

GLuint bg_texture;
GLuint ground_texture;

GLfloat angle = 0.00f;

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
}

void UpdateRobotS3(void) {
	void UpdateFlyingAction(void);
	angle = angle + 0.1f;
	if (angle >= 360.0f) {
		angle = 0.0f;
	}

	UpdateFlyingAction();
	/*lightAngle0 = lightAngle0 + 0.2f;
	if (lightAngle0 >= 360.0f) {
		lightAngle0 = 0.0f;
	}*/
}

void InitalizeRobotS3(void) {


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
	glVertex3f(gLength, 0.01f, -gWidth);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

