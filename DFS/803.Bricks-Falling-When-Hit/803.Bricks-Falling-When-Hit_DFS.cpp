class Solution {
    vector<vector<int>>visited; // 1: land, -1 : erased, 2 : connected
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        m = grid.size();
        n = grid[0].size();
                
        visited = grid;
        for (auto point:hits)        
            visited[point[0]][point[1]] *= -1;        
                        
        for (int j=0; j<n; j++)        
            if (visited[0][j]==1)
                dfs(0,j);                        
        
        vector<int>ret;
        reverse(hits.begin(),hits.end());
        for (auto point:hits)
        {
            int i = point[0], j = point[1];
            if (visited[i][j]!=-1) 
            {
                ret.push_back(0);
                continue;
            }
            bool connectRoof = (i==0);
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (visited[x][y]==2)
                {
                    connectRoof = true;
                    break;
                }                
            }
            
            if (connectRoof)
                ret.push_back(dfs(i,j-1);
            else
            {
                visited[i][j] = 1;            
                ret.push_back(0);
            }                            
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
    
    int dfs(int i, int j)
    {
        visited[i][j] = 2;
        int count = 1;        
        for (int k=0; k<4; k++)
        {
            int x = i+dir[k].first;
            int y = j+dir[k].second;
            if (x<0||x>=m||y<0||y>=n) continue;
            if (visited[x][y]==1)
                count += dfs(x,y);
        }        
        return count;
    }
};
