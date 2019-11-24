class Solution {
struct Node {
    int bx, by, px, py;
};    
public:
    int minPushBox(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();        
        
        int px,py,bx,by,tx,ty;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='B')
                {
                    bx = i;
                    by = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j]=='S')
                {
                    px = i;
                    py = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j]=='T')
                {
                    tx = i;
                    ty = j;
                    grid[i][j] = '.';
                }                
            }
        
        int flag[m][n][m][n];
        memset(flag, 255, sizeof(flag));
        flag[bx][by][px][py] = 0;
        
        auto dir=vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        deque<Node>q;
        q.push_back({bx,by,px,py});
        while (!q.empty())
        {
            auto [bx,by,px,py] = q.front();
            q.pop_front();
            if (bx==tx && by==ty) return flag[bx][by][px][py];
            
            for (int k=0; k<4; k++)
            {
                int x = px+dir[k].first;
                int y = py+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (grid[x][y]!='.') continue;
                if (x==bx && y==by) continue;
                if (flag[bx][by][x][y]>=0) continue;
                flag[bx][by][x][y] = flag[bx][by][px][py];
                q.push_front({bx,by,x,y});
            }
            if (abs(px - bx) + abs(py - by) == 1)
            {
                for (int k=0; k<4; k++)
                {
                    if (px+dir[k].first!=bx || py+dir[k].second!=by)
                        continue;
                
                    int x = bx+dir[k].first;
                    int y = by+dir[k].second;                   
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (grid[x][y]!='.') continue;
                    if (flag[x][y][bx][by]>=0) continue;
                    flag[x][y][bx][by] = flag[bx][by][px][py]+1;
                    q.push_back({x,y,bx,by});                
                }
            }
            
        }
        
        return -1;
        
    }
};
