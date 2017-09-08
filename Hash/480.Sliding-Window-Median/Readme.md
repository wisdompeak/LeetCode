### 480.Sliding-Window-Median

希望能够自动排序的容器，首选set或者multiset。对于这类非线性的容器，不能用++或--来实现迭代器的移动，必须使用next或prev。例如
```
set<int>::iterator mid = next(Set.begin(),k);
set<int>::iterator mid = prev(Set.end(),k);
```
