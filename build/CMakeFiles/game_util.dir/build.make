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
include CMakeFiles/game_util.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game_util.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game_util.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_util.dir/flags.make

CMakeFiles/game_util.dir/src/game_util.cpp.o: CMakeFiles/game_util.dir/flags.make
CMakeFiles/game_util.dir/src/game_util.cpp.o: ../src/game_util.cpp
CMakeFiles/game_util.dir/src/game_util.cpp.o: CMakeFiles/game_util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_util.dir/src/game_util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game_util.dir/src/game_util.cpp.o -MF CMakeFiles/game_util.dir/src/game_util.cpp.o.d -o CMakeFiles/game_util.dir/src/game_util.cpp.o -c /home/james/projects/2d_fighting_test/src/game_util.cpp

CMakeFiles/game_util.dir/src/game_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_util.dir/src/game_util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/2d_fighting_test/src/game_util.cpp > CMakeFiles/game_util.dir/src/game_util.cpp.i

CMakeFiles/game_util.dir/src/game_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_util.dir/src/game_util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/2d_fighting_test/src/game_util.cpp -o CMakeFiles/game_util.dir/src/game_util.cpp.s

# Object files for target game_util
game_util_OBJECTS = \
"CMakeFiles/game_util.dir/src/game_util.cpp.o"

# External object files for target game_util
game_util_EXTERNAL_OBJECTS =

libgame_util.a: CMakeFiles/game_util.dir/src/game_util.cpp.o
libgame_util.a: CMakeFiles/game_util.dir/build.make
libgame_util.a: CMakeFiles/game_util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/projects/2d_fighting_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgame_util.a"
	$(CMAKE_COMMAND) -P CMakeFiles/game_util.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_util.dir/build: libgame_util.a
.PHONY : CMakeFiles/game_util.dir/build

CMakeFiles/game_util.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_util.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_util.dir/clean

CMakeFiles/game_util.dir/depend:
	cd /home/james/projects/2d_fighting_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build /home/james/projects/2d_fighting_test/build/CMakeFiles/game_util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_util.dir/depend

