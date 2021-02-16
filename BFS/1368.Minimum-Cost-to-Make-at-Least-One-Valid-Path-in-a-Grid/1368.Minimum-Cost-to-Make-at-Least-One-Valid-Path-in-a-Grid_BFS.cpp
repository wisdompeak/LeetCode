
class Solution {
    int visited[101][101];
    int m,n;
    vector<pair<int,int>>dir;
public:
    int minCost(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        dir = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>>q;
        vector<pair<int,int>>temp;
        dfs(0,0,temp,grid);
        for (auto x: temp)
            q.push(x);
        
        int step = 0;
        
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
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

                    vector<pair<int,int>>temp;
                    dfs(a,b,temp,grid);
                    for (auto x:temp)
                    {
                        if (x.first==m-1 && x.second==n-1)
                            return step+1;
                        q.push(x);                        
                    }
                }
            }
            step++;
        }
        return 0;
    }

    void dfs(int x, int y, vector<pair<int,int>>&temp, vector<vector<int>>& grid)
    {
        if (x<0||x>=m||y<0||y>=n) return;
        if (visited[x][y]==1) return;
        temp.push_back({x,y});
        visited[x][y] = 1;

        int i = x + dir[grid[x][y]-1].first;
        int j = y + dir[grid[x][y]-1].second;
        dfs(i,j,temp,grid);
    }
};
