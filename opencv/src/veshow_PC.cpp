#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*-----------显示视频（电脑摄像头画面）---------*/
    VideoCapture capture(0);
    // VideoCapture capture("C:/Users/86157/Videos/TNT/TNT.mp4");
    while (true)
    {
        Mat Frame;
        capture >> Frame;
        imshow("video", Frame);
        waitKey(0);
    }
    return 0;
}