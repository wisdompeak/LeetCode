using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[10001][2]; 
    // dp[i][0]: the # of plans so that there is no building at the i-th plot
    // dp[i][1]: the # of plans so that there is a building at the i-th plot
public:
    int countHousePlacements(int n) 
    {                
        dp[0][0] = 1;
        dp[0][1] = 0;
        
        for (int i=1; i<=n; i++)
        {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1])%M;
            dp[i][1] = dp[i-1][0];            
        }
            
        LL ret = (dp[n][0]+dp[n][1]) % M;
        
        return ret * ret % M;
    }
};
