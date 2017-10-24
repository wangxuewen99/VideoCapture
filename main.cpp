#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <string>

#include "videocapture.h"

using namespace std;

void load_file(const string &filename, vector<unsigned char> &buf)
{
    ifstream ifs(filename, ifstream::in);
    if(ifs.is_open())
    {
        ifs.seekg(0, std::ios::end);
        int length = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        buf.resize(length);
        ifs.read((char*)buf.data(), length);
    }
}



void test(const string filename)
{
    vector<unsigned char> video_buf;
    load_file(filename, video_buf);

    VideoCapture cap;
    //cap.open(filename);
    cap.open(video_buf.data(), video_buf.size());
    if (!cap.isOpened())
    {
        cout << "open capture failed!" << endl;
        return;
    }

    int h = (int)cap.get(VideoCapture::CAP_PROP_FRAME_HEIGHT);
    int w = (int)cap.get(VideoCapture::CAP_PROP_FRAME_WIDTH);
    double fps = cap.get(VideoCapture::CAP_PROP_FPS);
    int n = (int)cap.get(VideoCapture::CAP_PROP_FRAME_COUNT);
    double frame_time = 1000.0 / fps;   // ms
    cv::Mat frame(h, w, CV_8UC3);
    int t0, t1;
    int wait_time;
    for(int i = 0; i < n; i++)
    {
        t0 = cv::getTickCount();
        if(cap.read(frame))
        {
            cv::imshow("frame", frame);
        }
        t1 = cv::getTickCount();
        wait_time = int(frame_time - (t1 -t0)*1000/cv::getTickFrequency());
        cv::waitKey(wait_time);
    }
}

int main()
{
    test("../data/1.mp4");
}
