class Solution {
public:
    int houseOfCards(int n) 
    {
        vector<int>nums(501);
        for (int i=1; i<=500; i++)
            nums[i] = 2*i + (i-1);
        
        vector<vector<int>>dp(501, vector<int>(501,0));
        dp[0][0] = 1;
        for (int i=1; i<=n/2; i++)
            for (int j=0; j<=n; j++)
            {
                dp[i][j] = dp[i-1][j] + (j>=nums[i]?dp[i-1][j-nums[i]]:0);
            }
        
        return dp[n/2][n];        
    }
};
