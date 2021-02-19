#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include "resource.h"

#pragma comment(lib,"openGL32.lib")
#pragma comment(lib,"glu32.lib")

//Macro
#define WINWIDTH 800
#define WINHEIGHT 600
#define PI 3.144444

/*Windowing variables*/
extern FILE* gpFile;
extern GLuint gWinWidth;
extern GLuint gWinHeight;
extern GLfloat fWindowLeft;
extern GLfloat fWindowRight;
extern GLfloat fWindowTop;
extern GLfloat fWindowBottom;
extern GLfloat fZAxisPosition;
extern GLuint nFontList;
extern HDC ghdc;
extern HINSTANCE ghInstance;

/*Scene render seqence variable*/
extern bool gbRenderScene_01;
extern bool gbRenderScene_02;
extern bool gbRenderScene_03;
extern bool gbRenderScene_04;
extern bool gbRenderScene_05;
extern bool gbRenderScene_06;


/*Camera Variables*/
// Adjust the multiplier to adjust the animation speed for objects
extern const GLfloat Camera_fDeltaMultiplier;

// Camera
extern const GLfloat Camera_fZZoomEnd ;
extern const GLfloat Camera_fZZoomStart;
extern const GLfloat Camera_fDeltaEyeAngle;
extern const GLfloat Camera_fZoomInDistance;

extern GLfloat Camera_fEye[3];
extern GLfloat Camera_fCenter[3];
extern GLfloat Camera_fUpVector[3];

/*Camera status variables*/
// Animation status variables
extern bool Camera_bDoneCameraZoomIn;
extern bool Camera_bDoneCameraRotate;
extern bool Camera_bDoneCameraZoomOut;
extern bool Camera_bDoneSceneRotation;


extern struct Color
{
	GLfloat red;
	GLfloat green;
	GLfloat blue;
};

typedef struct Color COLOR;

//Global Functions
int LoadGLTextures(GLuint* texture, TCHAR* imageResourceId);
void LoadTrack(LPCTSTR, DWORD);
//globalCamera functions
void ZoomInCamera(void);
void SpinCamera(void);
//void AnimateScene(void);
void RotateCamera(void);
void ZoomOutCamera(void);


//global variables for robot and background testures
extern GLuint bg_texture;
extern GLuint ground_texture;
extern GLuint robot_texture;
extern GLuint robot_texture_dark;
extern GLuint robot_body;
extern GLuint robot_face;
