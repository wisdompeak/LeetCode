class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        set<int> dp[101][101];
        
        if (grid[0][0]=='(')
            dp[0][0] = {1};
        else
            dp[0][0] = {};
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int k;
                if (grid[i][j]=='(')
                    k = 1;
                else
                    k = -1;
                
                if (i>=1) 
                {
                    for (int x: dp[i-1][j])
                        if (x+k>=0 && (m+n-1)-(i+j+1)>=(x+k))
                            dp[i][j].insert(x+k);
                }
                if (j>=1)
                    for (int x: dp[i][j-1])
                    {
                        if (x+k>=0 && (m+n-1)-(i+j+1)>=(x+k))
                            dp[i][j].insert(x+k);
                    }
            }
        
        return dp[m-1][n-1].find(0)!=dp[m-1][n-1].end();        
    }
};
