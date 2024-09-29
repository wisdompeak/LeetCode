### 3307.Find-the K-th-Character-in-String-Game-II

假设当前总共有n个字符，求其中的第k个。显然，如果k是在前n/2里，那么等效于求`dfs(n/2,k)`。如果是在后半部分，那么它其实是前半部分里第`k-n/2`个字符shift一位之后的结果，故等效于`dfs(n/2,k-n/2)+1`. 以此递归处理即可。时间就是logN.
