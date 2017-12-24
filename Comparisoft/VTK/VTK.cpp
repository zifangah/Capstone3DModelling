//#include <shobjidl.h>
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
#include "VTK.h"
#include "PointSelection.h"
#include <cstdio>

//VTK code goes here. It is now a function, and is called with the file paths.
int VTKmain(char* filePathReference, char* filePathProduction)
{
	

	if (filePathReference == NULL || filePathProduction == NULL) {
		printf("Please select both files first.\n");
		return 0;
	}

	//Read in the file

	vtkSmartPointer<vtkSTLReader> reader1 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(filePathReference);
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

	//Read in the file
	vtkSmartPointer<vtkSTLReader> reader2 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(filePathProduction);
	reader2->Update();


	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());

	//Add the mapper to the actor
	vtkSmartPointer<vtkActor> actor2 =
		vtkSmartPointer<vtkActor>::New();
	actor2->SetMapper(mapper2);

	//Initialize point selector
	vtkSmartPointer<vtkPointPicker> PointSelector =
			vtkSmartPointer<vtkPointPicker>::New();

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
	renderWindowInteractor->SetPicker(PointSelector); // Attach the point selector to the window

	// Set point selection style to that defined in PointSelection.h
	vtkSmartPointer<PointSelection> style =
			vtkSmartPointer<PointSelection>::New();
	renderWindowInteractor->SetInteractorStyle(style);

	// Add the actors to the scene
	renderer->AddActor(actor1);
	renderer->AddActor(actor2);

	renderer->SetBackground(.0, 1.0, 1.0); // Background color


										   // Render an image (lights and cameras are created automatically)
	renderWindow->Render();

	//Set the window title, must be called after Render()
	renderWindow->SetWindowName("Comparisoft");

	// Create a text widget
	
	/*vtkSmartPointer<vtkTextActor> textActor =
		vtkSmartPointer<vtkTextActor>::New();
	textActor->SetInput("Placeholder");
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
	textWidget->SelectableOff();*/
	

	renderWindowInteractor->Initialize();
	renderWindow->Render();
	//textWidget->On();
	//renderWindow->Render();

	// Begin mouse interaction
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}