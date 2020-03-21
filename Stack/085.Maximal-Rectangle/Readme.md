# leetcode-85-Maximal-Rectangle  

此题是leetcode第84题的二维扩展，转化为求maximal histgram.  
```cpp
for (int i=0; i<M; i++)  //遍历histgram的底行位置。注意：不需要遍历histgram的顶行位置！
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
注意：      
1. 不要试图用预处理的DP算法（计算sum[i][j]），这样仍需要四重循环，时间复杂度太大。
2. MaxHistgram时的小技巧：在数组首尾都加零。前者避免 i-s.top()-1 时遇到栈空，后者保证总会进行一次退栈。


[Leetcode Link](https://leetcode.com/problems/maximal-rectangle)