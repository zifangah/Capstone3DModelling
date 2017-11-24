cmake_minimum_required(VERSION 2.8)

PROJECT(Comparisoft)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(Comparisoft MACOSX_BUNDLE Comparisoft.cxx VTK.h VTK.cpp fileDialogue.h fileDialogue.cpp)

if(VTK_LIBRARIES)
    target_link_libraries(Comparisoft ${VTK_LIBRARIES})
else()
    target_link_libraries(Comparisoft vtkHybrid vtkWidgets)
endif()