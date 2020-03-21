146.LRU-Cache

本题类似460，更简单些。考虑到o(1)的时间要求，所以用C++自带的链表结构list。访问list类似于访问vector，但对于非首尾两端的元素，只能通过迭代器（可以理解为指针）来访问。

设计如下的数据结构：
```cpp
unordered_map<int,int>key2val; //记录 key -> val
list<int>List; //把所有key按照recently visited的先后顺序排列
unordered_map<int,list<int>::iterator>key2iter; //记录key对应的在List中的迭代器位置
```

对于get函数，首先考虑是否在key2val中有key的记录，没有就只能退出。然后在List里删除key，并把key再装在List的末尾。显然，访问List里的Key需要通过key2iter[Key],最后也要更新key2iter[Key]。

对于put函数，首先调用get(key)查看是否已经存在。如果已经存在，则只需要更新key2val[key]。另外注意到一个trick，在调用get(key)的时候，已经更新了key在List中的顺序，所以这个情况下，就可以安心退出了。

如果get(key)==-1，那么就需要加入一个key。两种情况：一种是List.size()<cap，那么直接加key（需要添加key2val[key]、添加List、添加key2iter[key]）；另一种是List.size()==cap，那么需要先删除一个元素，再加上key.删除key需要的操作有：确定要删除的keyDel（就在List最首），在List里删除keyDel，在key2val里删除keyDel.

总之，既然建立了三个数据结构 key2val, List, key2iter，那么在每一步操作的时候，注意都要更新这三个东西，就不会遗漏操作了。对于460题也是如此。


[Leetcode Link](https://leetcode.com/problems/lru-cache)