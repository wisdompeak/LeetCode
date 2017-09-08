### 480.Sliding-Window-Median

希望能够自动排序的容器，首选set或者multiset。对于这类非线性的容器，不能用+k或-k来实现迭代器的移动，必须用for循环不断++/--，或者使用next或prev。例如
```cpp
set<int>::iterator mid = next(Set.begin(),k); //从Set.begin()开始后移k个
set<int>::iterator mid = prev(Set.end(),k);  //从Set.end()开始前移k个
```
