#include "Align.h"
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkProperty.h>
#include <vtkLandmarkTransform.h>
#include <vtkMatrix4x4.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkSTLReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>


// Constructors
Align::Align() {
	vtkSmartPointer<vtkPoints> sourcePoints =
		vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkPoints> targetPoints =
		vtkSmartPointer<vtkPoints>::New();
};

// Methods
// Gets passed a pointer to the two actors, from which we can get the source objects
void Align::AlignModels() {
	//Hardcoded files for testing
	char* filePathReference = NULL;
	char* filePathProduction = NULL;
	filePathReference = "lowerModel.stl";
	filePathProduction = "upperModel.stl";
	vtkSmartPointer<vtkSTLReader> reader1 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(filePathReference);
	reader1->Update();

	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());

	//Add the mapper to the actor
	vtkSmartPointer<vtkActor> actor1 =
		vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	// Setup the transform
	vtkSmartPointer<vtkLandmarkTransform> landmarkTransform =
		vtkSmartPointer<vtkLandmarkTransform>::New();
	landmarkTransform->SetSourceLandmarks(sourcePoints);
	landmarkTransform->SetTargetLandmarks(targetPoints);
	//We only want rotation and translation so set to RigidBody
	landmarkTransform->SetModeToRigidBody();
	landmarkTransform->Update();

	vtkSmartPointer<vtkPolyData> source =
		vtkSmartPointer<vtkPolyData>::New();
	source->SetPoints(sourcePoints);

	vtkSmartPointer<vtkPolyData> target =
		vtkSmartPointer<vtkPolyData>::New();
	target->SetPoints(targetPoints);

	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter->SetInputConnection(reader1->GetOutputPort());
	transformFilter->SetTransform(landmarkTransform);
	transformFilter->Update();

	// Display the transformation matrix that was computed
	vtkMatrix4x4* mat = landmarkTransform->GetMatrix();
	std::cout << "Matrix: " << *mat << std::endl;

	// Set up the actor to display the transformed polydata in the bottom pane
	vtkSmartPointer<vtkPolyDataMapper> transformedMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	transformedMapper->SetInputConnection(transformFilter->GetOutputPort());

	vtkSmartPointer<vtkActor> transformedActor =
		vtkSmartPointer<vtkActor>::New();
	transformedActor->SetMapper(transformedMapper);
	transformedActor->GetProperty()->SetColor(0, 1, 0);


	// Set up the rest of the visualization pipeline
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	// Set up comparison
	double comparison_pane[4] = { 0, 0, 1, 0.5 };
	renderer->AddActor(actor1);
	renderer->AddActor(transformedActor);
	renderer->SetBackground(.3, .6, .3); // Set renderer's background color to green

	renderer->SetViewport(comparison_pane);
	renderer->ResetCamera();
	renderWindow->Render();
	renderWindow->SetWindowName("Comparisoft");
	renderWindowInteractor->Start();
}