# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zifangjiang/CLionProjects/Capstone3DModelling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug

# Include any dependencies generated for this target.
include Examples/stl-example/CMakeFiles/ReadSTL.dir/depend.make

# Include the progress variables for this target.
include Examples/stl-example/CMakeFiles/ReadSTL.dir/progress.make

# Include the compile flags for this target's objects.
include Examples/stl-example/CMakeFiles/ReadSTL.dir/flags.make

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o: Examples/stl-example/CMakeFiles/ReadSTL.dir/flags.make
Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o: ../Examples/stl-example/ReadSTL.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o -c /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/ReadSTL.cxx

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadSTL.dir/ReadSTL.cxx.i"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/ReadSTL.cxx > CMakeFiles/ReadSTL.dir/ReadSTL.cxx.i

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadSTL.dir/ReadSTL.cxx.s"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/ReadSTL.cxx -o CMakeFiles/ReadSTL.dir/ReadSTL.cxx.s

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.requires:

.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.requires

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.provides: Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.requires
	$(MAKE) -f Examples/stl-example/CMakeFiles/ReadSTL.dir/build.make Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.provides.build
.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.provides

Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.provides.build: Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o


Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o: Examples/stl-example/CMakeFiles/ReadSTL.dir/flags.make
Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o: ../Examples/stl-example/VTK.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadSTL.dir/VTK.cpp.o -c /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/VTK.cpp

Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadSTL.dir/VTK.cpp.i"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/VTK.cpp > CMakeFiles/ReadSTL.dir/VTK.cpp.i

Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadSTL.dir/VTK.cpp.s"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/VTK.cpp -o CMakeFiles/ReadSTL.dir/VTK.cpp.s

Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.requires:

.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.requires

Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.provides: Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.requires
	$(MAKE) -f Examples/stl-example/CMakeFiles/ReadSTL.dir/build.make Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.provides.build
.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.provides

Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.provides.build: Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o


Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o: Examples/stl-example/CMakeFiles/ReadSTL.dir/flags.make
Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o: ../Examples/stl-example/fileDialogue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o -c /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/fileDialogue.cpp

Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReadSTL.dir/fileDialogue.cpp.i"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/fileDialogue.cpp > CMakeFiles/ReadSTL.dir/fileDialogue.cpp.i

Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReadSTL.dir/fileDialogue.cpp.s"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example/fileDialogue.cpp -o CMakeFiles/ReadSTL.dir/fileDialogue.cpp.s

Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.requires:

.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.requires

Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.provides: Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.requires
	$(MAKE) -f Examples/stl-example/CMakeFiles/ReadSTL.dir/build.make Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.provides.build
.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.provides

Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.provides.build: Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o


# Object files for target ReadSTL
ReadSTL_OBJECTS = \
"CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o" \
"CMakeFiles/ReadSTL.dir/VTK.cpp.o" \
"CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o"

# External object files for target ReadSTL
ReadSTL_EXTERNAL_OBJECTS =

Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: Examples/stl-example/CMakeFiles/ReadSTL.dir/build.make
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libz.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libexpat.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkDomainsChemistryOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersFlowPaths-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersGeneric-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersHyperTree-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersParallelImaging-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersPoints-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersProgrammable-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersPython-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /System/Library/Frameworks/Python.framework/Versions/2.7/Python
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkWrappingPython27Core-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkWrappingTools-8.0.a
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersSMP-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersSelection-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersTexture-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersTopology-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersVerdict-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkverdict-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkGeovisCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libjpeg.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libpng.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libtiff.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkproj4-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOAMR-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libhdf5.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libsz.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libdl.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libm.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libhdf5_hl.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOEnSight-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOExodus-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libnetcdf.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOExportOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOImport-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOInfovis-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libxml2.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOLSDyna-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOMINC-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOMovie-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkoggtheora-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOPLY-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOParallel-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkjsoncpp-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOParallelXML-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOSQL-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtksqlite-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOTecplotTable-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOVideo-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingMorphological-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingStatistics-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingStencil-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInfovisBoostGraphAlgorithms-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInteractionImage-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingContextOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingFreeTypeFontConfig-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingImage-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingLOD-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingVolumeOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkViewsContext2D-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkViewsInfovis-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkDomainsChemistry-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersAMR-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOExport-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtklibharu-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingGL2PSOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkgl2ps-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersParallel-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkexoIIc-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOGeometry-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIONetCDF-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtknetcdf_c++.4.2.0.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/lib/libnetcdf.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkParallelCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOLegacy-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingOpenGL2-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkglew-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingMath-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkChartsCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingContext2D-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersImaging-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInfovisLayout-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInfovisCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkViewsCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInteractionWidgets-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersHybrid-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingGeneral-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingSources-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersModeling-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingHybrid-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOImage-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkDICOMParser-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkmetaio-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkInteractionStyle-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersExtraction-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersStatistics-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingFourier-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkalglib-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingAnnotation-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingColor-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingVolume-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkImagingCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOXML-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOXMLParser-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkIOCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtklz4-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingLabel-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingFreeType-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkRenderingCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonColor-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersGeometry-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersSources-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersGeneral-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonComputationalGeometry-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkFiltersCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonExecutionModel-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonDataModel-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonTransforms-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonMisc-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonMath-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonSystem-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkCommonCore-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtksys-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/local/Cellar/vtk/8.0.1/lib/libvtkfreetype-8.0.1.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: /usr/lib/libz.dylib
Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL: Examples/stl-example/CMakeFiles/ReadSTL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ReadSTL.app/Contents/MacOS/ReadSTL"
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReadSTL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Examples/stl-example/CMakeFiles/ReadSTL.dir/build: Examples/stl-example/ReadSTL.app/Contents/MacOS/ReadSTL

.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/build

Examples/stl-example/CMakeFiles/ReadSTL.dir/requires: Examples/stl-example/CMakeFiles/ReadSTL.dir/ReadSTL.cxx.o.requires
Examples/stl-example/CMakeFiles/ReadSTL.dir/requires: Examples/stl-example/CMakeFiles/ReadSTL.dir/VTK.cpp.o.requires
Examples/stl-example/CMakeFiles/ReadSTL.dir/requires: Examples/stl-example/CMakeFiles/ReadSTL.dir/fileDialogue.cpp.o.requires

.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/requires

Examples/stl-example/CMakeFiles/ReadSTL.dir/clean:
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example && $(CMAKE_COMMAND) -P CMakeFiles/ReadSTL.dir/cmake_clean.cmake
.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/clean

Examples/stl-example/CMakeFiles/ReadSTL.dir/depend:
	cd /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zifangjiang/CLionProjects/Capstone3DModelling /Users/zifangjiang/CLionProjects/Capstone3DModelling/Examples/stl-example /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example /Users/zifangjiang/CLionProjects/Capstone3DModelling/cmake-build-debug/Examples/stl-example/CMakeFiles/ReadSTL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Examples/stl-example/CMakeFiles/ReadSTL.dir/depend

