/******************************************************************************
@file		Align.h
@author 	Emerson Kirby

@details	This file handles the alignment of the models
******************************************************************************/
#include <vtkSmartPointer.h>
#include <vtkPoints.h>

class Align {

public:
	//Data members
	vtkSmartPointer<vtkPoints> sourcePoints;
	vtkSmartPointer<vtkPoints> targetPoints;
	//static char* filePathRef;
	//static char* filePathProd;

	//Constructors
	Align();
	
	//Methods
	void Align::AlignModels();
};
