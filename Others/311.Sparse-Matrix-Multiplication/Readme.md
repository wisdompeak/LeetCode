### 311.Sparse-Matrix-Multiplication

传统的矩阵乘法的写法是：
```cpp
        int M=A.size();
        int N=B[0].size();
        int K=A[0].size();
        
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             for (int k=0; k<K; k++)
                result[i][j]+=A[i][k]*B[k][j];
         }
```
观察可以发现，第二层和第三层循环之间没有其他语句，完全可以对调。对调之后，等于是给定了i和k再遍历j，就可以提前判断A[i][k]的性质，如果是零的话就可以跳过第三个循环。
```cpp
        for (int i=0; i<M; i++)
         for (int k=0; k<K; k++)
         {
             if (A[i][k]==0) continue;
             
             for (int j=0; j<N; j++)
                result[i][j]+=A[i][k]*B[k][j];
         }
```         


[Leetcode Link](https://leetcode.com/problems/sparse-matrix-multiplication)