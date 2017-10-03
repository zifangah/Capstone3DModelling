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

int main ( int argc, char *argv[] )
{
	if ( argc < 2 )
	{
		cout << "Required parameters: Filename" << endl;
		return EXIT_FAILURE;
	}

	//Read in the file
	std::string inputFilename1 = argv[1];

	vtkSmartPointer<vtkSTLReader> reader1 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(inputFilename1.c_str());
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

	//Declare the actor here, so it's in scope. If you don't, it causes errors.
	vtkSmartPointer<vtkActor> actor2 =
		vtkSmartPointer<vtkActor>::New();
	if (argc == 3) {
		//Read in the file
		std::string inputFilename2 = argv[2];

		vtkSmartPointer<vtkSTLReader> reader2 =
			vtkSmartPointer<vtkSTLReader>::New();
		reader2->SetFileName(inputFilename2.c_str());
		reader2->Update();

		// Create a mapper and actor
		vtkSmartPointer<vtkPolyDataMapper> mapper2 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
		mapper2->SetInputConnection(reader2->GetOutputPort());

		//Add the mapper to the actor
		actor2->SetMapper(mapper2);
	}



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
	if (argc == 3) {
		renderer->AddActor(actor2);
	}
	renderer->SetBackground(.0, 1.0, 1.0); // Background color 

	// Render an image (lights and cameras are created automatically)
	renderWindow->Render();

	//Set the window title, must be called after Render()
	renderWindow->SetWindowName("Window :D");

	//Change the control style. Isn't necessary for default bahavior.
	//vtkSmartPointer<vtkInteractorStyleTrackball> style =
	//	vtkSmartPointer<vtkInteractorStyleTrackball>::New();

	//renderWindowInteractor->SetInteractorStyle(style);

	// Begin mouse interaction
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}