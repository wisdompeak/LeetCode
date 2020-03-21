### 155.Min-Stack

#### 解法1： 
要做到实时得到getMin()，不妨就对栈内的每一个元素都记录下对应的当前栈内元素最小值。于是我们可以构建另一个栈StackMin，跟随数据本身的Stack同步进退。
```cpp
    void push(int x) 
    {
        Stack.push(x);
        if (StackMin.empty())
            StackMin.push(x);
        else
            StackMin.push(min(x,StackMin.top()));
    }
```    

#### 解法2：
有一种更省空间的解法。就是压入栈内的元素不直接是x，而是```delta = x-Min_old```。

入栈的时候，如果delta为正数，那么说明Min变量需要更新为```Min_new = Min_old```，否则就是```Min_new = x```

出栈的时候，我们看到的是栈顶元素delta，以及Min_new。我们需要复原的是x和Min_old：

1. 如果delta是正号，说明```Min_old = Min_new```，然后推出```x = delta+Min_old```.
2. 如果delta是负号，说明```x = Min_new```，然后推出```Min_old = x-delta```.


[Leetcode Link](https://leetcode.com/problems/min-stack)