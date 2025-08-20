#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 1e6+7, MOD = 998244353;

/*********************************/
// Linear method to compute inv[i]
vector<LL>compute_inv(int n)
{    
    vector<int>inv(n+1);
    inv[1] = 1;
    for(int i=2; i<n; ++i)
        inv[i]=(MOD-MOD/i) * inv[MOD%i] % MOD;
}

/*********************************/
// Qucik Pow Method, based on Fermat's little theorem

long long quickPow(long long x, long long N) 
{
    if (N <= 0) {
        return 1;
    }
    long long y = quickPow(x, N / 2) % MOD;
    return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
}

long long inv(long long x) 
{
    return quickPow(x, MOD - 2);
}

/*****************************/

long long compute_inv(int x) 
{
    LL s = 1;
    for (; x > 1; x = MOD%x)
      s = s*(MOD-MOD/x)%MOD;
    return s;
}
