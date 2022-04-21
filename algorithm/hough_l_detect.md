### 霍夫变换直线检测（Line Detection）原理及示例
### 霍夫变换（Hough Transform）
霍夫变换**运用两个坐标空间之间的变换**，将在一个空间中具有相同形状的曲线或直线映射到另一个坐标空间的一个点上形成峰值，从而把检测任意形状的问题转化为**统计峰值问题**。
>再结合我的笔记看看

### 霍夫直线检测（Hough Line Detection）

> Hough直线检测的基本原理在于利用点与线的对偶性，在我们的直线检测任务中，即图像空间中的直线与参数空间中的点是一一对应的，参数空间中的直线与图像空间中的点也是一一对应的。这意味着我们可以得出两个非常有用的结论：
1）图像空间中的每条直线在参数空间中都对应着单独一个点来表示；
2）图像空间中的直线上任何一部分线段在参数空间对应的是同一个点。
因此Hough直线检测算法就是把在图像空间中的直线检测问题转换到参数空间中对点的检测问题，通过在参数空间里寻找峰值来完成直线检测任务。

————————————————
[原文链接](https://blog.csdn.net/leonardohaig/article/details/87907462)很nice

---
* 看不懂：
1. 霍夫直线检测（Hough Line Detection）

> Hough直线检测的基本原理在于利用点与线的对偶性，在我们的直线检测任务中，即图像空间中的直线与参数空间中的点是一一对应的，参数空间中的直线与图像空间中的点也是一一对应的。这意味着我们可以得出两个非常有用的结论：
1）图像空间中的每条直线在参数空间中都对应着单独一个点来表示；
2）图像空间中的直线上任何一部分线段在参数空间对应的是同一个点。
因此Hough直线检测算法就是把在图像空间中的直线检测问题转换到参数空间中对点的检测问题，通过在参数空间里寻找峰值来完成直线检测任务。

2. 步骤
5.映射到霍夫空间（准备两个容器，一个用来展示hough-space概况，一个数组hough-space用来储存voting的值，因为投票过程往往有某个极大值超过阈值，多达几千，不能直接用灰度图来记录投票信息）  
6.取局部极大值，设定阈值，过滤干扰直线  
7.绘制直线、标定角点

3. 


----
### [霍夫(Hough)直线变换（直线检测）](http://t.csdn.cn/xAbvA)
>python
### 原理
首先将一条直线用一个点表示，这样用一个点表示直线上所有的点，一开始人们使用斜截式y=kx+q中的（k，q）来表示一条直线，变换后的空间成为霍夫空间。即：**笛卡尔坐标系中一条直线，对应霍夫空间的一个点**。

反过来同样成立（霍夫空间的一条直线，对应笛卡尔坐标系的一个点）

共线只有一种取值可能












---
### [源码分析](http://t.csdn.cn/d1aoc)
----
### [使用Point类](http://t.csdn.cn/CYH4n)
>俗称点类

----
### [补充](https://blog.csdn.net/yukinoai/article/details/88366564)
利用滑动条调节：
-   **threshold**：阈值，只有获得足够交点的极坐标点才被看成是直线

-   **minLineLength**：最小直线长度，比这个短的线都会被忽略。
-   **maxLineGap**：最大间隔，如果小于此值，这两条直线 就被看成是一条直线。
```python
WindowName = 'Approx'  # 窗口名
cv2.namedWindow(WindowName, cv2.WINDOW_AUTOSIZE)  # 建立空窗口
 
cv2.createTrackbar('threshold', WindowName, 0, 100, nothing)  # 创建滑动条
cv2.createTrackbar('minLineLength', WindowName, 0, 100, nothing)  # 创建滑动条
cv2.createTrackbar('maxLineGap', WindowName, 0, 100, nothing)  # 创建滑动条
 
while(1):
    img = src.copy()
    threshold = cv2.getTrackbarPos('threshold', WindowName)  # 获取滑动条值
    minLineLength = 2 * cv2.getTrackbarPos('minLineLength', WindowName)  # 获取滑动条值
    maxLineGap = cv2.getTrackbarPos('maxLineGap', WindowName)  # 获取滑动条值
 
    lines = cv2.HoughLinesP(edges, 1, np.pi/180, threshold, minLineLength, maxLineGap)
```

