### 1539.Kth-Missing-Positive-Number

#### 解法1：
将数组的所有元素放入一个集合。然后从1开始自增cur，查看cur是否在数组里出现过来统计missing的个数。

#### 解法2：
利用一个指针i指向元素，当cur<arr[i]的时候，不停地自增cur并增加missing的个数；当cur==arr[i]的时候，cur和i都可以同时自增1.

#### 解法3：
二分搜索。和```1060.Missing-Element-in-Sorted-Array```一样的思路。

假设我们猜测mid是否是答案。考察[1,mid-1]这段连续自然数区间，可知道这段区间的自然数有M个，并且有T个存在于数组中（即查找数组里有多少个小于mid的元素个数，利用lower_bound）。所以，在[1,mid-1]这段连续自然数区间内有missing number = M-T个。理论上我们希望这段区间应该有missing number共k-1个，于是就可以帮助判定mid是否偏大和偏小。
```cpp
            if (missing <= k-1)
                left = mid;
            else
                right = mid-1;
```
特别注意，当missing==k-1的时候，mid可能并不是最终答案，因为mid可能也存在于数组中，所以mid可以再往大猜(即left=mid)。因此这个分支在上面的代码里与```missing<k-1```合并。
