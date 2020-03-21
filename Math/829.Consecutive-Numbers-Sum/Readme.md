### 829.Consecutive-Numbers-Sum

此题显然可以看出这就是求一个等差数列使得和为N。我们假设首项是x,项数是m,则有```(x+x+m-1)*m/2=N```

我们转换一下，得到```x=(2N-m(m-1))/2m```。我们可以看到只需要```2N-m(m-1)```能被```2m```整除的话，x就有解。所以我们可以考虑遍历m，如果这个m对应有正整数解x，那么就是满足题意的一种方案。


[Leetcode Link](https://leetcode.com/problems/consecutive-numbers-sum)