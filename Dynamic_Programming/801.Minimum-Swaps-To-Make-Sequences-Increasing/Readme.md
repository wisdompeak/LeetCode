### 801.Minimum-Swaps-To-Make-Sequences-Increasing

对于第i轮的决策而言，是否交换A[i]和B[i]，完全取决于A[i-1]和B[i-1]是否交换以及它们所在的位置。显然这是第I类基本型的DP：第i轮的状态只与第i-1轮的状态有关，且每轮的“状态”只有两种：交换或者不交换。

我们定义changed[i]表示第i轮交换且满足递增性质的最少操作数，unchanged[i]表示第i轮不交换且仍满足递增性质的最少操作数。

我们更新unchanged[i]的时候，考虑第i-1轮是否交换这两种情况，并检验是否合法。也就说，如果第i-1轮不交换，第i轮不交换，那么需要检查是否```A[i-1]<A[i] && B[i-1]<B[i]```，是的话，说明可以更新```unchanged[i]=unchanged[i-1]```。如果第i-1轮交换，第i轮不交换，那么需要检查是否```B[i-1]<A[i] && A[i-1]<B[i]```，是的话，说明可以更新```unchanged[i]=changed[i-1]```。

同理可以更新changed[i].

最终的答案就是最后一轮里changed和unchanged中的最大值。
