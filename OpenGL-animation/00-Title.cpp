#include "Resources/Headers/Global.h"

#define FAST_SPEED 0.1f;
#define NORMAL_SPEED 0.01f
#define SLOW_SPEED 0.006f
#define TOP 2.0f
#define BOTTOM -10.0f

GLuint feather_texture;
GLfloat feather_angle = 0.0f;
GLfloat feather_x = 0.0f;
GLfloat feather_y = 0.0f;

void InitializeTitle(void) {
	fprintf(gpFile, "Calling title initialize\n");
	LoadGLTextures(&feather_texture, MAKEINTRESOURCE(FEATHER_TEXTURE));
	glBindTexture(GL_TEXTURE_2D, 0);
}

void DisplayTitle(void) {
	//glScalef(50.0f, 30.0f, 30.0f);
	glTranslatef(feather_x, feather_y, -5.0f);
	glRotatef(feather_angle,0.0f,0.0f,1.0f);
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
	/*
	if (feather_y > BOTTOM) {
		feather_y -= SLOW_SPEED;
	}
	else {
		gbRenderScene_00 = false;
		gbRenderScene_01 = true;
	}
	if (feather_angle >0 && feather_angle < 90.0f) {
		feather_angle -= SLOW_SPEED;
	}
	if (feather_angle < 0 && feather_angle > -90.0f) {
		feather_angle += SLOW_SPEED;
	}*/
}
