class Solution {
    vector<pair<int,int>>dir;
    int memo[501][501][4][2];
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        dir = {{-1,1},{1,1},{1,-1},{-1,-1}};
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==1)
                {
                    ret = max(ret, dfs(grid,i,j,0,1));
                    ret = max(ret, dfs(grid,i,j,1,1));
                    ret = max(ret, dfs(grid,i,j,2,1));
                    ret = max(ret, dfs(grid,i,j,3,1));
                }                    
            }
        return ret;
    }

    bool canContinue(int a, int b)
    {
        if (a==1 && b!=2) return false;
        if (a==2 && b!=0) return false;
        if (a==0 && b!=2) return false;
        return true;
    }
    bool inbound(int i, int j, int m, int n)
    {
        return i>=0 && i<m && j>=0 && j<n;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int k, int t)
    {        
        if (memo[x][y][k][t]!=0) return memo[x][y][k][t];

        int m = grid.size(), n = grid[0].size();
        int ret = 1;

        int i = x+dir[k].first, j = y+dir[k].second;
        
        if (inbound(i,j,m,n) && canContinue(grid[x][y], grid[i][j]))
            ret = max(ret, 1 + dfs(grid,i,j,k,t));

        if (t==1)
        {
            int kk=(k+1)%4;
            i = x+dir[k].first, j = y+dir[k].second;
            if (inbound(i,j,m,n) && canContinue(grid[x][y], grid[i][j]))
                ret = max(ret, 1 + dfs(grid,i,j,kk,0));        
        }                
        memo[x][y][k][t] = ret;
        return ret;
    }
};
