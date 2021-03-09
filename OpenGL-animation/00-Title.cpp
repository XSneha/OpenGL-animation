#include "Resources/Headers/Global.h"

#define FAST_SPEED 0.1f;
#define NORMAL_SPEED 0.01f
#define SLOW_SPEED 0.00006f
#define TOP 2.0f
#define BOTTOM -1.5f

GLuint feather_texture;
GLfloat feather_angle = 0.0f;
GLfloat feather_x = 0.0f;
GLfloat feather_y = TOP;
bool isUp = false;
bool leafSettled = false;

void InitializeTitle(void) {
	fprintf(gpFile, "Calling title initialize\n");
	LoadGLTextures(&feather_texture, MAKEINTRESOURCE(FEATHER_TEXTURE));
	glBindTexture(GL_TEXTURE_2D, 0);
}

void DisplayTitle(void) {
	//glScalef(50.0f, 30.0f, 30.0f);
	//
	glMatrixMode(GL_MODELVIEW);
	
	glPushMatrix();

	glLoadIdentity();

	glScalef(20.0f, 20.0f, 20.0f);
	glTranslatef(feather_x, feather_y, -5.0f);
//	glTranslatef(0.0f,0.0f, -5.0f);

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

	glPopMatrix();
}

void UpdateTitle(void)
{

	if (isUp) {
		feather_x += SLOW_SPEED;
	}
	else {
		feather_x -= SLOW_SPEED;
	}
	if (feather_angle <=0 && feather_angle >= -90.0f && !isUp) {
		
		feather_angle -= NORMAL_SPEED;
		fprintf(gpFile, ">= 90 feather_angle >0 : %f\n", feather_angle);
		if (feather_angle <= -90.0f ) {
			isUp = true;
		}
	}
	else if (feather_angle <=0  && isUp) {
	
		feather_angle += NORMAL_SPEED;
		fprintf(gpFile, "<= -90 feather_angle < 0 : %f\n", feather_angle);
		if (feather_angle >= 0.0f) {
			isUp = false;
			feather_angle = 0.0f;
		}
	}

	if (feather_y > BOTTOM) {
		feather_y -= SLOW_SPEED;
	}
	else {
		leafSettled = true;
	}

	if (leafSettled) {
		gbRenderScene_00 = false;
		gbRenderScene_01 = true;
	}
	
}
