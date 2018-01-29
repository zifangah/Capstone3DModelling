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

};


// Methods

void Align::AlignModels() {
	/*
	* Transformed the actors so they are aligned using clicked points (as set in PointSelection.cpp)
	* Sets variables refActor & prodActor to the transformed actors
	*
	* We perform the translation such that the reference file stays aligned the same, and the production file
	* is translated to align with it.
	*/

	//Hardcoded files for testing
	char* filePathReference = NULL;
	char* filePathProduction = NULL;
	filePathReference = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerProduction.stl";
	filePathProduction = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerReference.stl";
	
	// Set up reference file
	vtkSmartPointer<vtkSTLReader> reader1 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(filePathReference);
	reader1->Update();
	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());
	vtkSmartPointer<vtkActor> referenceActor =
		vtkSmartPointer<vtkActor>::New();
	referenceActor->SetMapper(mapper1);

	// Set up production file
	vtkSmartPointer<vtkSTLReader> reader2 =
		vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(filePathProduction);
	reader2->Update();
	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());
	vtkSmartPointer<vtkActor> productionActor =
		vtkSmartPointer<vtkActor>::New();
	productionActor->SetMapper(mapper2);

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

	//We perform the transformation to the production actor so it lines up with the reference actor
	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transformFilter->SetInputConnection(reader2->GetOutputPort());
	transformFilter->SetTransform(landmarkTransform);
	transformFilter->Update();

	// Display the transformation matrix that was computed (for debugging)
	vtkMatrix4x4* mat = landmarkTransform->GetMatrix();
	std::cout << "Matrix: " << *mat << std::endl;

	// Set up the actor to display the transformed polydata in the bottom pane
	vtkSmartPointer<vtkPolyDataMapper> transformedMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	transformedMapper->SetInputConnection(transformFilter->GetOutputPort());

	vtkSmartPointer<vtkActor> transformedProdActor =
		vtkSmartPointer<vtkActor>::New();
	transformedProdActor->SetMapper(transformedMapper);
	transformedProdActor->GetProperty()->SetColor(0, 1, 0);

	//Assign the actors to variables to return
	refActor = referenceActor;
	prodActor = transformedProdActor;
}