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
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test/test.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test/test.cpp.o: ../test/test.cpp
CMakeFiles/tests.dir/test/test.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test/test.cpp.o -MF CMakeFiles/tests.dir/test/test.cpp.o.d -o CMakeFiles/tests.dir/test/test.cpp.o -c /home/james/projects/2d_fighting_test/test/test.cpp

CMakeFiles/tests.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/2d_fighting_test/test/test.cpp > CMakeFiles/tests.dir/test/test.cpp.i

CMakeFiles/tests.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/2d_fighting_test/test/test.cpp -o CMakeFiles/tests.dir/test/test.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test/test.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test/test.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: libspatial_hash_grid.a
tests: libgame_util.a
tests: libhandle_global_collisions.a
tests: libcollision.a
tests: libcollisions_util.a
tests: libentity.a
tests: libplayer.a
tests: libstatic_object.a
tests: libdynamic_object.a
tests: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
tests: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
tests: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
tests: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
tests: _deps/catch2-build/src/libCatch2Main.a
tests: _deps/catch2-build/src/libCatch2.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/james/projects/2d_fighting_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

