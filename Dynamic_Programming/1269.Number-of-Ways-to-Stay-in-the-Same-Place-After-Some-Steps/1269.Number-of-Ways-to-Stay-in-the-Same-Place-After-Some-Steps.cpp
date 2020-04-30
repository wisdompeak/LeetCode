class Solution {
public:
    int numWays(int steps, int arrLen) 
    {
        int n = arrLen;
        auto dp = vector<vector<long>>(steps+1, vector<long>(steps/2+2,0));        
        dp[0][0] = 1;
        long M = 1e9+7;

        for (int k=1; k<=steps; k++)
        {            
            for (int i=0; i<steps/2+1; i++)
            {
                if (i==0)
                    dp[k][i] = (dp[k-1][i+1]+dp[k-1][i])%M;
                else if (i==n-1)
                    dp[k][i] = (dp[k-1][i-1]+dp[k-1][i])%M;
                else
                    dp[k][i] = (dp[k-1][i-1]+dp[k-1][i+1]+dp[k-1][i])%M;
            }
        }

        return dp[steps][0];
    }
};
