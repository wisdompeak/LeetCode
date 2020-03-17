class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int>gain(10001,0);
        for (auto x: nums)
            gain[x] += x;

        vector<int>dp(10001,0);
        dp[1] = gain[1];

        for (int i=2; i<=10000; i++)
        {
            dp[i] = max(dp[i-2]+gain[i], dp[i-1]);
        }
        return dp[10000];
    }
};
