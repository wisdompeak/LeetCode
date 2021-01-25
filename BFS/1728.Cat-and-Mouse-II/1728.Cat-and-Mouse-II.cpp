class Solution {
    int memo[9][9][9][9][3];
    pair<int,int>mouse;
    pair<int,int>cat;
    pair<int,int>food;    
    int catJump;
    int mouseJump;
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<array<int,5>>q;
        this->catJump = catJump;
        this->mouseJump = mouseJump;

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='M')
                    mouse = {i,j};
                if (grid[i][j]=='C')
                    cat = {i,j};
                if (grid[i][j]=='F')
                    food = {i,j};
            }
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='#') continue;
                if (i==food.first && j==food.second) continue;
                memo[food.first][food.second][i][j][1] = 1; // mouse win
                memo[food.first][food.second][i][j][2] = 1; // mouse win
                memo[i][j][food.first][food.second][1] = 2; // cat win                
                memo[i][j][food.first][food.second][2] = 2; // cat win                
                q.push({food.first, food.second, i, j, 1}); 
                q.push({food.first, food.second, i, j, 2}); 
                q.push({i, j, food.first, food.second, 1});                   
                q.push({i, j, food.first, food.second, 2});  
            }
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='#') continue;
                memo[i][j][i][j][1] = 2; // cat win
                memo[i][j][i][j][2] = 2; // cat win                                
                q.push({i, j, i, j, 1}); 
                q.push({i, j, i, j, 2}); 
            }
        
        int step = 0;
        while (!q.empty())
        {            
            step++;
            if (step>2000) return false;
            int len = q.size();
            while (len--)
            {
                int mx = q.front()[0];
                int my = q.front()[1];
                int cx = q.front()[2];
                int cy = q.front()[3];
                int t = q.front()[4];   
                int status = memo[mx][my][cx][cy][t];
                q.pop();
                
                for (auto nextNode: findAllAdjacents(grid,mx,my,cx,cy,t))
                {
                    int mx2 = nextNode[0];
                    int my2 = nextNode[1];
                    int cx2 = nextNode[2];
                    int cy2 = nextNode[3];                                        
                    int t2 = nextNode[4];

                    if (memo[mx2][my2][cx2][cy2][t2]!=0) continue; // has been determined

                    if (t2==status)   // immediate win, (m2,c2,t2)->(m,c,t)
                    {
                        memo[mx2][my2][cx2][cy2][t2] = status;
                        q.push({mx2,my2,cx2,cy2,t2});
                    }
                    else if (allAdjacentsWin(grid, mx2,my2,cx2,cy2,t2))    // eventually lose
                    {
                        memo[mx2][my2][cx2][cy2][t2] = (t2==1)? 2:1;
                        q.push({mx2,my2,cx2,cy2,t2});              
                    }                
                }                
            }
        }
        
        return memo[mouse.first][mouse.second][cat.first][cat.second][1]==1;        
    }
    
    vector<vector<int>> findAllAdjacents(vector<string>& grid, int mx, int my, int cx, int cy, int t)
    {
        int m = grid.size();
        int n = grid[0].size();
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        vector<vector<int>>neighbours;
        if (t==1)
        {
            for (int k=0; k<4; k++)
                for (int a = 0; a<=catJump; a++)
                {
                    int cx2 = cx+dir[k].first*a;
                    int cy2 = cy+dir[k].second*a;
                    if (cx2<0||cx2>=m||cy2<0||cy2>=n) break;
                    if (grid[cx2][cy2]=='#') break;
                    neighbours.push_back({mx,my,cx2,cy2,2});
                }
        }
        else
        {
            for (int k=0; k<4; k++)
                for (int a = 0; a<=mouseJump; a++)
                {
                    int mx2 = mx+dir[k].first*a;
                    int my2 = my+dir[k].second*a;
                    if (mx2<0||mx2>=m||my2<0||my2>=n) break;
                    if (grid[mx2][my2]=='#') break;
                    neighbours.push_back({mx2,my2,cx,cy,1});
                }
        }
        return neighbours;
    }
    
    bool allAdjacentsWin(vector<string>& grid, int mx, int my, int cx, int cy, int t)
    {
        int m = grid.size();
        int n = grid[0].size();
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        if (t==1)
        {
            for (int k=0; k<4; k++)
                for (int a = 0; a<=mouseJump; a++)
                {
                    int mx2 = mx+dir[k].first*a;
                    int my2 = my+dir[k].second*a;
                    if (mx2<0||mx2>=m||my2<0||my2>=n) break;
                    if (grid[mx2][my2]=='#') break;
                    if (memo[mx2][my2][cx][cy][2]!=2)
                        return false;
                }                
        }
        else if (t==2)
        {
            for (int k=0; k<4; k++)
                for (int a = 0; a<=catJump; a++)
                {
                    int cx2 = cx+dir[k].first*a;
                    int cy2 = cy+dir[k].second*a;
                    if (cx2<0||cx2>=m||cy2<0||cy2>=n) break;
                    if (grid[cx2][cy2]=='#') break;
                    if (memo[mx][my][cx2][cy2][1]!=1)
                        return false;
                }
        }
        return true;
    }    
};
