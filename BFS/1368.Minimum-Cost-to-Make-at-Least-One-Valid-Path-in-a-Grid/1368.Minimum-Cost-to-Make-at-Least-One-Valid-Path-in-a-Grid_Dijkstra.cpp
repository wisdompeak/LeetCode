typedef array<int,3> AI3;
class Solution {
    int visited[101][101];    
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<AI3, vector<AI3>, greater<>>pq;
        pq.push({0,0,0});
        
        auto dir = vector<pair<int,int>>({{0,1},{0,-1},{1,0},{-1,0}});
        while (!pq.empty())
        {
            auto [steps, x, y] = pq.top();
            pq.pop();
            if (visited[x][y]) continue;
            visited[x][y] = 1;

            if (x==m-1 && y==n-1)
                return steps;

            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (visited[i][j]==1) continue;
                int addon = grid[x][y]==k+1 ? 0:1;
                pq.push({steps+addon, i, j});
            }
        }
        return 0;
    }
};
