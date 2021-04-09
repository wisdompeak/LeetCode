class Solution {
    int m, n, t;
    vector<int> next[400];
    int match[400];
public:
    int maximumInvitations(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        t = m+n;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j])
                {
                    next[i].push_back(m+j);
                    next[m+j].push_back(i);
                }
            }
        
        for (int i=0; i<t; i++)
            match[i] = -1;
        
        vector<bool>visited(t);
        
        int count = 0;
        for (int i=0; i<m; i++)
        {
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
