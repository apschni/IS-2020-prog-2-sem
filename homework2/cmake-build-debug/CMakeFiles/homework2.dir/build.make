# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/artem/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/artem/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework2.dir/flags.make

CMakeFiles/homework2.dir/main.cpp.o: CMakeFiles/homework2.dir/flags.make
CMakeFiles/homework2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homework2.dir/main.cpp.o -c /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/main.cpp

CMakeFiles/homework2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/main.cpp > CMakeFiles/homework2.dir/main.cpp.i

CMakeFiles/homework2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/main.cpp -o CMakeFiles/homework2.dir/main.cpp.s

CMakeFiles/homework2.dir/Polynomial.cpp.o: CMakeFiles/homework2.dir/flags.make
CMakeFiles/homework2.dir/Polynomial.cpp.o: ../Polynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/homework2.dir/Polynomial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homework2.dir/Polynomial.cpp.o -c /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/Polynomial.cpp

CMakeFiles/homework2.dir/Polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework2.dir/Polynomial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/Polynomial.cpp > CMakeFiles/homework2.dir/Polynomial.cpp.i

CMakeFiles/homework2.dir/Polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework2.dir/Polynomial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/Polynomial.cpp -o CMakeFiles/homework2.dir/Polynomial.cpp.s

# Object files for target homework2
homework2_OBJECTS = \
"CMakeFiles/homework2.dir/main.cpp.o" \
"CMakeFiles/homework2.dir/Polynomial.cpp.o"

# External object files for target homework2
homework2_EXTERNAL_OBJECTS =

homework2: CMakeFiles/homework2.dir/main.cpp.o
homework2: CMakeFiles/homework2.dir/Polynomial.cpp.o
homework2: CMakeFiles/homework2.dir/build.make
homework2: CMakeFiles/homework2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable homework2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework2.dir/build: homework2

.PHONY : CMakeFiles/homework2.dir/build

CMakeFiles/homework2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework2.dir/clean

CMakeFiles/homework2.dir/depend:
	cd /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2 /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2 /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug /home/artem/CLionProjects/IS-2020-prog-2-sem/homework2/cmake-build-debug/CMakeFiles/homework2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework2.dir/depend

