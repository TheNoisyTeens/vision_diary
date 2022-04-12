#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*-----------显示视频（电脑摄像头画面）---------*/

    VideoCapture capture("C:/Users/86157/Videos/TNT/TNT.mp4");
    while (1)
    {

        Mat frame;    // 定义一个Mat变量，用于存储每一帧的图像
        capture >> frame;    // 读取当前帧

        // 若视频播放完成，退出循环
        if (frame.empty())
        {
            break;
        }

        imshow("video player", frame);    // 显示当前帧
        char c = waitKey(10);    // 延时10ms
        if (c == 27) break;    //如果触发Esc键，跳出循环，终止播放视频
    }

    return 0;
}

