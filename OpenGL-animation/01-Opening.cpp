#include "Resources/Headers/Global.h"

#define NORMAL_SPEED 0.01f
#define SLOW_SPEED 0.006f;

//curtain transition elements
static GLfloat fTransitUnit = 0.0f;
bool zoom = false;

// Adjust the multiplier to adjust the animation speed for objects
const GLfloat Camera_fDeltaMultiplier = 5.5f;

// Camera
const GLfloat Camera_fZZoomEnd = 50.0f;
const GLfloat Camera_fZZoomStart = 90.0f;
const GLfloat Camera_fZZoomOutStop = 70.0f;
const GLfloat Camera_fDeltaEyeAngle = 0.005f * Camera_fDeltaMultiplier;
const GLfloat Camera_fZoomInDistance = 0.006f * Camera_fDeltaMultiplier;

GLfloat cameraPos[3] = { 0.0f, 0.0f, 160.0f };
GLfloat cameraCenter[3] = { 0.0f, 0.0f, 0.0f };
GLfloat cameraUpVec[3] = { 0.0f, 1.0f, 0.0f };

static GLfloat doorAngle = 0.0f;
/*Camera status variables*/
// Animation status variables
bool Camera_bDoneCameraZoomIn = false;
bool Camera_bDoneCameraRotate = false;
bool Camera_bDoneCameraZoomOut = false;
bool Camera_bDoneSceneRotation = false;
bool gb_display_text = true;

COLOR cDarkGold = { 0.9f, 0.7f, 0.0f };
COLOR cLightGold = { 1.0f, 0.8f, 0.0f };

GLuint sky_texture;
GLfloat rotationAngle = 0.0f;

void InitializeOpening(void){
	fprintf(gpFile, "Calling Opening initialize\n");
	LoadGLTextures(&sky_texture, MAKEINTRESOURCE(SKY_TEXTURE));
	glBindTexture(GL_TEXTURE_2D, 0);
}

void DisplayOpening(void){
	// Function Declarations
	void DrawRoom(void);
	void DisplayText(void);
	void DrawRobot(void);
	void DrawPlant(void);
	void floadArms();
	//variables
	static ULONGLONG timer = GetTickCount64();
	ULONGLONG timer_end = GetTickCount64();

	//code
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Setup camera
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], cameraCenter[0], cameraCenter[1], cameraCenter[2], cameraUpVec[0], cameraUpVec[1], cameraUpVec[2]);

	// Draw the room
	glPushMatrix();

	if ((timer_end - timer) <= 4000) {
		DisplayText();
	}
	else if(!Camera_bDoneCameraZoomIn){
		gb_display_text = false;
		glPushMatrix();
		//glScalef(50.0f, 30.0f, 30.0f);
		DrawRoom();
		glPopMatrix();
		//glScalef(0.15f, 0.15f, 0.15f);
		//glTranslatef(0.0f,-0.2f,-2.0f);
		//DrawRobot();
	}
	else if (Camera_bDoneCameraZoomIn) {

		glPushMatrix();
		glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
		//glScalef(0.15f, 0.15f, 0.15f);
		glTranslatef(0.0f,0.0f,5.0f);
		//glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
		glRotatef(90.0f,0.0f,1.0f,0.0f);
		floadArms();
		DrawRobot();
		glPopMatrix();
		glPushMatrix();
		glScalef(2.0f,2.0f,2.0f);
//		glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
		glTranslatef(-1.2f, 2.0f, 0.0f);
		DrawPlant();
		glPopMatrix();
		glPopMatrix();
	}

	glPopMatrix();
}

void UpdateOpening(void)
{
	void walk();
	void ZoomInCamera(void);

	if (doorAngle <= 360.0f) {
		doorAngle += 0.0001f;
	}
	else {
		doorAngle = 0.0f;
	}

	if (gb_display_text ==false && !Camera_bDoneCameraZoomIn) {
		ZoomInCamera();
	}
	else if (gb_display_text == false && Camera_bDoneCameraZoomIn) {
		//fprintf(gpFile, "!isFront angle increment: %f\n", legAngle);
		rotationAngle += NORMAL_SPEED;
		if (legAngle <= 0 && legAngle >= -30.0f && !isFront) {
			fprintf(gpFile, "!isFront angle increment: %f\n", legAngle);

			legAngle -= 0.2;
			if (legAngle <= -30.0f) {
				isFront = true;
			}
		}
		else if (legAngle <= 0 && isFront) {
			fprintf(gpFile, "isFront angle increment: %f\n", legAngle);

			legAngle += 0.2;
			if (legAngle >= 0.0f) {
				isFront = false;
				legAngle = 0.0f;
			}
		}
		//walk();
		//ZoomOutCamera();
	}

	if (gb_display_text == false && Camera_bDoneCameraZoomOut) {
		gbRenderScene_01 = false;
		//gbRenderScene_06 = true;
		//gbRenderScene_04 = true;
		gbRenderScene_02 = true;
	}
}


void walk() {
	
}

