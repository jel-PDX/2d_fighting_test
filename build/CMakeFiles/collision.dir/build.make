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
CMAKE_SOURCE_DIR = /home/james/projects/2d_fighting_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/projects/2d_fighting_test/build

# Include any dependencies generated for this target.
include CMakeFiles/collision.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/collision.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/collision.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/collision.dir/flags.make

CMakeFiles/collision.dir/src/collision.cpp.o: CMakeFiles/collision.dir/flags.make
CMakeFiles/collision.dir/src/collision.cpp.o: ../src/collision.cpp
CMakeFiles/collision.dir/src/collision.cpp.o: CMakeFiles/collision.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/collision.dir/src/collision.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/collision.dir/src/collision.cpp.o -MF CMakeFiles/collision.dir/src/collision.cpp.o.d -o CMakeFiles/collision.dir/src/collision.cpp.o -c /home/james/projects/2d_fighting_test/src/collision.cpp

CMakeFiles/collision.dir/src/collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/collision.dir/src/collision.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/2d_fighting_test/src/collision.cpp > CMakeFiles/collision.dir/src/collision.cpp.i

CMakeFiles/collision.dir/src/collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/collision.dir/src/collision.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/2d_fighting_test/src/collision.cpp -o CMakeFiles/collision.dir/src/collision.cpp.s

# Object files for target collision
collision_OBJECTS = \
"CMakeFiles/collision.dir/src/collision.cpp.o"

# External object files for target collision
collision_EXTERNAL_OBJECTS =

libcollision.a: CMakeFiles/collision.dir/src/collision.cpp.o
libcollision.a: CMakeFiles/collision.dir/build.make
libcollision.a: CMakeFiles/collision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcollision.a"
	$(CMAKE_COMMAND) -P CMakeFiles/collision.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/collision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/collision.dir/build: libcollision.a
.PHONY : CMakeFiles/collision.dir/build

CMakeFiles/collision.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/collision.dir/cmake_clean.cmake
.PHONY : CMakeFiles/collision.dir/clean

CMakeFiles/collision.dir/depend:
	cd /home/james/projects/2d_fighting_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build/CMakeFiles/collision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/collision.dir/depend
