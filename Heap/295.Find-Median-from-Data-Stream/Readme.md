### 295.Find-Median-from-Data-Stream

#### 解法1:
设计两个可以实时排序的multiset，其中一个Large存放较大的那一半数据，另一个Small存放较小的那一半数据。

每次读入一个新数num，将其和Large的首元素比较大小，决定是加入Large还是Small。加入之后，需要调整Large和Small的个数，使得总是保持Large比Small多一个或者两者数目相等。

输出的Median就是Large的首元素，或者Large首元素和Small尾元素的平均值。

#### 解法2:
使用multiset容器和相应的迭代器的操作,非常简单明了.不断更新处于正中间或者中间偏左的那个迭代器位置即可.

注意,multiset里有相同的元素加入时,新元素的迭代器位置在旧元素迭代器位置的后面.


[Leetcode Link](https://leetcode.com/problems/find-median-from-data-stream)