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
include CMakeFiles/handle_global_collisions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/handle_global_collisions.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/handle_global_collisions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/handle_global_collisions.dir/flags.make

CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o: CMakeFiles/handle_global_collisions.dir/flags.make
CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o: ../src/handle_global_collisions.cpp
CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o: CMakeFiles/handle_global_collisions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o -MF CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o.d -o CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o -c /home/james/projects/2d_fighting_test/src/handle_global_collisions.cpp

CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/2d_fighting_test/src/handle_global_collisions.cpp > CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.i

CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/2d_fighting_test/src/handle_global_collisions.cpp -o CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.s

# Object files for target handle_global_collisions
handle_global_collisions_OBJECTS = \
"CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o"

# External object files for target handle_global_collisions
handle_global_collisions_EXTERNAL_OBJECTS =

libhandle_global_collisions.a: CMakeFiles/handle_global_collisions.dir/src/handle_global_collisions.cpp.o
libhandle_global_collisions.a: CMakeFiles/handle_global_collisions.dir/build.make
libhandle_global_collisions.a: CMakeFiles/handle_global_collisions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhandle_global_collisions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/handle_global_collisions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/handle_global_collisions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/handle_global_collisions.dir/build: libhandle_global_collisions.a
.PHONY : CMakeFiles/handle_global_collisions.dir/build

CMakeFiles/handle_global_collisions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/handle_global_collisions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/handle_global_collisions.dir/clean

CMakeFiles/handle_global_collisions.dir/depend:
	cd /home/james/projects/2d_fighting_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build/CMakeFiles/handle_global_collisions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/handle_global_collisions.dir/depend

