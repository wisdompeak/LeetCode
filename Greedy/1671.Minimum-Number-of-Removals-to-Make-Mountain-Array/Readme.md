### 1671.Minimum-Number-of-Removals-to-Make-Mountain-Array

我们遍历每个元素nums[i]，思考如果它作为peak，那么能够得到多长的mountain array。显然，对于peak的左侧，我们需要寻找一个从左往右的、截止在nums[i]的最长递增序列（LIS）；同理，对于peak的右侧，我们需要寻找一个从右往左的、截止在nums[i]的最长递增序列。

我们知道经典的LIS算法，可以用o(N^2)或者o(NlogN)的复杂度，计算数组里面（截止至）每个元素的LIS的长度。我们预处理得到这样的leftLIS[i]和rightLIS[i]之后，那么以nums[i]为peak的mountain array的长度就是leftLIS[i]+rightLIS[i]-1.

特别需要注意的是，本题要求合法的mountain array必须满足leftLIS和rightLIS的长度都要至少是2.
