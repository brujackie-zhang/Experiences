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
CMAKE_SOURCE_DIR = /home/brujackie-zhang/workspace/opencv/Contrast_Bright

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brujackie-zhang/workspace/opencv/Contrast_Bright

# Include any dependencies generated for this target.
include CMakeFiles/basic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic.dir/flags.make

CMakeFiles/basic.dir/Contrast_Bright.cpp.o: CMakeFiles/basic.dir/flags.make
CMakeFiles/basic.dir/Contrast_Bright.cpp.o: Contrast_Bright.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brujackie-zhang/workspace/opencv/Contrast_Bright/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/basic.dir/Contrast_Bright.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/basic.dir/Contrast_Bright.cpp.o -c /home/brujackie-zhang/workspace/opencv/Contrast_Bright/Contrast_Bright.cpp

CMakeFiles/basic.dir/Contrast_Bright.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic.dir/Contrast_Bright.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brujackie-zhang/workspace/opencv/Contrast_Bright/Contrast_Bright.cpp > CMakeFiles/basic.dir/Contrast_Bright.cpp.i

CMakeFiles/basic.dir/Contrast_Bright.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic.dir/Contrast_Bright.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brujackie-zhang/workspace/opencv/Contrast_Bright/Contrast_Bright.cpp -o CMakeFiles/basic.dir/Contrast_Bright.cpp.s

CMakeFiles/basic.dir/Contrast_Bright.cpp.o.requires:
.PHONY : CMakeFiles/basic.dir/Contrast_Bright.cpp.o.requires

CMakeFiles/basic.dir/Contrast_Bright.cpp.o.provides: CMakeFiles/basic.dir/Contrast_Bright.cpp.o.requires
	$(MAKE) -f CMakeFiles/basic.dir/build.make CMakeFiles/basic.dir/Contrast_Bright.cpp.o.provides.build
.PHONY : CMakeFiles/basic.dir/Contrast_Bright.cpp.o.provides

CMakeFiles/basic.dir/Contrast_Bright.cpp.o.provides.build: CMakeFiles/basic.dir/Contrast_Bright.cpp.o

# Object files for target basic
basic_OBJECTS = \
"CMakeFiles/basic.dir/Contrast_Bright.cpp.o"

# External object files for target basic
basic_EXTERNAL_OBJECTS =

basic: CMakeFiles/basic.dir/Contrast_Bright.cpp.o
basic: CMakeFiles/basic.dir/build.make
basic: /usr/local/lib/libopencv_videostab.so.2.4.9
basic: /usr/local/lib/libopencv_ts.a
basic: /usr/local/lib/libopencv_superres.so.2.4.9
basic: /usr/local/lib/libopencv_stitching.so.2.4.9
basic: /usr/local/lib/libopencv_contrib.so.2.4.9
basic: /usr/local/lib/libopencv_nonfree.so.2.4.9
basic: /usr/local/lib/libopencv_ocl.so.2.4.9
basic: /usr/local/lib/libopencv_gpu.so.2.4.9
basic: /usr/local/lib/libopencv_photo.so.2.4.9
basic: /usr/local/lib/libopencv_objdetect.so.2.4.9
basic: /usr/local/lib/libopencv_legacy.so.2.4.9
basic: /usr/local/lib/libopencv_video.so.2.4.9
basic: /usr/local/lib/libopencv_ml.so.2.4.9
basic: /usr/local/lib/libopencv_calib3d.so.2.4.9
basic: /usr/local/lib/libopencv_features2d.so.2.4.9
basic: /usr/local/lib/libopencv_highgui.so.2.4.9
basic: /usr/local/lib/libopencv_imgproc.so.2.4.9
basic: /usr/local/lib/libopencv_flann.so.2.4.9
basic: /usr/local/lib/libopencv_core.so.2.4.9
basic: CMakeFiles/basic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable basic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic.dir/build: basic
.PHONY : CMakeFiles/basic.dir/build

CMakeFiles/basic.dir/requires: CMakeFiles/basic.dir/Contrast_Bright.cpp.o.requires
.PHONY : CMakeFiles/basic.dir/requires

CMakeFiles/basic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basic.dir/clean

CMakeFiles/basic.dir/depend:
	cd /home/brujackie-zhang/workspace/opencv/Contrast_Bright && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brujackie-zhang/workspace/opencv/Contrast_Bright /home/brujackie-zhang/workspace/opencv/Contrast_Bright /home/brujackie-zhang/workspace/opencv/Contrast_Bright /home/brujackie-zhang/workspace/opencv/Contrast_Bright /home/brujackie-zhang/workspace/opencv/Contrast_Bright/CMakeFiles/basic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basic.dir/depend

