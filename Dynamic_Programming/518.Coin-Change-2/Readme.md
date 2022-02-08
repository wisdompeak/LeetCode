### 518.Coin-Change-2

这道题看上去很像完全背包问题，因为所有的硬币可以无限使用。让我们回顾一下传统的完全背包是怎么做的。我们令dp[c]表示总（实际使用）容量为c的时候可以装的最大价值。外层循环遍历容量，内层循环遍历最后一件放入的物品：
```
for c in capcity:
    for i in obj:
        dp[c] = max(dp[c], dp[c-cost[i]]+val[i];
```
但是如果将完全背包的算法套到这个问题上来是不对的。上述的完全背包问题里，如果A、B两件物品构成了容量c的最优解，那么计算dp[c]时无论考虑A是最后一件还是B是最后一件，得到的dp[c]都是一样的（即两件物品的价值之和）。

但是在本题中，我们求的是组合方法的种类。如果我们定义dp[c]表示容量c的组合数，那么考虑先A后B的方法的话，dp[c]+=dp[a];但是考虑先B后A的方法的话，dp[c]+=dp[b]. 显然这两次的自增是重复计算AB这套组合了。所以此题的本质并不是一个完全背包问题，因为它的问题并不是求总价值的最优。

那么抛开完全背包问题的思维束缚，该如何思考这道题呢？我们知道为了避免在组合选数中重复计数，一个常见的办法就是排个序：意思是如果取若干个A之后再取若干个B的话，那么之后我们就不能再取A了。所以我们可以依次考虑每个硬币、以及每个硬币能选几个：
```cpp
for (int i=0; i<coins.size(); i++)
    for (int c=1; c<=amount; c++)
    {
        for (int k=0; k<=c/coins[i]; k++)
            dp[i][c] += dp[i-1][c - k*coins[i]];
    }
```
其中dp[i][c]表示使用前i种硬币、组成面值为c的组合方法数。注意，外层的两个循环其实可以对调，不影响结果。并且我们还可以只用一维数组：
```cpp
for (int i=0; i<coins.size(); i++)
{            
    auto dp_temp = dp;            
    for (int c=1; c<=amount; c++)
    {
        dp[c] = 0;
        for (int k=0; k<=c/coins[i]; k++)
            dp[c] += dp_temp[c-k*coins[i]];
    }
}
```

但是这三重循环的效率有点低。如果我们只用dp[c]来表示面值为c的组合方法数，那么可以化简为
```cpp
for (int i=0; i<coins.size(); i++)
    for (int c=1; c<=amount; c++)
    {        
        dp[c] += dp[c - coins[i]];
    }
```
这是因为我们在计算dp[c]时，考虑的是末尾是coins[i]的方案。巧妙的是，我们不需要分类考虑dp[c]的末尾到底应该有几个，只需要考虑如果有一个的话，可以直接转化为dp[c-coins[i]]。而dp[c-coins[i]]是已经提前计算好了的（因为c-coins[i]比c小）、同样也表示末尾是coins[i]的方案。有点递归的感觉。

[Leetcode Link](https://leetcode.com/problems/coin-change-2)
