#include "Global.h"
#define NORMAL_SPEED 0.001f
#define SLOW_SPEED 0.0001f;
#define MID 0.0f
#define SIDEMARGINE 1.95f

bool gbScrolling = false;
bool gbDisplayThankYou = false;
bool gbStartClosingCurtains = false;

GLfloat gfYscrollTranslation = -2.0f;

COLOR cDarkMaroon = { 0.5f, 0.0f, 0.0f };
COLOR cLightMaroon = { 0.7f, 0.03f, 0.03f };
COLOR cDarkGold1 = { 0.9f, 0.7f, 0.0f };
COLOR cLightGold1 = { 1.0f, 0.8f, 0.0f };

void InitializeClosing(void) {
	fprintf(gpFile, "Display closing S5 initialized\n");
}

void DisplayClosing(void)
{
	void ScrollCurtainCall(void);
	void ProjectBy(void);

	//variable declarations
	static ULONGLONG timer = GetTickCount64();

	//code
	gluLookAt(0.0f, 0.0f, -2.5f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	ULONGLONG timer_end = GetTickCount64();

	if ((timer_end - timer) >= 2000) {
		gbDisplayThankYou = true ;
	}
	if ((timer_end - timer) <= 4000)
	{
		ProjectBy();
	}
	else
	{
		gbScrolling = true;
		ScrollCurtainCall();
	}
}

void UpdateClosing(void)
{
	//variable declarations
	GLfloat fTopPos = -(fWindowTop - 0.7f);

	if (gbScrolling) {
		gfYscrollTranslation += NORMAL_SPEED;
	}
}

void ProjectBy(void)
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

	if (gbDisplayThankYou == false)
	{
		glTranslatef(-1.0f, 0.0f, -fZAxisPosition);
		glScalef(2.5f, 2.5f, 2.5f);
		glColor3f(cDarkGold1.red, cDarkGold1.green, cDarkGold1.blue);

		glRasterPos3f(0.0f, 0.1f, 0.0f);
		glListBase(uiFontList);
		glCallLists(13, GL_UNSIGNED_BYTE, "Created By...");
		glRasterPos3f(0.05f, 0.0f, 0.0f);
		glCallLists(13, GL_UNSIGNED_BYTE, "Sneha Sawant");
		//glRasterPos3f(0.1f, -0.1f, 0.0f);
		//glCallLists(12, GL_UNSIGNED_BYTE, "Presents...");
	}
	else
	{
		glTranslatef(-0.65f, -0.1f, -fZAxisPosition);
		glScalef(2.5f, 2.5f, 2.5f);
		glColor3f(cDarkGold1.red, cDarkGold1.green, cDarkGold1.blue);

		glRasterPos3f(0.0f, 0.1f, 0.0f);
		glListBase(uiFontList);
		glCallLists(13, GL_UNSIGNED_BYTE, "Thank You...");
	}

	if (hVertexFont)
	{
		DeleteObject(hVertexFont);
		hVertexFont = NULL;
	}
}


void ScrollCurtainCall(void)
{
	//variable declarations
	GLfloat fYAxisPosition = 1.0f;
	GLfloat fXAxisPosition1 = -0.3;
	const GLfloat LINE_GAP = 0.25f;

	//code
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-0.3f, gfYscrollTranslation, -fZAxisPosition);

	glColor3f(cDarkGold1.red, cDarkGold1.green, cDarkGold1.blue);
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glListBase(nFontList);
	glCallLists(10, GL_UNSIGNED_BYTE, "RTR Batch ");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(16, GL_UNSIGNED_BYTE, ":    2020-2021");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glCallLists(11, GL_UNSIGNED_BYTE, "Group Name ");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(11, GL_UNSIGNED_BYTE, ":    Vertex");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glCallLists(12, GL_UNSIGNED_BYTE, "Group Leader");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(16, GL_UNSIGNED_BYTE, ":    Amit Shinde");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glCallLists(18, GL_UNSIGNED_BYTE, "Renderig Technology");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(28, GL_UNSIGNED_BYTE, ":    Fixed Function Pipeline");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glCallLists(10, GL_UNSIGNED_BYTE, "Resources");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(20, GL_UNSIGNED_BYTE, ":    FFP Assignments");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(29, GL_UNSIGNED_BYTE, "     Yogeshwar Sir's Lectures");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(11, GL_UNSIGNED_BYTE,"      MSDN");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(fXAxisPosition1, fYAxisPosition, 0.0f);
	glCallLists(11, GL_UNSIGNED_BYTE, "Sound Track");
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(32, GL_UNSIGNED_BYTE, ":    Stillness Of The Lake");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(32, GL_UNSIGNED_BYTE, "     By Hariprasad Chaurasia");

	fYAxisPosition -= LINE_GAP;
	glRasterPos3f(0.8f, fYAxisPosition, 0.0f);
	glCallLists(32, GL_UNSIGNED_BYTE, "       and Shivkumar Sharma");

	//glViewport(0, 0, (GLsizei)gWinWidth, (GLsizei)gWinHeight);

	if (gfYscrollTranslation >= 2.7f)
	{
		gbStartClosingCurtains = true;
	}
}
