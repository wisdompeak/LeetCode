class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        
        int N = grid.size();
        auto visited = vector<vector<int>>(N,vector<int>(N,0));
        visited[0][0] = 1;
        
        int t = 0;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        while (!pq.empty())
        {
            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            t = h;
            
            if (x==N-1 && y==N-1)
                return t;
            
            queue<pair<int,int>>q;
            q.push({x,y});
            
            while (!q.empty())
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (int k = 0; k<4; k++)
                {
                    int xx = i+dir[k].first;
                    int yy = j+dir[k].second;
                    if (xx<0||xx>=N||yy<0||yy>=N)
                        continue;
                    if (visited[xx][yy]==1)
                        continue;
                    if (grid[xx][yy] > t)
                    {
                        pq.push({grid[xx][yy],xx,yy});
                        visited[xx][yy] = 1;
                    }
                    else   // grid[xx][yy] <= t
                    {
                        if (xx==N-1 && yy==N-1)
                            return t;
                        q.push({xx,yy});
                        visited[xx][yy] = 1;
                    }
                }
            }
            
        }
        
        return -1;
    }
};

