class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int k = 17;
        vector<int>dp(1<<k);
        dp[0] = 1;
        
        for (int x : nums)
        {
            auto dp2 = dp;
            for (int s = 0; s<(1<<k); s++)
            {
                dp2[s|x] += dp[s];
            }
            dp = std::move(dp2);
        }
        
        for (int s=(1<<k)-1; s>=0; s--)
        {
            if (dp[s]>0)
                return dp[s];
        }
        
        return 0;        
    }
};
