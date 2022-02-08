class Solution {
    vector<int> next[90000];
    int match[90000];
public:
    int minimumOperations(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int t = m*n;
        
        vector<pair<int,int>>dir({{1,0},{-1,0},{0,1},{0,-1}});
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (grid[x][y]!=1)  continue;
                    next[i*n+j].push_back(x*n+y);
                }
            }
        
        for (int i=0; i<t; i++)
            match[i] = -1;
        
        vector<bool>visited(t);
        
        int count = 0;
        for (int i=0; i<t; i++)
        {
            if (match[i]!=-1) continue;
            visited.assign(t, 0);
            if (dfs(i, visited))
                count++;            
        }
        
        return count;
        
    }
                                        
    bool dfs(int i, vector<bool>&visited)
    {
        for (int j: next[i])
        {
            if (visited[j]) continue;
            visited[j] = true;
            if (match[j]==-1 || dfs(match[j], visited))
            {
                match[i] = j;
                match[j] = i;
                return true;
            }
        }
        return false;
    }                                        
};
