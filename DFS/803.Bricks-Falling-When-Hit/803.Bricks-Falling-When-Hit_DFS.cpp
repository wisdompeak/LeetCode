class Solution {
    int m,n;
    vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
public:    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        m = grid.size();
        n = grid[0].size();
        for (auto hit: hits)        
            grid[hit[0]][hit[1]] *= -1;
        
        for (int j=0; j<n; j++)
            if (grid[0][j]==1)
                dfs(grid, 0,j);
        
        // grid:  0 empty; 1 suspended brick; 2 ceiling brick; -1: hit
        
        vector<int>rets;
        reverse(hits.begin(), hits.end());
        for (auto hit: hits)
        {
            int i = hit[0], j = hit[1];
            if (grid[i][j]!=-1)
            {
                rets.push_back(0);
                continue;
            }
            bool connectCeil = (i==0);
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (grid[x][y]==2)
                {
                    connectCeil = true;
                    break;
                }
            }
            
            if (connectCeil)
            {
                rets.push_back(dfs(grid, i, j)-1);
            }
            else
            {
                grid[i][j] = 1;
                rets.push_back(0);
            }
        }
        reverse(rets.begin(), rets.end());
        
        return rets;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        grid[x][y] = 2;
        int count = 1;
        for (int k=0; k<4; k++)
        {
            int i = x+dir[k].first;
            int j = y+dir[k].second;
            if (i<0||i>=m||j<0||j>=n) continue;
            if (grid[i][j]==1)
            {
                count += dfs(grid, i,j);
            }
        }
        return count;
    }
};
