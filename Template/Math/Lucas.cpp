/*
  To compute C(n,m) % p, when p is a small prime (and we cannot use Fermat's Little Theorem）
  https://oi-wiki.org/math/number-theory/lucas/
*/

long long Lucas(long long n, long long m, long long p) {
  if (m == 0) return 1;
  return (C(n % p, m % p) * Lucas(n / p, m / p, p)) % p;
}

long long C(int n, int m)
{
    long long cnt = 1;
    for(int i = 0; i < m; i++)
    {
        cnt *= n - i;
        cnt /= i + 1;
    }
    return cnt;
}
