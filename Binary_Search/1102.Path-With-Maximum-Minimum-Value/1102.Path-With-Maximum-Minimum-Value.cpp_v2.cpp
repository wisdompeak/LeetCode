using AI3 = array<int,3>;
class Solution {
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maximumMinimumPath(vector<vector<int>>& grid) 
    {
        int M = grid.size();
        int N = grid[0].size();
        priority_queue<AI3>pq;
        
        pq.push({grid[0][0], 0,0});
        vector<vector<int>>visited(M, vector<int>(N,0));        
        vector<vector<int>>rets(M, vector<int>(N,0));        
        
        while (pq.size()>0)
        {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (visited[x][y]==1) continue;
            rets[x][y] = d;
            visited[x][y] = 1;
            if (x==M-1 && y==N-1)
                return d;
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=M||j<0||j>=N)
                    continue;                                                
                pq.push({min(d, grid[i][j]), i, j});                
            }
        }
                
        return -1;        
    }
};
