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
	if ( argc != 2 )
	{
		cout << "Required parameters: Filename" << endl;
		return EXIT_FAILURE;
	}

	std::string inputFilename = argv[1];

	vtkSmartPointer<vtkSTLReader> reader =
			vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(inputFilename.c_str());
	reader->Update();

	// Visualize

	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
			vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

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
	renderer->AddActor(actor);
	renderer->SetBackground(.0, 1.0, 1.0); // Background color 

	// Render an image (lights and cameras are created automatically)
	renderWindow->Render();

	//Set the window title, must be called after Render()
	renderWindow->SetWindowName("Window :D");

	//Change the default control style
	//vtkSmartPointer<vtkInteractorStyleTrackball> style =
	//	vtkSmartPointer<vtkInteractorStyleTrackball>::New();

	//renderWindowInteractor->SetInteractorStyle(style);

	// Begin mouse interaction
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}