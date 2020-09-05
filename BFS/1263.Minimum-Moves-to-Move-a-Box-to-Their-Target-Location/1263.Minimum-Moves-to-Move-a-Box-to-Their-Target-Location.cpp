class Solution {
    struct Node {
        int bx, by, px, py;        
    };
public:
    int minPushBox(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int bx,by,px,py,tx,ty;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='S')
                {
                    px = i, py = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j]=='B')
                {
                    bx = i, by = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j]=='T')
                {
                    tx = i, ty = j;
                    grid[i][j] = '.';
                }
            }
        
        deque<Node>q;
        q.push_back({bx,by,px,py});
        int memo[21][21][21][21];
        memset(memo, 255, sizeof(memo));
        memo[bx][by][px][py] = 0;
        
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        while (!q.empty())
        {
            auto [bx, by, px, py] = q.front();
            q.pop_front();
            if (bx==tx && by==ty)
                return memo[bx][by][px][py];
            
            for (int k=0; k<4; k++)
            {
                int x = px+dir[k].first;
                int y = py+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (grid[x][y]!='.') continue;
                if (x==bx && y==by) continue;
                if (memo[bx][by][x][y]>=0) continue;
                memo[bx][by][x][y] = memo[bx][by][px][py];
                q.push_front({bx,by,x,y});               
            }
            if (abs(px-bx)+abs(py-by)==1)
            {
                for (int k=0; k<4; k++)
                {
                    if (px+dir[k].first==bx && py+dir[k].second==by)
                    {
                        int bx2 = bx+dir[k].first;
                        int by2 = by+dir[k].second;
                        if (bx2<0||bx2>=m||by2<0||by2>=n) continue;
                        if (grid[bx2][by2]!='.') continue;
                        if (memo[bx2][by2][bx][by]>=0) continue;
                        memo[bx2][by2][bx][by] = memo[bx][by][px][py]+1;
                        q.push_back({bx2,by2,bx,by});
                    }
                }
            }
        }
        return -1;        
    }
};