// DrawRoom()
void DrawRoom()
{
	//void DrawDoor(void);

	glScalef(50.0f, 30.0f, 30.0f);
	glTranslatef(0.0f,-0.3f,-0.0f);

	glBindTexture(GL_TEXTURE_2D, sky_texture);
	glBegin(GL_QUADS);
	// Back
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.5f, -1.0f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(1.0f, 1.5f, -1.0f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	//gallary 
	glBegin(GL_QUADS);
	// Back
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.1f, -1.0f);
	glVertex3f(-1.0f, 0.1f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	// Back
	GLfloat start_bar = -1.0f;
	for (int i = 0; i < 10; i++) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(start_bar * (i*0.1f), 0.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f) + 0.002f, 0.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f) + 0.002f, -1.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f), -1.0f, -1.0f);
	}
	start_bar = 1.0f;
	for (int i = 0; i < 10; i++) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(start_bar * (i * 0.1f), 0.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f) + 0.002f, 0.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f) + 0.002f, -1.0f, -1.0f);
		glVertex3f(start_bar * (i * 0.1f), -1.0f, -1.0f);
	}
	glEnd();

	glBegin(GL_QUADS);
	// Right
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(1.0f, 1.5f, -1.0f);
	glVertex3f(1.0f, 1.5f, 2.0f);
	glVertex3f(1.0f, -1.0f, 2.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	
	// Left
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-1.0f, 1.5f, 2.0f);
	glVertex3f(-1.0f, 1.5f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 2.0f);

	// Bottom
	glColor3f(1.0f, 0.9f, 0.8f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 2.0f);
	glVertex3f(1.0f, -1.0f, 2.0f);

	// Roof 
	glColor3f(1.0f, 2.9f, 0.8f);
	glVertex3f(1.0f, 1.5f, -1.0f);
	glVertex3f(-1.0f, 1.5f, -1.0f);
	glVertex3f(-1.0f, 1.5f, 2.0f);
	glVertex3f(1.0f, 1.5f, 2.0f);
	glEnd();


	//floore
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (GLfloat x = 1.0f; x > -1.0; x = x - 0.36f)
	{
		glVertex3f(x, -1.0f, 2.0f);
		glVertex3f(x, -1.0f, -2.0f);
	}

	for (GLfloat z = 2.0f; z > -1.0; z = z - 0.36f)
	{
		glVertex3f(-1.0, -1.0f, z);
		glVertex3f(1.0, -1.0f, z);
	}
	glEnd();

	if (!Camera_bDoneCameraZoomIn) {
		//Front
		glBegin(GL_QUADS);
		/*glColor3f(0.25f, 0.25f, 0.25f);
		glVertex3f(-1.0f, 1.5f, 2.0f);
		glVertex3f(1.0f, 1.5f, 2.0f);
		glVertex3f(1.0f, -1.0f, 2.0f);
		glVertex3f(-1.0f, -1.0f, 2.0f);*/

		//floore outside the room
		// Bottom
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(2.0f, -1.0f, 2.0f);
		glVertex3f(-2.0f, -1.0f, 2.0f);
		glVertex3f(-2.0f, -1.0f, 3.0f);
		glVertex3f(2.0f, -1.0f, 3.0f);

		//roof outside the room
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(2.0f, 1.5f, 2.0f);
		glVertex3f(-2.0f, 1.5f, 2.0f);
		glVertex3f(-2.0f, 1.5f, 3.0f);
		glVertex3f(2.0f, 1.5f, 3.0f);


		// extended Left wall
		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(-1.2f, 1.5f, 3.0f);
		glVertex3f(-1.2f, 1.5f, 2.0f);
		glVertex3f(-1.2f, -1.0f, 2.0f);
		glVertex3f(-1.2f, -1.0f, 3.0f);

		// extended right wall
		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(1.2f, 1.5f, 3.0f);
		glVertex3f(1.2f, 1.5f, 2.0f);
		glVertex3f(1.2f, -1.0f, 2.0f);
		glVertex3f(1.2f, -1.0f, 3.0f);

		glEnd();

		//DrawDoor();
	}
}

void DisplayText(void)
{
	HFONT hVertexFont;
	GLuint uiFontList;
	//initialization for font
	LOGFONT logFont;
	logFont.lfHeight = 60;
	logFont.lfWidth = 40;
	logFont.lfEscapement = 0;
	logFont.lfOrientation = 0;
	logFont.lfWeight = FW_NORMAL;
	logFont.lfItalic = FALSE;
	logFont.lfUnderline = FALSE;
	logFont.lfStrikeOut = FALSE;
	logFont.lfCharSet = ANSI_CHARSET;
	logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logFont.lfQuality = DEFAULT_QUALITY;
	logFont.lfPitchAndFamily = DEFAULT_PITCH;

	//create the font and display list
	hVertexFont = CreateFontIndirect(&logFont);

	SelectObject(ghdc, hVertexFont);
	uiFontList = glGenLists(128);
	//wglUseFontOutlines(ghdc, 0, 128, guiFontList, 0.0f, 0.5f, WGL_FONT_POLYGONS, agmf);
	wglUseFontBitmaps(ghdc, 0, 128, uiFontList);

	//code
	glLoadIdentity();
	
	glTranslatef(-2.0f, 0.0f, -fZAxisPosition);
	glScalef(2.5f, 2.5f, 2.5f);
	glColor3f(cDarkGold.red, cDarkGold.green, cDarkGold.blue);

	glRasterPos3f(0.5f, 0.1f, 0.0f);
	glListBase(uiFontList);
	glCallLists(11, GL_UNSIGNED_BYTE, "Presenting");
	glRasterPos3f(0.35f, 0.0f, 0.0f);
	glCallLists(19, GL_UNSIGNED_BYTE, "Story of a Robot...");
	glRasterPos3f(0.6f, -0.1f, 0.0f);
	//glCallLists(12, GL_UNSIGNED_BYTE, "	And Nature.");
	
	if (hVertexFont)
	{
		DeleteObject(hVertexFont);
		hVertexFont = NULL;
	}
}
