# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/brujackie-zhang/workspace/opencv/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brujackie-zhang/workspace/opencv/Test

# Include any dependencies generated for this target.
include CMakeFiles/a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.dir/flags.make

CMakeFiles/a.dir/test.cpp.o: CMakeFiles/a.dir/flags.make
CMakeFiles/a.dir/test.cpp.o: test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brujackie-zhang/workspace/opencv/Test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/a.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/a.dir/test.cpp.o -c /home/brujackie-zhang/workspace/opencv/Test/test.cpp

CMakeFiles/a.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brujackie-zhang/workspace/opencv/Test/test.cpp > CMakeFiles/a.dir/test.cpp.i

CMakeFiles/a.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brujackie-zhang/workspace/opencv/Test/test.cpp -o CMakeFiles/a.dir/test.cpp.s

CMakeFiles/a.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/a.dir/test.cpp.o.requires

CMakeFiles/a.dir/test.cpp.o.provides: CMakeFiles/a.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.dir/build.make CMakeFiles/a.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/a.dir/test.cpp.o.provides

CMakeFiles/a.dir/test.cpp.o.provides.build: CMakeFiles/a.dir/test.cpp.o

# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/test.cpp.o"

# External object files for target a
a_EXTERNAL_OBJECTS =

a : CMakeFiles/a.dir/test.cpp.o
a : CMakeFiles/a.dir/build.make
a : /usr/local/lib/libopencv_videostab.so.2.4.9
a : /usr/local/lib/libopencv_ts.a
a : /usr/local/lib/libopencv_superres.so.2.4.9
a : /usr/local/lib/libopencv_stitching.so.2.4.9
a : /usr/local/lib/libopencv_contrib.so.2.4.9
a : /usr/local/lib/libopencv_nonfree.so.2.4.9
a : /usr/local/lib/libopencv_ocl.so.2.4.9
a : /usr/local/lib/libopencv_gpu.so.2.4.9
a : /usr/local/lib/libopencv_photo.so.2.4.9
a : /usr/local/lib/libopencv_objdetect.so.2.4.9
a : /usr/local/lib/libopencv_legacy.so.2.4.9
a : /usr/local/lib/libopencv_video.so.2.4.9
a : /usr/local/lib/libopencv_ml.so.2.4.9
a : /usr/local/lib/libopencv_calib3d.so.2.4.9
a : /usr/local/lib/libopencv_features2d.so.2.4.9
a : /usr/local/lib/libopencv_highgui.so.2.4.9
a : /usr/local/lib/libopencv_imgproc.so.2.4.9
a : /usr/local/lib/libopencv_flann.so.2.4.9
a : /usr/local/lib/libopencv_core.so.2.4.9
a : CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.dir/build: a
.PHONY : CMakeFiles/a.dir/build

CMakeFiles/a.dir/requires: CMakeFiles/a.dir/test.cpp.o.requires
.PHONY : CMakeFiles/a.dir/requires

CMakeFiles/a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.dir/clean

CMakeFiles/a.dir/depend:
	cd /home/brujackie-zhang/workspace/opencv/Test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brujackie-zhang/workspace/opencv/Test /home/brujackie-zhang/workspace/opencv/Test /home/brujackie-zhang/workspace/opencv/Test /home/brujackie-zhang/workspace/opencv/Test /home/brujackie-zhang/workspace/opencv/Test/CMakeFiles/a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.dir/depend

