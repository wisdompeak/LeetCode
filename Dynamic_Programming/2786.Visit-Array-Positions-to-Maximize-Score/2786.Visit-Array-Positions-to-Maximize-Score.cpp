using LL = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) 
    {
        int n = nums.size();
        
        vector<vector<LL>>dp(n, vector<LL>(2,LLONG_MIN/2));
        if (nums[0]%2==0)
            dp[0][0] = nums[0];
        else
            dp[0][1] = nums[0];
        
        for (int i=1; i<n; i++)            
        {
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
            
            if (nums[i]%2==0)
            {                                
                dp[i][0] = max(dp[i][0], dp[i-1][0] + nums[i]);
                dp[i][0] = max(dp[i][0], dp[i-1][1] + nums[i] - x);
            }
            else
            {                
                dp[i][1] = max(dp[i][1], dp[i-1][1] + nums[i]);
                dp[i][1] = max(dp[i][1], dp[i-1][0] + nums[i] - x);
            }            
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
        
    }
};
