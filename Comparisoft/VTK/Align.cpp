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
#include <vtkSTLWriter.h>
#include <vtkIterativeClosestPointTransform.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>


// Constructors
Align::Align() {

};


// Methods

void Align::AlignModels(bool saveAlignedFile) {
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
	filePathReference = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/pug.stl";
	filePathProduction = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/pug.stl";
	//filePathReference = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerReference.stl";
	//filePathProduction = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerProduction.stl";
	
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

	//// Setup the transform
	//vtkSmartPointer<vtkLandmarkTransform> landmarkTransform =
	//	vtkSmartPointer<vtkLandmarkTransform>::New();
	//landmarkTransform->SetSourceLandmarks(sourcePoints);
	//landmarkTransform->SetTargetLandmarks(targetPoints);
	////We only want rotation and translation so set to RigidBody
	//landmarkTransform->SetModeToRigidBody();
	//landmarkTransform->Update()

	//Convert source points to polydata
	vtkSmartPointer<vtkPolyData> tempSource =
		vtkSmartPointer<vtkPolyData>::New();
	tempSource->SetPoints(sourcePoints);
	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilterSource =
		vtkSmartPointer<vtkVertexGlyphFilter>::New();
	vertexFilterSource->SetInputData(tempSource);
	vertexFilterSource->Update();
	sourcePoly = vtkSmartPointer<vtkPolyData>::New();
	sourcePoly->ShallowCopy(vertexFilterSource->GetOutput());

	//Convert points to polydata
	vtkSmartPointer<vtkPolyData> tempTarget =
		vtkSmartPointer<vtkPolyData>::New();
	tempTarget->SetPoints(targetPoints);
	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilterTarget =
		vtkSmartPointer<vtkVertexGlyphFilter>::New();
	vertexFilterTarget->SetInputData(tempTarget);
	vertexFilterTarget->Update();
	targetPoly = vtkSmartPointer<vtkPolyData>::New();
	targetPoly->ShallowCopy(vertexFilterTarget->GetOutput());


	// Setup ICP transform (HAVE TO DEAL WITH VERTEX FILTER)
	vtkSmartPointer<vtkIterativeClosestPointTransform> icp =
		vtkSmartPointer<vtkIterativeClosestPointTransform>::New();
	//icp->DebugOn();
	icp->SetSource(sourcePoly);
	icp->SetTarget(targetPoly);
	icp->GetLandmarkTransform()->SetModeToRigidBody();
	icp->SetMaximumNumberOfIterations(20);
	icp->StartByMatchingCentroidsOn();
	icp->Modified();
	icp->Update();

	// Get the resulting transformation matrix (this matrix takes the source points to the target points)
	vtkSmartPointer<vtkMatrix4x4> m = icp->GetMatrix();
	std::cout << "The resulting matrix is: " << *m << std::endl;

	// Transform the source points by the ICP solution
	vtkSmartPointer<vtkTransformPolyDataFilter> icpTransformFilter =
		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	icpTransformFilter->SetInputData(sourcePoly);
	icpTransformFilter->SetTransform(icp);
	icpTransformFilter->Update();

	////We perform the transformation to the production actor so it lines up with the reference actor
	//vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter =
	//	vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	//transformFilter->SetInputConnection(reader2->GetOutputPort());
	//transformFilter->SetTransform(landmarkTransform);
	//transformFilter->Update();

	//// Display the transformation matrix that was computed (for debugging)
	//vtkMatrix4x4* mat = landmarkTransform->GetMatrix();
	//std::cout << "Matrix: " << *mat << std::endl;

	// Set up the actor to display the transformed polydata in the bottom pane
	vtkSmartPointer<vtkPolyDataMapper> transformedMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	transformedMapper->SetInputConnection(icpTransformFilter->GetOutputPort());

	vtkSmartPointer<vtkActor> transformedProdActor =
		vtkSmartPointer<vtkActor>::New();
	transformedProdActor->SetMapper(transformedMapper);
	transformedProdActor->GetProperty()->SetColor(0, 1, 0);

	//Write the two aligned models to a file. Make this optional on a boolean parameter
	if (saveAlignedFile) {
		vtkSmartPointer<vtkSTLWriter> stlWriter =
			vtkSmartPointer<vtkSTLWriter>::New();
		//Write reference
		stlWriter->SetFileName("originalPug.stl");
		stlWriter->SetInputConnection(reader1->GetOutputPort());
		stlWriter->Write();

		//Write transformed
		stlWriter->SetFileName("transformedPug.stl");
		stlWriter->SetInputConnection(icpTransformFilter->GetOutputPort());
		stlWriter->Write();
	}
	
	//Assign the actors to variables to return
	refActor = referenceActor;
	prodActor = transformedProdActor;

}