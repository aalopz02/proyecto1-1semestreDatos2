cmake_minimum_required(VERSION 3.5.1)
project(Proyecto1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Xml REQUIRED )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
add_executable(Proyecto1 main.cpp dependencias/exprtk.hpp Window.cpp Window.h logic/lectorTextEdit.cpp headers/lectorTextEdit.h logic/Grafo.cpp headers/Grafo.h logic/comunicador.cpp headers/comunicador.h logic/formuladorMensajes.cpp headers/formuladorMensajes.h)
target_link_libraries(Proyecto1 Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})