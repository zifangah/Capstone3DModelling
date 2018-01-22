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

	//Constructors
	Align();
	
	//Methods
	//void Align::AlignModels();
};
