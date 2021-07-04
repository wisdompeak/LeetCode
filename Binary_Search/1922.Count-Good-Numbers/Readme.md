### 1922.Count-Good-Numbers

本题就是直接用```50. Pow(x, n)```实现快速幂的代码。基本思想是：```pow(x,k) = pow(x, k/2) ^2 * (k%2==1? x:1);```
