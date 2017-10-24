cmake_minimum_required(VERSION 2.8)

project(VideoCapture)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories ("${PROJECT_SOURCE_DIR}/include"
                     "${PROJECT_SOURCE_DIR}/src"
                     "${PROJECT_SOURCE_DIR}/3rd/include")

link_directories("${PROJECT_SOURCE_DIR}/3rd/lib")

add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/src/ffdecoder.cpp"
                               "${PROJECT_SOURCE_DIR}/src/videocapture.cpp"
                               "${PROJECT_SOURCE_DIR}/main.cpp")

target_link_libraries (${PROJECT_NAME} avformat avcodec avutil swscale dl rt x264 x265 z  m opencv_core opencv_imgproc opencv_highgui pthread)

