CF中经常会要求这样输出结果：```Let this probability be represented as an irreducible fraction x/y. You have to print x⋅y^−1 mod 998244353, where y^−1 is the inverse element of y modulo 998244353 (such integer that y⋅y−1 has remainder 1 modulo 998244353).```

这里的inverse element并不是指的倒数，而是逆元。y的逆元写作y^-1，满足这样的性质：
```
x / y = x * y^-1 (mod M), M is a prime
```
逆元的计算方法如下：
```
a^-1 = (M- [M/a] )(M%a)^-1(mod M)，其中[]是向下取整。
```
代码如下，可以作为模板记下来。
```cpp
const ll N=1e6+7,mod=998244353;
ll inv[N];
for(inv[1]=1,i=2;i<N;++i)
    inv[i]=(mod-mod/i)*inv[mod%i]%mod
```
逆元的计算有如下的性质：
```
x1/y1 + x2/y2 = x1 * y1^-1 + x2 * y2^-1 (mod M)
x1/y1/y2 = x1 * y1^-1 * y2^-1 (mod M)
```
