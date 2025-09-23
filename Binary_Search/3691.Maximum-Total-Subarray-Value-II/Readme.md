### 3691.Maximum-Total-Subarray-Value-II

首先学习一个知识点。在一个数组里我们可以用常数级别的时间来求得任意区间的最大值或最小值，这就是RMQ（Range Maximum Query）问题。我们已经知道线段树或者BIT都可以解决这类问题，但是对于immutable的数组而言，用ST算法效率更高。

Sparse Table其实和树上倍增（binary lifting）算法的思想完全一样。我们利用mx[i][k]表示从i开始、长度为2^k的区间内的最大值。于是就有直观的状态转移方程：
```cpp
for (int i = 0; i < n; i++)
  mn[i][0] = mx[i][0] = nums[i];
for (int k = 1; k <= K; k++) {
    for (int i = 0; i+(1<<k)-1 < n; i++) {
        mn[i][k] = min(mn[i][k-1], mn[i+(1<<(k-1))][k-1]);
        mx[i][k] = max(mx[i][k-1], mx[i+(1<<(k-1))][k-1]);
    }
}
```
当我们有了mx和mn数组，就可以求任意区间[L,R]内的MaxDiff。我们将次函数记作`GetDiff(int L, int R)`
```cpp
auto GetDiff = [&](int L, int R){
    int k = log2(R-L+1);
    return max(mx[L][k], mx[R-(1<<k)+1][k]) - min(mn[L][k], mn[R-(1<<k)+1][k]);
};
```

有了以上的工具，我们就可以解这道题。

首先我们可以用二分搜值来确定第k大的Diff数值是多少。假设我们猜测第k大的Diff是d，那么就可以算出有多少个subarray的MaxDiff大于等于d，记作`count_ge`.如果这个数小于k，那么我们意味着猜得太大了需要往小调整；否则就可以往大调整。那么如果计算`count_ge(d)`呢？这可以用滑动窗口。因为窗口越大，MaxDiff就可能越大。所以固定左端点i，可以单调移动右端点j直至`GetDiff(i,j)>=d`，于是`n-j`就是以i为左端点、且MaxDiff大于等于d的区间数量。之后左端点i右移一位，右端点依然是单调移动。

OK，此时我们得到了第k大的MaxDiff是`th`。考虑到k不超过1e5，我们可以将这些区间都枚举出来。

对于每个以i为左端点的区间，我们可以再次用二分搜值来接确定第一个`MaxDiff>th`的位置j。之后右端点从j到n的每一个位置，我们都可以将GetDiff(i,j)收入结果之中。如前所述，这样的枚举是可行的。

在上述的枚举过程中，如果我们加入了count_g个`MaxDiff>th`的区间，那么还有`k-count_g`区间未添加，而它们对应都恰好是`MaxDiff==th`，所以直接将`th*(k-count_g)`加入最终结果即可。




