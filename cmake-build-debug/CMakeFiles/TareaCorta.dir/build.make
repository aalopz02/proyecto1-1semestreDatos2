# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/andres/Downloads/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/andres/Downloads/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andres/CLionProjects/TareaCorta

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andres/CLionProjects/TareaCorta/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TareaCorta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TareaCorta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TareaCorta.dir/flags.make

CMakeFiles/TareaCorta.dir/main.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TareaCorta.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/main.cpp.o -c /home/andres/CLionProjects/TareaCorta/main.cpp

CMakeFiles/TareaCorta.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/main.cpp > CMakeFiles/TareaCorta.dir/main.cpp.i

CMakeFiles/TareaCorta.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/main.cpp -o CMakeFiles/TareaCorta.dir/main.cpp.s

CMakeFiles/TareaCorta.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/main.cpp.o.requires

CMakeFiles/TareaCorta.dir/main.cpp.o.provides: CMakeFiles/TareaCorta.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/main.cpp.o.provides

CMakeFiles/TareaCorta.dir/main.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/main.cpp.o


CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o: ../logic/mServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/mServer.cpp

CMakeFiles/TareaCorta.dir/logic/mServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/mServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/mServer.cpp > CMakeFiles/TareaCorta.dir/logic/mServer.cpp.i

CMakeFiles/TareaCorta.dir/logic/mServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/mServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/mServer.cpp -o CMakeFiles/TareaCorta.dir/logic/mServer.cpp.s

CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o


CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o: ../logic/memReserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/memReserver.cpp

CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/memReserver.cpp > CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.i

CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/memReserver.cpp -o CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.s

CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o


CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o: ../logic/guardarPagina.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/guardarPagina.cpp

CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/guardarPagina.cpp > CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.i

CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/guardarPagina.cpp -o CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.s

CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o


CMakeFiles/TareaCorta.dir/Window.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/Window.cpp.o: ../Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TareaCorta.dir/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/Window.cpp.o -c /home/andres/CLionProjects/TareaCorta/Window.cpp

CMakeFiles/TareaCorta.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/Window.cpp > CMakeFiles/TareaCorta.dir/Window.cpp.i

CMakeFiles/TareaCorta.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/Window.cpp -o CMakeFiles/TareaCorta.dir/Window.cpp.s

CMakeFiles/TareaCorta.dir/Window.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/Window.cpp.o.requires

CMakeFiles/TareaCorta.dir/Window.cpp.o.provides: CMakeFiles/TareaCorta.dir/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/Window.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/Window.cpp.o.provides

CMakeFiles/TareaCorta.dir/Window.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/Window.cpp.o


CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o: ../logic/pagina.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/pagina.cpp

CMakeFiles/TareaCorta.dir/logic/pagina.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/pagina.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/pagina.cpp > CMakeFiles/TareaCorta.dir/logic/pagina.cpp.i

CMakeFiles/TareaCorta.dir/logic/pagina.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/pagina.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/pagina.cpp -o CMakeFiles/TareaCorta.dir/logic/pagina.cpp.s

CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o


CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o: ../logic/leerPagina.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/leerPagina.cpp

CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/leerPagina.cpp > CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.i

CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/leerPagina.cpp -o CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.s

CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o


CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o: ../logic/lectorTextEdit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o -c /home/andres/CLionProjects/TareaCorta/logic/lectorTextEdit.cpp

CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/logic/lectorTextEdit.cpp > CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.i

CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/logic/lectorTextEdit.cpp -o CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.s

CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.requires

CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.provides: CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.provides

CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o


CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o: CMakeFiles/TareaCorta.dir/flags.make
CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o: TareaCorta_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o -c /home/andres/CLionProjects/TareaCorta/cmake-build-debug/TareaCorta_autogen/mocs_compilation.cpp

CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andres/CLionProjects/TareaCorta/cmake-build-debug/TareaCorta_autogen/mocs_compilation.cpp > CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.i

CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andres/CLionProjects/TareaCorta/cmake-build-debug/TareaCorta_autogen/mocs_compilation.cpp -o CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.s

CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/TareaCorta.dir/build.make CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o


# Object files for target TareaCorta
TareaCorta_OBJECTS = \
"CMakeFiles/TareaCorta.dir/main.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o" \
"CMakeFiles/TareaCorta.dir/Window.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o" \
"CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o" \
"CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o"

# External object files for target TareaCorta
TareaCorta_EXTERNAL_OBJECTS =

TareaCorta: CMakeFiles/TareaCorta.dir/main.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/Window.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o
TareaCorta: CMakeFiles/TareaCorta.dir/build.make
TareaCorta: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.5.1
TareaCorta: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.5.1
TareaCorta: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
TareaCorta: CMakeFiles/TareaCorta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable TareaCorta"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TareaCorta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TareaCorta.dir/build: TareaCorta

.PHONY : CMakeFiles/TareaCorta.dir/build

CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/main.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/mServer.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/memReserver.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/guardarPagina.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/Window.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/pagina.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/leerPagina.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/logic/lectorTextEdit.cpp.o.requires
CMakeFiles/TareaCorta.dir/requires: CMakeFiles/TareaCorta.dir/TareaCorta_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/TareaCorta.dir/requires

CMakeFiles/TareaCorta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TareaCorta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TareaCorta.dir/clean

CMakeFiles/TareaCorta.dir/depend:
	cd /home/andres/CLionProjects/TareaCorta/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andres/CLionProjects/TareaCorta /home/andres/CLionProjects/TareaCorta /home/andres/CLionProjects/TareaCorta/cmake-build-debug /home/andres/CLionProjects/TareaCorta/cmake-build-debug /home/andres/CLionProjects/TareaCorta/cmake-build-debug/CMakeFiles/TareaCorta.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TareaCorta.dir/depend

