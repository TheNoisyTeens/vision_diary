## RGB彩色图转灰度图

### RGB彩色图转灰度图
#### [代码](http://t.csdn.cn/qhhfc)
```python
import numpy as np
import cv2

def color2gray(color_img):
    size_h, size_w, channel = color_img.shape
    gray_img = np.zeros((size_h, size_w), dtype=np.uint8)
    for i in range(size_h):
        for j in range(size_w):
            gray_img[i, j] = round((color_img[i, j, 0]*30 + color_img[i, j, 1]*59 +\
             color_img[i, j, 2]*11)/100)
    return gray_img

if __name__ == '__main__':
    pic = cv2.imread('./pic/eye.png')
    pic_gray = color2gray(pic)  # 得到其灰度图像
    cv2.imshow('origin picture', pic)
    cv2.imshow('gray picture', pic_gray)
    cv2.waitKey()
    
```
```python
gray_img[i, j] = round((color_img[i, j, 0]*30 + color_img[i, j, 1]*59 +\
             color_img[i, j, 2]*11)/100)
   ```
       
   >我的理解：
   >* 暂时把图像空间理解为三维数组，三维数组的第一维就是图片的宽度，第二维是图片的宽度，第三维是R、G、B三通道的值
   >* 比如`color_img[i, j, 0]` `i,j`代表像素点位置，0表示R通道，因此`color_img[i, j, 0]` 表示( i , j )（像素位置）的对应R通道值
  * 1. [gray_img = np.zeros((size_h, size_w), dtype=np.uint8)](http://t.csdn.cn/tuE4I)
  
  *    2. [for i in range(size_h):](http://t.csdn.cn/RTMqQ)
* 3. [color_img.shape](http://t.csdn.cn/apUAg)
	* [shape函数](http://t.csdn.cn/apUAg) 
	>>返回的是tuple元组（一旦初始化就无法改变）
>可以将**小数转为整数，除法变为移位，乘法也变为移位（整数计算比浮点型快，移位运算和加减法比乘除法快）**     
#### 原理

#### 小补充
>直接使用 `image = cv2.imread(im_name)`会导致得到的数组 image 为三维数组，不是二维数组，就算 im_name 是二维灰度图像，但读出来的数组却还是三维的
>原文链接：http://t.csdn.cn/fktTb

---

### RGB彩色图转HSV
#### [代码](http://t.csdn.cn/kXGAX)
```python
import cv2
import numpy as np

def rgb2hsv(img):
    h = img.shape[0]
    w = img.shape[1]
    H = np.zeros((h,w),np.float32)
    S = np.zeros((h, w), np.float32)
    V = np.zeros((h, w), np.float32)
    r,g,b = cv2.split(img)
    r, g, b = r/255.0, g/255.0, b/255.0
    for i in range(0, h):
        for j in range(0, w):
            mx = max((b[i, j], g[i, j], r[i, j]))
            mn = min((b[i, j], g[i, j], r[i, j]))
            V[i, j] = mx
            if V[i, j] == 0:
                S[i, j] = 0
            else:
                S[i, j] = (V[i, j] - mn) / V[i, j]
            if mx == mn:
                H[i, j] = 0
            elif V[i, j] == r[i, j]:
                if g[i, j] >= b[i, j]:
                    H[i, j] = (60 * ((g[i, j]) - b[i, j]) / (V[i, j] - mn))
                else:
                    H[i, j] = (60 * ((g[i, j]) - b[i, j]) / (V[i, j] - mn))+360
            elif V[i, j] == g[i, j]:
                H[i, j] = 60 * ((b[i, j]) - r[i, j]) / (V[i, j] - mn) + 120
            elif V[i, j] == b[i, j]:
                H[i, j] = 60 * ((r[i, j]) - g[i, j]) / (V[i, j] - mn) + 240
            H[i,j] = H[i,j] / 2
    return H, S, V

img = cv2.imread('E:/pdata/junhenghua.jpg')
h,s,v = rgb2hsv(img)
cv2.imshow("h",h)
cv2.imshow("s",s)
cv2.imshow("v",v)
merged = cv2.merge([h,s,v]) #前面分离出来的三个通道
cv2.imshow("hsv",merged)
cv2.waitKey(0)
cv2.destroyAllWindows()

```

* 理解：
```python
	H = np.zeros((h,w),np.float32)
	H[i, j] = 0
```
>我的理解：
>H为二维数组，`H[i, j] = 0`是赋值操作，将H第i行第j列赋值为0
>链接：图像（三维数组）
>第三维为3，表示有3个这个"面"大小为i*j

* `max()`函数：获取最大值
---
* 补充：
[Python | Numpy三维数组维度变换/提取](http://t.csdn.cn/8ltjG)
[NumPy概述](https://edu.csdn.net/skill/python/python-3-195)
* 函数：
[reshape()函数](http://t.csdn.cn/9rnPI)
