# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug"

# Include any dependencies generated for this target.
include .cs211/lib/catch/CMakeFiles/catch.dir/depend.make

# Include the progress variables for this target.
include .cs211/lib/catch/CMakeFiles/catch.dir/progress.make

# Include the compile flags for this target's objects.
include .cs211/lib/catch/CMakeFiles/catch.dir/flags.make

.cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.o: .cs211/lib/catch/CMakeFiles/catch.dir/flags.make
.cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.o: ../.cs211/lib/catch/src/catch-main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object .cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.o"
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/catch.dir/src/catch-main.cxx.o -c "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/.cs211/lib/catch/src/catch-main.cxx"

.cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch.dir/src/catch-main.cxx.i"
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/.cs211/lib/catch/src/catch-main.cxx" > CMakeFiles/catch.dir/src/catch-main.cxx.i

.cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch.dir/src/catch-main.cxx.s"
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/.cs211/lib/catch/src/catch-main.cxx" -o CMakeFiles/catch.dir/src/catch-main.cxx.s

# Object files for target catch
catch_OBJECTS = \
"CMakeFiles/catch.dir/src/catch-main.cxx.o"

# External object files for target catch
catch_EXTERNAL_OBJECTS =

.cs211/lib/catch/libcatch.a: .cs211/lib/catch/CMakeFiles/catch.dir/src/catch-main.cxx.o
.cs211/lib/catch/libcatch.a: .cs211/lib/catch/CMakeFiles/catch.dir/build.make
.cs211/lib/catch/libcatch.a: .cs211/lib/catch/CMakeFiles/catch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcatch.a"
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && $(CMAKE_COMMAND) -P CMakeFiles/catch.dir/cmake_clean_target.cmake
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/catch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
.cs211/lib/catch/CMakeFiles/catch.dir/build: .cs211/lib/catch/libcatch.a

.PHONY : .cs211/lib/catch/CMakeFiles/catch.dir/build

.cs211/lib/catch/CMakeFiles/catch.dir/clean:
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" && $(CMAKE_COMMAND) -P CMakeFiles/catch.dir/cmake_clean.cmake
.PHONY : .cs211/lib/catch/CMakeFiles/catch.dir/clean

.cs211/lib/catch/CMakeFiles/catch.dir/depend:
	cd "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp" "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/.cs211/lib/catch" "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug" "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch" "/Users/gxliu1/Documents/NU/Year 1/CS 211/fp/cmake-build-debug/.cs211/lib/catch/CMakeFiles/catch.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : .cs211/lib/catch/CMakeFiles/catch.dir/depend

