CF中经常会要求这样输出结果：
```
Let this probability be represented as an irreducible fraction x/y. 
You have to print x⋅y^−1 mod 998244353, where y^−1 is the inverse element of y modulo 998244353 (such integer that y⋅y−1 has remainder 1 modulo 998244353).
```

这里的inverse element并不是指的倒数，而是逆元。y的逆元写作y^-1，

更一般地，我们说如果a和b满足这样的性质：
```
x / a ≡ x * b (mod M)
```
从形式上来看，b好像就与1/a（在同余的意义上）等价，所以我们称b就是a的逆元，记做 b = a^-1（反之也成立）。     
对于a而言，存在逆元的充要条件是a与M互质。当然，我们做题时M一般都已经是质数。

#### 逆元的计算方法

##### 方法1：
```
a^-1 ≡ (M- [M/a] )(M%a)^-1  (mod M)，其中[]是向下取整。
```

##### 方法2：快速幂法
根据费马小定理，我们有
```
a^-1 ≡ a ^ (M-2)  (mod M)
```
显然，我们需要利用快速幂来计算这个数。

##### 方法3：线性求逆元
如果我们想求1,2,3...N 每个数的逆元：
```cpp
const ll N = 1e6+7, M = 998244353;
ll inv[N];
int i;
for(inv[1]=1, i=2; i<N; ++i)
    inv[i] = (M - M/i) * inv[M % i] % M
```

#### 逆元的一些性质
逆元的计算有如下的性质：
```
x1/y1 + x2/y2 ≡ x1 * y1^-1 + x2 * y2^-1 (mod M)
x1/y1/y2 ≡ x1 * y1^-1 * y2^-1 (mod M)
```
