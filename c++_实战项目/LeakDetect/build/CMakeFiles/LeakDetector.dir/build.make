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
CMAKE_SOURCE_DIR = /home/zy/Desktop/Till_2021_flag/LeakDetect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zy/Desktop/Till_2021_flag/LeakDetect/build

# Include any dependencies generated for this target.
include CMakeFiles/LeakDetector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeakDetector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeakDetector.dir/flags.make

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o: CMakeFiles/LeakDetector.dir/flags.make
CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o: ../src/LeakDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zy/Desktop/Till_2021_flag/LeakDetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o -c /home/zy/Desktop/Till_2021_flag/LeakDetect/src/LeakDetector.cpp

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zy/Desktop/Till_2021_flag/LeakDetect/src/LeakDetector.cpp > CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.i

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zy/Desktop/Till_2021_flag/LeakDetect/src/LeakDetector.cpp -o CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.s

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.requires:

.PHONY : CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.requires

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.provides: CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/LeakDetector.dir/build.make CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.provides.build
.PHONY : CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.provides

CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.provides.build: CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o


# Object files for target LeakDetector
LeakDetector_OBJECTS = \
"CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o"

# External object files for target LeakDetector
LeakDetector_EXTERNAL_OBJECTS =

libLeakDetector.a: CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o
libLeakDetector.a: CMakeFiles/LeakDetector.dir/build.make
libLeakDetector.a: CMakeFiles/LeakDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zy/Desktop/Till_2021_flag/LeakDetect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLeakDetector.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LeakDetector.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeakDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeakDetector.dir/build: libLeakDetector.a

.PHONY : CMakeFiles/LeakDetector.dir/build

CMakeFiles/LeakDetector.dir/requires: CMakeFiles/LeakDetector.dir/src/LeakDetector.cpp.o.requires

.PHONY : CMakeFiles/LeakDetector.dir/requires

CMakeFiles/LeakDetector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeakDetector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeakDetector.dir/clean

CMakeFiles/LeakDetector.dir/depend:
	cd /home/zy/Desktop/Till_2021_flag/LeakDetect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zy/Desktop/Till_2021_flag/LeakDetect /home/zy/Desktop/Till_2021_flag/LeakDetect /home/zy/Desktop/Till_2021_flag/LeakDetect/build /home/zy/Desktop/Till_2021_flag/LeakDetect/build /home/zy/Desktop/Till_2021_flag/LeakDetect/build/CMakeFiles/LeakDetector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LeakDetector.dir/depend

