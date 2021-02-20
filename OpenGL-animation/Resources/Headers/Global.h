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

//Import Libraries
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment(lib,"openGL32.lib")
#pragma comment(lib,"glu32.lib")
// #pragma warning(disable : 4996)

//Macro
#define WINWIDTH 800
#define WINHEIGHT 600
#define PI 3.144444


//Symbolic Constonts
#define TRUE 	1	//True is 1
#define FALSE	0	//False is 0

#define BUFFER_SIZE		256		//Maximum length of string in mesh file
#define S_EQUAL			0		//Return value of strcmp when strings are equal

#define NR_POINT_COORDS		3		//Number of point coordinates
#define NR_TEXTURE_COORDS	2		//Number of texture coordinates
#define NR_NORMAL_COORDS	3		//Number of Normal coordinates
#define NR_FACE_TOKENS		3		//Number of entries in face data
#define NR_TRIANGLE_VERTICES 3		//Number of vertices in triangle

#define MODEL_X_TRANSLATE	0.0f	//X translation of MOdel
#define MODEL_Y_TRANSLATE	0.0f	//Y translation of Model
#define MODEL_Z_TRANSLATE	-6.0f	//Z translation of MOdel

#define MODEL_X_SCALE_FACTOR	0.2f	//X scale factor of Model
#define MODEL_Y_SCALE_FACTOR	0.2f	//Y scale factor of Model
#define MODEL_Z_SCALE_FACTOR	0.2f	//Z scale factor of Model

#define START_ENGLE_POS			0.0f		//Marks beginning angle positionof rotation
#define END_ENGLE_POS			360.0f		//Marks terminating angle position rotation
#define MODEL_ANGLE_INCREMENT	0.01f		//Increment angle for Model

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

//Handle to a mesh file
extern FILE* g_fp_meshfile;

/*Scene render seqence variable*/
extern bool gbRenderScene_01;
extern bool gbRenderScene_02;
extern bool gbRenderScene_03;
extern bool gbRenderScene_04;
extern bool gbRenderScene_05;
extern bool gbRenderScene_06;

//quadric 
extern GLUquadric* quadric;

/*Camera Variables*/
// Adjust the multiplier to adjust the animation speed for objects
extern const GLfloat Camera_fDeltaMultiplier;

// Camera
extern const GLfloat Camera_fZZoomEnd;
extern const GLfloat Camera_fZZoomStart;
extern const GLfloat Camera_fDeltaEyeAngle;
extern const GLfloat Camera_fZoomInDistance;
extern const GLfloat Camera_fZZoomOutStop;

extern GLfloat Camera_fEye[3];
extern GLfloat Camera_fCenter[3];
extern GLfloat Camera_fUpVector[3];

/*Camera status variables*/
// Animation status variables
extern bool Camera_bDoneCameraZoomIn;
extern bool Camera_bDoneCameraRotate;
extern bool Camera_bDoneCameraZoomOut;
extern bool Camera_bDoneSceneRotation;


struct Color
{
	GLfloat red;
	GLfloat green;
	GLfloat blue;
};

typedef struct Color COLOR;

//uninitialize 
void Unitialize();

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
extern GLuint sky_texture;

//model loading variales / functions

typedef	struct vec_2d_int
{
	GLint** pp_arr;
	size_t size;
}vec_2d_int_t;

typedef struct vec_2d_flaot
{
	GLfloat** pp_arr;
	size_t size;
}vec_2d_float_t;

extern GLfloat g_model_rotate;

//vector of vector of floats to hold vertex data
extern vec_2d_float_t* gp_vertices;

//vector of vector of floats to hold texture data
extern vec_2d_float_t* gp_texture;

//vector of vector of floats to hold normal data
extern vec_2d_float_t* gp_normals;

//vector of vector of int to hold index data int g_vertices
extern vec_2d_int_t* gp_face_tri, * gp_face_texture, * gp_face_normals;

vec_2d_int_t* create_vec_2d_int(void);
vec_2d_float_t* create_vec_2d_float(void);
void push_back_vec_2d_int(vec_2d_int_t* p_vec, int* p_arr);
void push_back_vec_2d_float(vec_2d_float_t* p_vec, float* p_arr);
void clean_vec_2d_int(vec_2d_int_t** pp_vec);
void clean_vec_2d_float(vec_2d_float_t** pp_vec);

void LoadMeshData(const char* fileName);

