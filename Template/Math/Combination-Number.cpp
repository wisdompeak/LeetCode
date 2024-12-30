using LL = long long;

/*********************************/
//  Version 1: compute all C(n,m) saved in comb
long long comb[1000][1000];  
for (int i = 0; i <= n; ++i) 
{
    comb[i][i] = comb[i][0] = 1;            
    if (i==0) continue;
    for (int j = 1; j < i; ++j) 
    {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
}  

/*********************************/
// Version 2: Compute C(n,m) on demand based on definition
long long help(int n, int m)
{
    long long cnt = 1;
    for(int i = 0; i < m; i++)
    {
        cnt *= n - i;
        cnt /= i + 1;
    }
    return cnt;
}

/*********************************/
// Version 3: Compute C(m,n) on demand with module M
using LL = long long;
LL M = 1e9+7;
vector<LL> factorial;

vector<LL> GetFactorial(LL N)
{
    vector<LL>rets(N+1);
    rets[0] = 1;
    for (int i=1; i<=N; i++)
        rets[i] = rets[i-1] * i % M;
    return rets;
}

long long quickPow(long long x, long long N) {
    if (N == 0) {
        return 1;
    }
    LL y = quickPow(x, N / 2) % M;
    return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
}

LL comb(LL m, LL n)
{
    if (n>m) return 0;
    LL a = factorial[m];
    LL b = factorial[n] * factorial[m-n] % M;
    LL inv_b = quickPow(b, (M-2));
    
    return a * inv_b % M;
}

/*********************************/
// Version 4: Compute C(m,n) on demand with module M
long long quickMul(long long x, long long N) 
{
    if (N <= 0) {
        return 1;
    }
    LL y = quickMul(x, N / 2) % MOD;
    return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
}
    
void precompute(int n, vector<long long>& fact, vector<long long>& inv_fact) 
{
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; ++i) 
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[n] = quickMul(fact[n], MOD - 2);
    for (int i = n - 1; i >= 1; --i) 
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

long long comb(int n, int k, const vector<long long>& fact, const vector<long long>& inv_fact) 
{
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
