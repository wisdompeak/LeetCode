class Solution {
public:
    int houseOfCards(int n) 
    {
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for (int i=1; i<=n/2; i++)
            for (int j=0; j<=n; j++)
            {
                dp[i][j] = dp[i-1][j] + (j>=(3*i-1)?dp[i-1][j-(3*i-1)]:0);
            }
        
        return dp[n/2][n];        
    }
};
