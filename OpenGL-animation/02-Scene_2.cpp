#include "Resources/Headers/Global.h"

bool g_cut_scene = false;

//Initalize Function for flying bird
void InitializeBirdS1(void) {
	fprintf(gpFile, "Display Bird Flying S1\n");
}

//Display Function for flying bird
void DisplayBirdS1(void) {
	void DrawRobot();
	void DrawBird();
	void DrawPlant();
	void Room(void);

	//variables
	static ULONGLONG timer = GetTickCount64();
	ULONGLONG timer_end = GetTickCount64();

	if ((timer_end - timer) >= 5000) {
		g_cut_scene = true;
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 1.0f, -15.0f);
	Room();
	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, -10.0f);
	
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	DrawBird();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.02f, 0.02f, 0.02f);
	glTranslatef(0.0f, -4.8f, -20.0f);
	glTranslatef(-0.5f, 0.0f, -2.0f);
	//glRotatef(90.0f,0.0f,1.0f,0.0f);
	//DrawRobot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -10.0f);
	//glTranslatef(-0.5f, 0.0f, -2.0f);
	glScalef(0.4f, 0.4f, 0.4f);

	DrawPlant();
	glPopMatrix();
}

//Update Function for flying bird
void UpdateBirdS1(void) {
	void UpdateFlyingAction(void);
	UpdateFlyingAction();

	if (g_cut_scene == true) {
		gbRenderScene_02 = false;
		//gbRenderScene_04 = true;
	}
}


void Room(void) {
	GLfloat bgHeight = 3.0f;
	GLfloat bgWidth = 3.0f;
	GLfloat gWidth = 7.0f;

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -gWidth);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, sky_texture);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-bgWidth, bgHeight, 0);

	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-bgWidth, 0, 0);

	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(bgWidth, 0, 0);

	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(bgWidth, bgHeight, 0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	GLfloat gLength = 3.0f;

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	//glBindTexture(GL_TEXTURE_2D, ground_texture);
	glBegin(GL_QUADS);
	//ground
	//glTexCoord2d(0.0f, 90.0f);
	glVertex3f(-gLength, 0.01f, -gWidth);
	//glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-gLength, -0.2f, gWidth);
	//glTexCoord2d(90.0f, 0.0f);
	glVertex3f(gLength, -0.2f, gWidth);
	//glTexCoord2d(90.0f, 90.0f);
	glVertex3f(gLength, 0.01f, -gWidth);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}
