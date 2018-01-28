/******************************************************************************
@file		Align.h
@author 	Emerson Kirby

@details	This file handles the alignment of the models
******************************************************************************/
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkActor.h>
#include <vtkPolyData.h>

class Align {

public:
	//Data members
	vtkSmartPointer<vtkPoints> sourcePoints;
	vtkSmartPointer<vtkPoints> targetPoints;
	vtkSmartPointer<vtkPolyData> sourcePoly;
	vtkSmartPointer<vtkPolyData> targetPoly;
	vtkSmartPointer<vtkActor> refActor;
	vtkSmartPointer<vtkActor> prodActor;
	//static char* filePathRef;
	//static char* filePathProd;

	//Constructors
	Align();
	
	//Methods
	void Align::AlignModels(bool saveAlignedFile);

};
