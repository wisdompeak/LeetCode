class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int M = (1<<17);
        vector<int>dp(M+1);
        dp[0] = 1;
        
        for (int x : nums)
        {
            auto dp2 = dp;
            for (int s = 0; s<M; s++)
            {
                dp2[s|x] += dp[s];
            }
            dp = std::move(dp2);
        }
        
        for (int s=M; s>=0; s--)
        {
            if (dp[s]>0)
                return dp[s];
        }
        
        return 0;        
    }
};
