using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[305];
public:
    int numberOfWays(int n, int x) 
    {
        dp[0] = 1;
        
        for (int i=1; i<=n; i++)
        {            
            LL num = 1;
            for (int t=0; t<x; t++)
                num *= i;
            
            for (int s = n; s >= num; s--)
            {
                dp[s] += dp[s-num];
                dp[s] %= M;
            }                
        }
        
        return dp[n];
    }
};
