### 2403.Minimum-Time-to-Kill-All-Monsters

本题首先需要知道，并不是将monster按照从小到大排序就是最优解。Example 1 就是一个反例。考虑到monster的个数只有17，说明所有的状态数是`2^17=131072`，使用状态压缩dp的复杂度是可以接受的。

我们令二进制数state表示哪些怪兽被消灭，dp[state]表示消灭这些怪兽所需要的最少天数，因此状态转移方程取决于state里面哪一个是最后一只被消灭的怪兽，穷举一下即可：
```cpp
int k = __builtin_popcount(state); // state所对应的怪兽数目
for (int i=0; i<n; i++)
{    
    if (bit i属于state的子集）
      dp[state] = min{ dp[state - (1<<i)] + 怪兽i作为第k个目标所需要花费的时间}
}
```
最后返回`dp[(1<<n)-1]`.

整体的时间复杂度是`2^17*17 = 2e6`。
