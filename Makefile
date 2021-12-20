# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/szymon/Documents/uczelnia/CPP/pro/the-binding-of-sus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/szymon/Documents/uczelnia/CPP/pro/the-binding-of-sus

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/szymon/Documents/uczelnia/CPP/pro/the-binding-of-sus/CMakeFiles /home/szymon/Documents/uczelnia/CPP/pro/the-binding-of-sus//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/szymon/Documents/uczelnia/CPP/pro/the-binding-of-sus/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gaem

# Build rule for target.
gaem: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gaem
.PHONY : gaem

# fast build rule for target.
gaem/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/build
.PHONY : gaem/fast

src/actor.o: src/actor.cpp.o
.PHONY : src/actor.o

# target to build an object file
src/actor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/actor.cpp.o
.PHONY : src/actor.cpp.o

src/actor.i: src/actor.cpp.i
.PHONY : src/actor.i

# target to preprocess a source file
src/actor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/actor.cpp.i
.PHONY : src/actor.cpp.i

src/actor.s: src/actor.cpp.s
.PHONY : src/actor.s

# target to generate assembly for a file
src/actor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/actor.cpp.s
.PHONY : src/actor.cpp.s

src/game.o: src/game.cpp.o
.PHONY : src/game.o

# target to build an object file
src/game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/game.cpp.o
.PHONY : src/game.cpp.o

src/game.i: src/game.cpp.i
.PHONY : src/game.i

# target to preprocess a source file
src/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/game.cpp.i
.PHONY : src/game.cpp.i

src/game.s: src/game.cpp.s
.PHONY : src/game.s

# target to generate assembly for a file
src/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/game.cpp.s
.PHONY : src/game.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/texture_manager.o: src/texture_manager.cpp.o
.PHONY : src/texture_manager.o

# target to build an object file
src/texture_manager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/texture_manager.cpp.o
.PHONY : src/texture_manager.cpp.o

src/texture_manager.i: src/texture_manager.cpp.i
.PHONY : src/texture_manager.i

# target to preprocess a source file
src/texture_manager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/texture_manager.cpp.i
.PHONY : src/texture_manager.cpp.i

src/texture_manager.s: src/texture_manager.cpp.s
.PHONY : src/texture_manager.s

# target to generate assembly for a file
src/texture_manager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gaem.dir/build.make CMakeFiles/gaem.dir/src/texture_manager.cpp.s
.PHONY : src/texture_manager.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... gaem"
	@echo "... src/actor.o"
	@echo "... src/actor.i"
	@echo "... src/actor.s"
	@echo "... src/game.o"
	@echo "... src/game.i"
	@echo "... src/game.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/texture_manager.o"
	@echo "... src/texture_manager.i"
	@echo "... src/texture_manager.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

