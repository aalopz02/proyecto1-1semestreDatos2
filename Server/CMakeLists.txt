cmake_minimum_required(VERSION 3.5.1)
project(Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )

add_executable(Server headers/Grafo.h
        headers/memReserver.h
        headers/mServer.h
        logic/Grafo.cpp
        logic/memReserver.cpp
        logic/mServer.cpp
        main.cpp logic/Servidor.cpp headers/Servidor.h)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
target_link_libraries(Server Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)

