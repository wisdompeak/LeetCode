### 1060.Missing-Element-in-Sorted-Array

此题的暴力解法就不赘述了，就是令cur = nums[0]，然后不断自增1，查看这个数是否在数组中出现，统计是否missing的个数。知道missing的个数达到k时，输出cur。

这里考虑一个比较高效的二分搜索方法。

我们假设这个第k个missing的元素是m，那么它会有哪些性质呢？假设在从nums[0]到m-1总共有M个连续的自然数，并且我们可以知道数组里面有多少个小于m的数T。所以，我们可以计算出从nums[0]到m-1里面有多少个数是在数组里missing的。理论上我们需要missing = k-1. 这是一个必要条件。

如果数组中missing > k-1，那么说明m猜得太大。如果missing < k-1，说明m猜得太小。如果missing = k-1，说明m可能是答案，但也有可能m也存在于数组中从而并不是一个missing number，所以m也得继续往大猜。综上就有这样的转移：
```cpp
if (missing > k-1)
  right = m - 1;
else
  left = m;
```
应该本题一定有解，所以最终收敛的解就肯定是答案。
