using LL = long long;
class Solution {    
public:        
    const LL MOD = 1e9 + 7;
    vector<LL> factorial;
    vector<LL> GetFactorial(LL N)
    {
        vector<LL>rets(N+1);
        rets[0] = 1;
        for (int i=1; i<=N; i++)
            rets[i] = rets[i-1] * i % MOD;
        return rets;
    }

    long long quickPow(long long x, long long N) {
        if (N == 0) {
            return 1;
        }
        LL y = quickPow(x, N / 2) % MOD;
        return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
    }

    LL comb(LL m, LL n)
    {
        if (n>m) return 0;
        LL a = factorial[m];
        LL b = factorial[n] * factorial[m-n] % MOD;
        LL inv_b = quickPow(b, (MOD-2));

        return a * inv_b % MOD;
    }

    int countGoodArrays(int n, int m, int k) 
    {
        factorial = GetFactorial(n);        
        return comb(n-1,k) * m % MOD * quickPow(m-1, n-k-1) % MOD;        
    }
};
