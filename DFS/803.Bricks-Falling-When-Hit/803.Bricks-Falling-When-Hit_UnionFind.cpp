class Solution {
    int m,n;
    int Father[200*200];
    int Size[200*200];
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
        {
            Father[y] = x;
            Size[x] += Size[y];
        }
        else 
        {
            Father[x] = y;
            Size[y] += Size[x];
        }
    }        
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        auto grid0 = grid;

        m = grid.size();
        n = grid[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                Father[i*n+j] = i*n+j;
                Size[i*n+j] = 1;
            }
                
        for (auto &hit: hits)
            grid[hit[0]][hit[1]] = 0;

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                if (i-1>=0 && grid[i-1][j]==1)
                {
                    if (FindFather((i-1)*n+j)!=FindFather(i*n+j))
                        Union((i-1)*n+j, i*n+j);
                }
                if (j-1>=0 && grid[i][j-1]==1)
                {
                    if (FindFather(i*n+j-1)!=FindFather(i*n+j))
                        Union(i*n+j-1, i*n+j);
                }
            }
        vector<pair<int,int>>dir({{0,1},{0,-1},{-1,0},{1,0}});
        vector<int>rets;
        for (int k=hits.size()-1; k>=0; k--)
        {
            int x = hits[k][0], y = hits[k][1];            
            if (grid0[x][y]==0) 
            {
                rets.push_back(0);
                continue;
            }
            grid[x][y] = 1;
            int count = 0;
            int flag = 0;
            for (int t=0; t<4; t++)
            {
                int i = x+dir[t].first;
                int j = y+dir[t].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (grid[i][j]==0) continue;                
                if (FindFather(i*n+j)!=FindFather(x*n+y))                
                {
                    if (FindFather(i*n+j)>=n)
                        count+=Size[FindFather(i*n+j)];

                    if (FindFather(i*n+j)<n || x==0)
                        flag = 1;
                    Union(i*n+j, x*n+y);                    
                }
            }            
            rets.push_back(flag==1? count:0);            
        }
        reverse(rets.begin(), rets.end());

        return rets;
    }
};
