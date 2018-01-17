// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

//Not sure what this is for, but it doesn't seem to break anything
#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <iostream>
<<<<<<< HEAD
<<<<<<< HEAD
//#include <windows.h>
#include <stdlib.h>
#include <string.h>
//#include <tchar.h>
=======
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
>>>>>>> master
#include <stddef.h>
#include <string>
#include "VTK.h"
#include "fileDialogue.h"



// Global variables
<<<<<<< HEAD
<<<<<<< HEAD

// The main window class name.
//static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
//static TCHAR szTitle[] = _T("Comparisoft");

//HINSTANCE hInst;
=======
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
>>>>>>> master

//declare the file path variables here so that they are global
char* filePathReference = NULL;
char* filePathProduction = NULL;

<<<<<<< HEAD
<<<<<<< HEAD
// Forward declarations of functions included in this code module:
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int main(int argc, char *argv[])

{
	filePathReference = argv[1];
	filePathProduction = argv[2];
	//filePathReferance = L"lowerModel.stl";
	//filePathProduction = L"upperModel.stl";
	VTKmain(filePathReference, filePathProduction);

	/*
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();*/

	/*
	//Set some variables usually set in WinMain
=======
/*
argc is the count of arguments passed to the program. 1 is the program name, so this number will be n+1, where n is the number of commands
we pass. argv is the arguments passed. 1 is the program name, the others are the ones that we pass, in the order passed.
*/
int main(int argc, char *argv[])

{
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b

=======
/*
argc is the count of arguments passed to the program. 1 is the program name, so this number will be n+1, where n is the number of commands
we pass. argv is the arguments passed. 1 is the program name, the others are the ones that we pass, in the order passed.
*/
int main(int argc, char *argv[])

{

>>>>>>> master
	//Writing points to logfile instead
	freopen("output.txt", "w", stdout);

	filePathReference = argv[1];
	filePathProduction = argv[2];

	//Hardcoded files for testing
	//filePathReferance = L"lowerModel.stl";
	//filePathProduction = L"upperModel.stl";

	//Launch the VTK function
	VTKmain(filePathReference, filePathProduction);

}
<<<<<<< HEAD
<<<<<<< HEAD

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//
//
/*
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
			TEXT("Woot!"),

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
			TEXT("Woot!"),

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
				//MessageBox(hWnd, L"Woot!", fileName1, MB_OK | MB_ICONINFORMATION);

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
}*/
=======
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
>>>>>>> master
