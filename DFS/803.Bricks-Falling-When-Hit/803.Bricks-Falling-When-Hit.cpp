class Solution {
    vector<vector<int>>visited; // 1: land, -1 : erased, 2 : connected
    vector<pair<int,int>>dir;
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        int m = grid.size();
        int n = grid[0].size();
        dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        visited = grid;
        for (auto point:hits)        
            visited[point[0]][point[1]] *= -1;        
                        
        for (int j=0; j<n; j++)        
            if (visited[0][j]==1)
            {
                int num = 0;
                dfs(0,j,num);                        
            }
        
        vector<int>ret;
        reverse(hits.begin(),hits.end());
        for (auto point:hits)
        {
            int i = point[0];
            int j = point[1];
                        
            if (visited[i][j]!=-1) 
            {
                ret.push_back(0);
                continue;
            }
            bool find = (i==0);
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (!isValid(x,y)) continue;
                if (visited[x][y]==2)
                {
                    find = true;
                    break;
                }                
            }
            
            if (find)
            {
                int num = -1;
                dfs(i,j,num);                        
                ret.push_back(num);
            }
            else
            {
                visited[i][j] = 1;            
                ret.push_back(0);
            }                            
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
    
    bool isValid(int x, int y)
    {
        int m = visited.size();
        int n = visited[0].size();
        return !(x<0||x>=m||y<0||y>=n);
    }
    
    void dfs(int i, int j, int &num)
    {
        visited[i][j] = 2;
        num++;
        for (int k=0; k<4; k++)
        {
            int x = i+dir[k].first;
            int y = j+dir[k].second;
            if (!isValid(x,y)) continue;
            if (visited[x][y]==1)
                dfs(x,y,num);
        }        
    }
};
