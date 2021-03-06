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
CMAKE_SOURCE_DIR = /home/brujackie-zhang/workspace/opencv/stitch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brujackie-zhang/workspace/opencv/stitch

# Include any dependencies generated for this target.
include CMakeFiles/stitch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stitch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stitch.dir/flags.make

CMakeFiles/stitch.dir/stitch.cpp.o: CMakeFiles/stitch.dir/flags.make
CMakeFiles/stitch.dir/stitch.cpp.o: stitch.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brujackie-zhang/workspace/opencv/stitch/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/stitch.dir/stitch.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/stitch.dir/stitch.cpp.o -c /home/brujackie-zhang/workspace/opencv/stitch/stitch.cpp

CMakeFiles/stitch.dir/stitch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stitch.dir/stitch.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brujackie-zhang/workspace/opencv/stitch/stitch.cpp > CMakeFiles/stitch.dir/stitch.cpp.i

CMakeFiles/stitch.dir/stitch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stitch.dir/stitch.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brujackie-zhang/workspace/opencv/stitch/stitch.cpp -o CMakeFiles/stitch.dir/stitch.cpp.s

CMakeFiles/stitch.dir/stitch.cpp.o.requires:
.PHONY : CMakeFiles/stitch.dir/stitch.cpp.o.requires

CMakeFiles/stitch.dir/stitch.cpp.o.provides: CMakeFiles/stitch.dir/stitch.cpp.o.requires
	$(MAKE) -f CMakeFiles/stitch.dir/build.make CMakeFiles/stitch.dir/stitch.cpp.o.provides.build
.PHONY : CMakeFiles/stitch.dir/stitch.cpp.o.provides

CMakeFiles/stitch.dir/stitch.cpp.o.provides.build: CMakeFiles/stitch.dir/stitch.cpp.o

# Object files for target stitch
stitch_OBJECTS = \
"CMakeFiles/stitch.dir/stitch.cpp.o"

# External object files for target stitch
stitch_EXTERNAL_OBJECTS =

stitch: CMakeFiles/stitch.dir/stitch.cpp.o
stitch: CMakeFiles/stitch.dir/build.make
stitch: /usr/local/lib/libopencv_videostab.so.2.4.9
stitch: /usr/local/lib/libopencv_ts.a
stitch: /usr/local/lib/libopencv_superres.so.2.4.9
stitch: /usr/local/lib/libopencv_stitching.so.2.4.9
stitch: /usr/local/lib/libopencv_contrib.so.2.4.9
stitch: /usr/local/lib/libopencv_nonfree.so.2.4.9
stitch: /usr/local/lib/libopencv_ocl.so.2.4.9
stitch: /usr/local/lib/libopencv_gpu.so.2.4.9
stitch: /usr/local/lib/libopencv_photo.so.2.4.9
stitch: /usr/local/lib/libopencv_objdetect.so.2.4.9
stitch: /usr/local/lib/libopencv_legacy.so.2.4.9
stitch: /usr/local/lib/libopencv_video.so.2.4.9
stitch: /usr/local/lib/libopencv_ml.so.2.4.9
stitch: /usr/local/lib/libopencv_calib3d.so.2.4.9
stitch: /usr/local/lib/libopencv_features2d.so.2.4.9
stitch: /usr/local/lib/libopencv_highgui.so.2.4.9
stitch: /usr/local/lib/libopencv_imgproc.so.2.4.9
stitch: /usr/local/lib/libopencv_flann.so.2.4.9
stitch: /usr/local/lib/libopencv_core.so.2.4.9
stitch: CMakeFiles/stitch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable stitch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stitch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stitch.dir/build: stitch
.PHONY : CMakeFiles/stitch.dir/build

CMakeFiles/stitch.dir/requires: CMakeFiles/stitch.dir/stitch.cpp.o.requires
.PHONY : CMakeFiles/stitch.dir/requires

CMakeFiles/stitch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stitch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stitch.dir/clean

CMakeFiles/stitch.dir/depend:
	cd /home/brujackie-zhang/workspace/opencv/stitch && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brujackie-zhang/workspace/opencv/stitch /home/brujackie-zhang/workspace/opencv/stitch /home/brujackie-zhang/workspace/opencv/stitch /home/brujackie-zhang/workspace/opencv/stitch /home/brujackie-zhang/workspace/opencv/stitch/CMakeFiles/stitch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stitch.dir/depend

