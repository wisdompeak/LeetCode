### 2911.Minimum-Changes-to-Make-K-Semi-palindromes

要在整个字符串中分割出k个区间，显然是dp的套路。令dp[i][p]表示将前i个字符分割成符合条件的p个区间，所需要的最小改动操作。显然有：
```cpp
for (int i=0; i<n; i++)
  for (int p=1; p<=k; p++)
    for (int j=0; j<i; j++
      dp[i][p] = min(dp[i][p], dp[j][p-1]+range[j+1][i]);
```
其中range[j+1][i]表示在[j+1:i]这个区间内，使得其变为k-semi-palindrome的最少改动次数。如果无法实现，那么则赋值为无穷大。

根据题目的数据范围，o(n^3)是可以接受的。最终返回的就是dp[n-1][k].

那么如何generally求range[a][b]呢。我们可以提前用o(n^3)的时间处理所有的区间即可。
```cpp
for (int i = 0; i < n; i++)        
    for (int j = i; j < n; j++)
    {       
        int len = j-i+1;
        for (int d=1; d<=len/2; d++)
        {
            if (len%d!=0) continue;
            int sum = 0;
            for (int r=0; r<d; r++)
                sum += helper(s, i, j, d, r);  // 从i到j区间内，从第r个开始，依次间隔d
            range[i][j] = min(range[i][j], sum);
        }
    }
```
注意，d与r的两层循环共用o(nlogn)的复杂度。对于一个长度len，它的因子的个数有log(len)个；对于每个因子都需要把整个len长度的子串遍历一遍
