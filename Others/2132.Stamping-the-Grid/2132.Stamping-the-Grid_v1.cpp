class Solution {
public:
    vector<vector<int>>getPresum(vector<vector<int>>& A)
    {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>>presum(m, vector<int>(n));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int a = i==0?0:presum[i-1][j];
                int b = j==0?0:presum[i][j-1];
                int c = (i==0||j==0)?0:presum[i-1][j-1];
                presum[i][j] = a + b - c + A[i][j];
            }
        return presum;
    }

    int queryPresum(vector<vector<int>>& presum, int i, int j, int x, int y)
    {
        int a = j==0?0:presum[x][j-1];
        int b = i==0?0:presum[i-1][y];
        int c = (i==0||j==0)?0:presum[i-1][j-1];
        int area = presum[x][y] - a - b + c;
        return area;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) 
    {
        int m = grid.size(), n = grid[0].size();
        auto gridPresum = getPresum(grid);

        vector<vector<int>>stamp(m, vector<int>(n));
        for (int i=stampHeight-1; i<m; i++)
            for (int j=stampWidth-1; j<n; j++)
            {
                int x = i-stampHeight+1;
                int y = j-stampWidth+1; 
                int area = queryPresum(gridPresum, x, y, i, j);
                if (area == 0)
                    stamp[i][j] = 1;
            }
        
        auto stampPresum = getPresum(stamp);
                
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==1) continue;
                int x = min(m-1, i+stampHeight-1);
                int y = min(n-1, j+stampWidth-1);
                int area = queryPresum(stampPresum, i, j, x, y);
                if (area == 0) return false;
            }
        return true;
    }
};
