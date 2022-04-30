class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>grid2(m, vector<int>(n));
        vector<vector<int>>grid5(m, vector<int>(n));
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int x = grid[i][j];
                while (x%2==0)
                {
                    grid2[i][j]+=1;
                    x/=2;
                }
                while (x%5==0)
                {
                    grid5[i][j]+=1;
                    x/=5;
                }
            }
        
        vector<vector<int>>left2(m, vector<int>(n));
        vector<vector<int>>right2(m, vector<int>(n));
        vector<vector<int>>up2(m, vector<int>(n));
        vector<vector<int>>down2(m, vector<int>(n));
        vector<vector<int>>left5(m, vector<int>(n));
        vector<vector<int>>right5(m, vector<int>(n));
        vector<vector<int>>up5(m, vector<int>(n));
        vector<vector<int>>down5(m, vector<int>(n));
        
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                left2[i][j] = (j==0?0:left2[i][j-1]) + grid2[i][j];
                left5[i][j] = (j==0?0:left5[i][j-1]) + grid5[i][j];
            }
                
            for (int j=n-1; j>=0; j--)
            {
                right2[i][j] = (j==n-1?0:right2[i][j+1]) + grid2[i][j];
                right5[i][j] = (j==n-1?0:right5[i][j+1]) + grid5[i][j];
            }                
        }
        
        for (int j=0; j<n; j++)
        {
            for (int i=0; i<m; i++)
            {
                up2[i][j] = (i==0?0:up2[i-1][j]) + grid2[i][j];
                up5[i][j] = (i==0?0:up5[i-1][j]) + grid5[i][j];
            }
                
            for (int i=m-1; i>=0; i--)
            {
                down2[i][j] = (i==m-1?0:down2[i+1][j]) + grid2[i][j];
                down5[i][j] = (i==m-1?0:down5[i+1][j]) + grid5[i][j];
            }
        }        
        
        int ret = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                ret = max(ret, min((left2[i][j]+up2[i][j]-grid2[i][j]),(left5[i][j]+up5[i][j]-grid5[i][j])));
                ret = max(ret, min((left2[i][j]+down2[i][j]-grid2[i][j]),(left5[i][j]+down5[i][j]-grid5[i][j])));
                ret = max(ret, min((right2[i][j]+up2[i][j]-grid2[i][j]),(right5[i][j]+up5[i][j]-grid5[i][j])));
                ret = max(ret, min((right2[i][j]+down2[i][j]-grid2[i][j]),(right5[i][j]+down5[i][j]-grid5[i][j])));                
            }
        return ret;      
    }
};
