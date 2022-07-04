using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[1005];
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        dp[1] = 1;
        for (int i=1; i<=n; i++)
        {
            for (int j=i+delay; j<i+forget; j++)
            {
                if (j>n) break;
                dp[j] += dp[i];
                dp[j] %= M;
            }                
        }

        LL ret = 0;
        for (int i=1; i<=n; i++)
        {
            if (i+forget>n)
                ret = (ret + dp[i]) % M;
        }            

        return ret;        
    }
};
