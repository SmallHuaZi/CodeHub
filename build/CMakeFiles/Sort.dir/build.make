# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build

# Include any dependencies generated for this target.
include CMakeFiles/Sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sort.dir/flags.make

CMakeFiles/Sort.dir/main.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/main.c.o: ../main.c
CMakeFiles/Sort.dir/main.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Sort.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/main.c.o -MF CMakeFiles/Sort.dir/main.c.o.d -o CMakeFiles/Sort.dir/main.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/main.c

CMakeFiles/Sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/main.c > CMakeFiles/Sort.dir/main.c.i

CMakeFiles/Sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/main.c -o CMakeFiles/Sort.dir/main.c.s

CMakeFiles/Sort.dir/sources/B_Tree.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sources/B_Tree.c.o: ../sources/B_Tree.c
CMakeFiles/Sort.dir/sources/B_Tree.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Sort.dir/sources/B_Tree.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/sources/B_Tree.c.o -MF CMakeFiles/Sort.dir/sources/B_Tree.c.o.d -o CMakeFiles/Sort.dir/sources/B_Tree.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/B_Tree.c

CMakeFiles/Sort.dir/sources/B_Tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sources/B_Tree.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/B_Tree.c > CMakeFiles/Sort.dir/sources/B_Tree.c.i

CMakeFiles/Sort.dir/sources/B_Tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sources/B_Tree.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/B_Tree.c -o CMakeFiles/Sort.dir/sources/B_Tree.c.s

CMakeFiles/Sort.dir/sources/Search.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sources/Search.c.o: ../sources/Search.c
CMakeFiles/Sort.dir/sources/Search.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Sort.dir/sources/Search.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/sources/Search.c.o -MF CMakeFiles/Sort.dir/sources/Search.c.o.d -o CMakeFiles/Sort.dir/sources/Search.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Search.c

CMakeFiles/Sort.dir/sources/Search.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sources/Search.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Search.c > CMakeFiles/Sort.dir/sources/Search.c.i

CMakeFiles/Sort.dir/sources/Search.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sources/Search.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Search.c -o CMakeFiles/Sort.dir/sources/Search.c.s

CMakeFiles/Sort.dir/sources/Sort.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sources/Sort.c.o: ../sources/Sort.c
CMakeFiles/Sort.dir/sources/Sort.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Sort.dir/sources/Sort.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/sources/Sort.c.o -MF CMakeFiles/Sort.dir/sources/Sort.c.o.d -o CMakeFiles/Sort.dir/sources/Sort.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Sort.c

CMakeFiles/Sort.dir/sources/Sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sources/Sort.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Sort.c > CMakeFiles/Sort.dir/sources/Sort.c.i

CMakeFiles/Sort.dir/sources/Sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sources/Sort.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Sort.c -o CMakeFiles/Sort.dir/sources/Sort.c.s

CMakeFiles/Sort.dir/sources/String.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sources/String.c.o: ../sources/String.c
CMakeFiles/Sort.dir/sources/String.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Sort.dir/sources/String.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/sources/String.c.o -MF CMakeFiles/Sort.dir/sources/String.c.o.d -o CMakeFiles/Sort.dir/sources/String.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/String.c

CMakeFiles/Sort.dir/sources/String.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sources/String.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/String.c > CMakeFiles/Sort.dir/sources/String.c.i

CMakeFiles/Sort.dir/sources/String.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sources/String.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/String.c -o CMakeFiles/Sort.dir/sources/String.c.s

CMakeFiles/Sort.dir/sources/Tree.c.o: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sources/Tree.c.o: ../sources/Tree.c
CMakeFiles/Sort.dir/sources/Tree.c.o: CMakeFiles/Sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Sort.dir/sources/Tree.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sort.dir/sources/Tree.c.o -MF CMakeFiles/Sort.dir/sources/Tree.c.o.d -o CMakeFiles/Sort.dir/sources/Tree.c.o -c /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Tree.c

CMakeFiles/Sort.dir/sources/Tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sources/Tree.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Tree.c > CMakeFiles/Sort.dir/sources/Tree.c.i

CMakeFiles/Sort.dir/sources/Tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sources/Tree.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/sources/Tree.c -o CMakeFiles/Sort.dir/sources/Tree.c.s

# Object files for target Sort
Sort_OBJECTS = \
"CMakeFiles/Sort.dir/main.c.o" \
"CMakeFiles/Sort.dir/sources/B_Tree.c.o" \
"CMakeFiles/Sort.dir/sources/Search.c.o" \
"CMakeFiles/Sort.dir/sources/Sort.c.o" \
"CMakeFiles/Sort.dir/sources/String.c.o" \
"CMakeFiles/Sort.dir/sources/Tree.c.o"

# External object files for target Sort
Sort_EXTERNAL_OBJECTS =

../bin/Sort: CMakeFiles/Sort.dir/main.c.o
../bin/Sort: CMakeFiles/Sort.dir/sources/B_Tree.c.o
../bin/Sort: CMakeFiles/Sort.dir/sources/Search.c.o
../bin/Sort: CMakeFiles/Sort.dir/sources/Sort.c.o
../bin/Sort: CMakeFiles/Sort.dir/sources/String.c.o
../bin/Sort: CMakeFiles/Sort.dir/sources/Tree.c.o
../bin/Sort: CMakeFiles/Sort.dir/build.make
../bin/Sort: CMakeFiles/Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable ../bin/Sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sort.dir/build: ../bin/Sort
.PHONY : CMakeFiles/Sort.dir/build

CMakeFiles/Sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sort.dir/clean

CMakeFiles/Sort.dir/depend:
	cd /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build /home/smallhuazi/VSCode/C_C++/CTest/SortAndSearch/build/CMakeFiles/Sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sort.dir/depend

