### 2025.Maximum-Number-of-Ways-to-Partition-an-Array

在不做任何改动的情况下，我们的工作很简单，就是查看哪些presum等于sum/2，用Hash统计一下即可。

如果我们对nums[i]做了变动，那么就有```new_sum = sum + d```其中```d = k-nums[i]```. 此时我们想要看的是更新后的new_presum里有多少等于new_sum/2。但是如果把所有的new_presum都计算一遍，需要o(N)的操作，很不合算。此时我们发现，在i之前的那些presum其实是没有变化的，即```new_presum = presum```。也就是说，如果有合法的切分点位于i之前，那么我们只需要在之前的presum里查看一下即可。

那么很显然，下一步我们会想，如果有合法的切分点位于i之后，我们还是得查看new_presum对不对？此时我们转念一下，在这种情况下，切分点后面的sufsum数列其实没有改变。如果有sufsum等于new_sum/2，那么同样意味着整个数组可以等分为两半。

所以本题的算法很简单：预先计算presum和sufsum。遍历改动的位置nums[i]，在i之前查看有多少presum等于new_sum/2，再在i之后查看有多少sufsum等于new_sum/2. 这两部分方案数之和就是这次改动能够成立的partition方法。
