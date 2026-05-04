cmake_minimum_required(VERSION 4.2)
project(Inchiriere_masini)

set(CMAKE_CXX_STANDARD 20)

add_executable(Inchiriere_masini main.cpp
        Masina.cpp
        Masina.h
        TestMasina.cpp
        TestMasina.h
        RepoMasini.cpp
        RepoMasini.h
        Console.cpp
        Console.h
        Service.cpp
        Service.h
        ListaInlantuita.h
        Validator.cpp
        Validator.h
        Undo.cpp
        Undo.h
        UndoAdauga.cpp
        UndoAdauga.h
        UndoSterge.cpp
        UndoSterge.h
        UndoModifica.cpp
        UndoModifica.h
        Repo.h
        RepoMasiniMap.cpp
        RepoMasiniMap.h)
