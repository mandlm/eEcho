cmake_minimum_required(VERSION 3.6)
project(qEcho)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    blinkthread.cpp
    blinkthread.h
    distancethread.cpp
    distancethread.h
)

target_link_libraries(${PROJECT_NAME} wiringPi Qt5::Widgets)

