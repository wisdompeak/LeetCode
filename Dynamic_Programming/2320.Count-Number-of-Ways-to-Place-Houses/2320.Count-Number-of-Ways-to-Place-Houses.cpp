using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[10001][2];
public:
    int countHousePlacements(int n) 
    {                
        dp[1][0] = 1;
        dp[1][1] = 1;
        
        for (int i=2; i<=n; i++)
        {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1])%M;
            dp[i][1] = dp[i-1][0];            
        }
            
        LL ret = (dp[n][0]+dp[n][1]) % M;
        
        return ret * ret % M;
    }
};
