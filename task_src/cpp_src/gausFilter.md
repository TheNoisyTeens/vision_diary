## [高斯滤波(GaussianFilter)原理及C++实现](http://t.csdn.cn/YZQOg)


```cpp
///
//x，y方向联合实现获取高斯模板
//
void generateGaussMask(cv::Mat& Mask,cv::Size wsize, double sigma){
	Mask.create(wsize,CV_64F);
	int h = wsize.height;
	int w = wsize.width;
	int center_h = (h - 1) / 2;
	int center_w = (w - 1) / 2;
	double sum = 0.0;
	double x, y;
	for (int i = 0; i < h; ++i){
		y = pow(i - center_h, 2);
		for (int j = 0; j < w; ++j){
			x = pow(j - center_w, 2);
			//因为最后都要归一化的，常数部分可以不计算，也减少了运算量
			double g = exp(-(x + y) / (2 * sigma*sigma));
			Mask.at<double>(i, j) = g;
			sum += g;
		}
	}
	Mask = Mask / sum;
}
```
1. `pow()`函数
```cpp
pow(a,b);//计算a的b次方
```
计算次方

2. [static_cast](http://t.csdn.cn/0cISE)

static_cast**使用方式**：

    static_cast< new_type >(expression)  

* new_type为目标数据类型
* expression为原始数据类型变量或者表达式。  
>相当于传统的C语言里的强制转换，该运算符把expression转换为new_type类型


3.  [cv::Size](http://t.csdn.cn/Oc1XC)

size类中的两个数据成员叫做w i d t h widthwidth和h e i g h t heightheight，

4. 图像初始化
```cpp
dst = cv::Mat::zeros(src.size(), src.type());
```

5. 
```cpp
//初始化一个图像，存放高斯滤波后的结果
Mat  dst  =  cv::Mat::zeros(src.size(),src.type());
```

6. 记得类型转换
```cpp
Vec3b  rgb  =  {  static_cast<uchar>(sum[0]),  static_cast<uchar>(sum[1]),  static_cast<uchar>(sum[2])  };
```

7. 边界填充
```cpp
Mat Newsrc;
copyMakeBorder(src,Newsrc,center_i,center_i,center_j,center_j,cv::BORDER_REPLICATE);//边界复制
```
8. 卷积操作索引思路
```cpp
for(int i=0;i<img_h;i++)
     for (int r = -1; r <= 1; ++r)
          for (int c = -1; c <= 1; ++c)
          {                  
               gx[i][j] += Newsrc.at<uchar>(i + r, j + c) * sobel_x[r+1][c+1];
          }      
```
















#### 注意
C++没有对矩阵的操作

