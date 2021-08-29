### 1986.Minimum-Number-of-Work-Sessions-to-Finish-the-Tasks

因为数据规模n<=14，考虑到3^14是4e6数量级，可以判定这是非常套路的“枚举子集”的动态规划问题。

我们用长度为14的二进制数state的每个bit位表示该任务是否被实施，那么dp[state]表示state所代表的任务集合需要最少多少个session。

利用枚举子集的模板：
```cpp
  for (int state=1; state<(1<<n); state++)  
      for (int subset=state; subset>0; subset=(subset-1)&state)
      {
          dp[state] = DoSomething(dp[subset]);
      }  
```
dp[state]如果对应着多个session，那么它必然可以“拆分”成两个任务集subset与state-subset，然后对各自所需的session数目进行相加。所以我们需要遍历state的所有subset，找到最优的一种拆分。即```dp[state]=min{dp[subset]+dp[state-subset]}```。注意，上述的枚举子集的框架，所需要的时间复杂度是o(3^n)而不是o(2^n)

初始值：对于一些特定的任务组合state，如果总时间小于sessionTime，那么他们的dp[state]就是1. 其余的dp[state]我们都设置为无穷大。这需要花费2^n的时间预处理遍历所有的组合。。

