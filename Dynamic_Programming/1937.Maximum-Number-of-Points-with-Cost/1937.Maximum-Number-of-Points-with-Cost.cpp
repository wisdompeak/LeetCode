using LL = long long;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int m = points.size();
        int n = points[0].size();
        
        vector<vector<LL>>dp(m, vector<LL>(n, INT_MIN));
        for (int j=0; j<n; j++)
            dp[0][j] = points[0][j];
        
        for (int i=1; i<m; i++)            
        {
            LL rollingMax = INT_MIN;            
            for (int j=0; j<n; j++)
            {
                rollingMax = max(rollingMax, dp[i-1][j]+j);
                dp[i][j] = max(dp[i][j], rollingMax + points[i][j] - j);
            }
            
            rollingMax = INT_MIN;            
            for (int j=n-1; j>=0; j--)
            {
                rollingMax = max(rollingMax, dp[i-1][j]-j);
                dp[i][j] = max(dp[i][j], rollingMax +points[i][j] + j);
            }
        }
        
        LL ret = INT_MIN;
        for (int j=0; j<n; j++)
            ret = max(ret, dp[m-1][j]);
        
        return ret;
    }
};
