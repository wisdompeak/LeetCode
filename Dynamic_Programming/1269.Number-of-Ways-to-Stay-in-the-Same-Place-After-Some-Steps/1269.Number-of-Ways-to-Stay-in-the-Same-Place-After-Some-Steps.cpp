class Solution {
public:
    int numWays(int steps, int arrLen) 
    {
        arrLen = min(steps, arrLen);
        int M = 1e9+7;
        auto dp = vector<vector<int>>(steps+1, vector<int>(arrLen,0));
        dp[0][0] = 1;
        
        for (int i=1; i<=steps; i++)
        {
            for (int j=0; j<arrLen; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (j>0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%M;
                if (j<arrLen-1) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%M;                
            }
        }
        
        return dp[steps][0];
        
    }
};
