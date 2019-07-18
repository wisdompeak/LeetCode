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
有一种更省空间的解法。就是压入栈内的元素不直接是x，而是```delta = x-Min```，注意其中Min是考虑了x之后的本轮最新值。

反弹的时候，考虑栈顶元素的正负号：

1. 如果是正号，说明该轮入栈的时候的x比Min大，所以弹出的元素应该是delta+Min，而Min保持不变。
2. 如果是负号，说明该轮入栈的时候的x比Min小，所以弹出的元素应该是Min-|delta|，并且Min需要更新。
