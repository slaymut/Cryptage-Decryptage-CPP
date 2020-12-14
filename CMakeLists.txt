cmake_minimum_required(VERSION 3.5)
project(ProjectPart2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set (SRCS
    src/arbreb.cpp
    src/sommet.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/printsommet.cpp
    src/occurrence.cpp
    src/list_displayer.cpp
    src/affiche_code.cpp
    headers/arbreb.h
    headers/mainwindow.h
    headers/printsommet.h
    headers/printnames.h
    headers/sommet.h
    headers/Context.hpp
    headers/affiche_code.hpp
    headers/list_displayer.hpp
    headers/occurrence.hpp
    headers/input.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
