#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*---------------------------显示照片------------------------------------*/
    Mat img = imread("D:\\exam.jpg");    //读取图像，这边修改成自己的图片路径，注意使用双斜杠，\ 表示转义字符
    namedWindow("image",CV_WINDOW_NORMAL);//不一定要
    if(img.empty())//未获取到图像
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("image", img);//显示图像，第一个参数为窗口名
    waitKey(0);//参数为0，使程序暂停，等待触发一个按键操作

    return 0;
}
