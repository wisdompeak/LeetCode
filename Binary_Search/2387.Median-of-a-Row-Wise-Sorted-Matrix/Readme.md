### 2387.Median-of-a-Row-Wise-Sorted-Matrix

令`k=(m*n+1)/2`，本题就是求矩阵里的从小到大的第k个元素。本质和`215.Kth-Largest-Element-in-an-Array`相同，只不过需要将各行`smallerOrEqual(mid)`的结果累加起来得到count。
```cpp
if (count < k)
  left = mid+1;
else
  right = mid;
```
