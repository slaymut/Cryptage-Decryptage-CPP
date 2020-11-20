# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

cmake_minimum_required(VERSION 3.5)
project(proj)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Core Gui  Widgets REQUIRED)


set (SRCS
    src/arbreb.cpp
    src/sommet.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/mainmenu.cpp
    src/printsommet.cpp
    headers/arbreb.h
    headers/mainwindow.h
    headers/mainmenu.h
    headers/printsommet.h
    headers/printnames.h
    headers/sommet.h
    ProjectWindow.pro
)


add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
