class Solution {
public:
    int ret = 0;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m = grid1.size();
        int n = grid1[0].size();
                
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid2[i][j] == 1)                    
                    bfs(grid1, grid2, i, j);                
            }
                
        return ret;
    }
    
    void bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid, int x0, int y0)
    {        
        queue<pair<int,int>>q;
        q.push({x0,y0});
        grid[x0][y0] = -2;
        
        auto dir = vector<pair<int,int>>({{0,1},{0,-1},{1,0},{-1,0}});
        int m = grid.size();
        int n = grid[0].size();

        int flag = 1;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (grid1[x][y]!=1) flag = 0;
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (grid[i][j]!=1) continue;

                grid[i][j] = -2;
                q.push({i,j});
            }
        }

        if (flag==1) ret+=1;
    }    
};
