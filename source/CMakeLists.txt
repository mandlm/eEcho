cmake_minimum_required(VERSION 3.6)
project(qEcho)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-psabi")

add_executable(${PROJECT_NAME}
    qecho.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
	led.cpp
	led.h
	blinkthread.cpp
    blinkthread.h
    distancethread.cpp
    distancethread.h
)

target_link_libraries(${PROJECT_NAME} wiringPi Qt5::Widgets)

