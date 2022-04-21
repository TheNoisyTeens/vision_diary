## [利用sobel算子进行边缘检测](http://t.csdn.cn/FAYZT)




1. 写入一个二维矩阵
```python
sobel_x=[[1,0,-1],[2,0,-2],[1,0,-1]]
```
2. 对图像进行copy要调用`copy()`函数，再用`astype()`函数指定类型
```python
将原图像copy到该矩阵中  
gaussian_img[center: center + H, center: center + W] = img.copy().astype(np.float)
```
>还没学`copy()`、`astype()`






