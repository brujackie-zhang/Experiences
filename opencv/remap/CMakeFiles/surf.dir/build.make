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
CMAKE_SOURCE_DIR = /home/brujackie-zhang/workspace/opencv/search/surf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brujackie-zhang/workspace/opencv/search/surf

# Include any dependencies generated for this target.
include CMakeFiles/surf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/surf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/surf.dir/flags.make

CMakeFiles/surf.dir/surf.cpp.o: CMakeFiles/surf.dir/flags.make
CMakeFiles/surf.dir/surf.cpp.o: surf.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brujackie-zhang/workspace/opencv/search/surf/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/surf.dir/surf.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/surf.dir/surf.cpp.o -c /home/brujackie-zhang/workspace/opencv/search/surf/surf.cpp

CMakeFiles/surf.dir/surf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surf.dir/surf.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brujackie-zhang/workspace/opencv/search/surf/surf.cpp > CMakeFiles/surf.dir/surf.cpp.i

CMakeFiles/surf.dir/surf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surf.dir/surf.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brujackie-zhang/workspace/opencv/search/surf/surf.cpp -o CMakeFiles/surf.dir/surf.cpp.s

CMakeFiles/surf.dir/surf.cpp.o.requires:
.PHONY : CMakeFiles/surf.dir/surf.cpp.o.requires

CMakeFiles/surf.dir/surf.cpp.o.provides: CMakeFiles/surf.dir/surf.cpp.o.requires
	$(MAKE) -f CMakeFiles/surf.dir/build.make CMakeFiles/surf.dir/surf.cpp.o.provides.build
.PHONY : CMakeFiles/surf.dir/surf.cpp.o.provides

CMakeFiles/surf.dir/surf.cpp.o.provides.build: CMakeFiles/surf.dir/surf.cpp.o

# Object files for target surf
surf_OBJECTS = \
"CMakeFiles/surf.dir/surf.cpp.o"

# External object files for target surf
surf_EXTERNAL_OBJECTS =

surf: CMakeFiles/surf.dir/surf.cpp.o
surf: CMakeFiles/surf.dir/build.make
surf: /usr/local/lib/libopencv_videostab.so.2.4.9
surf: /usr/local/lib/libopencv_ts.a
surf: /usr/local/lib/libopencv_superres.so.2.4.9
surf: /usr/local/lib/libopencv_stitching.so.2.4.9
surf: /usr/local/lib/libopencv_contrib.so.2.4.9
surf: /usr/local/lib/libopencv_nonfree.so.2.4.9
surf: /usr/local/lib/libopencv_ocl.so.2.4.9
surf: /usr/local/lib/libopencv_gpu.so.2.4.9
surf: /usr/local/lib/libopencv_photo.so.2.4.9
surf: /usr/local/lib/libopencv_objdetect.so.2.4.9
surf: /usr/local/lib/libopencv_legacy.so.2.4.9
surf: /usr/local/lib/libopencv_video.so.2.4.9
surf: /usr/local/lib/libopencv_ml.so.2.4.9
surf: /usr/local/lib/libopencv_calib3d.so.2.4.9
surf: /usr/local/lib/libopencv_features2d.so.2.4.9
surf: /usr/local/lib/libopencv_highgui.so.2.4.9
surf: /usr/local/lib/libopencv_imgproc.so.2.4.9
surf: /usr/local/lib/libopencv_flann.so.2.4.9
surf: /usr/local/lib/libopencv_core.so.2.4.9
surf: CMakeFiles/surf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable surf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/surf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/surf.dir/build: surf
.PHONY : CMakeFiles/surf.dir/build

CMakeFiles/surf.dir/requires: CMakeFiles/surf.dir/surf.cpp.o.requires
.PHONY : CMakeFiles/surf.dir/requires

CMakeFiles/surf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/surf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/surf.dir/clean

CMakeFiles/surf.dir/depend:
	cd /home/brujackie-zhang/workspace/opencv/search/surf && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brujackie-zhang/workspace/opencv/search/surf /home/brujackie-zhang/workspace/opencv/search/surf /home/brujackie-zhang/workspace/opencv/search/surf /home/brujackie-zhang/workspace/opencv/search/surf /home/brujackie-zhang/workspace/opencv/search/surf/CMakeFiles/surf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/surf.dir/depend

