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
        for (int i=0; i<m*n; i++)
        {
            Father[i] = i;
            Size[i] = 1;
        }
        for (auto &hit: hits)
            grid[hit[0]][hit[1]] = 0;

        vector<pair<int,int>>dir({{0,1},{0,-1},{-1,0},{1,0}});
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;                    
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (grid[x][y]==0) continue;                
                    if (FindFather(i*n+j)!=FindFather(x*n+y))
                        Union(i*n+j, x*n+y);
                }
            }
        
        vector<int>rets;
        for (int t=hits.size()-1; t>=0; t--)
        {
            int i = hits[t][0], j = hits[t][1];            
            if (grid0[i][j]==0) 
            {
                rets.push_back(0);
                continue;
            }
            grid[i][j] = 1;
            int count = 0;
            int flag = 0;
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (grid[x][y]==0) continue;                
                if (FindFather(i*n+j)!=FindFather(x*n+y))                
                {
                    if (FindFather(x*n+y)>=n)
                        count+=Size[FindFather(x*n+y)];
                    if (FindFather(x*n+y)<n || i==0)
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
