cmake_minimum_required(VERSION 3.5.1)
project(TareaCorta)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Xml REQUIRED )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
add_executable(TareaCorta main.cpp logic/mServer.cpp headers/mServer.h logic/memReserver.cpp headers/memReserver.h logic/guardarPagina.cpp headers/guardarPagina.h Window.cpp Window.h logic/pagina.cpp headers/pagina.h logic/leerPagina.cpp headers/leerPagina.h logic/lectorTextEdit.cpp headers/lectorTextEdit.h)
target_link_libraries(TareaCorta Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})