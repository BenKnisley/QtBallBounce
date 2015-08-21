project(QPainter_BallBounce)
cmake_minimum_required(VERSION 2.8)

## Set project output directorys
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../static )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin )

## Set linker and compiler flags
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set (CMAKE_EXE_LINKER_FLAGS "-ldl" )

## Qt library
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED Core Widgets Gui OpenGL)

## OpenGl library
#find_package(OpenGL REQUIRED)

add_executable(BallBounce ./src/main.cpp ./src/mainWindow.cpp ./src/ball.cpp)
target_link_libraries(BallBounce Qt5::Widgets)


## Add a run target
add_custom_target(
    run
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
    COMMAND ./BallBounce
)
