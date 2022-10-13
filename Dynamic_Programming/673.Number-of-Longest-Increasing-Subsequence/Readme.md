### 673.Number-of-Longest-Increasing-Subsequence

在传统的LIS的DP解法基础上，再设置一个表征LIS数目的数组。len[i]表示以i元素结尾的LIS的长度；num[i]表示以i元素结尾的LIS的数目。

递推关系是：

```len[i] = max (len[j]+1) for 0<=j<i && nums[j]<nums[i]```

```num[i] = sum (num[j]) for 0<=j<i && len[j]+1=len[i] && nums[j]<nums[i]```


[Leetcode Link](https://leetcode.com/problems/number-of-longest-increasing-subsequence)
