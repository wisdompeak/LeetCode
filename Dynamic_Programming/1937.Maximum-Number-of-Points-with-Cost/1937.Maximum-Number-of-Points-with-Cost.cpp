using LL  = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int m = points.size();
        int n = points[0].size();
        
        vector<LL>dp(n, INT_MIN);
                
        for (int j=0; j<n; j++)
            dp[j] = points[0][j];
        
        for (int i=1; i<m; i++)
        {
            vector<LL>dp2(n, INT_MIN);
            
            LL maxVal = INT_MIN;
            for (int j=0; j<n; j++)
            {
                maxVal = max(maxVal, dp[j]+j);
                dp2[j] = max(dp2[j], maxVal - j + points[i][j]);
            }
            
            maxVal = INT_MIN;
            for (int j=n-1; j>=0; j--)
            {
                maxVal = max(maxVal, dp[j]-j);
                dp2[j] = max(dp2[j], maxVal + j + points[i][j]);
            }            
            
            dp = std::move(dp2);
        }
        
        LL ret = INT_MIN;
        for (int j=0; j<n; j++)
            ret = max(ret, dp[j]);
        
        return ret;        
    }
};
