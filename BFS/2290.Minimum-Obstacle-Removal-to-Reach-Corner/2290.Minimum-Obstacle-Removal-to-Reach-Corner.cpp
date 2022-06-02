class Solution {
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m==1 && n==1) return 0;
        vector<vector<int>>visited(m, vector<int>(n,0));
        
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0] = 1;
        
        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {                
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy]: dir)
                {
                    int i = x+dx;
                    int j = y+dy;                    
                    
                    if (i<0||i>=m||j<0||j>=n) continue;
                    if (visited[i][j]==1) continue;
                    if (grid[i][j] == 1)
                    {
                        visited[i][j] = 1;
                        q.push({i,j});
                    }                      
                    else
                    {
                        for (auto [ii, jj]: travel(grid, visited, i, j))
                        {
                            if (ii==m-1 && jj==n-1)
                                return step;
                            q.push({ii,jj});
                        }                                                
                    }
                }
            }
            step++;
        }
        return 0;        
    }
    
    vector<pair<int,int>>travel(vector<vector<int>>& grid, vector<vector<int>>& visited, int x0, int y0)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if (x0==m-1 && y0==n-1)
            return {{x0, y0}};
        
        queue<pair<int,int>>q;
        q.push({x0,y0});
        visited[x0][y0] = 1;
        
        vector<pair<int,int>>rets;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : dir)
            {
                int i = x+dx;
                int j = y+dy;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (visited[i][j]==1) continue;
                visited[i][j] = 1;
                if (i==m-1 && j==n-1)
                    rets.push_back({i,j});
                else if (grid[i][j]==1)
                    rets.push_back({i,j});
                else
                    q.push({i,j});
            }
        }
        
        return rets;
    }
};
