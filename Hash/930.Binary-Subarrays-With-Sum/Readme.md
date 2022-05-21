### 930.Binary-Subarrays-With-Sum

#### 解法1：Hash+prefix

我们遍历每一个元素j，考察以j为结尾、满足条件的subarray，这样的起点i可以在哪里？如果满足条件的起点i有多种可能，那么答案就可以累加上这么多数量．

如何确定i的位置呢？凡是涉及到数组的subarray的和，我们通常会转化为前缀和来处理。即```sum[i:j] = prefix[j]-prefix[i-1]```。其中sum[i:j]即使S，当我们固定j的时候，prefix[j]也是已知的。因此可以知道我们期望的prefix[i-1]是多少，假设为val。所以我们可以用Hash来存储某个所有前缀和val所对应的i的个数。因此我们就有
```
ret += Map[prefix[j] - S]
```

#### 解法2：Sliding Window
遍历左边界左边界。假设左边界为i，那么可以向右单调移动j直至滑窗内的元素和恰好为S。此时如果知道j右边有k个连续的0，那么就意味着以i为左边界、元素和是S的滑窗就有k+1个。

对于每个元素，它后面有多少个连续的0，可以提前预处理得到的。

因为i和j都是单调移动的，所以时间复杂度是o(N).

[Leetcode Link](https://leetcode.com/problems/binary-subarrays-with-sum)
