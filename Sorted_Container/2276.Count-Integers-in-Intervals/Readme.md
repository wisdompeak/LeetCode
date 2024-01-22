### 2276.Count-Integers-in-Intervals

此题的本质就是```715.Range-Module```. 我们常用map来维护互不重叠的区间，其中的key代表了区间的起点（并是有序排列），value表示区间的终点。

基本思想：我们维护一个计数器count表示当前有多少整数被记录。每当加入一个新区间，我们需要标记删除哪些旧区间（因为会与新区间重叠或相交），同时在count里减去这些旧区间对应的数字个数。然后加入新区间，同时在count里加上新区间的个数。注意新区间不一定就是[left,right]，而是可能与旧区间merge后的大区间。

对于一个新区间[left,right]，我们首先考虑left左边需要删除哪些旧区间。只有一种情况，就是如果left左边有一个区间与新区间重合的时候。如图
```
   A            B
_________     _____   _________
      __________________
    left              right
```
判定起来也很方便，用```iter = Map.lower_bound(left)```来定位区间B，然后prev(iter)就是区间A。如果A的右边界大于left，那么A区间就要被删除。此时，我们需要注意，之后加入的新区间因为要与A区间merge，它的起点将是```start = A->first```.

对于一个新区间[left,right]右边需要删除的区间，则可能会有多个。如图
```
   A       B    C       D
_________  __  ___  _________
      __________________
    left              right
```
我们从B开始，一路向后遍历区间，直至发现D是最后一个左边界与right勾搭上的区间。于是区间B、C、D都会是需要待删除的区间。同理我们需要注意，之后加入的新区间因为要与BCD区间merge，它的终点将是```end = D->second```. 因此我们的代码长得如下：
```cpp
int end = right;
auto iter = Map.lower_bound(left);
while (iter!=Map.end() && iter->first <= end) 
{
  end = max(end, iter->second);
  iter = next(iter);
}
```
但是这里有个疏漏，事实上A的右边界可以很靠后，所以初始值的end必须同样要考虑到A->second。所以要添加一行：
```cpp
int end = right;
auto iter = Map.lower_bound(left);
if (iter!=Map.begin())
   end = max(end, prev(iter)->second); 
```

最终我们将这些标记要删除的区间都从Map里删除，并添加上新的```Map[start] = end```.
