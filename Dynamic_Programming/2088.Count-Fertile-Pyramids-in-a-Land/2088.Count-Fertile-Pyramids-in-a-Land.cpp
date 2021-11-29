class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>left(m, vector<int>(n));
        vector<vector<int>>right(m, vector<int>(n));
        vector<vector<int>>dp1(m, vector<int>(n));
        vector<vector<int>>dp2(m, vector<int>(n));
        
        for (int i=0; i<m; i++)
        {
            int count = 0;
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0)
                    count = 0;
                else
                    count+=1;
                left[i][j] = count;
            }
        }
        
        for (int i=0; i<m; i++)
        {
            int count = 0;
            for (int j=n-1; j>=0; j--)
            {
                if (grid[i][j]==0)
                    count = 0;
                else
                    count+=1;
                right[i][j] = count;
            }
        }
        
        int ret = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                if (i==0)
                {
                    dp1[i][j] = 1;
                }
                else
                {
                    dp1[i][j] = min(min(left[i][j], right[i][j]), dp1[i-1][j]+1);
                }
                ret += dp1[i][j]-1;
            }
        
        for (int i=m-1; i>=0; i--)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) continue;
                if (i==m-1)
                {
                    dp2[i][j] = 1;
                }
                else
                {
                    dp2[i][j] = min(min(left[i][j], right[i][j]), dp2[i+1][j]+1);
                }
                ret += dp2[i][j]-1;
            }
        
        return ret;
        
    }
};
