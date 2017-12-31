class Solution {
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
                
        for (int i=1; i<=n-1; i++)
            dp[i][i+1]=i;        
        
        for (int len=3; len<=n; len++)
        {
            for (int start=1; start<=n-len+1; start++)
            {
                int temp = INT_MAX;
                for (int x=start+1; x<start+len-1; x++)
                {                    
                    temp = min( temp , x+max(dp[start][x-1], dp[x+1][start+len-1]));
                }
                dp[start][start+len-1]=temp;
            }
        }
        
        return dp[1][n];
        
    }
};
