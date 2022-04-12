##  显示图像
### 一、函数解析
#### 1. `imread`函数

* 函数功能：从文件中加载图片。
* 函数结构：`imread( const String& filename, int flags = IMREAD_COLOR );`

\* 参数1：要加载的文件路径
文件路径一般分为**相对路径**和**绝对路径**。
>相对路径是指直接将图片文件存储在当前目录文件中。此时直接输入文件名即可。
例如:
```c++
imread("test.png", IMREAD_GRAYSCALE);
```
>绝对路径是指非当前目录文件下的图片文件路径，<font color='red'> 这时路径一定要加双斜杠 \ 或者 单斜杠 /，不然读不出来图片，\ 为转义字符 </font>。
```cpp
imread("F:/Cvimage/test.png", IMREAD_GRAYSCALE);
imread("F:\\Cvimage\\test.png", IMREAD_GRAYSCALE);
```
\* 参数2：读取图片的样式，其对应属性如下表所示：
![](imshow_md_files%5Cimage.png?v=1&type=image)
>通常，前三个的使用频率较高。

#### 2. namedWindow
>可以没有
* 函数功能：生成一个显示窗口，可以指定该窗口的类型。
* 调用格式为：
```cpp
nameWindow(const string& winname,int flags = WINDOW_AUTOSIZE) ;
```
\* 参数1：新建的窗口的名称。

\* 参数2：窗口的标识，一般默认为WINDOW_AUTOSIZE 。对应的属性如表所示。
![](imshow_md_files%5Cimage%20%282%29.png?v=1&type=image)
#### 3. imshow
* 函数功能：将图片显示在指定窗口。  
* 调用格式为：
```cpp
imshow(const String & winname, InputArray mat)
```
 \* 参数1：要显示图像的窗口的名字。  
\* 参数2：要显示的图像矩阵。
### 二、代码实例
```cpp
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	Mat picture = imread("test.jpg");
	if (picture.empty()) {
		printf("Could not load image...\n");
		return -1;
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", picture );
	waitKey(0);
	return 0;
}
```
* 不清楚：
	* [`Mat`类](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)
	* `mat.empty()`
	* [`waitKey(0)`](opencv/function/waitk.md)
————————————————
>[原文链接](https://blog.csdn.net/Y_YX_520/article/details/115069387)
---


