# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\maslo\Desktop\test\BinnarySearchTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\maslo\Desktop\test\BinnarySearchTree\build

# Include any dependencies generated for this target.
include CMakeFiles/binnarySearchTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/binnarySearchTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/binnarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binnarySearchTree.dir/flags.make

CMakeFiles/binnarySearchTree.dir/main.cpp.obj: CMakeFiles/binnarySearchTree.dir/flags.make
CMakeFiles/binnarySearchTree.dir/main.cpp.obj: C:/Users/maslo/Desktop/test/BinnarySearchTree/main.cpp
CMakeFiles/binnarySearchTree.dir/main.cpp.obj: CMakeFiles/binnarySearchTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maslo\Desktop\test\BinnarySearchTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binnarySearchTree.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/binnarySearchTree.dir/main.cpp.obj -MF CMakeFiles\binnarySearchTree.dir\main.cpp.obj.d -o CMakeFiles\binnarySearchTree.dir\main.cpp.obj -c C:\Users\maslo\Desktop\test\BinnarySearchTree\main.cpp

CMakeFiles/binnarySearchTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binnarySearchTree.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\maslo\Desktop\test\BinnarySearchTree\main.cpp > CMakeFiles\binnarySearchTree.dir\main.cpp.i

CMakeFiles/binnarySearchTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binnarySearchTree.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\maslo\Desktop\test\BinnarySearchTree\main.cpp -o CMakeFiles\binnarySearchTree.dir\main.cpp.s

# Object files for target binnarySearchTree
binnarySearchTree_OBJECTS = \
"CMakeFiles/binnarySearchTree.dir/main.cpp.obj"

# External object files for target binnarySearchTree
binnarySearchTree_EXTERNAL_OBJECTS =

binnarySearchTree.exe: CMakeFiles/binnarySearchTree.dir/main.cpp.obj
binnarySearchTree.exe: CMakeFiles/binnarySearchTree.dir/build.make
binnarySearchTree.exe: CMakeFiles/binnarySearchTree.dir/linklibs.rsp
binnarySearchTree.exe: CMakeFiles/binnarySearchTree.dir/objects1.rsp
binnarySearchTree.exe: CMakeFiles/binnarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\maslo\Desktop\test\BinnarySearchTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binnarySearchTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\binnarySearchTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binnarySearchTree.dir/build: binnarySearchTree.exe
.PHONY : CMakeFiles/binnarySearchTree.dir/build

CMakeFiles/binnarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\binnarySearchTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/binnarySearchTree.dir/clean

CMakeFiles/binnarySearchTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maslo\Desktop\test\BinnarySearchTree C:\Users\maslo\Desktop\test\BinnarySearchTree C:\Users\maslo\Desktop\test\BinnarySearchTree\build C:\Users\maslo\Desktop\test\BinnarySearchTree\build C:\Users\maslo\Desktop\test\BinnarySearchTree\build\CMakeFiles\binnarySearchTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binnarySearchTree.dir/depend

