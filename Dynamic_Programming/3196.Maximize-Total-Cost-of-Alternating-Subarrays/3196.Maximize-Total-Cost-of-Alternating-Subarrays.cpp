using LL = long long;
class Solution {
    LL dp[100005][2];
public:
    long long maximumTotalCost(vector<int>& nums) 
    {
        int n = nums.size();
        
        dp[0][1] = nums[0];
        dp[0][0] = LLONG_MIN/2;
        
        for (int i=1; i<n; i++)
        {            
            dp[i][0] = dp[i-1][1] - nums[i];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + nums[i];
        }
        
        return max(dp[n-1][0], dp[n-1][1]);        
    }
};
