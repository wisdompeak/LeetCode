### 2539.Count-the-Number-of-Good-Subsequences

我们遍历频次f从1到n（其中n是所有字母里最高的频次）。对于固定的频次f，我们考察26个字母中，每个字母取f个的组合数comb(c,f)，以及不取的决策（即+1），这样就可以保证所取的子序列里每个字母的频次都一致。
```cpp
for (int f=1; f<=n; f++)
{
    LL temp = 1;
    for (int c: count)
        temp  = temp * (comb(c, f)+1) % M;
    ret = (ret + temp -1) % M;
}
```
注意，对于频次f，我们其实都包括了“全不取”的策略，这相当于空串是不合法的，所以对于每个temp我们都要减一。

关于计算组合数，应为要对M取模，我们可以直接用组合数定义和费马小定理来硬算，即
```cpp
LL comb(LL m, LL n)
{
    if (n>m) return 0;
    LL a = factorial[m];
    LL b = factorial[n] * factorial[m-n] % M;
    LL inv_b = quickPow(b, (M-2));    
    return a * inv_b % M;
}
```
