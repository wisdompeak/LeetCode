class Solution {
    int m,n;
    vector<vector<int>>presum;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        m = mat.size();
        n = mat[0].size();
        
        presum.resize(m+1);
        for (int i=0; i<=m; i++)
            presum[i].resize(n+1);
                       
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                presum[i][j] = presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+mat[i-1][j-1];

        int left = 0, right = min(m,n);
        while (left < right)
        {
            int mid = right-(right-left)/2;
            if (isOK(mid, threshold))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }

    bool isOK(int len, int threshold)
    {
        for (int i=len; i<=m; i++)
            for (int j=len; j<=n; j++)
            {
                int sum = presum[i][j] - presum[i][j-len] - presum[i-len][j] + presum[i-len][j-len];
                if (sum <= threshold)
                    return true;
            }
        return false;
    }
};
