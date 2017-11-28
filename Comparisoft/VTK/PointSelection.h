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

/**
@brief Stores selected coordinates on data sets.
*/
struct coordinate {
	double x_val;
	double y_val;
	double z_val;
};

/**
@brief Point selection class for selecting 3 points on each data set
*/
class PointSelection : public vtkInteractorStyleTrackballCamera
{
public:
	static PointSelection* New();
	vtkTypeMacro(PointSelection, vtkInteractorStyleTrackballCamera);

	coordinate ref_coordinates[3]; /* Stores selected coordinates on the reference pane */
	coordinate prod_coordinates[3]; /* Stores selected coordinates on the production pane */

	int ref_count = 0; /* Number of coordinates selected on the reference pane */
	int prod_count = 0; /* Number of coordinates selected on the production pane */
	int count = 0; /* Determines which pane the point is being selected for */

	/**
	@brief Alter the inherited OnLeftButtonDown() of
	vtkInteractorStyleTrackballCamera to be compatible with our intended use.
	@returns void
	*/
	void OnRightButtonDown() override
	{
		/* Pixel being selected */
		std::cout << "Picking pixel: " << this->Interactor->GetEventPosition()[0]
				  << " " << this->Interactor->GetEventPosition()[1] << std::endl;
		this->Interactor->GetPicker()->Pick(this->Interactor->GetEventPosition()[0],
											this->Interactor->GetEventPosition()[1],
											0,  // always zero.
											this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
		double picked[3];

		/* Pixel actually selected */
		this->Interactor->GetPicker()->GetPickPosition(picked);
		std::cout << "Value selected: " << picked[0] << " " << picked[1] << " " << picked[2] << std::endl;
		std::cout << std::endl;

		if ((ref_count < 3) && (count % 2 == 0)) {
			ref_coordinates[ref_count] = {picked[0], picked[1], picked[2]};
			ref_count++;
		}

		else if ((prod_count < 3) && (count % 2 != 0)) {
			prod_coordinates[prod_count] = {picked[0], picked[1], picked[2]};
			prod_count++;
		}

		count++;

		if ((prod_count == 3) && (ref_count == 3)) {
			std::cout << "Point 1 on R Pane (x, y, z): " << ref_coordinates[0].x_val << " "
					  << ref_coordinates[0].y_val << " " << ref_coordinates[0].z_val << std::endl;
			std::cout << "Point 2 on R Pane (x, y, z): " << ref_coordinates[1].x_val << " "
					  << ref_coordinates[1].y_val << " " << ref_coordinates[1].z_val << std::endl;
			std::cout << "Point 3 on R Pane (x, y, z): " << ref_coordinates[2].x_val << " "
					  << ref_coordinates[2].y_val << " " << ref_coordinates[2].z_val << std::endl;
			std::cout << std::endl;

			std::cout << "Point 1 on P Pane (x, y, z): " << prod_coordinates[0].x_val << " "
					  << prod_coordinates[0].y_val << " " << prod_coordinates[0].z_val << std::endl;
			std::cout << "Point 2 on P Pane (x, y, z): " << prod_coordinates[1].x_val << " "
					  << prod_coordinates[1].y_val << " " << prod_coordinates[1].z_val << std::endl;
			std::cout << "Point 3 on P Pane (x, y, z): " << prod_coordinates[2].x_val << " "
					  << prod_coordinates[2].y_val << " " << prod_coordinates[2].z_val << std::endl;
		}

		vtkInteractorStyleTrackballCamera::OnRightButtonDown();
	}
};

vtkStandardNewMacro(PointSelection);

#endif //VTK_POINTSELECTION_H
