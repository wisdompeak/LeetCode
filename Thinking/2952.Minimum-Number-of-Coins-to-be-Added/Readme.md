### 2952.Minimum-Number-of-Coins-to-be-Added

将所有的coins排序后，假设当前已有的硬币能够组成任意[0, limit]之间的面额，那么又得到一枚面值是x的硬币，此时能够组成多少种面额呢？显然，当新硬币不用时，我们依然能构造出[0, limit]；当使用新硬币时，我们可以构造出[x, limit+x]。当这两段区间不连接时，即`limit+1<x`时，说明我们无论如何也无法构造出面额是`limit+1`的面额，意味着我们必须单独加入该面额的硬币才能构造出该面额，这样我们将上限提高至了`2*limit+1`。反之`limit+1>=x`时，则意味着我们可以构造出任意[0,limit+x]区间内的面额。

此题和`330.Patching-Array`和`1798.Maximum-Number-of-Consecutive-Values-You-Can-Make`非常相似。
