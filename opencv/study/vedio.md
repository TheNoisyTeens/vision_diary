## 播放AVI视频
### 一、前言
>使用Opencv播放视频，几乎与使用它来显示图像一样容易。

播放视频时只需要处理的新问题是如何循环地读取视频中的每一帧，以及如何从枯燥的电影视频的读取中退出该循环操作。
### 二、函数解析
#### 1. VideoCapture函数
* 函数功能：VideoCapture类的构造函数，如果传入对应的参数，可以直接打开视频文件或者要调用的摄像头。
* 构造函数：
```cpp
cv::VideoCapture::VideoCapture(const string& filename) //默认构造函数	
//实例
VideoCapture capture("test.mp4");//定义一个VideoCapture类的局部变量
//另一种方法
VideoCapture capture；//先定义一个VideoCapture类的变量
capture.open("test.mp4");//再获取视频文件
```
#### 2、isOpened函数
* 函数功能：判断视频捕捉是否已经初始化，若是，则返回true。  
* 函数：
```cpp
cv::VideoCapture::isOpened()
//实例
capture.isOpened();	
```
#### 3、release函数

* 函数功能:关闭视频文件或捕捉设备  
* 函数：
```cpp
cv::VideoCapture::release()
//实例
capture.release();
```
><font color='red'> 该方法被`Videoccapture::open()`和`Videoccapture`析构函数自动调用，因而无需再次调用</font> 。

### 三、代码实例
```cpp
#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	namedWindow("video player", WINDOW_AUTOSIZE);//创建一个窗口，尺寸设为自动调整
	//方法一
	//VideoCapture capture("C:\\Users\\15916\\Downloads\\exam.mp4");
	//方法二
	VideoCapture capture;
	capture.open("C:\\Users\\15916\\Downloads\\exam.mp4");
	
	if (!capture.isOpened()) {
		cout << "read video failed!" <<endl ;//判断是否初始化成功
	}
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
		char c=waitKey(10);    // 延时10ms
		if (c == 27) break;    //如果触发Esc键，跳出循环，终止播放视频
	}
	capture.release();//可以不加
	return 0;
}
```

>* [`Vediocapture`类](https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html)
>* `capture.release()`
>* `capture >> frame;` // 读取当前帧

————————————————
[原文链接](https://blog.csdn.net/Y_YX_520/article/details/115159519)
>* ?
>函数功能：VideoCapture类的构造函数，如果传入对应的参数，可以直接打开视频文件或者要调用的摄像头

\--------------------------------------------------------------------------------------------------------
## 用滑动条进行视频播放控制
### 一、函数解析
#### 1. createTrackbar函数
* 函数功能：创建一个具有指定名称和滑动范围的滑动条，分配一个变量值用于匹配滑块的位置，当滑块位置变化时调用相应的回调函数。创建的滑动条被显示在指定的窗口上。
* 函数：
```cpp
createTrackbar(
const String& trackbarname, 参数1：创建滑动条的名称
const String& winname, 参数2：要显示滑动条的窗口名称
int *value, 参数3：可选指针，指向整型变量，其值反映滑块的位置。在创建时，滑块的位置由这个变量定义。
int count, 参数4：滑动条的最大值，最小值始终为0
TrackbarCallback onChange = 0, 参数5：回调函数
void *userdata = 0 参数6：用户数据
)
```
**滑动条要实现怎样的功能，取决于回调函数的内容**。如果参数5和参数6均采用默认值0，实现的功能仅仅是在某一窗口上设置上了一个可滑动的滑动条，没有具体功能，仅此而已。因此回调函数是关键。
* **回调函数的格式**：
```cpp
 void(* cv::TrackbarCallback) (int pos, void *userdata)
{
}
```
#### 2. capture.get函数
* 函数功能：capture.get()是videoCapture类的一个成员函数，用于返回指定文件的属性。  
* 函数：

```cpp
cv::VideoCapture::get(int propId)
```
视频文件的属性有许多，相关属性表见[属性](https://docs.opencv.org/master/d4/d15/group__videoio__flags__base.html#gaeb8dd9c89c10a5c63c139bf7c4f5704d)

#### 3. capture.set函数

* 函数功能: 与get()函数相似，作为一个成员函数，它的功能是设置相关属性的值。  
* 函数：

```cpp
cv::VideoCapture::set(int propId, double value)	
```
  
\*  参数1：要修改的属性名称。
\* 参数2：属性的具体数值。

### 二、代码实例
```cpp
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int pos = 0;
VideoCapture cap;
 void onTrackbarSlide(int pos,void* )//回调函数
{
	cap.set(CAP_PROP_POS_FRAMES,pos); //设置当前的视频帧数与滑块位置相对应
}

int main() {
	
	cap.open("C:\\Users\\15916\\Downloads\\exam.mp4");
	if (!cap.isOpened()) {
		cout << "Play video failed!" << endl;
	}
	namedWindow("Video Player", 1);
	int frames = cap.get(CAP_PROP_FRAME_COUNT);
	createTrackbar("scrollbar", "Video Player", &pos, frames, onTrackbarSlide);//将一个名为scrollbar的滑动条显示在名为Video Player的窗口上，当滑块位置pos变化时调用回调函数onTrackbarSlide

	while (1) {
		Mat frame;
		cap>>frame;
		if (frame.empty()) break;
		imshow("Video Player", frame);
		char c=waitKey(30);
		if (c == 27) {
			break;
		}
	}
}
```
>说明：这段代码的功能是实现让视频的播放进度受滑动条的控制。
第一点：初始化进度条的位置为0；这里的滑块位置不随视频播放进度而变化。所以只要不手动调节滑块位置，会一直在0的位置。
第二点：当滑动条的位置变化时，会调用回调函数，这里的回调函数是设置视频的播放帧数为当前滑块位置所对应的数值。
第三点：通过capture.get()函数获取视频文件的总帧数，在进度条范围设置时，最大值刚好对应的是视频文件的总帧数。

#### [滑动条随视频进度前进](http://t.csdn.cn/3nm3j)
```cpp
framePos = cap.get(CV_CAP_PROP_POS_FRAMES); //获取视频帧位置
setTrackbarPos("Frame", "Video", framePos); //通过视频帧位置，来设置滑动条位置
 ```
————————————————
[原文链接](https://blog.csdn.net/Y_YX_520/article/details/115194025)

---
#### Vediocapture的属性

|属性|  属性说明|
|--|--|
|CAP_PROP_POS_MSEC|  视频文件的当前位置（毫秒）|
| CAP_PROP_POS_FRAMES | 下一个要解码/捕获的帧的基于0的索引 |
|CAP_PROP_FPS| 帧速率|
| CAP_PROP_FPS | 帧速率 |
|CAP_PROP_FRAME_COUNT|视频文件中的帧数|


---
补充：
* 一帧是十二分之一秒。每秒帧数指的就是“每秒播放的画面数

