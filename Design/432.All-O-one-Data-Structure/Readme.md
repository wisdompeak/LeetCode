### 432.All-O-one-Data-Structure

此题和[146.LRU](https://github.com/wisdompeak/LeetCode/tree/master/Design/146.LRU-Cache)和[460.LFU](https://github.com/wisdompeak/LeetCode/tree/master/Design/460.LFU-Cache)的解法非常相似．这类问题的关键点就是，如果用o(1)的时间复杂度对val进行实时的排序．方法是用两个数据结构
```cpp
list<int>ListNum;
unordered_map<int,list<int>iterator>value2iter;
```
其中ListNum是一个链表，存储着顺序的value．只要给出了迭代器的位置（可以理解为指针），那么在特定位置的插入和删除都是o(1)的操作．那么假设已知value，如何在这个链表里找到这个对应value的位置呢？就需要另一个Hash表value2iter来存储．总结来说，就是给出一个value，那么value2iter[value]给出了这个value在链表里的位置，可以进行删除或添加的操作．

为什么ListNum可以一直保持是顺序的呢？对于任何一个key的操作，题意要求就是将其value增（或者减）一．假设我们在链表中定位了value（如前所说：通过Num2Iter）,只需要在其后面相邻的地址插入一个value+1（或者在其前面相邻的地址插入一个vlaue-1)即可，所以这个链表始终可以保持顺序，而且指针的位移操作是o(1)的．
