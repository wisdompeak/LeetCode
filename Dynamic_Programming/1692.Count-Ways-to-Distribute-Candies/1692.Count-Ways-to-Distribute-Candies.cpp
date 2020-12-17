class Solution {
    long dp[1005][1005];
    long M = 1e9+7;
public:
    int waysToDistribute(int n, int k) 
    {
        for (int i=1; i<=n; i++)
            dp[i][1] = 1;
        
        for (int i=1; i<=n; i++)
            for (int j=2; j<=k; j++)
            {
                dp[i][j] = (dp[i-1][j-1] + j * dp[i-1][j] % M) % M;
            }
        return dp[n][k];
    }
};
