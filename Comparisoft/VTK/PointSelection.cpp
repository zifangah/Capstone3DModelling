/******************************************************************************/
/**
@file		PointSelection.cpp
@reference	PointSelection.h
@author 	Dana Klamut

@details	This file handles the point selection on the data sets.
Adapted from: https://www.vtk.org/Wiki/VTK/Examples/Cxx/Interaction/PointPicker
*/
/******************************************************************************/

#include "PointSelection.h"
#include "Align.h"
/**
	@brief Alter the inherited OnLeftButtonDown() of
	vtkInteractorStyleTrackballCamera to be compatible with our intended use.
	@returns void
*/
	void PointSelection::OnRightButtonDown()
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
			Align bottomPanel;
			
			//Insert points into bottom panel
			bottomPanel.sourcePoints = vtkSmartPointer<vtkPoints>::New();
			//double sourcePoint0[3] = { ref_coordinates[0].x_val, ref_coordinates[0].y_val, ref_coordinates[0].z_val };
			//bottomPanel.sourcePoints->InsertNextPoint(sourcePoint0);
			//double sourcePoint1[3] = { ref_coordinates[1].x_val, ref_coordinates[1].y_val, ref_coordinates[1].z_val };
			//bottomPanel.sourcePoints->InsertNextPoint(sourcePoint1);
			//double sourcePoint2[3] = { ref_coordinates[2].x_val, ref_coordinates[2].y_val, ref_coordinates[2].z_val };
			//bottomPanel.sourcePoints->InsertNextPoint(sourcePoint2);
			
			//for (vtkIdType i = 0; i < bottomPanel.sourcePoints->GetNumberOfPoints(); i++)
			//{
			//	double p[3];
			//	bottomPanel.sourcePoints->GetPoint(i, p);
			//	// This is identical to:
			//	// polydata->GetPoints()->GetPoint(i,p);
			//	std::cout << "Point " << i << " : (" << p[0] << " " << p[1] << " " << p[2] << ")" << std::endl;
			//}

			bottomPanel.targetPoints = vtkSmartPointer<vtkPoints>::New();
			//double targetPoint0[3] = { prod_coordinates[0].x_val, prod_coordinates[0].y_val, prod_coordinates[0].z_val };
			//bottomPanel.targetPoints->InsertNextPoint(targetPoint0);
			//double targetPoint1[3] = { prod_coordinates[1].x_val, prod_coordinates[1].y_val, prod_coordinates[1].z_val };
			//bottomPanel.targetPoints->InsertNextPoint(targetPoint1);
			//double targetPoint2[3] = { prod_coordinates[2].x_val, prod_coordinates[2].y_val, prod_coordinates[2].z_val };
			//bottomPanel.targetPoints->InsertNextPoint(targetPoint2);
			
			//for (vtkIdType i = 0; i < bottomPanel.targetPoints->GetNumberOfPoints(); i++)
			//{
			//	double p[3];
			//	bottomPanel.targetPoints->GetPoint(i, p);
			//	// This is identical to:
			//	// polydata->GetPoints()->GetPoint(i,p);
			//	std::cout << "Point " << i << " : (" << p[0] << " " << p[1] << " " << p[2] << ")" << std::endl;
			//}


			 //Test source points
			double sourcePoint1[3] = { 0.0, 0.0, 1.0 };
			bottomPanel.sourcePoints->InsertNextPoint(sourcePoint1);
			double sourcePoint2[3] = { 0.0, 1.0, 0.0 };
			bottomPanel.sourcePoints->InsertNextPoint(sourcePoint2);
			double sourcePoint3[3] = { 0.0, 0.0, 1.0 };
			bottomPanel.sourcePoints->InsertNextPoint(sourcePoint3);

			// Test target points
			double targetPoint1[3] = { 0.0, 0.0, 1.1 };
			bottomPanel.targetPoints->InsertNextPoint(targetPoint1);
			double targetPoint2[3] = { 0.0, 1.0, 0.0 };
			bottomPanel.targetPoints->InsertNextPoint(targetPoint2);
			double targetPoint3[3] = { 0.0, 0.0, 0.0 };
			bottomPanel.targetPoints->InsertNextPoint(targetPoint3);


			bottomPanel.AlignModels();

			// We now have sufficient click data, pass to our alignment
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

vtkStandardNewMacro(PointSelection);
