typedef vector<int> VI;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<VI, vector<VI>, greater<VI>>pq;
        pq.push({grid[0][0],0,0});
        
        int N = grid.size();
        auto visited = vector<vector<int>>(N,vector<int>(N,0));
        
        int ret = 0;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        while (!pq.empty())
        {
            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            ret = max(ret, h);
            pq.pop();
            
            if (visited[x][y]) continue;            
            visited[x][y] = 1;
            
            if (x==N-1 && y==N-1)
                return ret;
            
            for (int k = 0; k<4; k++)
            {
                int xx = x+dir[k].first;
                int yy = y+dir[k].second;
                if (xx<0||xx>=N||yy<0||yy>=N)
                    continue;
                if (visited[xx][yy]==1)
                    continue;
                pq.push({grid[xx][yy],xx,yy});
            }            
        }
        
        return -1;
    }
};
