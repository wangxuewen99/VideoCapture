# VideoCapture
decode frames from video file or a video memory stream using ffmpeg
## Usage
1. put your ffmpeg include files in 3rd/include and lib files in 3rd/lib
2. mkdir build & cd build
3. cmake .. & make

## about demo
1. there is a simple demo to use video capture in main.cpp
2. this demo show how to decode frames from video file use cap.open(filename)
3. this demo show how to decode frames from video file use cap.open(video_buf.data(), video_buf.size())
