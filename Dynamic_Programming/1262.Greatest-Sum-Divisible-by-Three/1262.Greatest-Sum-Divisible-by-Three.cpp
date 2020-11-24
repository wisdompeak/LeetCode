class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        vector<int>dp(3);
        dp[1] = INT_MIN;
        dp[2] = INT_MIN;

        for (int i=0; i<nums.size(); i++)
        {
            auto dp_temp = dp;
            for (int j=0; j<3; j++)
            {
                dp[j] = max(dp_temp[j], dp_temp[(j-nums[i]%3+3)%3]+nums[i]);
            }
        }
        return dp[0];
    }
};
