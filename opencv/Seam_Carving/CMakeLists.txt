CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(Seam_Carving)
FIND_PACKAGE(OpenCV REQUIRED)
ADD_EXECUTABLE(seam Seam_Carving.cpp)
TARGET_LINK_LIBRARIES(seam ${OpenCV_LIBS}) 
