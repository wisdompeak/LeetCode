using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[1000][1000];
public:
    int countPaths(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        LL ret = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                ret = (ret + dfs(grid, i, j)) % M;
        return ret;        
    }

    LL dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (dp[i][j]!=0) return dp[i][j];

        dp[i][j] = 1;
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int k=0; k<4; k++)
        {
            int x = i+dir[k].first;
            int y = j+dir[k].second;
            if (x<0||x>=m||y<0||y>=n) continue;
            if (grid[x][y]>=grid[i][j]) continue;
            dp[i][j] = (dp[i][j] + dfs(grid, x, y)) % M;
        }

        return dp[i][j];
    }
};
