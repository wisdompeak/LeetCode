class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        auto visited = vector<vector<int>>(m,vector<int>(n,0));
        
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (visited[i][j] == 1) continue;
               
                queue<vector<int>>q;
                q.push({i,j,-1});
                visited[i][j] = 1;
                
                while (!q.empty())
                {
                    int x = q.front()[0];
                    int y = q.front()[1];
                    int d = q.front()[2];
                    q.pop();
                    
                    for (int k=0; k<4; k++)
                    {
                        if (d==0 && k==1) continue;
                        if (d==1 && k==0) continue;
                        if (d==3 && k==2) continue;
                        if (d==2 && k==3) continue;
                        int a = x+dir[k].first;
                        int b = y+dir[k].second;
                                                                        
                        if (a<0||a>=m||b<0||b>=n) continue;                        
                        if (grid[a][b]!=grid[x][y]) continue;
                        
                        if (visited[a][b]==1) return true;                                                
                        visited[a][b]=1;
                        q.push({a,b,k});
                    }
                }
            }
        
        return false;
    }    
};
