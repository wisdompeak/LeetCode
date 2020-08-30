class Solution {
    int m,n;
public:
    int minDays(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        
        int count = islands(grid);
        if (count > 1) return 0;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                grid[i][j] = 0;
                int count = islands(grid);
                if (count > 1) return 1;
                grid[i][j] = 1;
            }
        
        return 2;        
    }
    
    int islands(vector<vector<int>>& grid)
    {
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        auto visited = vector<vector<int>>(m, vector<int>(n,0));
        int count = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                if (visited[i][j]==1) continue;
                
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j] = 1;
                                
                count++;
                
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for (int k=0; k<4; k++)
                    {
                        int a = x+dir[k].first;
                        int b = y+dir[k].second;
                        if (a<0||a>=m||b<0||b>=n) continue;
                        if (grid[a][b]==0) continue;
                        if (visited[a][b]==1) continue;
                        q.push({a,b});
                        visited[a][b] = 1;                        
                    }
                }
                
                if (count == 2) return 2;
            }
        return count;
    }
};
