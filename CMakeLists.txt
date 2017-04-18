cmake_minimum_required(VERSION 3.7)
project(lab2_for_students)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/.name
        .idea/lab2.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/lab2
        cmake-build-debug/lab2.cbp
        cmake-build-debug/Makefile
        CMakeLists.txt
        main.cpp
        Statistics.cpp
        Statistics.h
        winequality.csv)

add_executable(lab2_for_students ${SOURCE_FILES})