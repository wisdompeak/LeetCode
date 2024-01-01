### 2916.Subarrays-Distinct-Element-Sum-of-Squares-II

我们声明建立一个线段树，在i时刻，线段树每个叶子节点j表示区间[j:i]里distinct number的个数，记做count[j]。注意，我们遍历时刻i=0,1,2...n-1，其中n就是nums的元素个数。当j>i时，区间实际不存在，故记做count[j]=0.

我们令square[i]表示所有以i为结尾的区间的square of distinct number的和。

我们定义count[a:b]表示某个区间内的distinct number的数目，square[a:b]表示该区间内distinct number的数目的平方。

对于位置i，我们在数组里找到相同nums[i]出现的前一个位置k。于是
1. 对于j=0,1,...,k而言，`square[j:i] = square[j:i-1]`.
2. 对于j=k+1,k+2,...,i-1而言，`count[j:i] = count[j:i-1]+1，两边平方一下就得到`square[j:i] = square[j:i-1] + 2*count[j:i-1] + 1`.
将两部分相加得到
```
sum{square[j:i]} = sum{square[j:i-1]} (for j=0,1,2,...i-1) + 2 * sum{count[j:i-1]} + (i-1-k)`,  j=k+1,...i-1
```
可见`sum{square[j:i]}`与`sum{square[j:i-1]}`之间存在递推关系。其中相差的部分`sum{count[j:i-1]}`就是之前定义的线段树中在t=i-1时刻，叶子节点区间[k+1, i-1]的元素之和。

当我们求出`sum{square[j:i]}`之后，该如何更新这棵线段树呢？显然，只有以k+1,k+2,...i-1开头的这些区间，随着i的加入，distinct number会增1. 所以我们只需要将叶子节点区间[k+1, i-1]的元素统一都增加1即可。

最终的答案就是将每个位置i的`sum{square[j:i]}`再加起来。

