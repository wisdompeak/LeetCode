using LL = long long;
LL M = 1e9+7;
class Solution {    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<LL>>>dp(m, vector<vector<LL>>(n, vector<LL>(k)));
        
        LL sum = 0;
        for (int i=0; i<m; i++)
        {
            sum += grid[i][0];
            sum %= k;
            dp[i][0][sum] = 1;
        }
        
        sum = 0;
        for (int j=0; j<n; j++)
        {
            sum += grid[0][j];
            sum %= k;
            dp[0][j][sum] = 1;
        }
        
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)            
                for (int t=0; t<k; t++)
                {
                    LL r = ((t-grid[i][j])%k+k)%k;
                    dp[i][j][t] = dp[i-1][j][r] + dp[i][j-1][r];
                    dp[i][j][t] %= M;                    
                }
        
        return dp[m-1][n-1][0];
    }
};
