### 300.Longest-Increasing-Subsequence

#### 解法1：DP
这是第II类基本型的动态规划。我们考虑以nums[i]为结尾的LIS的第二大元素是什么？于是我们在i之前的所有index里找一个最好的j：如果nums[j]<nums[i]，那么以j为结尾的LIS就可以被收编进以i为结尾的LIS。显然，最好的j就是dp[j]最大的那个。

DP的时间复杂度是o(N^2)

#### 解法2：Greedy
贪心算法中的经典题：求最长子序列。时间复杂度可以是o(NlogN)

遍历所有元素，维护一个递增的数组q：当q为空，或者新元素val大于q.back()时加入q尾；否则，寻找q中第一个适合val插入的位置（原q序列里第一个大于等于val的位置），替换成val。 这么做的目的是：虽然LIS的长度并没有改变，但是使得当前q里面的LIS“变矮了”，更有利于后续元素加入进来构建更长的LIS。

举个例子：1 3 10 4 6. 考虑前三个元素后的q是[1 3 10]，但是考虑第四个元素后，我们将10替换成了4. 这样的好处是，第五个元素5可以直接append到这个q末尾从而时LIS再增长1.

如此遍历结束之后，q.size()就是最长子序列的长度。

对于C++，用lower_bound(q.begin(),q.end(),val)返回的就是第一个大于或等于val的元素的迭代器（或者说是地址）。


[Leetcode Link](https://leetcode.com/problems/longest-increasing-subsequence)
