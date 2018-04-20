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
add_executable(Proyecto1 main.cpp
        dependencias/exprtk.hpp
        Window.cpp
        Window.h
        logic/lectorTextEdit.cpp
        headers/lectorTextEdit.h
        dependencias/Server/logic/Grafo.cpp
        dependencias/Server/headers/Grafo.h
        dependencias/Server/headers/formuladorMensajes.h
        dependencias/Server/headers/memReserver.h
        dependencias/Server/headers/mServer.h
        dependencias/Server/headers/comunicador.h
        dependencias/Server/logic/formuladorMensajes.cpp
        dependencias/Server/logic/comunicador.cpp
        dependencias/Server/logic/memReserver.cpp
        dependencias/Server/logic/mServer.cpp
        )


target_link_libraries(Proyecto1 Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})