cmake_minimum_required(VERSION 2.8)

PROJECT(ReadSTL)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(ReadSTL MACOSX_BUNDLE ReadSTL.cxx VTK.h VTK.cpp fileDialogue.h fileDialogue.cpp mainwindow.h mainwindow.cpp)

if(VTK_LIBRARIES)
    target_link_libraries(ReadSTL ${VTK_LIBRARIES})
else()
    target_link_libraries(ReadSTL vtkHybrid vtkWidgets)
endif()