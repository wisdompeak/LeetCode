using AI3 = array<int,3>;
class Solution {    
    vector<pair<int,int>>dir= {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minimumTime(vector<vector<int>>& grid) 
    {
        if (grid[0][1]>1 && grid[1][0]>1) return -1;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>arrival(m, vector<int>(n,-1));
        
        priority_queue<AI3, vector<AI3>, greater<>>pq;
        if (grid[0][1]<=1) pq.push({1,0,1});
        if (grid[1][0]<=1) pq.push({1,1,0});            
        
        while (!pq.empty())
        {
            auto [t,x,y] = pq.top();
            pq.pop();
            if (arrival[x][y]!=-1)
                continue;
            arrival[x][y] = t;
            if (x==m-1 && y==n-1)
                break;
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (arrival[i][j] != -1) continue;
                
                if (grid[i][j]<=t+1)
                    pq.push({t+1, i, j});
                else if ((grid[i][j]-t)%2==0)
                    pq.push({grid[i][j]+1, i, j});
                else
                    pq.push({grid[i][j], i, j});
            }
        }
        
        return arrival[m-1][n-1];
    }
};
