# leetcode-85-Maximal-Rectangle  

此题是leetcode第84题的二维扩展，转化为求maximal histgram.  
```cpp
for (int i=0; i<M; i++)
{
   for (int j=0; j<N; j++)
   {
      if (matrix[i][j]==0)
        q[j]=0;
      else
        q[j]=q[j]+1;
   }
}
```
注意，不要试图用预处理的DP算法（计算sum[i][j]），这样仍需要四重循环，时间复杂度太大。
