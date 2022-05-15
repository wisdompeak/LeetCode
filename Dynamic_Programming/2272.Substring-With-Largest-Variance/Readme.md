### 2272.Substring-With-Largest-Variance

本题的突破口是数据范围n=1e4.这是一个比较奇怪的数字。通常来说如果允许nlogn的复杂度，那么n可以达到1e5；类似的，如果是n^2的复杂度，那么n大概就是1000. 在这里，很可能是一个大概是存在100的常数k，使得复杂度的限制在o(kn)。于是我们大概可以猜到，这个k就是跟26或者26^2相关，也就是英文字母的个数。

于是我们就想到了穷举本题中的最大频次字符x和最小频次字母y。这样的话，我们需要在原字符串里面找一个滑窗，使得x的频次与y的频次之差最大，而其他字母都没有任何作用。这就联想到，如果将x的字符都替换为1，y的字符都替换为-1，其他字符都替换为0，那么不就是变成了寻找```max subarray sum```的题目了吗？

但是注意，这里有一点不同，根据题意，我们想要找的subarray必须至少包含一个-1. 传统的kadane算法，我们很有可能找出只有+1的subarray。那么怎么办呢？有两种方法。

#### 解法1
我们可以找那个-1为突破口。根据Kadane的思想，我们找到以每个元素为结尾的最大subarray sum记做dp1[i]，那么反过来走一遍就可以得到以每个元素为开头的最大subarray sum记做dp2[i]。那么我们再遍历所有的-1元素i，那么dp1[i]+dp2[i]-nums[i]必然是包含了至少一个-1的max subarray sum。我们再全局找一个最大值即可。

#### 解法2
我们依然按照kadane算法的思路，但是设置两个临时变量：curSum0表示以当前元素为结尾、不包含-1的最大subarray sum，另外用curSum1表示以当前元素为结尾、已经包含-1的最大subarray sum。转移方程如下：
```cpp
  for (int i = 0; i < n; i++) 
  {
      if (nums[i] == 1)
      {
          curSum1 = curSum1+nums[i];
          curSum0 = max(curSum0+nums[i], nums[i]);                
      }
      else if (nums[i] == -1)
      {
          curSum1 = max(nums[i], max(curSum0, curSum1)+nums[i]);  // 三种情况可以转移到新的curSum1
          curSum0 = 0;  // 因为nums[i]是-1，curSum0没有意义，只能置零
      }

      ret = max(ret, curSum1);
  }
```
特别注意，curSum0的初始值可以是0，但是curSum1的初始值必须设置为INT_MIN.
