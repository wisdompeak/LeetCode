### 2945.Find-Maximum-Non-decreasing-Array-Length

我们考虑，如果以nums[i]为某段subarray的结尾，那么我们在[1:i]前缀里能够得到的符合条件的最长序列。我们记最后这段subarray sum为dp[i]. 显然，我们需要找到一个位置j，使得dp[j]<=dp[i]（其中dp[i]=sum[j+1:i]）。为了使得序列尽量长，我们自然希望dp[i]能尽量小，故在所有符合条件的j里，我们一定会找最大的j。因此我们可以有这段dp代码：
```cpp
for (int i=1; i<=n; i++)
{
    LL sum = nums[i];
    int j = i-1;
    while (j>=0 && sum < dp[j])
    {
        sum += nums[j];
        j--;
    }
    dp[i] = sum;
    len[i] = len[j]+1;            
}
return len[n];
```
但是这个算法的时间复杂度是o(N^2)。

我们将关系式`dp[j]<=dp[i]`改写为`dp[j]<=presum[i]-presum[j]`，即`presum[i] >= presum[j]+dp[j]`. 显然，我们将所有已经得到的那些映射`presum[j]+dp[j] -> j`（因为下标小于i，故是已知量），提前放入一个有序map里，用二分搜索就可以找到对于i而言符合条件的key的范围。那么如何再找到其中最大的j呢？理论上我们需要把这些key都遍历一遍，检查他们的value。但我们会想到一个常见的套路：如果保证这个map不仅是按照key递增有序的、同时也是按照value递增有序的，那么我们就只需要一次二分搜索即可定位恰好小于等于presum[i]的key，那个key所对应的value就是我们想要的最大j，而不需要再遍历寻找value的最大值。

根据以上的数据结构，我们就可以轻松求出i所对应的j，以及dp[i]和len[i]。接下来我们需要将`presum[i]+dp[i] -> i`放入map里去。注意，我们依然想要保证map按照key和value都是递增有序的。事实上，我们将`presum[i]+dp[i]`作为key插入map之后，map里比其大的key所对应的value都必然小于i（因为它们是nums里位于i之前的index），这些元素都可以从map里删去。这是因为它们的key既大（不容易让后续的presum接上），value也小（index也靠前），各方面都不及`presum[i]+dp[i] -> i`优秀，今后注定不会被用到。将他们弹出之后，我们发现，map依然保持了我们想要的双递增的性质。

故这样的算法时间复杂度就是o(nlogn).
