### 3463.Check-If-Digits-Are-Equal-in-String-After-Operations-II

我们不难发现，如果将一个数组nums按照题目描述中的方法操作直至只剩一个元素，中间过程其实构造了一个杨辉倒三角形。每个元素对于最终结果的贡献次数，对应于二项式系数的分布（binomial coefficient）。假设nums长度是n+1，那么nums[i]在最终的结果中被累加了C(n,i)次。

根据题意，我们想求nums里前n-1个元素按照二项式系数权重累加后对于10的余数，是否等于nums里后n-1个元素按照二项式系数权重累加后对于10的余数。这其中就涉及到如何求任意的`C(m,k)%10`。C(m,k)里面有除法，对它的取模需要涉及除数的逆元。

首先，我们不能用费马小定理。因为这里的模数是10，并不是一个质数。此时可以想到分拆为2和5. 事实上，如果a与b关于2同余，并且关于5同余，那么一定关于10同余。所以我们对于本题，需要做两次分别关于2和5的同余的检查。

此时，我们能否用费马小定理求逆元呢？依然不能。费马小定理的使用有个条件，b不能被p整除。
```
a / b (mod p) = a * inv(b) (mod p)
where inv(b) = b^(p-2) and b cannot be divided by p.
```
这里的p非常小，分别是2和5，很容易被组合数计算表达式的分母整除。

因此此题涉及到了一个生僻的知识点，Lucas定理。见https://oi-wiki.org/math/number-theory/lucas/
```
long long Lucas(long long n, long long m, long long p) {
  if (m == 0) return 1;
  return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
```
用这个函数，我们就直接求得了`C(n,i)%p`的值，再作为nums[i]的系数带入计算。
