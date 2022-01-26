class Diff2d {    
public:
    vector<vector<int>>f;
    vector<vector<int>>diff;    
    int m,n;
    Diff2d(int m, int n)
    {
        this->m = m;
        this->n = n;
        diff.resize(m+1);
        f.resize(m+1);        
        for (int i=0; i<m+1; i++)
        {
            diff[i].resize(n+1);
            f[i].resize(n+1);
        }            
    }
    void set(int x0, int y0, int x1, int y1, int val)
    {
        diff[x0][y0]+=val;
        diff[x0][y1+1]-=val;
        diff[x1+1][y0]-=val;
        diff[x1+1][y1+1]+=val;
    }
    void compute()
    {
        f[0][0] = diff[0][0];
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int a = i==0?0:f[i-1][j];
                int b = j==0?0:f[i][j-1];
                int c = (i==0||j==0)?0:f[i-1][j-1];                
                f[i][j] = a + b - c + diff[i][j];
            }
    }    
};
