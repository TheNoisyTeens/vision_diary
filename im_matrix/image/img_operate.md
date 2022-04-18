>Opencv中图像三原色在内存中的排列顺序为B-G-R
### 1. at操作
`at`操作是一种直接简单的对单个像素的操作方式，用于获取图像矩阵某点的值或改变某点的值

对于灰度图读取和修改操作如下：
```cpp
uchar srcPixel_value = cv::Mat.at<uchar>(row, col);
cv::Mat.at<uchar>(row, col) = srcPixel_value ; 
```

对于RGB彩色图像而言：
```cpp
cv::Vec3b rgb_value = cv::Mat.at<cv::Vec3b>(row, col);
cv::Mat.at<cv::Vec3b>(row, col) = rgb_value ;
```
或者：
```cpp
image.at<cv::Vec3b>(row, col)[0] =  255;
image.at<cv::Vec3b>(row, col)[1] =  255;
image.at<cv::Vec3b>(row, col)[2] = 255;
```
at操作虽然简单方便，但是这种操作是一种效率比较低的操作，尤其用其进行遍历操作时，效率会很低。因此一般不推荐使用。

### 2. ptr操作
ptr操作时通过指针偏移的方式进行像素的查找、遍历和修改的，因此效率相对较高。

**ptr<>()是按照行来访问数组的，指针指向某一行第一个元素的首地址。只要知道这一行的首地址**，其余地址++就可以访问了。
对于灰度图的读取和修改操作如下：
```cpp
uchar srcPixel_value = cv::Mat.ptr<uchar>(row)[col];
cv::Mat.ptr<uchar>(row)[col] = srcPixel_value ; 
```
对于RGB彩色图像而言：
```cpp
img.at<Vec3b>(14,25) [0]= 25;//B  
img.at< Vec3b >(14,25) [1]= 25;//G  
img.at< Vec3b >(14,25 [2]= 25;//R  
```
cv::MAT.ptr<>()访问效率比较高，程序也比较安全，有越界判断。推荐使用。

————————————————
原文链接：https://blog.csdn.net/bxlover007/article/details/105521135

### 3. rows行



### 4. cols列

---
### 补充
#### [Opencv之`<Vec3b>`](http://t.csdn.cn/6pqnT)
vector(向量): C++中的一种数据结构,确切的说是一个类.它相当于一个动态的数组,当程序员无法知道自己需要的数组的规模多大时,用其来解决问题可以达到最大节约空间的目的。
声明一个int向量以替代一维的数组:`vector <int> a`;(等于声明了一个int数组a[],大小没有指定,可以动态的向里面添加删除。

比如`Vec<uchar, 3>`其实这句就是定义一个uchar类型的数组，长度为3而已，例如 8U 类型的 RGB 彩色图像可以使用 `<Vec3b>`，3 通道 float 类型的矩阵可以使用`<Vec3f>`。对于 Vec 对象，可以使用[]符号如操作数组般读写其元素，如：`Vec3b color;` //用 color 变量描述一种 RGB 颜色
```cpp
color[0]=255; //0通道的B 分量
color[1]=0; //1通道的G 分量
color[2]=0; //2通道的R 分量
```
————————————————
原文链接：https://blog.csdn.net/qq_29540745/article/details/52517269

---
### [new points：C++ 向量（vector）](http://t.csdn.cn/twcOZ)
可以广义上认为是数组的增强版 ,与数组相比，vector就是一个可以不用再初始化就必须制定大小的边长数组
>当然了，它还有许多高级功能
>
1.1 向量声明和初始化
vector 型变量的声明以及初始化的形式也有许多, 常用的有以下几种形式:
```cpp
/* 初始化vector对象的方法 */
vector<T> v1 ;                          //v1是一个空的vector,它潜在的元素是T类型的，执行默认初始化
vector<T> v2(v1) ;                      //v2中包含v1中所有元素的副本
vector<T> V2 = V1;                      //与上等价
vector<T> v3(n, val) ;                  //声明一个初始大小为10且初始值都为1的向量
vector<T> v4(n) ;                       //v4包含了n个重复地执行了值初始化的对象
vector<T> v5{a,b,c,...}                 //v5包含了初始值个数的元素，每个元素给赋予对应的初值
vector<T> v5 = {a,b,c,...}              //与上等价
```
如果vector的元素类型是int，默认初始化为0；如果vector元素类型为string，则默认初始化为空字符串。
除此之外, 还可以直接使用数组来初始化向量,例如 :
```cpp
vector<int> v1;               
vector<father> v2;
vector<string> v3;            
vector<vector<int> >;          //注意空格。这里相当于二维数组int a[n][n];
vector<int> v5 = { 1,2,3,4,5 };//列表初始化,注意使用的是花括号
vector<string> v6 = { "hi","my","name","is","lee" };
vector<int> v7(5, -1);         //初始化为-1,-1,-1,-1,-1。第一个参数是数目，第二个参数是要初始化的值
vector<string> v8(3, "hi");
vector<int> v9(10);            //默认初始化为0
vector<int> v10(4);            //默认初始化为空字符串
 
/* 直接使用数组来初始化向量 */
int n[] = {1, 2, 3, 4, 5} ;
vector<int> v11(n, n+5) ;      //将数组n的前5个元素作为向量a的初值
```

————————————————
原文链接：https://blog.csdn.net/fuxiaoxiaoyue/article/details/84847967

---
```cpp
// [2] 彩色图片通道分离  
std::vector<cv::Mat> channels;  
cv::split(*src, channels);

// [1] 初始化  
*dst = (*src).clone();  
// [4] 合并返回  
cv::merge(channels, *dst);
```

---
[Opencv 创建图像时，CV_8UC1,CV_32FC3等参数的含义](http://t.csdn.cn/e1ooZ)
