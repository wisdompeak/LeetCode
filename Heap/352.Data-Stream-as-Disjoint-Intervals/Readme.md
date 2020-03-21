### 352.Data-Stream-as-Disjoint-Intervals

#### 方法1
本题需要一种数据结构，能够每扔进一个元素就能自动排序。我们很容易想到priority_queue。但是我们还需要能够便于查找元素，那么priority_queue就没有办法了，它本质是栈，只能一个一个读取。我们这里采用的是有序集合（ordered set)，不仅能实现自动排序，它的lower_bound函数也很好用，可以log(N)地迅速定位查找。需要注意的是，集合的元素在物理内存上并不是连续的，所以迭代器（可以想象成指针）不能任意移动指定数目，只能通过重载的自增自减操作来实现移动。

本题中，集合的元素是自定义结构Interval，所以需要自己写自动比较排序的函数. 集合的定义和自定义比较函数如下：
```cpp
struct cmp
{
   bool operator()(Interval a, Interval b)
   {
      return a.start<b.start;
   }
};

set<Interval,cmp>Set;
```
每当新进一个元素val，我们可以得到 auto it=Set.lower_bound(val) 表示定位到的指针。注意，根据自定义函数cmp，所有start比it->start严格小的区间都在it位置之前。

程序的主体根据这几种情况来分类考虑：
1. val是否已经存在一个区间里。需要把val和it所在区间上下限比较（如果it不是Set.end()的话)；注意，还需要把val和(it--)所代表区间的上下限比较（如果it不是Set.begin()的话）
2. val是否和一个已经存在的区间相邻接。如果 it!=Set.end() && val+1==it->start，那么把原来的it区间删除，加入一个更新了下界的区间。同理，如果it!=Set.begin()那么就可以考察it--，当it->end==val-1，那么把原来的it区间删除，加入一个更新了上界的区间。
3. 如果发现2里面我们操作了两次，说明有两个区间可以再合并。我们再次找到it；如果it!=Set.begin()那么就可以找到it--.把上述两个迭代器对应的元素从集合里删除，取代一个新的加入。
4. 如果发现1-3都没有操作，那么val就可以独立成为一个区间加入。

本题对于Set的迭代器操作要求概念明晰。
1. 知道对于集合，it+=1操作是不合法的，只有it++/it--操作才被合法重载。
2. 集合里的元素只能删除、增加，不可以修改，

#### 方法2
将所有的元素都放在一个有序集合Set里，不着急处理。仅当需要输出区间数组时，根据这堆有序数列即时生成。这样就避免了考虑区间合并等复杂的处理。

根据数列生成区间的方法：遍历这个集合，不断更新start和end。当集合元素a!=end+1时，就可以根据start/end生成一个区间；同时更新 start=a, end=a.

#### 方法3
使用有序的Map，key是左边界，val是右边界。总体思路和方法1差不多，需要完备考虑各种插入的情况。



[Leetcode Link](https://leetcode.com/problems/data-stream-as-disjoint-intervals)