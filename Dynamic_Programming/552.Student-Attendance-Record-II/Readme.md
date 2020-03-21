### 552.Student-Attendance-Record-II

此题明显要用DP，但是如何设计状态和状态转移方程都非常难想。但最终的解法其实也非常巧妙，原来用到了多元状态的转移。

任何一种排列，可以归结为六种状态：dp00,dp01,dp02,dp10,dp11,dp12. 状态dp_ij的定义是：其中i表示这个数列里absence出现的次数，显然对于一个valid的数列，i的范围只能是0和1；j表示这个数列里末尾连续出现late的次数，显然对于一个valid的数列，i的范围只能是0，1，2。因此有六种状态的定义。

显然我们可以发现，随着record长度的增加，序列的状态就是在这六种之间转移。规律如下：
```
新状态   旧状态
dp02[i]  =  do01[i-1]  // 加'L'转变而来
dp01[i]  =  dp00[i-1]  // 加'L'转变而来
dp00[i]  =  dp00[i-1]+dp01[i-1]+dp02[i-1] // 分别加'P'转变而来
dp12[i]  =  dp11[i-1]  // 加'L'转变而来
dp11[i]  =  dp10[i-1]  // 加'L'转变而来
dp10[i]  =  dp10[i-1]+dp11[i-1]+dp12[i-1]+dp00[i-1]+dp01[i-1]+dp02[i-1] // 前三种加'P'转变而来，后三种加'A'转变而来
```
当然，因为dp**[i]的状态只取决于dp**[i-1]，所以也可以不用设置六个一位数组，节省一点空间。

另外，唯一需要需要注意的边界条件是```dp00[0]=1```

类似的DP题目还有：    
714.Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee    
487.Max Consecutive Ones II   
376.Wiggle Subsequence    
只不过用两个状态变量就够了.


[Leetcode Link](https://leetcode.com/problems/student-attendance-record-ii)