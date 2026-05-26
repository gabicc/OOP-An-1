#cmake_minimum_required(VERSION 4.2)
#project(Inchiriere_masini)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(Inchiriere_masini main.cpp
#        Masina.cpp
#        Masina.h
#        TestMasina.cpp
#        TestMasina.h
#        RepoMasini.cpp
#        RepoMasini.h
#        Console.cpp
#        Console.h
#        Service.cpp
#        Service.h
#        ListaInlantuita.h
#        Validator.cpp
#        Validator.h
#        Undo.cpp
#        Undo.h
#        UndoAdauga.cpp
#        UndoAdauga.h
#        UndoSterge.cpp
#        UndoSterge.h
#        UndoModifica.cpp
#        UndoModifica.h
#        Repo.h
#        RepoMasiniMap.cpp
#        RepoMasiniMap.h
#        mainwindow.cpp
#        mainwindow.h)



cmake_minimum_required(VERSION 3.16)

project(Inchiriere_masini VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
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
        RepoMasiniMap.h
        InchiriereGUI.cpp
        InchiriereGUI.h
        CosReadOnlyGUI.cpp
        CosReadOnlyGUI.h
        CosCRUDGUI.cpp
        CosCRUDGUI.h
        Observer.cpp
        Observer.h
        Subject.cpp
        Subject.h
        MasinaTableModel.cpp
        MasinaTableModel.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Inchiriere_masini
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Inchiriere_masini APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Inchiriere_masini SHARED
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Inchiriere_masini
                ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Inchiriere_masini PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Inchiriere_masini)
endif()
set_target_properties(Inchiriere_masini PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Inchiriere_masini
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Inchiriere_masini)
endif()
