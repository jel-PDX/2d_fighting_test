# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/james/Desktop/Programming/2d_fighting_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/Desktop/Programming/2d_fighting_test/build

# Include any dependencies generated for this target.
include CMakeFiles/spatial_hash_grid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/spatial_hash_grid.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/spatial_hash_grid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spatial_hash_grid.dir/flags.make

CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o: CMakeFiles/spatial_hash_grid.dir/flags.make
CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o: ../src/spatial_hash_grid.cpp
CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o: CMakeFiles/spatial_hash_grid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/Desktop/Programming/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o -MF CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o.d -o CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o -c /home/james/Desktop/Programming/2d_fighting_test/src/spatial_hash_grid.cpp

CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/Desktop/Programming/2d_fighting_test/src/spatial_hash_grid.cpp > CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.i

CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/Desktop/Programming/2d_fighting_test/src/spatial_hash_grid.cpp -o CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.s

# Object files for target spatial_hash_grid
spatial_hash_grid_OBJECTS = \
"CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o"

# External object files for target spatial_hash_grid
spatial_hash_grid_EXTERNAL_OBJECTS =

libspatial_hash_grid.a: CMakeFiles/spatial_hash_grid.dir/src/spatial_hash_grid.cpp.o
libspatial_hash_grid.a: CMakeFiles/spatial_hash_grid.dir/build.make
libspatial_hash_grid.a: CMakeFiles/spatial_hash_grid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/Desktop/Programming/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libspatial_hash_grid.a"
	$(CMAKE_COMMAND) -P CMakeFiles/spatial_hash_grid.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spatial_hash_grid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spatial_hash_grid.dir/build: libspatial_hash_grid.a
.PHONY : CMakeFiles/spatial_hash_grid.dir/build

CMakeFiles/spatial_hash_grid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spatial_hash_grid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spatial_hash_grid.dir/clean

CMakeFiles/spatial_hash_grid.dir/depend:
	cd /home/james/Desktop/Programming/2d_fighting_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/Desktop/Programming/2d_fighting_test /home/james/Desktop/Programming/2d_fighting_test /home/james/Desktop/Programming/2d_fighting_test/build /home/james/Desktop/Programming/2d_fighting_test/build /home/james/Desktop/Programming/2d_fighting_test/build/CMakeFiles/spatial_hash_grid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spatial_hash_grid.dir/depend

