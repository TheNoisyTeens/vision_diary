#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*---------------------------��ʾ��Ƭ------------------------------------*/
    Mat img = imread("D:\\exam.jpg");    //��ȡͼ������޸ĳ��Լ���ͼƬ·����ע��ʹ��˫б�ܣ�\ ��ʾת���ַ�
    namedWindow("image",CV_WINDOW_NORMAL);//��һ��Ҫ
    if(img.empty())//δ��ȡ��ͼ��
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("image", img);//��ʾͼ�񣬵�һ������Ϊ������
    waitKey(0);//����Ϊ0��ʹ������ͣ���ȴ�����һ����������

    return 0;
}
