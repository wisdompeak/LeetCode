### 732.My-Calendar-III

本题和253一模一样。典型的扫描线算法。

我们用一个按key有序的Map。每次调用book函数时，我们就操作```Map[start]+=1```和```Map[end]-=1```。然后遍历这个Map的key，按照时间轴的顺序累加差分值，即遇到1就加一，遇到-1就减一。这样就得到每个时刻有多少并行的会议。最终输出其中的最大值。

[Leetcode Link](https://leetcode.com/problems/my-calendar-iii)
