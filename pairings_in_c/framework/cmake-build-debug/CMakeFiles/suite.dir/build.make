# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/falx/Development/PET/pairings_in_c/framework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/falx/Development/PET/pairings_in_c/framework/cmake-build-debug

# Utility rule file for suite.

# Include the progress variables for this target.
include CMakeFiles/suite.dir/progress.make

suite: CMakeFiles/suite.dir/build.make

.PHONY : suite

# Rule to build all files generated by this target.
CMakeFiles/suite.dir/build: suite

.PHONY : CMakeFiles/suite.dir/build

CMakeFiles/suite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/suite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/suite.dir/clean

CMakeFiles/suite.dir/depend:
	cd /home/falx/Development/PET/pairings_in_c/framework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/falx/Development/PET/pairings_in_c/framework /home/falx/Development/PET/pairings_in_c/framework /home/falx/Development/PET/pairings_in_c/framework/cmake-build-debug /home/falx/Development/PET/pairings_in_c/framework/cmake-build-debug /home/falx/Development/PET/pairings_in_c/framework/cmake-build-debug/CMakeFiles/suite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/suite.dir/depend

