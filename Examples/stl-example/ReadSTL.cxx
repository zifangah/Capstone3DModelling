// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <iostream>
#include <windows.h> 
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 
#include <shobjidl.h>
#include <stddef.h>
#include <string>
#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleSwitch.h>
#include <vtkInteractorStyleTrackball.h>
#include <vtkTextWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkTextRepresentation.h>
#include <vtkCoordinate.h>
#include <vtkCommand.h>


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
LPWSTR fileDialogue();
//int VTKmain(LPWSTR, LPWSTR);
int VTKmain();
//std::string utf8_encode(const std::wstring);

//old winmain initialization
/*
int WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)*/


int main()
{
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
}

//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
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

	//the file path returned from the common dialogue box, this is declared globally with the global variables
	//LPWSTR filePathReferance = NULL;

	//the name and extension after the filepath is split
	wchar_t fileNameReferance[_MAX_FNAME];
	wchar_t fileExtensionReferance[_MAX_EXT];

	//the combined name and extension goes here. convert to LPCWSTR using .c_str()
	std::wstring fileReferance = L"temp";

	//production file values
	//LPWSTR filePathProduction = NULL;
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
			filePathReferance = fileDialogue();

			//if the user cancelled, it will still be null
			if (filePathReferance != NULL) {

				//split the filepath into drive, derectory path, file name, and extension. we don't need drive or derectory here
				_wsplitpath_s(filePathReferance, NULL, 0, NULL, 0, fileNameReferance, _MAX_FNAME, fileExtensionReferance, _MAX_EXT);

				//convert the name and extension so thet they can be concatenated
				fileReferance = std::wstring(fileNameReferance);
				fileReferance += std::wstring(fileExtensionReferance);

				//test value, ignore this
				//MessageBox(hWnd, L"Woot! *.*/", fileName1, MB_OK | MB_ICONINFORMATION);

				//convert back so it can be printed(yes, really, this is how this works)
				//if this line causes errors, go to Project, ReadSTL Properties, Configuration, Project Defaults, and set character set to Unicode
				SetDlgItemText(hWnd, 3, fileReferance.c_str());
			}
		}

		//if production button(2) is pressed
		if (LOWORD(wParam) == 2) {
			hdc = BeginPaint(hWnd, &ps);
			filePathProduction = fileDialogue();
			if (filePathProduction != NULL) {
				_wsplitpath_s(filePathProduction, NULL, 0, NULL, 0, fileNameProduction, _MAX_FNAME, fileExtensionProduction, _MAX_EXT);
				fileProduction = std::wstring(fileNameProduction);
				fileProduction += std::wstring(fileExtensionProduction);
				//MessageBox(hWnd, L"Woot! *.*/", fileName1, MB_OK | MB_ICONINFORMATION);
				SetDlgItemText(hWnd, 4, fileProduction.c_str());
			}
		}

		//if the VTK button is pressed
		if (LOWORD(wParam) == 5) {
			//VTKmain(filePathReferance, filePathProduction);
			VTKmain();
		}

		break;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		/*TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
			*/


		// End application-specific layout section.  

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

LPWSTR fileDialogue()
{

	LPWSTR pszFilePath = NULL;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog *pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem *pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						//MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	return pszFilePath;

}

// Convert a wide Unicode string to an UTF8 string
std::string utf8_encode(const std::wstring &wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}






//VTK code is here

//launch the program from the command line
//int main ( int argc, char *argv[] )
//{
//	if ( argc < 2 )
//	{
//		cout << "Required parameters: Filename" << endl;
//		return EXIT_FAILURE;
//	}

//VTK code goes here. It is now a function, and is called with the file paths.
//int VTKmain (LPWSTR referenceFile, LPWSTR productionFile)
int VTKmain()
{
	
	if (filePathReferance==NULL || filePathProduction==NULL) {
		MessageBox(NULL, L"Please select both files first.", L"File Path", MB_OK);
		return 0;
	}

	//MessageBox(NULL, filePathReferance, L"File Path", MB_OK);

	//Read in the file
	//std::string inputFilename1 = argv[1];

	//std::string inputFilename1 = "lower Model.stl";

	vtkSmartPointer<vtkSTLReader> reader1 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(utf8_encode(filePathReferance).c_str());
	//reader1->SetFileName(inputFilename1.c_str());
	reader1->Update();

	// Visualize


	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());

	//Add the mapper to the actor
	vtkSmartPointer<vtkActor> actor1 =
			vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	//A second stl file

	//Declare the actor here, so it's in scope. If you don't, it causes errors. *this can be ignored now*
	vtkSmartPointer<vtkActor> actor2 =
		vtkSmartPointer<vtkActor>::New();

	//Read in the file
	//std::string inputFilename2 = argv[2];

	//std::string inputFilename2 = "upperModel.stl";

	vtkSmartPointer<vtkSTLReader> reader2 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(utf8_encode(filePathProduction).c_str());
	//reader2->SetFileName(inputFilename2.c_str());
	reader2->Update();


	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());

	//Add the mapper to the actor
	actor2->SetMapper(mapper2);



	//Create renderer and render window, add the renderer to the window
	vtkSmartPointer<vtkRenderer> renderer =
			vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	

	// Create an interactor, and attatch it to a renderwindow
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	renderWindowInteractor->SetRenderWindow(renderWindow);

	// Add the actors to the scene
	renderer->AddActor(actor1);
	renderer->AddActor(actor2);
	
	renderer->SetBackground(.0, 1.0, 1.0); // Background color 


	// Render an image (lights and cameras are created automatically)
	renderWindow->Render();

	//Set the window title, must be called after Render()
	renderWindow->SetWindowName("I'm a window! :D");

	// Create a text widget
	vtkSmartPointer<vtkTextActor> textActor =
		vtkSmartPointer<vtkTextActor>::New();
	textActor->SetInput(utf8_encode(filePathReferance).c_str());
	textActor->GetTextProperty()->SetColor(0.0, 1.0, 0.0);

	vtkSmartPointer<vtkTextWidget> textWidget =
		vtkSmartPointer<vtkTextWidget>::New();

	vtkSmartPointer<vtkTextRepresentation> textRepresentation =
		vtkSmartPointer<vtkTextRepresentation>::New();
	textRepresentation->GetPositionCoordinate()->SetValue(.15, .15);
	textRepresentation->GetPosition2Coordinate()->SetValue(.7, .2);
	textWidget->SetRepresentation(textRepresentation);

	textWidget->SetInteractor(renderWindowInteractor);
	textWidget->SetTextActor(textActor);
	textWidget->SelectableOff();

	//Change the control style. Isn't necessary for default bahavior.
	//vtkSmartPointer<vtkInteractorStyleTrackball> style =
	//	vtkSmartPointer<vtkInteractorStyleTrackball>::New();

	//renderWindowInteractor->SetInteractorStyle(style);

	//Hide the console window. Must be before renderWindowInteractor->Start() in order to work.
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	renderWindowInteractor->Initialize();
	renderWindow->Render();
	//textWidget->On();
	//renderWindow->Render();

	// Begin mouse interaction
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}