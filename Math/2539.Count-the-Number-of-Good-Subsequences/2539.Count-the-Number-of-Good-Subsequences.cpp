using LL = long long;
class Solution {
    LL M = 1e9+7;
    vector<LL> factorial;
public:
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

    int countGoodSubsequences(string s) 
    {
        unordered_map<char, int>Map;
        for (auto ch: s)
            Map[ch] += 1;

        vector<LL>count;
        for (auto [k,v]: Map)
            count.push_back(v);

        int n = *max_element(count.begin(), count.end());

        factorial = GetFactorial(n);

        LL ret = 0;
        for (int f=1; f<=n; f++)
        {
            LL temp = 1;
            for (int c: count)
                temp  = temp * (comb(c, f)+1) % M;
            ret = (ret + temp -1) % M;
        }
        return ret;
    }
};
