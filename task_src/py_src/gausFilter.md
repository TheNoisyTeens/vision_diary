### [高斯滤波详解 python实现高斯滤波](http://t.csdn.cn/o2C0a)
```python
import cv2
 
import numpy as np
 
# Gaussian filter
 
def gaussian_filter(img, K_size=3, sigma=1.3):
 
    if len(img.shape) == 3:
 
        H, W, C = img.shape
 
    else:
 
        img = np.expand_dims(img, axis=-1)
 
        H, W, C = img.shape
 
    ## Zero padding
 
    pad = K_size // 2
 
    out = np.zeros((H + pad * 2, W + pad * 2, C), dtype=np.float)
 
    out[pad: pad + H, pad: pad + W] = img.copy().astype(np.float)
 
    ## prepare Kernel
 
    K = np.zeros((K_size, K_size), dtype=np.float)
 
    for x in range(-pad, -pad + K_size):
 
        for y in range(-pad, -pad + K_size):
 
            K[y + pad, x + pad] = np.exp( -(x ** 2 + y ** 2) / (2 * (sigma ** 2)))
 
    K /= (2 * np.pi * sigma * sigma)
 
    K /= K.sum()
 
    tmp = out.copy()
 
    # filtering
 
    for y in range(H):
 
        for x in range(W):
 
            for c in range(C):
 
                out[pad + y, pad + x, c] = np.sum(K * tmp[y: y + K_size, x: x + K_size, c])
 
    out = np.clip(out, 0, 255)
 
    out = out[pad: pad + H, pad: pad + W].astype(np.uint8)
 
    return out
 
# Read image
 
img = cv2.imread("../paojie.jpg")
 
# Gaussian Filter
 
out = gaussian_filter(img, K_size=3, sigma=1.3)
 
# Save result
 
cv2.imwrite("out.jpg", out)
 
cv2.imshow("result", out)
 
cv2.waitKey(0)
 
cv2.destroyAllWindows()
```
1. 获取图像长，宽，通道数
```python
H, W, C = img.shape
```
`img.shape`可以获取图像长，宽，通道数

2. 结合切片法对图像进行copy
```python
gaussian_img[center: center + H, center: center + W] = img.copy().astype(np.float)
```
>？：
>不大懂二维or三维
>`copy()`函数
3. zeros()函数创建矩阵
```python
gaussian_img = np.zeros((H + center * 2, W + center * 2, C), dtype=np.float)
```
`img=np.zeros(shape,dtype)`
* `shape`可以为`(h,w)`(二维)或`(h,w,c)`(三维)
4. 矩阵除法
```python
gaussian_kernel /= (2 * np.pi * sigma * sigma)
```
`matrix /= value`该操作将matrix这个二维矩阵的每一个元素都除以value

5. (二维)矩阵求和
```python
gaussian_kernel.sum()
```
`matrix.sum()`对矩阵matrix求和，即所有元素相加

6. 
(1)访问三维矩阵
(2)矩阵相乘
(3)矩阵求和
```python
for x in range(H):  
    for y in range(W):  
        for c in range(C):  
            gaussian_img[center + x, center + y, c] = np.sum(gaussian_kernel * tmp[x: x + K_size, y: y + K_size, c])
```
`matrix[h,w,c]`以此访问矩阵matrix的元素
`matrix1*matrix2`将matrix1与matrix2对应元素相乘
`np.sum(matrix)`对matrix矩阵求和，即所有元素相加


7. 遍历所有像素点(三通道)
```python
for x in range(H):  
    for y in range(W):  
        for c in range(C):
```


8. [np.clip( )函数](http://t.csdn.cn/ZLbHt)
```python
gaussian_img = np.clip(gaussian_img, 0, 255)
```

`numpy.clip(a, a_min, a_max, out=None)`对数组a的元素值进行范围限定



```python

```

```python

```

```python

```

#### 还需了解
* copy()
* astype(dtype)

#### 这里要注意
* 注意对矩阵元素值的限定  
* 将矩阵元素类型转换为uint8

#### 学习重点
矩阵元素值类型
>涉及到`astype()`函数
