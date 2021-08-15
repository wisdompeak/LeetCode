class Solution {
    vector<int>Father;
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
        if (x<y) Father[y] = x;
        else Father[x] = y;
    } 
    int m,n;
    
public:
    bool checkOK()
    {
        return FindFather(m*n)==FindFather(m*n+1);      
    }    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        m = row, n = col;
        Father.resize(m*n+2);
        for (int i=0; i<m*n+2; i++)
            Father[i] = i;
        
        vector<vector<int>>mat(m, vector<int>(n,1));
        for (auto cell: cells)
            mat[cell[0]-1][cell[1]-1] = 0;
        
        vector<pair<int,int>>dir({{1,0},{-1,0},{0,1},{0,-1}});
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (mat[i][j]==0) continue;
                
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (mat[x][y]==0) continue;
                    
                    if (FindFather(i*n+j)!=FindFather(x*n+y))
                    {
                        Union(i*n+j, x*n+y);
                    }
                }                
            }
        
        for (int j=0; j<n; j++) Union(m*n, 0*n+j);
        
        for (int j=0; j<n; j++) Union(m*n+1, (m-1)*n+j);
        
        for (int t=cells.size()-1; t>=0; t--)
        {
            if (checkOK()) return t+1;
            
            int i = cells[t][0]-1;
            int j = cells[t][1]-1;
            mat[i][j] = 1;
            
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (mat[x][y]==0) continue;

                if (FindFather(i*n+j)!=FindFather(x*n+y))
                {
                    Union(i*n+j, x*n+y);
                }
            }
        }
        
        return 0;
    }
};
