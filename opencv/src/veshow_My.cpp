#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*-----------��ʾ��Ƶ����������ͷ���棩---------*/

    VideoCapture capture("C:/Users/86157/Videos/TNT/TNT.mp4");
    while (1)
    {

        Mat frame;    // ����һ��Mat���������ڴ洢ÿһ֡��ͼ��
        capture >> frame;    // ��ȡ��ǰ֡

        // ����Ƶ������ɣ��˳�ѭ��
        if (frame.empty())
        {
            break;
        }

        imshow("video player", frame);    // ��ʾ��ǰ֡
        char c = waitKey(10);    // ��ʱ10ms
        if (c == 27) break;    //�������Esc��������ѭ������ֹ������Ƶ
    }

    return 0;
}

