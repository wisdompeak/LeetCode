class Solution {
    bool dp[101][101][103];
public:
    bool hasValidPath(vector<vector<char>>& grid) 
    {        
        int m = grid.size(), n = grid[0].size();
        
        if (grid[0][0]=='(')
            dp[0][0][1] = true;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<=(m+n-1)/2; k++)
                {
                    if (i==0 && j==0) continue;
                    
                    if (k>0 && grid[i][j]=='(')
                        dp[i][j][k] =  (i>=1 && dp[i-1][j][k-1]) || (j>=1 && dp[i][j-1][k-1]);
                    else if (grid[i][j]==')')
                        dp[i][j][k] =  (i>=1 && dp[i-1][j][k+1]) || (j>=1 && dp[i][j-1][k+1]);                    
                }

        return dp[m-1][n-1][0];
        
    }
};
