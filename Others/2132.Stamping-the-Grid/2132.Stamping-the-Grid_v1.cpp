class RegionSum {
    vector<vector<int>>presum;
public:
    RegionSum(vector<vector<int>>& A)
    {
        int m = A.size();
        int n = A[0].size();
        presum.resize(m);
        for (int i=0; i<m; i++)
            presum[i].resize(n);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int a = i==0?0:presum[i-1][j];
                int b = j==0?0:presum[i][j-1];
                int c = (i==0||j==0)?0:presum[i-1][j-1];
                presum[i][j] = a + b - c + A[i][j];
            }
    }
    int query(int i, int j, int x, int y)
    {
        int a = j==0?0:presum[x][j-1];
        int b = i==0?0:presum[i-1][y];
        int c = (i==0||j==0)?0:presum[i-1][j-1];
        int area = presum[x][y] - a - b + c;
        return area;
    }
};

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>stamps(m, vector<int>(n));

        RegionSum Grid(grid);        
        for (int i=0; i+stampHeight-1<m; i++)
            for (int j=0; j+stampWidth-1<n; j++)
            {
                int x = i+stampHeight-1;
                int y = j+stampWidth-1; 
                int area = Grid.query(i, j, x, y);
                if (area == 0)
                    stamps[x][y] = 1;
            }
        
        RegionSum Stamps(stamps);                
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==1) continue;
                int x = min(m-1, i+stampHeight-1);
                int y = min(n-1, j+stampWidth-1);
                int area = Stamps.query(i, j, x, y);
                if (area == 0) return false;
            }
        return true;
    }
};
