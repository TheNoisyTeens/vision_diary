## 回调函数

* 因为Ｃ语言中函数名也是地址，因此对于形参数是函数指针的话，这个时候直接将地址传进去就可以了
>要想传入函数，则形参应为函数指针
>既然是函数指针，则这个函数指针的定义形式就已经确定了，主要包括函数参数类型、个数、返回值等

* 换句话说，程序可以在运行时，通过登记不同的回调函数，来决定、改变中间函数的行为
* 把回调函数传入库函数的动作，称为**登记回调函数**

* **主函数和回调函数是在同一层的，而库函数在另外一层。**如果库函数对我们不可见，我们修改不了库函数的实现，也就是说不能通过修改库函数让库函数调用普通函数那样实现，那我们就只能通过传入不同的回调函数了

>[链接](http://t.csdn.cn/FkCCq)
>[深入理解：回调函数](http://t.csdn.cn/tC5h6)
