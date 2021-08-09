class Solution {    
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int dp[n][k+1];

        for (int i=0; i<n; i++)
            for (int j=0; j<=k; j++)
                dp[i][j] = INT_MAX/2;

        int mx = 0;
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            mx = max(mx, nums[i]);
            sum += nums[i];
            dp[i][0] = mx*(i+1)-sum;
        }        

        for (int i=1; i<n; i++)          
            for (int j=1; j<=min(i, k); j++)
            {
                int mx = 0;
                int intervalSum = 0;
                for (int s=i; (s>=j-1) && (s>=1); s--)
                {
                    mx = max(mx, nums[s]);
                    intervalSum += nums[s];
                    dp[i][j] = min(dp[i][j], dp[s-1][j-1] + mx*(i-s+1) - intervalSum);
                }
            }

        int ret = INT_MAX/2;
        for (int j=0; j<=k; j++)
            ret = min(ret, dp[n-1][j]);
        return ret;
    }
};
