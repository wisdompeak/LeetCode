typedef long long ll;
class Solution {
    ll dp1[16][16];
    ll dp2[16][16];
    ll M = 1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        dp1[0][0] = grid[0][0];
        dp2[0][0] = grid[0][0];
        
        for(int i=1; i<m; i++)
        {
            dp1[i][0] = dp1[i-1][0]*grid[i][0];
            dp2[i][0] = dp2[i-1][0]*grid[i][0];
        }
        
        for(int j=1; j<n; j++)
        {
            dp1[0][j] = dp1[0][j-1]*grid[0][j];
            dp2[0][j] = dp2[0][j-1]*grid[0][j];
        }
        
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                dp1[i][j] = max(max(dp1[i-1][j]*grid[i][j], dp2[i-1][j]*grid[i][j]), max(dp1[i][j-1]*grid[i][j], dp2[i][j-1]*grid[i][j]));
                dp2[i][j] = min(min(dp1[i-1][j]*grid[i][j], dp2[i-1][j]*grid[i][j]), min(dp1[i][j-1]*grid[i][j], dp2[i][j-1]*grid[i][j]));
            }
        if (dp1[m-1][n-1] < 0)
            return -1;
        else
            return dp1[m-1][n-1]%M;
        
    }
};
