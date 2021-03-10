#include <stdio.h>
#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <math.h>
#include "Resources/Headers/Global.h"

#define M_PI       3.14159265358979323846   // pi
#define DEGTORAD(x)		(GLfloat)(x * (M_PI / 180.0f))

#define NORMAL_SPEED 0.01f
#define SLOW_SPEED 0.006f;
/*Degree to radian converion for camera angle*/

FILE* gpFile = NULL;
GLuint gWinWidth = 0;
GLuint gWinHeight = 0;

GLfloat fWindowLeft = 0.0f;
GLfloat fWindowRight = 0.0f;
GLfloat fWindowTop = 0.0f;
GLfloat fWindowBottom = 0.0f;
GLfloat fZAxisPosition = 3.0f;
GLuint nFontList = 0;
HDC ghdc = NULL;
HINSTANCE ghInstance = NULL;
GLUquadric* quadric = NULL;

/* Scene Transition Variables */
bool gbRenderScene_00 = false;
bool gbRenderScene_01 = true;
bool gbRenderScene_02 = false;
bool gbRenderScene_03 = false;
bool gbRenderScene_04 = false;
bool gbRenderScene_05 = false;
bool gbRenderScene_06 = false;

bool sound_traffic = false;
bool sound_dream = false;
bool sound_title = true;

void LoadTrack(LPCTSTR fileName, DWORD flag)
{
	BOOL bSoundPlayed = FALSE;

	//code
	PlaySound(NULL, 0, 0);

	bSoundPlayed = PlaySound(fileName, ghInstance, flag);
	if (bSoundPlayed == FALSE)
	{
		fprintf(gpFile, "There is an error while playing track...\n");
	}
	fprintf(gpFile, "track loaded sucessfully...\n");
}

// ZoomInCamera()
void ZoomInCamera()
{
	if (Camera_bDoneCameraZoomIn)
		return;

	// To zoom in the camera, reduce the Z eye distance.
	if (cameraPos[2] <= Camera_fZZoomEnd)
		Camera_bDoneCameraZoomIn = true;

	cameraPos[2] -= SLOW_SPEED;
}


// SpinCamera()
void SpinCamera()
{
	// Function declarations
	void CalculateUpVector(void);

	// Variable declarations

	// The radius value at which the camera rotation should stop
	const GLfloat fEndRadius = 4.0f;
	// The amount by which the radius should be reduced at each step
	const GLfloat fRadiusDivisor = 1.0005f; //1.001f;

	static GLfloat fRadius = 20.0f;
	static GLfloat fEyeAngleTheta = 0.0f;
	static GLfloat fEyeAnglePhi = 0.0f;

	// Code
	if (Camera_bDoneSceneRotation)
		return;

	// Camera radius reduces from 20 to 4, zooming in on to the book.
	fRadius = ((fRadius > fEndRadius) ? (fRadius / fRadiusDivisor) : fEndRadius);

	if (fRadius == fEndRadius)
		Camera_bDoneSceneRotation = true;

	// Theta goes from 0 to 90.
	if (fEyeAngleTheta < 90.0f)
		fEyeAngleTheta += Camera_fDeltaEyeAngle;

	// Phi goes from 0 to 90.
	if (fEyeAnglePhi < 90.0f)
		fEyeAnglePhi += Camera_fDeltaEyeAngle;

	// Set eye position
	cameraPos[0] = fRadius * sinf(DEGTORAD(fEyeAngleTheta)) * cosf(DEGTORAD(fEyeAnglePhi));
	cameraPos[1] = fRadius * sinf(DEGTORAD(fEyeAngleTheta)) * sinf(DEGTORAD(fEyeAnglePhi));
	cameraPos[2] = fRadius * cosf(DEGTORAD(fEyeAngleTheta));

	CalculateUpVector();
}

