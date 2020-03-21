### 475.Heaters

最佳的binary search方案是：遍历所有houses[i]，记录其位置pos，在有序的heaters序列里找到第一个大于（等于）pos的迭代器元素it，判断\*it和\*(it-1)与pos的距离，较小值就是该house[i]的最小供暖半径。  

寻找it的方法用lower_bound函数。
```cpp
auto it = lower_bound(heaters.begin(),heaters.end(),pos);
```
特别注意当```it==heaters.begin()```或```it==heaters.end()```时的特例。说明houses[i]在所有heaters的一边，所以只需要计算单边的半径距离。


[Leetcode Link](https://leetcode.com/problems/heaters)