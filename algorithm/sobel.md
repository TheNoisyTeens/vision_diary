## sobel算子边缘检测
>**边缘检测算法**是图像处理中最为基本的问题。其目的是标志图像出亮度变化明显的点，从而反映出图像中重要变化.

**索贝尔算子**（Sobel operator）主要用作边缘检测，在技术上，它是一离散性差分算子，**用来运算图像亮度函数的灰度近似值**。
在图像的任何一点使用此算子，将会产生对应的**灰度矢量**或是其法矢量。

Sobel卷积因子为：
![![](http://hi.csdn.net/attachment/201006/11/0_1276230617fDrr.gif)](sobel_md_files%5Cimage.png?v=1&type=image)
该算子包含两组3x3的矩阵，分别为横向及纵向，将之与图像作平面卷积，即可分别得出横向及纵向的**亮度差分近似值**。如果以A代表原始图像，Gx和Gy分别是在横向及纵向的灰度偏导的近似值，其公式如下：
![](sobel_md_files%5Cimage%20%282%29.png?v=1&type=image)

><font color='red'>**注**：对于一个彩色图要先把它转换为灰度图</font>

具体计算如下：
```
Gx = (-1)*f(x-1, y-1) + 0*f(x,y-1) + 1*f(x+1,y-1)

      +(-2)*f(x-1,y) + 0*f(x,y)+2*f(x+1,y)

      +(-1)*f(x-1,y+1) + 0*f(x,y+1) + 1*f(x+1,y+1)
      
   = [f(x+1,y-1)+2*f(x+1,y)+f(x+1,y+1)]-[f(x-1,y-1)+2*f(x-1,y)+f(x-1,y+1)]

 
Gy = 1* f(x-1, y-1) + 2*f(x,y-1)+ 1*f(x+1,y-1)

      +0*f(x-1,y) 0*f(x,y) + 0*f(x+1,y)

      +(-1)*f(x-1,y+1) + (-2)*f(x,y+1) + (-1)*f(x+1, y+1)

   = [f(x-1,y-1) + 2f(x,y-1) + f(x+1,y-1)]-[f(x-1, y+1) + 2*f(x,y+1)+f(x+1,y+1)]
```
>**其中f(a,b)表示图像(a,b)点的灰度值**

 

图像的每一个像素的横向及纵向灰度值通过以下公式结合，来计算该点灰度的大小：
>对于每一个点我们可以获得两个方向的梯度，我们可以通过下面这个公式算出梯度的估计值
>
![](sobel_md_files%5Cimage%20%283%29.png?v=1&type=image)

通常，为了提高效率 使用不开平方的近似值：
![](sobel_md_files%5Cimage%20%285%29.png?v=1&type=image)

然后可用以下公式计算梯度方向：
![](sobel_md_files%5Cimage%20%284%29.png?v=1&type=image)


<font color='red'>我们定义一个**阈值Gmax**，如果G比Gmax大可以认为该点(x,y)为边缘点，则设置这个点为白色否则该点为黑色。这样我们就得到了通过边缘检测的图像</font>

Sobel算子根据像素点上下、左右邻点灰度加权差，在边缘处达到极值这一现象检测边缘。对噪声具有平滑作用，提供较为精确的边缘方向信息，边缘定位精度不够高。当对精度要求不是很高时，是一种较为常用的边缘检测方法。

>将之与图像作平面卷积?

————————————————
[原文链接](https://blog.csdn.net/tianhai110/article/details/5663756)

[原文链接(附代码)](http://t.csdn.cn/6K2ar)

---
[关于卷积](https://blog.csdn.net/chaipp0607/article/details/72236892?locationNum=9&fps=1)--look
[卷积计算过程](http://t.csdn.cn/YYFAd)--look
