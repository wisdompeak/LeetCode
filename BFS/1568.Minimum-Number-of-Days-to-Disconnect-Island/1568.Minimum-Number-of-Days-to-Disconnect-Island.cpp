class Solution {
    int m,n;
public:
    int minDays(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        
        int count = island(grid);
        if (count > 1 || count == 0) return 0;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                grid[i][j] = 0;
                int count = island(grid);
                if (count>1 || count==0) return 1;
                grid[i][j] = 1;
            }
        return 2;        
    }
    
    int island(vector<vector<int>>& grid)
    {
        auto visited = vector<vector<int>>(m, vector<int>(n,0));
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        int count = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                if (visited[i][j]==1) continue;
                
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j] = 1;
                
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
                        if (visited[a][b]==1) continue;
                        if (grid[a][b]==0) continue;
                        
                        q.push({a,b});
                        visited[a][b]=1;                        
                    }
                }
                
                count+=1;
                if (count>1) return 2;                
            }
        return count;
    }
};
