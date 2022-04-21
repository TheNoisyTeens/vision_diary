### 1. 创建图像
* 对于c++来说
(1) 用**Mat构造函数**

```cpp
Mat image(rows,cols,type)
```
rows为像素长
cols为像素宽
[type](http://t.csdn.cn/p5k2O)为类型，例如`CV_8UC1`
* 对于python来说用**np.zeros()初始化矩阵**
```python
image=np.zeros(Size,dtype)
```
 (2)用zeros()函数
 ```cpp
  //  [1-3]  初始化一个图像，存放高斯滤波后的结果
  Mat  dst  =  cv::Mat::zeros(src.size(),src.type());	
``` 


Size为矩阵大小
>可以是一维矩阵，也可以是二维矩阵···
>`(h,w,c)`三维矩阵
dtype为元素值类型，例如`dtype=np.uint32`

### 2. 获取图像长、宽
* 对于c++来说用类属性访问`.rows`和`.cols`
```cpp
int img_h=image.rows;
int img_w=image.cols;
```
* 对于python来说用.`shape[0]`和`shape[1]`
```python
img_h=image.shape[0]
img_w=image.shape[1]
```
