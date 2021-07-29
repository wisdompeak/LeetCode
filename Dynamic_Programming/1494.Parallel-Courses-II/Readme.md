### 1494.Parallel-Courses-II

此题乍看贪心法可解。如果想要得到一个合法的课程顺序，必然利用拓扑排序的手段，首先完成那些入度为0的课程。但是本题特别之处在于，如果入度为0的课程多于k个，那么第一轮该优先选取哪k个，才能保证最终用最少的轮数完成所有课程？事实上，并没有任何有效的贪心策略能够帮助挑选这k个课程。优先有序节点总数多的课程，或者优先后续节点深度多的课程，都是没有道理的。

事实上这是一道NP问题，并没有多项式时间的解法。所以只好用暴力的方法去解决。状态压缩DP就是比较“高效”的暴力方法。事实上，题目给出n<=15的条件，就暗示了应该用这种方法。

我们用整形变量state的各个bit位来代表是否完成了某门课程，比如说第i个bit位是1就表示完成了第i门课程。dp[state]表示完成对应的这些课程需要最少多少轮。显然，我们需要考虑前一轮的状态prevState是什么？显然我们找一个最小的dp[prevState]然后加1，就可以得到最优的dp[state]。

我们知道prevState必然是state的子集。我们可以用暴力搜索所有它的子集，这里有一个比较高效的循环语句值得收藏：
```cpp
for (int subset=state; subset>0; subset=(subset-1)&state)
```
这样得到的subset是比较高效的。

那么接下来我们就要判断这个subset对应的状态，是否能够通过新一轮的课程学习，达到state对应的状态。这里需要几个条件：
1. state的课程数目不能比subset的课程数目多余k。这可以用C++的内置函数来实现：
```cpp
__builtin_popcount(state) - __builtin_popcount(subset) <= k
```
2. state的课程的先修课程，必须全部囊括在subset里面。也就是说，subset必须是state先修课程的超集。我们需要提前计算出state的先修课程集合prevState[state]，然后判断是否
```cpp
prevState[state] & subset == prevState[state]
```
满足这两个条件的话，那么就说明subset是可以转移到state的。故有```dp[state]=dp[subset]+1```

此外，我们可以提前处理数据，计算所有状态的prevState。这个不难做到，只要将state的每一门课程的先修课程取并集即可。
