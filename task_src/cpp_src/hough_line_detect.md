### 拼凑
1. 二维向量存储直线？
```cpp
vector<Vec2f> lines;

float rho = lines[i][0], theta = lines[i][1];
```

2.  [cv2.line()](https://blog.csdn.net/qq_38309818/article/details/111564206)-画线条
它有五个参数:
* img：要划的线所在的图像;
* pt1：直线起点
* pt2：直线终点  （坐标分别为宽、高,opencv中图像的坐标原点在左上角）
* color：直线的颜色
* thickness=1：线条粗细,默认是1.如果一个闭合图形设置为-1，那么整个图形就会被填充。
>如:
>```cpp
>line(img, (0, 0), (511, 511), (0, 0, 255), 5)
>```

3. 但是原点到这些直线的距离不会超过 ![^{\sqrt{}^{ {x_{1}}^{2} + {y_{1}}^{2}}}](https://private.codecogs.com/gif.latex?%5E%7B%5Csqrt%7B%7D%5E%7B%20%7Bx_%7B1%7D%7D%5E%7B2%7D%20&plus;%20%7By_%7B1%7D%7D%5E%7B2%7D%7D%7D)。 图像矩阵宽度为W、 高度为H， 那么可以构造以下计数器， 用L代表整数round(![^{\sqrt{W^{^{2}} + H^{^{2}}}}](https://private.codecogs.com/gif.latex?%5E%7B%5Csqrt%7BW%5E%7B%5E%7B2%7D%7D%20&plus;%20H%5E%7B%5E%7B2%7D%7D%7D%7D))+1


```cpp

```




```cpp

```





```cpp

```

