class Solution {
    int dp[205][20005];
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0) return false;

        int n = nums.size();
        nums.insert(nums.begin(), 0);

        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
            for (int s = 0; s<=sum/2; s++)
            {
                dp[i][s] = dp[i-1][s] || (s>=nums[i] && dp[i-1][s-nums[i]]);
            }

        return dp[n][sum/2];
    }
};
