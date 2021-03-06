### 1872.Stone-Game-VIII

题目问的是最终先手相对于后手最多的净胜分，因此相应地，我们设计dp[i]表示当剩下i堆时，先手能比后手最多的净胜分。最终输出的答案是dp[n]. 另外设计前缀和数组presum[i]表示前i堆的石头总重量。

我们来看dp[1]，表示当前仅有一堆，根据规则先手无法再取，自然也没有后手，随意净胜为0，即```dp[1] = 0```.

我们再看dp[2]，表示当前有堆石头，根据规则先手只有一个决策：必须取走这两堆，且该轮得分就是这两堆的重量。事实上这两堆的重量就是全部石头的重量，即presum[n]。先手走完之后，后手面对的是仅有一堆石头的情况，它在该状态下能得的净胜分其实就是dp[1]. 所以对于dp[2]而言，先手的最大净胜分就是```presum[n]-dp[1]```.

我们再看dp[3]，表示当前有三堆。根据规则先手有两种决策：1. 取走全部的三堆，该轮得分是presum[n]，留给对手的状态是dp[1]，故先手的净胜分是```presum[n]-dp[1]```. 2. 取走左边的两堆，注意到这样的话该轮得分的本质是presum[n-1]，就给对手的状态是dp[2]，故先手的净胜分是```presum[n-1]-dp[2]```. 那么综上，对于dp[2]而言，肯定会选择```presum[n]-dp[1]```和```presum[n-1]-dp[2]```之间更大的数值做决策。

相应地，我们查看dp[4]，可以推出，当先手选择取走四堆、三堆、两堆，分别对应的净胜分就是```presum[n]-dp[1]```，```presum[n-1]-dp[2]```，```presum[n-2]-dp[3]```。我们会在这三项中选择最大的一个。而前面两项在考察dp[2]时已经计算过了，这次只不过多了一个新选项而已。

可见，我们考察dp[i]的时候，其实就是在dp[i-1]和新选项```presum[n-i+2]-dp[i-1]```中取一个更大的。

这样我们就从dp[1]一直推到dp[n]，即是答案。
