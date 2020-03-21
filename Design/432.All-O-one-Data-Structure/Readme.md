### 432.All-O-one-Data-Structure

此题和[146.LRU](https://github.com/wisdompeak/LeetCode/tree/master/Design/146.LRU-Cache)和[460.LFU](https://github.com/wisdompeak/LeetCode/tree/master/Design/460.LFU-Cache)的解法非常相似．我们需要一个数据结构存储着所有的val，并且这个val是实时有序的（方便我们最快找到最大和最小的val），还要求所有的插入和删除都是o(1)。

解决方案还是链表(list<int>)。设计如下的数据结构
```cpp
list<int>List;
unordered_map<int,list<int>iterator>val2iter;
```
其中List是一个链表，存储着顺序的value．只要给出了迭代器的位置（可以理解为指针），那么在特定位置的插入和删除都是o(1)的操作．那么假设已知value，如何在这个链表里找到这个对应value的位置呢？就需要另一个Hash表val2iter来存储．总结来说，就是给出一个value，那么val2iter[value]给出了这个value在链表里的位置，可以进行删除或添加的操作．

为什么List可以一直保持是顺序的呢？对于任何一个key的操作，题意要求就是将其value增（或者减）一．假设我们在链表中定位了value（如前所说：通过val2iter）,只需要在其后面相邻的地址插入一个value+1（或者在其前面相邻的地址插入一个vlaue-1)即可，所以这个链表始终可以保持顺序．

解决了以上的问题之后，剩下的数据结构就不难设计:
```cpp
unordered_map<string,int>key2val;   // key->val
unordered_map<int,unordered_set<string>>val2set;  //val->set of keys
```
我们需要一个Hash表val2set，来存储从val到对应的key的集合。于是inc(key)的操作，就是将key从value对应的集合中删除，再把key加入value+1对应的集合中。对于dec(key)的操作同理。

本题的一个细节之处是，对于val==0的处理。我们可以在list中加入一个dummy head，也就是```val0=0```来方便操作。但是要注意避免任何对于val2set[0]的删除操作（因为在初始化时，我们不可能在这个集合中加入无限多的元素，所以干脆永远保持val2set[0]是空的）。


[Leetcode Link](https://leetcode.com/problems/all-o-one-data-structure)