// CalculateUpVector()
// Calculations done according to:
void CalculateUpVector()
{
	// Function declarations
	GLfloat Normalize(GLfloat[]);

	// Variable declarations
	GLfloat fDirection[3];
	GLfloat S[3];
	GLfloat fMagnitude;

	// Code
	fDirection[0] = cameraCenter[0] - cameraPos[0];
	fDirection[0] = cameraCenter[0] - cameraPos[0];
	fDirection[1] = cameraCenter[1] - cameraPos[1];
	fDirection[2] = cameraCenter[2] - cameraPos[2];

	fMagnitude = Normalize(fDirection);

	fDirection[0] /= fMagnitude;
	fDirection[1] /= fMagnitude;
	fDirection[2] /= fMagnitude;

	fMagnitude = Normalize(cameraUpVec);

	cameraUpVec[0] /= fMagnitude;
	cameraUpVec[1] /= fMagnitude;
	cameraUpVec[2] /= fMagnitude;

	S[0] = fDirection[1] * cameraUpVec[2] - fDirection[2] * cameraUpVec[1];
	S[1] = fDirection[2] * cameraUpVec[0] - fDirection[0] * cameraUpVec[2];
	S[2] = fDirection[0] * cameraUpVec[1] - fDirection[1] * cameraUpVec[0];

	fMagnitude = Normalize(S);

	S[0] /= fMagnitude;
	S[1] /= fMagnitude;
	S[2] /= fMagnitude;

	cameraUpVec[0] = S[1] * fDirection[2] - S[2] * fDirection[1];
	cameraUpVec[1] = S[2] * fDirection[0] - S[0] * fDirection[2];
	cameraUpVec[2] = S[0] * fDirection[1] - S[1] * fDirection[0];
}

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

// Normalize()
GLfloat Normalize(GLfloat vec[])
{
	return (sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}


// RotateCamera()
void RotateCamera(void)
{
	// Variable declarations
	static GLfloat fRadius = 4.0f;
	static GLfloat fEyeAngleTheta = 90.0f;
	static GLfloat fEyeAnglePhi = 90.0f;

	// Code
	if (Camera_bDoneCameraRotate)
		return;

	// Theta goes from 90 to 0.
	if (fEyeAngleTheta > 0.0f)
		fEyeAngleTheta -= Camera_fDeltaEyeAngle;

	// Phi goes from 90 t0 0.
	if (fEyeAnglePhi > 0.0f)
		fEyeAnglePhi -= Camera_fDeltaEyeAngle;

	// Set eye position
	cameraPos[0] = fRadius * sinf(DEGTORAD(fEyeAngleTheta)) * cosf(DEGTORAD(fEyeAnglePhi));
	cameraPos[1] = fRadius * sinf(DEGTORAD(fEyeAngleTheta)) * sinf(DEGTORAD(fEyeAnglePhi));
	cameraPos[2] = fRadius * cosf(DEGTORAD(fEyeAngleTheta));

	CalculateUpVector();

	if (fEyeAngleTheta <= 0.0f && fEyeAnglePhi <= 0.0f)
		Camera_bDoneCameraRotate = true;
}


// ZoomOutCamera()
void ZoomOutCamera()
{
	if (Camera_bDoneCameraZoomOut)
		return;

	// To zoom out the camera, increase the Z eye distance.
	if (cameraPos[2] >= Camera_fZZoomOutStop)
	{
		Camera_bDoneCameraZoomOut = true;
	}

	cameraPos[2] += Camera_fZoomInDistance;
}


int LoadGLTextures(GLuint* texture, TCHAR* imageResourceId)
{
	HBITMAP hBitmap;
	BITMAP bmp;
	int iStatus = FALSE;
	glGenTextures(1, texture);
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceId, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hBitmap)
	{
		iStatus = TRUE;
		GetObject(hBitmap, sizeof(bmp), &bmp);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4); //pixel store mode in GPU memory (word alignment 4 bytes specified)
		glBindTexture(GL_TEXTURE_2D, *texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//generate mipmapped texture (3bytes, width, height & data from bmp)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
		DeleteObject(hBitmap);
	}

	return (iStatus);
}