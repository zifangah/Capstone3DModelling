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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

// Convert a wide Unicode string to an UTF8 string
//std::string utf8_encode(const std::wstring &wstr)
//{
//	if (wstr.empty()) return std::string();
//	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
//	std::string strTo(size_needed, 0);
//	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
//	return strTo;
//}

//VTK code is here
=======
=======

>>>>>>> HighlightSelectedPoints
#include <cstdio>
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
#include <cstdio>
>>>>>>> master

//VTK code goes here. It is now a function, and is called with the file paths.
int VTKmain(char* filePathReference, char* filePathProduction)
{
	

	if (filePathReference == NULL || filePathProduction == NULL) {
		printf("Please select both files first.\n");
		return 0;
	}

	//File 1
	vtkSmartPointer<vtkSTLReader> reader1 =
		vtkSmartPointer<vtkSTLReader>::New();
<<<<<<< HEAD
<<<<<<< HEAD
	//reader1->SetFileName(utf8_encode(filePathReferance).c_str());
=======
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
>>>>>>> master
	reader1->SetFileName(filePathReference);
	reader1->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());

	vtkSmartPointer<vtkActor> actor1 =
		vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	vtkSmartPointer<vtkSTLReader> reader2 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(filePathProduction);
	reader2->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());

	vtkSmartPointer<vtkActor> actor2 =
		vtkSmartPointer<vtkActor>::New();
	actor2->SetMapper(mapper2);

	//Initialize point selector
	vtkSmartPointer<vtkPointPicker> PointSelector =
			vtkSmartPointer<vtkPointPicker>::New();

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
	//Create renderer and render window, add the renderer to the window
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
=======
	
	/* Create one render window and one interactor for all 3 panes */
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
	
	/* Create one render window and one interactor for all 3 panes */
>>>>>>> origin/Production
	vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->SetSize(800, 800);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();
	
	renderWindowInteractor->SetRenderWindow(renderWindow);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
	renderWindowInteractor->SetPicker(PointSelector); // Attach the point selector to the window

	// Set point selection style to that defined in PointSelection.h
=======
	renderWindowInteractor->SetPicker(PointSelector);
	
<<<<<<< HEAD
	//Set point selection style to that defined in PointSelection.h
>>>>>>> origin/Production
=======
	//8Set point selection style to that defined in PointSelection.h
>>>>>>> HighlightSelectedPoints
	vtkSmartPointer<PointSelection> style =
			vtkSmartPointer<PointSelection>::New();
	renderWindowInteractor->SetInteractorStyle(style);


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

<<<<<<< HEAD
	renderWindowInteractor->Initialize();
=======
	renderWindowInteractor->SetPicker(PointSelector);
	
	//Set point selection style to that defined in PointSelection.h
	vtkSmartPointer<PointSelection> style =
			vtkSmartPointer<PointSelection>::New();
	renderWindowInteractor->SetInteractorStyle(style);


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

=======
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

>>>>>>> origin/Production
	/* Set-up combined Comparison Pane */
	renderer3->AddActor(actor1);
	renderer3->AddActor(actor2);
	renderer3->SetBackground(.5, .7, .8);
	renderer3->SetViewport(comparison_pane);
	renderer3->ResetCamera();

<<<<<<< HEAD
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
>>>>>>> origin/Production
	renderWindow->Render();
	renderWindow->SetWindowName("Comparisoft");
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}