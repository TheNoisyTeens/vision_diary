## 创建滑动条
### 用滑动条进行视频播放控制
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
* 帧率(fps)：每秒可输出多少帧，用1s/fps可求出一帧时间

