class Solution {
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for (int i=1; i<=n-1; i++)
            dp[i][i+1]=i;
                
        for (int len=3; len<=n; len++)
        {
            for (int i=1; i<=n-len+1; i++)
            {
                int temp = INT_MAX;
                for (int j=i+1; j<=i+len-2; j++)
                {                    
                    temp = min( temp , j + max(dp[i][j-1], dp[j+1][i+len-1]));
                }
                dp[i][i+len-1]=temp;
            }
        }
        
        return dp[1][n];        
    }
};
