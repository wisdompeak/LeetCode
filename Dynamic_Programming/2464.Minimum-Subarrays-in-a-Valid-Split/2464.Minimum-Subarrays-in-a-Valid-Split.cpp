class Solution {
    int dp[1005];
public:
    int validSubarraySplit(vector<int>& nums) 
    {
        memset(dp, 0x3f, sizeof(dp));
        int n = nums.size();
        for (int i=0; i<n; i++)
            for (int j=0; j<=i; j++)
            {
                if (gcd(nums[j], nums[i])>1)
                    dp[i] = min(dp[i], j==0?1:(dp[j-1]+1));
            }

        if (dp[n-1]==0x3f3f3f3f)
            return -1;
        return dp[n-1];
    }
};
