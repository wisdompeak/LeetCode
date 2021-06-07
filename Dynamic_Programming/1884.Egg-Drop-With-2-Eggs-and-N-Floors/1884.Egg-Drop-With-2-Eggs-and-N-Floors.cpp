class Solution {
    int dp[1005][3];
public:
    int twoEggDrop(int n) 
    {        
        for (int i=1; i<=n; i++)
            dp[i][1] = i;
        dp[1][2] = 1;
        
        for (int i=2; i<=n; i++)
        {
            dp[i][2] = i;
            for (int j=1; j<=i; j++)
            {                
                dp[i][2] = min(dp[i][2], max(dp[j-1][1], dp[i-j][2]) + 1);
            }
        }
        
        return dp[n][2];                            
    }
};
