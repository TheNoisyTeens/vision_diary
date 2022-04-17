## 高斯滤波
>一维高斯分布，即正态分布

\* [pytorch之torch.nn.Conv2d()函数详解](http://t.csdn.cn/BygGs)【卷积】
\* [参数padding](http://t.csdn.cn/3ulZv)
\*[torch.randn()](http://t.csdn.cn/iO4uK)

---
* look：
[构建一维垂直方向上的高斯卷积核的函数](http://t.csdn.cn/YidST)
[高斯滤波详解 python实现高斯滤波](http://t.csdn.cn/c0TpW)

---

## OpenCV高斯滤波器详解及代码实现
**注意**: 高斯滤波是将二维高斯正态分布放在图像矩阵上做卷积运算。考虑的是邻域内像素值的空间距离关系，因此对彩色图像处理时应分通道进行操作，也就是说操作的图像原矩阵时**用单通道数据，最后合并为彩色图像**。

在卷积运算中，用到的公式是：  
g(i, j) = ∑ f(i-k, j-l)h(k, l) 。其中 k，l代表核上的坐标。而核的坐标明显与数组下标不一致。因此，我们需**要做一个转换以满足用数组下标来访问该核的数据**。

高斯滤波原理就是将上图的二维正态分布应用在二维的矩阵上，G(x,y)的值就是矩阵上的权值，将得到的权值进行归一化，**将权值的范围约束在[0,1]之间，并且所有的值的总和为1**。


---

#### void gaussian(cv::Mat *_src, double **_array, int _size)
```cpp
 // [2] 忽略边缘
if (i > (_size / 2) - 1 && j > (_size / 2) - 1 && i < (*_src).rows - (_size / 2) && j < (*_src).cols - (_size / 2)) {

}
```
```cpp
// 放入中间结果,计算所得的值与没有计算的值不能混用 
temp.ptr<uchar>(i)[j] = sum;
//temp.at<uchar>(i,j) = sum;//我觉得也行
```
```cpp
// [1] 扫描
    for (int i = 0; i < (*_src).rows; i++) 
    {
        for (int j = 0; j < (*_src).cols; j++) 
        {
            // [2] 忽略边缘
            if (i > (_size / 2) - 1 && j > (_size / 2) - 1 &&
                i < (*_src).rows - (_size / 2) && j < (*_src).cols - (_size / 2)) {
                // [3] 找到图像输入点f(i,j),以输入点为中心与核中心对齐
                //     核心为中心参考点 卷积算子=>高斯矩阵180度转向计算
                //     x y 代表卷积核的权值坐标   i j 代表图像输入点坐标
                //     卷积算子     (f*g)(i,j) = f(i-k,j-l)g(k,l)          f代表图像输入 g代表核
                //     带入核参考点 (f*g)(i,j) = f(i-(k-ai), j-(l-aj))g(k,l)   ai,aj 核参考点
                //     加权求和  注意：核的坐标以左上0,0起点
                double sum = 0.0;
                for (int k = 0; k < _size; k++) {
                    for (int l = 0; l < _size; l++) {
                        sum += (*_src).ptr<uchar>(i-k+(_size/2))[j-l+(_size/2)] * _array[k][l];
                    }
                }
                // 放入中间结果,计算所得的值与没有计算的值不能混用
                temp.ptr<uchar>(i)[j] = sum;
            }
        }
//(i-k+(_size/2))[j-l+(_size/2)]*_array[k][l]
//(i-k+(_size/2))[j-l+(_size/2)]，坐标表示方法（卷积相关）
```
#### double **getGaussianArray(int arr_size, double sigma)

```cpp
// [2] 高斯分布计算
    int center_i, center_j;
    center_i = center_j = arr_size / 2;
    
    for (i = 0; i < arr_size; i++ ) 
    {
        for (j = 0; j < arr_size; j++)
        {
            (i-center_i,j-center_j) //坐标表示方法                                                           
	    }
    }
```

#### void myGaussianFilter(cv::Mat *src, cv::Mat *dst, int n, double sigma)
彩色图像通道分离处理，每个通道都进行高斯滤波，最后合并
```cpp
    // [1] 初始化
    *dst = (*src).clone();
    // [2] 彩色图片通道分离
    std::vector<cv::Mat> channels;
    cv::split(*src, channels);
    // [3] 滤波
    // [3-1] 确定高斯正态矩阵
    double **array = getGaussianArray(n, sigma);
    // [3-2] 高斯滤波处理
    for (int i = 0; i < 3; i++) {
        gaussian(&channels[i], array, n);
    }
    // [4] 合并返回
    cv::merge(channels, *dst);

```
————————————————
原文链接：https://blog.csdn.net/qq_36359022/article/details/80154900
