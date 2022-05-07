class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>person = bfs(grid, 0);
        vector<vector<int>>fire = bfs(grid, 1);
        
        if (person[m-1][n-1]==INT_MAX || person[m-1][n-1] > fire[m-1][n-1])
            return -1;
        if (fire[m-1][n-1]==INT_MAX)
            return 1e9;

        int D = fire[m-1][n-1]-person[m-1][n-1];

        if (fire[m-1][n-2] == fire[m-2][n-1]) return D-1;
        if (fire[m-1][n-2] < fire[m-2][n-1])
        {
            if (person[m-2][n-1] == person[m-1][n-1]-1)
                return D;
        }
        else
        {
            if (person[m-1][n-2] == person[m-1][n-1]-1)
                return D;
        }

        return D-1;
    }

    vector<vector<int>>bfs(vector<vector<int>>&grid, int type)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>rets(m, vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;

        if (type==0)        
        {
            q.push({0,0});
            rets[0][0] = 0;
        }            
        else
        {            
            for (int i=0; i<m; i++)
                for (int j=0; j<n; j++)
                    if (grid[i][j]==1) 
                    {
                        q.push({i,j});
                        rets[i][j] = 0;
                    }                        
        }
        vector<pair<int,int>>dir({{1,0},{-1,0},{0,1},{0,-1}});
        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto [x,y] = q.front();
                q.pop();

                for (auto& [dx, dy] : dir)
                {
                    int i = x+dx, j = y+dy;
                    if (i<0||i>=m||j<0||j>=n) continue;
                    if (grid[i][j]==2) continue;
                    if (rets[i][j]!=INT_MAX) continue;
                    rets[i][j] = step+1;
                    if (i!=m-1 || j!=n-1)
                        q.push({i,j});
                }
            }
            step++;
        }

        return rets;
    }
};
