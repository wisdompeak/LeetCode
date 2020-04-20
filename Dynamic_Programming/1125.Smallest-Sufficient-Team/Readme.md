### 1125.Smallest-Sufficient-Team

这本质是一道背包问题，用到了状态压缩的技巧。我们将当前所收集的技巧编码成一个整形skillset，每个bit位表示该技巧是否被收集到。dp[skillset]表示截止当前为止，实现skillset至少需要多少人。

仿照背包问题的套路，第一层循环我们遍历每个人，第二层循环我们遍历所有可能的skillset。考虑这个人的技能skills[i]带来什么样的impact呢？通过bit or操作，它可以将skillset升级为newSkillSet，于是dp[newSkillSet]就有机会更新为更小的值dp[skillset]+1.

遍历完所有的人之后，我们只需要查看的结果就是dp[requiredSkillSet]。
