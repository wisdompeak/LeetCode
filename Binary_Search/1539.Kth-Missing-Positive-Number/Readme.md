### 1539.Kth-Missing-Positive-Number

#### 解法1：
将数组的所有元素放入一个集合。然后从1开始自增cur，查看cur是否在数组里出现过来统计missing的个数。

#### 解法2：
利用一个指针i遍历数组元素，同时用cur表示当前可能的missing number。初始时cur = 1.

如果cur>arr[i]，那么考察下一个i。否则即cur<=arr[i]，说明从cur到arr[i]-1之间（双闭区间）都是missing number。于是missing number的数量减少```k-=arr[i]-cur```，下一个需要尝试的missing number更新为arr[i]+1. 直到k降为0为止。

注意，如果数组遍历完之后k仍然不为0，考虑到cur本身必然就是一个missing number，那么最终的答案是cur+=k-1.

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
