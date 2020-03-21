### 956.Tallest-Billboard

此题乍看很像背包问题，我们来想想如果是背包问题的话会怎么做。

经典的背包问题的思路是：我会设置布尔状态dp[left][right]，表示是否能得到左边高度是left,右边高度是right的状态。每次考虑一个rod[i]，考察把它放在左边，放在右边，以及不用三种情况下，对后续dp的影响。也就是说，如果```dp[left][right]==true```，那么```dp[left+rods[i]]```和```dp[right+rods[i]]```也都可以赋值为true。

以上解法的最大问题是空间和时间的开销都很大，因为left和right都是[0,5000]的区间。空间是o(5000^2)，时间则是o(N*5000^2)。

怎么优化呢？一个想法是反思状态dp设计得是否合理。在上述的设计中，我们最终要找的是一个最大的k，使得有dp[k][k]==true。但其实我们发现，大部分的dp存储的信息最终都浪费掉了，特别是dp代表一个布尔状态，只存储true或false是不是太可惜了。我们最终要求的只是一个左右相等的状态，但我们几乎求解了所有可能的left/right pair，有必要吗？于是这就激励我们，考察左右的差值diff，这是一个[-5000,5000]范围的变量。假设我们如果已经知道了一个固定的diff，我们最希望得到的是什么呢？当然是在此条件下最大的left/right了。因为我们最终答案希望是diff=0时最大的left/right，在后续的探索中，如果用到了这个diff，我们自然只会利用这个最大的left/right。

于是我们可以尝试写出状态
```
dp[diff] = max{ Left | s.t Left-Right = diff}
```
也就是说，我们在当前这一轮中，dp[diff]表示当前所有left-right==diff的配对中，最大的那个Left（相应Right其实也可以确定下来）

如何更新状态呢？假设我们已经有了dp[diff]=left，现在要考察rods[i]，这个棍子有三种选择：

1.我们不使用这根棍子，所有的diff都不受影响，故dp[diff]不变。

2.我们将这根棍子加在left上，那么diff就会变大，我们就可能需要更新diff+rods[i]对应的dp,而这个对应的dp值就是left+rods[i]。

3.我们将这根棍子加在right上，那么diff就会变小，我们就可能需要更新diff-rods[i]对应的dp,而这个对应的dp值依然是left（因为左棍的长度不变）。

需要注意的是，以上的更新只有在left存在的情况下进行。也就是说，需要保证dp[diff]=left有意义。初始化时，只有dp[0]=0,表示初始状态下高度差为0的方案就是left=0,right=0; 其他所有的dp[diff]都标记为-1，表示目前非法。

另外，需要注意，diff的范围是[-5000,5000]，但是dp[diff]数组的index不能是负数。我们在处理下标时需要一个偏移量5000。


[Leetcode Link](https://leetcode.com/problems/tallest-billboard)