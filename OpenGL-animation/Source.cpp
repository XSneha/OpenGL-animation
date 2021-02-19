#include "Global.h"

//global declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declerations
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullScreen = false;
HWND ghwnd = NULL;
bool gdActiveWindow = false;
HGLRC ghrc = NULL;

//Display Function Declaration
void DisplayOpening(void);
void DisplayBirdS1(void);
void DisplayRobotS2(void); // walkig on street
void DisplayRobotS3(void);
void DisplayNatureS4(void);
void DisplayClosing(void);

//Update Function Declaration
void Update(void);
void UpdateOpening(void);
void UpdateBirdS1(void);
void UpdateRobotS2(void);
void UpdateRobotS3(void);
void UpdateNatureS4(void);
void UpdateClosing(void);

//Initalize Function Declaration
void InitializeOpening(void);
void InitializeBirdS1(void);
void InitalizeRobotS2(void);
void InitalizeRobotS3(void);
void InitalizeNatureS4(void);
void InitializeClosing(void);

int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function
	void Initialize(void);
	void ToggleFullScreen(void);
	void Display(void);

	//Variable decleration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("AnimatedStory");
	int screenX, screenY, screenCenterX, screenCenterY, windowCenterX, windowCenterY, windowXcoordinates, windowYcoordinates;
	bool pDone = false;


	//code
	if (fopen_s(&gpFile, "log.txt", "w") != 0) 
	{
		MessageBox(NULL, TEXT("Failed to create error log file...!!!"), TEXT("Error"), MB_ICONERROR | MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "file created\n");
	}

	ghInstance = hInstance;

	// initialize of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	fprintf(gpFile, "register");

	//centering code
	screenX = GetSystemMetrics(SM_CXSCREEN);

	screenCenterX = screenX / 2;

	screenY = GetSystemMetrics(SM_CYSCREEN);

	screenCenterY = screenY / 2;


	windowCenterX = WINWIDTH / 2;
	windowCenterY = WINHEIGHT / 2;

	windowXcoordinates = screenCenterX - windowCenterX;
	windowYcoordinates = screenCenterY - windowCenterY;

	hwnd = CreateWindow(szAppName, TEXT("Animated Story"), WS_OVERLAPPEDWINDOW, windowXcoordinates, windowYcoordinates, WINWIDTH, WINHEIGHT, NULL, NULL, hInstance, NULL);

	ghwnd = hwnd;
	Initialize();

	fprintf(gpFile, "create\n");
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//set screen to full-screen be default
	ToggleFullScreen();

	//game loop
	while (pDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				pDone = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gdActiveWindow == true)
			{
				//call display function for open GL renering
				Display();
				//call update function for open GL renering
				Update();
			}
		}
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//local function declaration
	void ToggleFullScreen();
	void Resize(int, int);
	void Unitialize();

	//code
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gdActiveWindow = true;
		break;

	case WM_KILLFOCUS:
		gdActiveWindow = false;
		break;

	case WM_ERASEBKGND:
		return 0;

	case WM_SIZE:
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		case 0X46:	//F
		case 0X66:	//f
			ToggleFullScreen();
			break;
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		Unitialize();
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen()
{
	//variable declerations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	//code
	if (gbFullScreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, (dwStyle & ~WS_OVERLAPPEDWINDOW));
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_FRAMECHANGED | SWP_NOZORDER);
			}
		}
		ShowCursor(FALSE);
		gbFullScreen = true;
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, (dwStyle | WS_OVERLAPPEDWINDOW));
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_NOZORDER | SWP_NOSIZE);
		ShowCursor(true);
		gbFullScreen = false;
	}
}

