




1. 使用字典(键值对)记录点
```python
# [1-5] 投票字典及其初始化，用来记录空间变换——键：值=霍夫空间位置：直角坐标位置  
accuDict = {}  
for i in range(numRho):  
    for j in range(numTheta):  
        accuDict[(i, j)] = []

# 记录该点  
accuDict[(n, m)].append((x, y))
```
用字典的值(好像是一个序列)来标记点
```python
 voteThresh = 60
    for r in range(rows):
        for c in range(cols):
            if accumulator[r][c] > voteThresh:
                points = accuDict[(r,c)]
                cv2.line(I,points[0],points[len(points)-1],(255),2)
```
3. 符合要求的`(r,n)`(极坐标)才会被画出
```python
 voteThresh = 60
    for r in range(rows):
        for c in range(cols):
            if accumulator[r][c] > voteThresh:
                points = accuDict[(r,c)]
                cv2.line(I,points[0],points[len(points)-1],(255),2)
```

---
### 吸取教训
```
error:
'float' object cannot be interpreted as an integer
```

---
### 没看懂
```python
1. 为什么是这样长和宽
# [1-3] 计算投票器长，宽  
numTheta = int(180.0 / stepTheta)  
numRho = int(2 * L / stepRho + 1)
# 计算投票哪一个区域  
n = int(round(rho + L) / stepRho)
```
2. 为什么
```python
1.  for y in range(rows):
    
2.  for x in range(cols):
    
3.  if(image[y][x] == 255)
```
懂了：
根据坐标图
x为横轴，y为纵轴
