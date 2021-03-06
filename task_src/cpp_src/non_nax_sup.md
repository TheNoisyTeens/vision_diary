## [非极大值抑制（Non-Maximum Suppression）分析](https://blog.csdn.net/kezunhai/article/details/11620357)

### 原理
1. 
在John Canny提出的Canny算子的论文中，非最大值抑制就只是在0、90、45、135四个梯度方向上进行的，每个像素点梯度方向按照相近程度用这四个方向来代替。这种情况下，非最大值抑制所比较的相邻两个像素就是：
* 0：左边 和 右边
* 45：右上 和 左下
* 90： 上边 和 下边      
* 135： 左上 和 右下    

2. 插值
>因为，自然图像中的边缘梯度方向不一定是沿着这四个方向的。因此，就有很大的必要进行插值，找出在一个像素点上最能吻合其所在梯度方向的两侧的像素值。
         然而，实际数字图像中的像素点是离散的二维矩阵，所以处在真正中心位置C处的梯度方向两侧的点是不一定存在的如果|gy|>|gx|，这说明该点的梯度方向更靠近Y轴方向，所以g2和g4则在C的上下，我们可以用下面来说明这两种情况（方向相同和方向不同）：


3. 
如果<font color='red'> |gy|>|gx| </font>，这说明该点的梯度方向更靠近Y轴方向，所以g2和g4则在C的上下，我们可以用下面来说明这两种情况（方向相同和方向不同）：
![输入图片描述](non_nax_sup_md_files%5C0.png?v=1&type=image)
上图中，C表示中心位置点，斜的直线表示梯度方向（非极大值抑制是在梯度方向上的极大值），左边的一副表示<font color='red'>gy与gx的方向相同</font>，而右边的这幅这表示gy与gx的方向相反（注意原点在左上角），而**权重**则为<font color='red'> weight = |gx|/|gy| </font>，因此则根据此种情况，其插值表示则为：
```
dTemp1 = weight*g1 + (1-weight)*g2;
dTemp2 = weight*g3 + (1-weight)*g4;	
```
同理，我们可以得到<font color='red'> |gx|>|gy| </font>的情况，此时说明该点的梯度方向更靠近X轴方向，g2和g4则在水平方向，我们可以用下图来说明该种情况：
![输入图片描述](non_nax_sup_md_files%5C1.png?v=1&type=image)
上图中，C表示中心位置点，斜的直线表示梯度方向（非极大值抑制是在梯度方向上的极大值），左边的一副表示gy与gx的方向相同，而右边的这幅这表示gy与gx的方向相反（注意原点在左上角），而权重则为weight = |gy|/|gx|，因此则根据此种情况，其插值表示则为：  
```     
dTemp1 = weight*g1 + (1-weight)*g2;
dTemp2 = weight*g3 + (1-weight)*g4;	
```

————————————————
原文链接：https://blog.csdn.net/kezunhai/article/details/11620357
