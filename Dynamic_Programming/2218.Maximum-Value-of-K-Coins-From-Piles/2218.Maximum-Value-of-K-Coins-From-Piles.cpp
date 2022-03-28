class Solution {
    int dp[1002][2002];
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<vector<int>>presum(n);
        for (int i=0; i<n; i++)
        {
            int sum = 0;
            presum[i].push_back(sum);
            for (int j=0; j<piles[i].size(); j++)
            {
                sum += piles[i][j];
                presum[i].push_back(sum);
            }
        }

        int ret = 0;        
        for (int i=0; i<n; i++)
            for (int j=0; j<=k; j++)
            {                
                for (int t = 0; t<=min(j, (int)piles[i].size()); t++)
                    dp[i][j] = max(dp[i][j], (i==0?0:dp[i-1][j-t]) + presum[i][t]);                
                                    
                if (i==n-1)
                    ret = max(ret, dp[i][j]);
            }                
        
        return ret;
    }
};
