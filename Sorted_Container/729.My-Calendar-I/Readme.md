### 729.My-Calendar-I

此题是训练C++里使用有序容器数据结构（比如说map，set等）基本功的一道题。

首先，使用Map.upper_bound(start)找到第一个大于start的迭代器iter，检查其对应的区间[a,b)是否与[start,end)重合。记得前提是iter有意义，也就是iter!=Map.end().

接着，将iter回退一个位置，找到第一个小于等于start的迭代器，检查其对应的区间[a,b)是否与[start,end)重合。同样，记得前提是此时的iter有意义，也就是iter!=Map.begin().


[Leetcode Link](https://leetcode.com/problems/my-calendar-i)