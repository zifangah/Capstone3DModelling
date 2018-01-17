
/******************************************************************************/
/**
@file		PointSelection.h
@author 	Dana Klamut
@details	This file handles the point selection on the data sets.
Adapted from: https://www.vtk.org/Wiki/VTK/Examples/Cxx/Interaction/PointPicker
*/
/******************************************************************************/

#ifndef VTK_POINTSELECTION_H
#define VTK_POINTSELECTION_H

#include <vtkSmartPointer.h>
#include <vtkRendererCollection.h>
#include <vtkPointPicker.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <vtkAutoInit.h>
>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======
#include <vtkAutoInit.h>
>>>>>>> master

/**
@brief Stores selected coordinates on data sets.
*/
struct coordinate {
	double x_val;
	double y_val;
	double z_val;
};

class PointSelection : public vtkInteractorStyleTrackballCamera {

public:
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 628ae4e85d0cb492a48759dcc996ea166b12582b
=======

<<<<<<< HEAD
>>>>>>> master
=======
#define vtkTypeMacro(thisClass,superclass) \
      vtkAbstractTypeMacro(thisClass, superclass) \
      protected: \
      vtkObjectBase *NewInstanceInternal() const VTK_OVERRIDE \
      { \
        return thisClass::New(); \
      } \

>>>>>>> HighlightSelectedPoints
	static PointSelection* New();
	//vtkTypeMacro(PointSelection, vtkInteractorStyleTrackballCamera);

	int ref_count = 0; /* Number of coordinates selected on the reference pane */
	int prod_count = 0; /* Number of coordinates selected on the production pane */
	int count = 0; /* Determines which pane the point is being selected for */

	coordinate ref_coordinates[3]; /* Stores selected coordinates on the reference pane */
	coordinate prod_coordinates[3]; /* Stores selected coordinates on the production pane */

	ofstream file;

	bool is_open;

	void OnRightButtonDown() override ;
};

#endif //VTK_POINTSELECTION_H
