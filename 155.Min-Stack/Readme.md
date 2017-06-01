### 155.Min-Stack

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
