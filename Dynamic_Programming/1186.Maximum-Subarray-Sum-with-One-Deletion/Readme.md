### 1186.Maximum-Subarray-Sum-with-One-Deletion

本题可以先从一个很经典的问题出发：如何求一个数组里和最大的subarray？答案是kadane算法，可以用dp的思想来说明。令dp[i]表示以元素i为结尾的subrray里能得到的最大和。因此计算dp[i]时必然会考虑充分利用以元素i-1为结尾的最大subarray。
```
dp[i] = max(dp[i-1]+arr[i], arr[i])
```
注意：也有可能dp[i-1]是个负数反而会带来“负担”，因此上面的状态转移方程里还需要考虑arr[i]本身这个单元素数组的可能性。

那么对于本题而言，我们多了一个"deletion"的权力。如何利用这个权力，处理方法其实和```487.Max Consecutive Ones II```很像。就是将原本的dp[i]再拆分为两个状态。dp[i][0]表示"maximum sum for a non-empty subarray ending at i, w/o any deletion"，而dp[i][1]表示"maximum sum for a non-empty subarray ending at i, with one deletion done".

可以分析出新的转移方程：
```
dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
```
其中第一条和常规的kadane算法没有差别。第二条是分两种情况讨论，考虑这个被删除的数是否是arr[i]。如果被删的是arr[i]，那么问题就转化为求以元素i-1结尾的常规的最大subarray sum；如果被删的不是arr[i]，那么说明被删的数是存在于对应dp[i-1][1]（即必须删去某个元素）的最大subarray里。



[Leetcode Link](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion)