class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int k = primes.size();
        vector<int>p(k,0);

        vector<int>rets({1});

        for (int i=0; i<n-1; i++)
        {
            int nxt = INT_MAX;
            for (int j=0; j<k; j++)
                nxt = min(nxt, primes[j]*rets[p[j]]);
            for (int j=0; j<k; j++)
            {
                if (nxt == primes[j]*rets[p[j]])
                    p[j]++;
            }
            rets.push_back(nxt);
        }

        return rets.back();
    }
};
