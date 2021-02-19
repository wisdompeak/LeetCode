### 1756.Design-Most-Recently-Used-Queue

本题的算法是一种将o(N)复杂度降至o(sqrt(N))的经典方法。

我们将整个队列用链表来维护。同时，将整个链表虚拟地分为若干个chunk，每一个chunk有恒定的step = sqrt(n)个元素（最后一个chunk除外）。我们另外用数组skip记录每份chunk的第一个元素的指针（迭代器）。

如果我们要定位第k个元素（注意我们使用0-index更方便），我们可以知道它就在k/step个chunk。然后我们通过该chunk的首元素指针skip[k/step]开始，右移k%step次就可以定位到我们要找的元素。

接下来我们要维护这个skip数组。因为第k个元素要被抽走，所以通常情况下，从第k/step+1个chunk开始，每个chunk的首元素指针多要往后顺移一位。有个特殊情况是，如果第k个元素本身就是该chunk的首元素，那么我们要从第k/step个chunk就开始移位。即
```cpp
int j = (k%step==0) ? k/step: k/step+1;
for (int i=j; i<skip.size(); i++)
  skip[i] = next(skip[i]);
```

特别注意的是我们的操作顺序：我们需要先把第k个元素添加在list的末尾，再做skip的位移，再做第链表中原k个元素的删除。

