### 857.Minimum-Cost-to-Hire-K-Workers

我们考虑如果将```wage[i]/quality[i]```作为评价指标来进行排序意味着什么？

```wage[i]/quality[i]```最高的那位,意味着最不实惠的工人，它拉高了unitWage，使得其他工人都必须按照这个unitWage乘以各自的ｑｕａｌｉｔｙ拿工资．但转念一想，如果我们必须雇佣这个最不实惠的工人的话，那么剩下的工人该如何选择呢？显然我们只要选K-1个ｑｕａｌｉｔｙ最低的工人，他们可以拉高那个＂最不实惠工人＂的ｑｕａｌｉｔｙ比重，从而减少其他工人的ｑｕａｌｉｔｙ比重，从而降低总工资．

我们再考虑，如果选择了```wage[i]/quality[i]```第二高的那位，那么我们就在接下来的N-2个人里面选择K-1个ｑｕａｌｉｔｙ最底的工人即可．

由此贪心法的最优策略就出来了．实际操作中，我们根据```wage[i]/quality[i]```从低到高进行处理．


[Leetcode Link](https://leetcode.com/problems/minimum-cost-to-hire-k-workers)