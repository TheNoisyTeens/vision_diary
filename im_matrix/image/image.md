## 图像矩阵
1. 
### 三维矩阵的理解（RGB图像的输入）
![三维矩阵](https://img-blog.csdnimg.cn/20210815111617585.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDkxNzM5MA==,size_16,color_FFFFFF,t_70)

>#### 本质原理:  
> 一张RGB格式的彩色图像可以看成是一个三维[矩阵](https://so.csdn.net/so/search?q=%E7%9F%A9%E9%98%B5&spm=1001.2101.3001.7020)，矩阵中的每一个数代表图像不同的位置上不同的颜色的亮度．但是图像存储时并不是直接存储这些三维矩阵，而是要先对其进行压缩编码再存储．因此读取图像的过程其实是先读取其压缩编码后的结果，然后将其解码的过程
---
2. 
### [Python | Numpy三维数组维度变换/提取](http://t.csdn.cn/8ltjG)
### 三维数组图形–立方体
我们可以将三维数组想象成为一个立方体，三维数组的每个维度代表着立方体的长宽高的一个，假设我们与一个三维数组a[3][3][3]，把它形象成为一个变长为3的立方体，每一个维度就是将对的边三等分，我们将第一维度理解为立方体的长，第二维度理解为宽，第三维度理解为高，想象立方体就在我们前面，一个面和我们的身体平行

a[1]：就表示立方体中间的一个水平面
a[0][0]：就表示左上角的一个和我们身体垂直的边
a[:, :,0]：表示与我们身体平行的第一个平面
>下面是数在立方体中的分布
![](https://img-blog.csdnimg.cn/20190524210555159.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3hmODk2NA==,size_8,color_FFFFFF,t_70)
### 图片中的三维数组

图片是又RGB三种颜色构成的，我们可以将它看作是一个三维数组，这个三维数组就是一个立方体，三维数组的第一维就是图片的宽度

-   a[:, :, 0]：表示R通道的长宽图片
![](https://img-blog.csdnimg.cn/20190524210907139.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3hmODk2NA==,size_8,color_FFFFFF,t_70)
————————————————
[原文链接](https://blog.csdn.net/xf8964/article/details/90524020)

---
3. 
### [Python | Numpy三维数组维度变换/提取](http://t.csdn.cn/8ltjG)
>每次使用Numpy，遇到需要从（A,B,C）三维数组中提取（A,B）、（A,C）或者（B,C）或者（A,）这几个维度数据时，如何切片(结合上文三维数组图形–立方体)


---
4. 
\-------matlab,可以参考
### [Java读取MAT文件中的三维矩阵](http://t.csdn.cn/Njp1G)
### 一、matlab保存数据

在matlab中将三维矩阵b保存到文件b.mat中，b三维矩阵如下：
![](https://img-blog.csdnimg.cn/20201128215456749.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMjYxMjUx,size_16,color_FFFFFF,t_70#pic_center)
### 三维矩阵在mat文件中的存储格式

>此处说明三维矩阵是如何在**mat文件中**存储的。在文件或内存中，我们很容易地根据行和列存储二维矩阵，但是没有很简单的办法存储三维矩阵，所以需要将三维矩阵转换为二维矩阵进行存储。

如果将三维矩阵M[W][H][D]存储为二维矩阵，则根据行优先存储和列优先存储，有以下两种方式：
![](https://img-blog.csdnimg.cn/20201128215511187.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMjYxMjUx,size_16,color_FFFFFF,t_70#pic_center)
**在mat文件，采用的是列优先的方式存储三维矩阵**
————————————————
[原文链接](https://blog.csdn.net/qq_41261251/article/details/110294260)
* 看不懂：
行优先存储和列优先存储
---

5. 
* 灰度图是2维矩阵，RGB彩色图是3维的。
>d1 d2 d3分别是rgb矩阵3个维度的大小，如果读取的file是一个彩图，那么**RGB的第3维大小就是3**；灰度图的话没有第3维，matlab会给d3赋1。

* 理解了：
RGB的第3维大小就是3



