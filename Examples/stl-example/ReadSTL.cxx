#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkDelaunay2D.h>
#include <vtkImageMapToColors.h>

int main ( int argc, char *argv[] )
{
	if ( argc != 3 )
	{
		cout << "Required parameters: Filename x 2" << endl;
		return EXIT_FAILURE;
	}

	std::string inputFilename1 = argv[1];
	std::string inputFilename2 = argv[2];

	/* Map the scalar values in the image to colors with a lookup table: */
	vtkSmartPointer<vtkLookupTable> lookupTable =
			vtkSmartPointer<vtkLookupTable>::New();
//	lookupTable->SetNumberOfTableValues(256);
//	lookupTable->SetRange(0.0, 255.0);
//	lookupTable->Build();

	/* Pass the original image and the lookup table to a filter to create
	 a color image: */
	vtkSmartPointer<vtkImageMapToColors> scalarValuesToColors =
			vtkSmartPointer<vtkImageMapToColors>::New();
//	scalarValuesToColors->SetLookupTable(lookupTable);
	scalarValuesToColors->PassAlphaToOutputOn();
#if VTK_MAJOR_VERSION <= 5
	scalarValuesToColors->SetInput(image);
#else
//	scalarValuesToColors->SetInputData(image);
#endif

	/* Set-up file 1 */
	vtkSmartPointer<vtkSTLReader> reader1 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader1->SetFileName(inputFilename1.c_str());
	reader1->Update();

	vtkSmartPointer<vtkPolyDataMapper> mapper1 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper1->SetInputConnection(reader1->GetOutputPort());

	vtkSmartPointer<vtkActor> actor1 =
			vtkSmartPointer<vtkActor>::New();
	actor1->SetMapper(mapper1);

	/* Set-up file 2 */
	vtkSmartPointer<vtkSTLReader> reader2 =
			vtkSmartPointer<vtkSTLReader>::New();
	reader2->SetFileName(inputFilename2.c_str());
	reader2->Update();

	vtkSmartPointer<vtkPolyDataMapper> mapper2 =
			vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper2->SetInputConnection(reader2->GetOutputPort());

	vtkSmartPointer<vtkActor> actor2 =
			vtkSmartPointer<vtkActor>::New();
	actor2->SetMapper(mapper2);

	/* Create one render window and one interactor for all 3 panes */
	vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->SetSize(800, 800);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

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

	/* Set-up combined Comparison Pane */
	renderer3->AddActor(actor1);
	renderer3->AddActor(actor2);
	renderer3->SetBackground(.5, .7, .8);
	renderer3->SetViewport(comparison_pane);
	renderer3->ResetCamera();

	renderWindow->Render();
	renderWindow->SetWindowName("Comparisoft");
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}