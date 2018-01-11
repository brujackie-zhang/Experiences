# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brujackie-zhang/workspace/opencv/Seam_Carving

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brujackie-zhang/workspace/opencv/Seam_Carving

# Include any dependencies generated for this target.
include CMakeFiles/seam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/seam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seam.dir/flags.make

CMakeFiles/seam.dir/Seam_Carving.cpp.o: CMakeFiles/seam.dir/flags.make
CMakeFiles/seam.dir/Seam_Carving.cpp.o: Seam_Carving.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brujackie-zhang/workspace/opencv/Seam_Carving/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/seam.dir/Seam_Carving.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seam.dir/Seam_Carving.cpp.o -c /home/brujackie-zhang/workspace/opencv/Seam_Carving/Seam_Carving.cpp

CMakeFiles/seam.dir/Seam_Carving.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seam.dir/Seam_Carving.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brujackie-zhang/workspace/opencv/Seam_Carving/Seam_Carving.cpp > CMakeFiles/seam.dir/Seam_Carving.cpp.i

CMakeFiles/seam.dir/Seam_Carving.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seam.dir/Seam_Carving.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brujackie-zhang/workspace/opencv/Seam_Carving/Seam_Carving.cpp -o CMakeFiles/seam.dir/Seam_Carving.cpp.s

CMakeFiles/seam.dir/Seam_Carving.cpp.o.requires:

.PHONY : CMakeFiles/seam.dir/Seam_Carving.cpp.o.requires

CMakeFiles/seam.dir/Seam_Carving.cpp.o.provides: CMakeFiles/seam.dir/Seam_Carving.cpp.o.requires
	$(MAKE) -f CMakeFiles/seam.dir/build.make CMakeFiles/seam.dir/Seam_Carving.cpp.o.provides.build
.PHONY : CMakeFiles/seam.dir/Seam_Carving.cpp.o.provides

CMakeFiles/seam.dir/Seam_Carving.cpp.o.provides.build: CMakeFiles/seam.dir/Seam_Carving.cpp.o


# Object files for target seam
seam_OBJECTS = \
"CMakeFiles/seam.dir/Seam_Carving.cpp.o"

# External object files for target seam
seam_EXTERNAL_OBJECTS =

seam: CMakeFiles/seam.dir/Seam_Carving.cpp.o
seam: CMakeFiles/seam.dir/build.make
seam: /usr/local/lib/libopencv_videostab.so.2.4.9
seam: /usr/local/lib/libopencv_ts.a
seam: /usr/local/lib/libopencv_superres.so.2.4.9
seam: /usr/local/lib/libopencv_stitching.so.2.4.9
seam: /usr/local/lib/libopencv_contrib.so.2.4.9
seam: /usr/local/lib/libopencv_nonfree.so.2.4.9
seam: /usr/local/lib/libopencv_ocl.so.2.4.9
seam: /usr/local/lib/libopencv_gpu.so.2.4.9
seam: /usr/local/lib/libopencv_photo.so.2.4.9
seam: /usr/local/lib/libopencv_objdetect.so.2.4.9
seam: /usr/local/lib/libopencv_legacy.so.2.4.9
seam: /usr/local/lib/libopencv_video.so.2.4.9
seam: /usr/local/lib/libopencv_ml.so.2.4.9
seam: /usr/local/lib/libopencv_calib3d.so.2.4.9
seam: /usr/local/lib/libopencv_features2d.so.2.4.9
seam: /usr/local/lib/libopencv_highgui.so.2.4.9
seam: /usr/local/lib/libopencv_imgproc.so.2.4.9
seam: /usr/local/lib/libopencv_flann.so.2.4.9
seam: /usr/local/lib/libopencv_core.so.2.4.9
seam: CMakeFiles/seam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/brujackie-zhang/workspace/opencv/Seam_Carving/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable seam"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seam.dir/build: seam

.PHONY : CMakeFiles/seam.dir/build

CMakeFiles/seam.dir/requires: CMakeFiles/seam.dir/Seam_Carving.cpp.o.requires

.PHONY : CMakeFiles/seam.dir/requires

CMakeFiles/seam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/seam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/seam.dir/clean

CMakeFiles/seam.dir/depend:
	cd /home/brujackie-zhang/workspace/opencv/Seam_Carving && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brujackie-zhang/workspace/opencv/Seam_Carving /home/brujackie-zhang/workspace/opencv/Seam_Carving /home/brujackie-zhang/workspace/opencv/Seam_Carving /home/brujackie-zhang/workspace/opencv/Seam_Carving /home/brujackie-zhang/workspace/opencv/Seam_Carving/CMakeFiles/seam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seam.dir/depend

