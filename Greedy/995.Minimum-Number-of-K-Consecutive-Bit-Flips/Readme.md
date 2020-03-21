### 995.Minimum-Number-of-K-Consecutive-Bit-Flips

本题的最优策略其实很容易想到。我们从前往后依次查看A[i]：如果A[i]是1，那么我们就跳过；如果A[i]是0，那么我们就翻转A[i]，同时需要带着一起翻转A[i+1]~A[i+K-1]。这样一直查下去，看最后K个数是否都是1. 显然我们就有了O(NK)的解法。C++耗时5000多毫秒，竟然也给过了。

很明显，上述解法的最大弊端是：当A[i]需要翻转时，我们还需要用for循环逐个翻转A[i+1]~A[i+K-1]，效率很差。很容易想到一个简单的改进的方法，用差分数组diff.差分数组diff[j]记录的是：A[j]经历的翻转次数要比A[j-1]经历的翻转次数多多少？比如说，我们将当前的A[i]翻转了，将会使得A[i+1]~A[i+K-1]整体的翻转次数提升一个，但是之后就又回落下去了。所以就记录下diff[i+1]+=1, diff[i+K]-=1，这样的话，对任意A[j]经历过的翻转总数是flipNum，那么A[j+1]需要经历的翻转总数就是flipNum+diff[j+1]。

类似用到差分数组的题目还有：370.Range-Addition


[Leetcode Link](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips)