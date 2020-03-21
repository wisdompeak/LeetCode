### 474.Ones-and-Zeroes

本题本质就是0-1背包问题，只不过cost变成了两个量。0-1背包问题已经有非常成熟的套路了。dp[i][j]表示用i个0和j个1最多可以拼出多少个完整的字符串。

```cpp
        for (int k=0; k<strs.size(); k++)  //遍历所有的字符串
        {
            检查当前字符串strs[k]，得到有zeros个0，ones个1;
                            
            auto temp=dp;
            for (int i=zeros; i<=m; i++)
             for (int j=ones; j<=n; j++)
             {
                 dp[i][j]=max(temp[i][j],temp[i-zeros][j-ones]+1);
                 //在循环体里更新所有的dp[i][j]。
                 //这里用了一个temp来保存上一轮（即处理上一个字符串时）的dp
                 //对于当前的字符串，有两种选择，要么不加入，则dp[i][j]不变；要么加入，则更新为temp[i-zeros][j-ones]+1                
             }            
        }
```

这里用temp的原因是方便起见，以免更新dp时使用了这一轮的新dp值。当然，也有取巧的办法省下temp的开辟，即在两个内存for循环里将i，j都按从大到小遍历，那么更新dp时就不会与新值冲突。


[Leetcode Link](https://leetcode.com/problems/ones-and-zeroes)