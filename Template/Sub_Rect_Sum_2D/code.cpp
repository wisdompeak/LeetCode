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
