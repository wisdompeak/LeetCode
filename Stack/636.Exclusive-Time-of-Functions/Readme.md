### 636.Exclusive-Time-of-Functions

很明显此题应该用到栈。遇到start就入栈，遇到end就出栈。
```cpp
stack<pair<int,int>>Stack; //记录id和时刻
```
遇到end（该事件的结束点）时，出栈一个元素（该事件的起始点）做匹配，算出这个事件A的时间差，累计在这个事件A上（用一个数组来记录）。同时，因为这个事件A占用的时间要从它的上级事件中扣除，所以还要考察此时的栈顶元素B，在相应B的runtime记录里减去这段时间。这种补偿只需要做一次，因为等事件B退栈时，所占用的总时间（包括A的）也会再从更上级事件C里面扣除的。以此类推。

注意start和end的计时标准不一致。比较巧妙的方法就是对于end所标记的时刻，人为加上1，这样计算时间差的时候就可以直接相减。


[Leetcode Link](https://leetcode.com/problems/exclusive-time-of-functions)