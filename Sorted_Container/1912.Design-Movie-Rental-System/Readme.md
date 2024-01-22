### 1912.Design-Movie-Rental-System

本题就是模拟题，根据题意设计如下的数据结构：
```cpp
    unordered_map<int, set<array<int,2>>>left;  // movie -> {price, shop}
    set<array<int,3>>rented; // {price, shop, movie}
    unordered_map<int, unordered_map<int,int>> prices; // prices[shop][movie]
```
对于每部未租出的电影，left[movie]存放着按照价格排序的copy，以实现search的功能。

对于已经租出的电影，rented存放按照价格排序的copy，以实现report的功能。
