cmake_minimum_required(VERSION 4.2)
project(MultiDictionar)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MultiDictionar
        IteratorMD.cpp
        MD.cpp
        TestExtins.cpp
        TestScurt.cpp
        IteratorMD.h
        MD.h
        TestExtins.h
        TestScurt.h
        App.cpp
        IteratorLDI.h
        LDI.h)
