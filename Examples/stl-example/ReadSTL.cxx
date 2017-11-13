// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <iostream>
#include <windows.h>
#include <stdlib.h>  
#include <string.h> 
#include <tchar.h> 
#include <stddef.h>
#include <string>
#include "VTK.h"
#include "fileDialogue.h"
#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"


// Global variables  

// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Comparisoft");

HINSTANCE hInst;

//declare the file path variables here so that they are global
LPWSTR filePathReferance = NULL;
LPWSTR filePathProduction = NULL;

// Forward declarations of functions included in this code module:  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int main(int argc, char *argv[])

{
	
	
	/*
	//Set some variables usually set in WinMain

	 HINSTANCE hInstance = GetModuleHandle(NULL);

	//how to initialize the window
	int nCmdShow = SW_SHOW;

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

					   // The parameters to CreateWindow explained:  
					   // szWindowClass: the name of the application  
					   // szTitle: the text that appears in the title bar  
					   // WS_OVERLAPPEDWINDOW: the type of window to create  
					   // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
					   // 500, 100: initial size (width, length)  
					   // NULL: the parent of this window  
					   // NULL: this application does not have a menu bar  
					   // hInstance: the first parameter from WinMain  
					   // NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 500,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
	*/}

//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  
//  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//initialize varibles here. Initializing them in the switch statement causes compile errors.
	PAINTSTRUCT ps;
	HDC hdc;

	//test value, ignore this
	LPWSTR greeting = L"Hello, World!";

	//referance file values

	//create a temporary value to store the result of the open file dialogue
	LPWSTR reftmp = NULL;

	//the name and extension after the filepath is split
	wchar_t fileNameReferance[_MAX_FNAME];
	wchar_t fileExtensionReferance[_MAX_EXT];

	//the combined name and extension goes here. 
	std::wstring fileReferance = L"temp";

	//production file values
	LPWSTR prdtmp = NULL;
	wchar_t fileNameProduction[_MAX_FNAME];
	wchar_t fileExtensionProduction[_MAX_EXT];
	std::wstring fileProduction = L"temp";

	//text windows. The buttons don't need this because they will never be referenced
	HWND textReferance = NULL;
	HWND textProduction = NULL;

	switch (message)
	{
	case WM_CREATE:
	{

		//1: Reference button, 2: production button, 3: Reference text box, 4: Production text box, 5: VTK button

		//create button for referance file
		CreateWindow(

			//thing to create
			TEXT("button"),

			//text in the button
			TEXT("Select Referance File"),

			//Styles
			WS_VISIBLE | WS_CHILD,

			//x, y, width, height
			20, 20, 200, 25,

			//parent window
			hWnd,

			//unique identifier
			(HMENU)1,

			NULL, NULL
		);

		//create button for production file
		CreateWindow(

			//thing to create
			TEXT("button"),

			//text in the button
			TEXT("Select Production File"),

			//Styles
			WS_VISIBLE | WS_CHILD,

			//x, y, width, height
			20, 80, 200, 25,

			//parent window
			hWnd,

			//unique identifier
			(HMENU)2,

			NULL, NULL
		);

		//create textbox for referance file
		textReferance = CreateWindow(

			//thing to create
			TEXT("static"),

			//text in the textbox
			TEXT("Woot! *.*/"),

			//Styles
			WS_VISIBLE | WS_CHILD,

			//x, y, width, height
			250, 20, 350, 25,

			//parent window
			hWnd,

			//unique identifier
			(HMENU)3,

			NULL, NULL
		);

		//create textbox for production file
		textReferance = CreateWindow(

			//thing to create
			TEXT("static"),

			//text in the textbox
			TEXT("Woot! *.*/"),

			//Styles
			WS_VISIBLE | WS_CHILD,

			//x, y, width, height
			250, 80, 350, 25,

			//parent window
			hWnd,

			//unique identifier
			(HMENU)4,

			NULL, NULL
		);

		//create button for running VTK
		CreateWindow(

			//thing to create
			TEXT("button"),

			//text in the button
			TEXT("Open VTK Window"),

			//Styles
			WS_VISIBLE | WS_CHILD,

			//x, y, width, height
			20, 140, 200, 25,

			//parent window
			hWnd,

			//unique identifier
			(HMENU)5,

			NULL, NULL
		);

		break;
	}

	case WM_COMMAND:

	{
		//if refrance button(1) is pressed
		if (LOWORD(wParam) == 1) {
			hdc = BeginPaint(hWnd, &ps);

			//open the common dialogue box, it returns a string
			reftmp = fileDialogue();

			if (reftmp != NULL) {
				filePathReferance = reftmp;
			}

			//if the user cancelled, it will still be null
			if (filePathReferance != NULL) {

				//split the filepath into drive, derectory path, file name, and extension. we don't need drive or derectory here
				_wsplitpath_s(filePathReferance, NULL, 0, NULL, 0, fileNameReferance, _MAX_FNAME, fileExtensionReferance, _MAX_EXT);

				//convert the name and extension so thet they can be concatenated
				fileReferance = std::wstring(fileNameReferance);
				fileReferance += std::wstring(fileExtensionReferance);

				//test value, ignore this
				//MessageBox(hWnd, L"Woot! *.*/", fileName1, MB_OK | MB_ICONINFORMATION);

				//change it from a wstring to a string, convert back so it can be printed(yes, really, this is how this works)
				//if this line causes errors, go to Project, ReadSTL Properties, Configuration, Project Defaults, and set character set to Unicode
				SetDlgItemText(hWnd, 3, utf8_encode(fileReferance).c_str());
			}
		}

		//if production button(2) is pressed
		if (LOWORD(wParam) == 2) {
			hdc = BeginPaint(hWnd, &ps);
			prdtmp = fileDialogue();
			if (prdtmp != NULL) {
				filePathProduction = prdtmp;
			}
			if (filePathProduction != NULL) {
				_wsplitpath_s(filePathProduction, NULL, 0, NULL, 0, fileNameProduction, _MAX_FNAME, fileExtensionProduction, _MAX_EXT);
				fileProduction = std::wstring(fileNameProduction);
				fileProduction += std::wstring(fileExtensionProduction);
				SetDlgItemText(hWnd, 4, utf8_encode(fileProduction).c_str());
			}
		}

		//if the VTK button is pressed
		if (LOWORD(wParam) == 5) {
			VTKmain(filePathReferance, filePathProduction);
		}

		break;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);  
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	}

	return 0;
}