void Initialize()
{
	//function declaration
	void Resize(int, int);
	bool LoadGLTexture(GLuint *, TCHAR []);
	void InitalizeProject(void);

	//variables
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	//code
	ghdc = GetDC(ghwnd);
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	//PIXELFORMATEDDESCRIPTOR initialization

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;

	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);

	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "error in ChoosePixelFormat");
		DestroyWindow(ghwnd);
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "error in SetPixelFormat");
		DestroyWindow(ghwnd);
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "error in wglCreateContext");
		DestroyWindow(ghwnd);
	}

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "error in wglMakeCurrent");
		DestroyWindow(ghwnd);
	}

	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//DepthCode
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Font Initalize
	HFONT hFont;
	LOGFONT logfont;
	logfont.lfHeight = -30;
	logfont.lfWidth = 0;
	logfont.lfEscapement = 0;
	logfont.lfOrientation = 0;
	logfont.lfWeight = FW_BOLD;
	logfont.lfItalic = FALSE;
	logfont.lfUnderline = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = ANSI_CHARSET;
	logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logfont.lfQuality = DEFAULT_QUALITY;
	logfont.lfPitchAndFamily = DEFAULT_PITCH;
	// Create the font and display list
	hFont = CreateFontIndirect(&logfont);
	SelectObject(ghdc, hFont);
	nFontList = glGenLists(128);
	wglUseFontBitmaps(ghdc, 0, 128, nFontList);
	DeleteObject(hFont);

	LoadTrack(TEXT("Resources/Sound/Stillness_Of_The_Lake.wav"), (SND_ASYNC | SND_FILENAME));
	//Project Initalize
	InitalizeProject();

	Resize(WINWIDTH, WINHEIGHT);//warmUp
}


void InitalizeProject(void)
{
	//initializing all scenes
	InitializeOpening();
	InitializeBirdS1();
	InitalizeRobotS2();
	InitalizeRobotS3();
	InitalizeNatureS4();
	InitializeClosing();
}


void Resize(int width, int height)
{
	//Local Variables
	GLfloat fovy = 45.0f;
	GLfloat fAspectRatio = (GLfloat)width / (GLfloat)height;
	GLfloat fNear = 0.1f;
	GLfloat fFar = 100.0f;
	gWinWidth = width;
	gWinHeight = height;
	
	//Code
	if (height == 0)
		height = 1;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy,
		fAspectRatio,
		fNear,
		fFar);

	//Set Window co-ordinates
	fWindowTop = (GLfloat)tan(fovy / 2) * fZAxisPosition;
	fWindowBottom = -fWindowTop;
	fWindowRight = fWindowTop * fAspectRatio;
	fWindowLeft = -fWindowRight;
}

void Update(void)
{
	if (gbRenderScene_01)
	{
		UpdateOpening();
	}
	else if (gbRenderScene_02)
	{
		UpdateBirdS1();
	}
	else if (gbRenderScene_03)
	{
		UpdateRobotS2();
	}
	else if (gbRenderScene_04)
	{
		UpdateRobotS3();
	}
	else if (gbRenderScene_05)
	{
		UpdateNatureS4();
	}

	else if (gbRenderScene_06)
	{
		UpdateClosing();
	}
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gbRenderScene_01)
	{
		DisplayOpening();
	}
	else if (gbRenderScene_02)
	{
		DisplayBirdS1();
	}
	else if (gbRenderScene_03)
	{
		DisplayRobotS2();
	}
	else if (gbRenderScene_04)
	{
		DisplayRobotS3();
	}
	else if (gbRenderScene_05)
	{
		DisplayNatureS4();
	}

	else if (gbRenderScene_06)
	{
		DisplayClosing();
	}
	
	SwapBuffers(ghdc);
}

void Unitialize()
{

	//code
	if (gbFullScreen == true)
	{
		SetWindowLong(ghwnd, GWL_STYLE, (dwStyle | WS_OVERLAPPEDWINDOW));
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_NOZORDER | SWP_NOSIZE);
		ShowCursor(true);
	}

	glDeleteTextures(1, &ground_texture);
	glDeleteTextures(1, &bg_texture);
	glDeleteTextures(1, &robot_body);
	glDeleteTextures(1, &robot_face);
	glDeleteTextures(1, &robot_texture);
	glDeleteTextures(1, &robot_texture_dark);

	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (gpFile)
	{
		fprintf(gpFile, "closed");
		fclose(gpFile);
		gpFile = NULL;
	}
}
