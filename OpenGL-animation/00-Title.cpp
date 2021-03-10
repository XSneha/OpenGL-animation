#include "Resources/Headers/Global.h"

#define FEATHER_SPEED 0.0001f;
#define NORMAL_SPEED 0.01f
#define SLOW_SPEED 0.00006f
#define TOP 2.0f
#define BOTTOM -1.5f

GLuint feather_texture;
GLfloat feather_angle = 0.0f;
GLfloat feather_x = 0.0f;
GLfloat feather_y = TOP;
GLfloat feather_y2 = TOP - 0.2f;
bool isUp = false;
bool leafSettled = false;

void InitializeTitle(void) {
	fprintf(gpFile, "Calling title initialize\n");
	LoadGLTextures(&feather_texture, MAKEINTRESOURCE(FEATHER_TEXTURE));
	glBindTexture(GL_TEXTURE_2D, 0);
}

void DisplayTitle(void) {
	void DrawFeather(void);

	//glScalef(50.0f, 30.0f, 30.0f);
	//
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
//	glScalef(20.0f, 20.0f, 20.0f);
	glTranslatef(feather_x + 1.0f, feather_y, -3.0f);
	//	glTranslatef(0.0f,0.0f, -5.0f);
	glRotatef(feather_angle-30, 0.0f, 0.0f, 1.0f);
	DrawFeather();
	glPopMatrix();

	glPushMatrix();
//	glScalef(20.0f, 20.0f, 20.0f);
	glTranslatef(feather_x - 1.5f, feather_y2 - 0.5f, -3.0f);
	//	glTranslatef(0.0f,0.0f, -5.0f);
	glRotatef(feather_angle-30, 0.0f, 0.0f, 1.0f);	DrawFeather();
	glPopMatrix();
}

void DrawFeather(void) {
	
	glBindTexture(GL_TEXTURE_2D, feather_texture);
	glBegin(GL_QUADS);
	// Back
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void UpdateTitle(void)
{

	if (isUp) {
		feather_x += FEATHER_SPEED;
	}
	else {
		feather_x -= FEATHER_SPEED;
	}
	if (feather_angle <=0 && feather_angle >= -60.0f && !isUp) {
		
		feather_angle -= NORMAL_SPEED;
		if (feather_angle <= -60.0f ) {
			isUp = true;
		}
	}
	else if (feather_angle <=0  && isUp) {
	
		feather_angle += NORMAL_SPEED;
		if (feather_angle >= 0.0f) {
			isUp = false;
			feather_angle = 0.0f;
		}
	}

	if (feather_y > BOTTOM) {
		feather_y -= SLOW_SPEED;
	}
	if (feather_y2 > BOTTOM) {
		feather_y2 -= SLOW_SPEED;
	}
	else {
		leafSettled = true;
	}

	if (leafSettled) {
		gbRenderScene_00 = false;
		gbRenderScene_01 = true;
	}
	
}
