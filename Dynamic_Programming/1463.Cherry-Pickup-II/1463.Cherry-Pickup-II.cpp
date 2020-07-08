class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        auto dp = vector<vector<int>>(n, vector<int>(n,INT_MIN/2));        
        dp[0][n-1] = grid[0][0]+grid[0][n-1];
        
        int ret = 0;        
        for (int t=1; t<m; t++)
        {
            auto dp_temp = dp;
            for (int i=0; i<n; i++)
                for (int j=i; j<n; j++)
                {
                    dp[i][j] = INT_MIN/2;
                    for (int a=i-1; a<=i+1; a++)
                        for (int b=j-1; b<=j+1; b++)
                        {
                            if (a<0||a>=n||b<0||b>=n) continue;
                            if (i==j)
                                dp[i][j] = max(dp[i][j], dp_temp[a][b]+grid[t][i]);
                            else
                                dp[i][j] = max(dp[i][j], dp_temp[a][b]+grid[t][i]+grid[t][j]);                            
                        }                    
                }                              
        }
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                ret = max(ret, dp[i][j]);
                
        return ret;
    }
};
