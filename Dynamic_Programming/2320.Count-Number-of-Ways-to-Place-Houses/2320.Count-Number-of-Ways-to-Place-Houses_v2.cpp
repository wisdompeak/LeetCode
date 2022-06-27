using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[10001];  // dp[i]: the # of plans so that there is a building at the i-th plot
public:
    int countHousePlacements(int n) 
    {                
        dp[0] = 0;
        dp[1] = 1;
                
        for (int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%M;                        
        }

        LL ret = 1;
        for (int i=1; i<=n; i++)
            ret = (ret+dp[i]) % M;
            
        return ret * ret % M;
    }
};
