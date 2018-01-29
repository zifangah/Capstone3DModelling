// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

//Not sure what this is for, but it doesn't seem to break anything
#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <string>
#include "VTK.h"
#include "fileDialogue.h"



// Global variables

//declare the file path variables here so that they are global
char* filePathReference = NULL;
char* filePathProduction = NULL;

/*
argc is the count of arguments passed to the program. 1 is the program name, so this number will be n+1, where n is the number of commands
we pass. argv is the arguments passed. 1 is the program name, the others are the ones that we pass, in the order passed.
*/
int main(int argc, char *argv[])

{

	//Writing points to logfile instead
	freopen("output.txt", "w", stdout);

	//filePathReference = argv[1];
	//filePathProduction = argv[2];

	//Hardcoded files for testing
	filePathReference = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerProduction.stl";
	filePathProduction = "C:/Development/Capstone/Capstone3DModelling/Comparisoft/VTK/VTK-bin/Release/CaroleLowerReference.stl";

	//Launch the VTK function
	VTKmain(filePathReference, filePathProduction);

}
