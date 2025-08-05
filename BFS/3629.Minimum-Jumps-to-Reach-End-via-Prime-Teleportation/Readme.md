### 3629.Minimum-Jumps-to-Reach-End-via-Prime-Teleportation

很容易判断，总体框架必然是BFS。

此题额外要求预处理nums里的每个质数与其倍数之间的映射关系，存入prime_to_idx中。一个高效的做法是在用埃氏筛判定1到M内的所有质数时，顺便记录下每个自然数的最小质因数（spf）。这样就方便我们对于nums的每个元素x做快速的质因数分解（不断去除以spf[x]），从而建立起它的所有质因子p到x的映射集合。

BFS的写法比较常规。从队列里弹出index=i后，考察是否需要将`i+1`, `i-1`以及`prime_to_idx[nums[i]]`（仅当nums[i]是质数时）放入队列。注意对于已经处理过的质数需要略过。
