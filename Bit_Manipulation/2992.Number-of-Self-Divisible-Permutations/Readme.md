### 2992.Number-of-Self-Divisible-Permutations

此题如果暴力DFS的话，会有12!种排列，显然会TLE.

考虑到2^12=4096，我们可以逐位填充，用一个bitmask来表示哪些数字已经被选中了。令dp[i][state]表示前i位里填充状态是state（每个bit位表示对应的数字已经使用）时，有多少种合法的排列。有状态转移方程
```cpp
for (int d=1; d<=n; d++)
{
    if (gcd(d,i)!=1) continue;
    if (((state>>(d-1))&1)==0) continue;
    dp[i][state] += dp[i-1][state-(1<<(d-1))];
}
```
最终返回dp[n][(1<<n)-1].
