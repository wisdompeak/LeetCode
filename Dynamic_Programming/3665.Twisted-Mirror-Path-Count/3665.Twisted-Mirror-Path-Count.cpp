class Solution {
    int dp[501][501][2];
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int M = 1e9+7;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) {
                    dp[i][j][0] = 1;                    
                    continue;
                }
                int ret = 0;
                if (i>=1 && j>=0) {
                    if (grid[i-1][j]==0)
                        dp[i][j][0] += dp[i-1][j][0]+dp[i-1][j][1];
                    else
                        dp[i][j][0] += dp[i-1][j][1];
                }                    
                if (i>=0 && j-1>=0) {
                    if (grid[i][j-1]==0)
                        dp[i][j][1] += dp[i][j-1][0]+dp[i][j-1][1];
                    else
                        dp[i][j][1] += dp[i][j-1][0];
                }
                dp[i][j][0]%=M;
                dp[i][j][1]%=M;
            }
        return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%M;
    }
};
