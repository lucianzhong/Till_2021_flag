# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zy/Desktop/Till_2021_flag/c++_muti_thread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zy/Desktop/Till_2021_flag/c++_muti_thread/build

# Include any dependencies generated for this target.
include CMakeFiles/parallel_quick_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parallel_quick_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallel_quick_sort.dir/flags.make

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o: CMakeFiles/parallel_quick_sort.dir/flags.make
CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o: ../src/parallel_quick_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zy/Desktop/Till_2021_flag/c++_muti_thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o -c /home/zy/Desktop/Till_2021_flag/c++_muti_thread/src/parallel_quick_sort.cpp

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zy/Desktop/Till_2021_flag/c++_muti_thread/src/parallel_quick_sort.cpp > CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.i

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zy/Desktop/Till_2021_flag/c++_muti_thread/src/parallel_quick_sort.cpp -o CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.s

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.requires:

.PHONY : CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.requires

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.provides: CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.requires
	$(MAKE) -f CMakeFiles/parallel_quick_sort.dir/build.make CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.provides.build
.PHONY : CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.provides

CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.provides.build: CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o


# Object files for target parallel_quick_sort
parallel_quick_sort_OBJECTS = \
"CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o"

# External object files for target parallel_quick_sort
parallel_quick_sort_EXTERNAL_OBJECTS =

parallel_quick_sort: CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o
parallel_quick_sort: CMakeFiles/parallel_quick_sort.dir/build.make
parallel_quick_sort: CMakeFiles/parallel_quick_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zy/Desktop/Till_2021_flag/c++_muti_thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parallel_quick_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallel_quick_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallel_quick_sort.dir/build: parallel_quick_sort

.PHONY : CMakeFiles/parallel_quick_sort.dir/build

CMakeFiles/parallel_quick_sort.dir/requires: CMakeFiles/parallel_quick_sort.dir/src/parallel_quick_sort.cpp.o.requires

.PHONY : CMakeFiles/parallel_quick_sort.dir/requires

CMakeFiles/parallel_quick_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallel_quick_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallel_quick_sort.dir/clean

CMakeFiles/parallel_quick_sort.dir/depend:
	cd /home/zy/Desktop/Till_2021_flag/c++_muti_thread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zy/Desktop/Till_2021_flag/c++_muti_thread /home/zy/Desktop/Till_2021_flag/c++_muti_thread /home/zy/Desktop/Till_2021_flag/c++_muti_thread/build /home/zy/Desktop/Till_2021_flag/c++_muti_thread/build /home/zy/Desktop/Till_2021_flag/c++_muti_thread/build/CMakeFiles/parallel_quick_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallel_quick_sort.dir/depend

