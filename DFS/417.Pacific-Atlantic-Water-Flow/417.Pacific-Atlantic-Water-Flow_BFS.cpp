class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if (m==0) return {};
        int n = matrix[0].size();
        auto visited1 = vector<vector<int>>(m, vector<int>(n,0));
        auto visited2 = vector<vector<int>>(m, vector<int>(n,0));
        
        vector<pair<int,int>>starts;
        for (int i=0; i<m; i++)
            starts.push_back({i,-1});
        for (int j=0; j<n; j++)
            starts.push_back({-1,j});
        bfs(matrix, starts, visited1);
        
        starts.clear();
        for (int i=0; i<m; i++)
            starts.push_back({i,n});
        for (int j=0; j<n; j++)
            starts.push_back({m,j});
        bfs(matrix, starts, visited2);
        
        vector<vector<int>>rets;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (visited1[i][j]&&visited2[i][j])
                    rets.push_back({i,j});
        return rets;
    }
    
    void bfs(vector<vector<int>>& matrix, vector<pair<int,int>>&starts, vector<vector<int>>& visited)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        queue<pair<int,int>>q;
        for (auto x: starts) q.push(x);
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (visited[i][j]) continue;
                if (x>=0&&x<m&&y>=0&&y<n && matrix[i][j]<matrix[x][y]) continue;
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }
};
