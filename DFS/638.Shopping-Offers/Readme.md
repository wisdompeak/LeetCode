### 638.Shopping-Offers

设计递归函数dfs(state)，其中state表示还有哪些物品没有采购，返回的值表示采购完这些物品的最少代价。

考虑到最多只有6件物品，每个物品最多6个。所以我们用18个bit的二进制数来表示状态。每3个bit可以表示该种物品的数量（从0到7）。

在dfs(state)里，为我们尝试每一种合法的offer，将state更新后递归处理。我们取所有尝试中代价最小的结果，并记录在memo[state]里面。

需要注意的细节：
1. 有些offer是不合算的，可以提前从special里排除掉；
2. 在dfs(state)里，除了尝试offer，还可以直接从prices里面按原价采购每一件物品。

PS: 最新的题目里把每种物品的数量放宽到了10件，所以需要```4*6=24```个bit的二进制数来表示状态。


[Leetcode Link](https://leetcode.com/problems/shopping-offers)
