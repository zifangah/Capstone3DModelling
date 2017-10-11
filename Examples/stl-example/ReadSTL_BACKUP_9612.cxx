#include <iostream>
#include <windows.h>
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

//int main ( int argc, char *argv[] )
//{
//	if ( argc < 2 )
//	{
//		cout << "Required parameters: Filename" << endl;
//		return EXIT_FAILURE;
//	}
int main (int, char *[])
{
<<<<<<< HEAD
	/*
	OPENFILENAME ofn;       // common dialog box structure
	char szFile[260];       // buffer for file name
	HWND hwnd;              // owner window
	HANDLE hf;              // file handle

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;

	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE) {
		cout << ofn.lpstrFile;
=======
	if ( argc != 3 )
	{
		cout << "Required parameters: Filename x 2" << endl;
		return EXIT_FAILURE;
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13
	}
	Sleep(10000);
	*/

<<<<<<< HEAD


	//Read in the file
	//std::string inputFilename1 = argv[1];
	cout << "Reading file 1\n";
	std::string inputFilename1 = "lowerModel.stl";

=======
	std::string inputFilename1 = argv[1];
	std::string inputFilename2 = argv[2];

	/* Set-up file 1 */
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13
	vtkSmartPointer<vtkSTLReader> reader1 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(inputFilename1.c_str());
	reader1->Update();

<<<<<<< HEAD
	// Visualize

	cout << "Mapping file 1\n";
	// Create a mapper and actor
=======
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13
	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());

<<<<<<< HEAD
	//Add the mapper to the actor
	vtkSmartPointer<vtkActor> actor1 =
			vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	//A second stl file

	//Declare the actor here, so it's in scope. If you don't, it causes errors.
	vtkSmartPointer<vtkActor> actor2 =
		vtkSmartPointer<vtkActor>::New();
	//if (argc == 3) {
	if (3 == 3) {
		//Read in the file
		//std::string inputFilename2 = argv[2];
		cout << "Reading file 2\n";
		std::string inputFilename2 = "upperModel.stl";

		vtkSmartPointer<vtkSTLReader> reader2 =
			vtkSmartPointer<vtkSTLReader>::New();
		reader2->SetFileName(inputFilename2.c_str());
		reader2->Update();

		cout << "Mapping file 2\n";
		// Create a mapper and actor
		vtkSmartPointer<vtkPolyDataMapper> mapper2 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
		mapper2->SetInputConnection(reader2->GetOutputPort());

		//Add the mapper to the actor
		actor2->SetMapper(mapper2);
	}


	cout << "Creating render window\n";
	//Create renderer and render window, add the renderer to the window
	vtkSmartPointer<vtkRenderer> renderer =
			vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	
	cout << "Creating interactor\n";
	// Create an interactor, and attatch it to a renderwindow
=======
	vtkSmartPointer<vtkActor> actor1 =
			vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	/* Set-up file 2 */
	vtkSmartPointer<vtkSTLReader> reader2 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(inputFilename2.c_str());
	reader2->Update();

	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());

	vtkSmartPointer<vtkActor> actor2 =
			vtkSmartPointer<vtkActor>::New();
	actor2->SetMapper(mapper2);

	/* Create one render window and one interactor for all 3 panes */
	vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->SetSize(800, 800);
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	renderWindowInteractor->SetRenderWindow(renderWindow);

<<<<<<< HEAD
	// Add the actors to the scene
	renderer->AddActor(actor1);
	//if (argc == 3) {
	if (3 == 3) {
		renderer->AddActor(actor2);
	}
	renderer->SetBackground(.0, 1.0, 1.0); // Background color 
=======
	/* Define viewport ranges */
	double reference_pane[4] = {0, 0.5, 0.5, 1};
	double production_pane[4] = {0.5, 0.5, 1, 1};
	double comparison_pane[4] = {0, 0, 1, 0.5};

	vtkSmartPointer<vtkRenderer> renderer1 =
			vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderer> renderer2 =
			vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderer> renderer3 =
			vtkSmartPointer<vtkRenderer>::New();

	renderWindow->AddRenderer(renderer1);
	renderWindow->AddRenderer(renderer2);
	renderWindow->AddRenderer(renderer3);

	/* Set-up Reference Pane */
	renderer1->AddActor(actor1);
	renderer1->SetBackground(.5, .5, .6);
	renderer1->SetViewport(reference_pane);
	renderer1->ResetCamera();

	/* Set-up Production Pane */
	renderer2->AddActor(actor2);
	renderer2->SetBackground(.5, .6, .5);
	renderer2->SetViewport(production_pane);
	renderer2->ResetCamera();

	/* Set-up combined Comparison Pane */
	renderer3->AddActor(actor1);
	renderer3->AddActor(actor2);
	renderer3->SetBackground(.5, .7, .8);
	renderer3->SetViewport(comparison_pane);
	renderer3->ResetCamera();
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13

	cout << "Rendering scene\n";
	// Render an image (lights and cameras are created automatically)
	renderWindow->Render();
<<<<<<< HEAD

	//Set the window title, must be called after Render()
	renderWindow->SetWindowName("I'm a window! :D");

	//Change the control style. Isn't necessary for default bahavior.
	//vtkSmartPointer<vtkInteractorStyleTrackball> style =
	//	vtkSmartPointer<vtkInteractorStyleTrackball>::New();

	//renderWindowInteractor->SetInteractorStyle(style);

	//Hide the console window. Must be before renderWindowInteractor->Start() in order to work.
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	// Begin mouse interaction
=======
	renderWindow->SetWindowName("Comparisoft");
>>>>>>> f70ee5ba795dc0e078b12e98fd1b24c890715a13
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}