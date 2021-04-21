class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int>dp(n);
        dp[0] = triangle[0][0];
        for (int i=1; i<n; i++)
        {
            auto dp2 = dp;
            for (int j=0; j<=i; j++)
            {
                if (j==0)
                    dp[j] = dp2[0]+triangle[i][0];
                else if (j==i)
                    dp[j] = dp2[i-1]+triangle[i][j];
                else
                    dp[j] = min(dp2[j-1],dp2[j])+triangle[i][j];
            }                
        }
        int ret = INT_MAX;
        for (int i=0; i<n; i++)
            ret = min(ret, dp[i]);
        return ret;
        
    }
};
