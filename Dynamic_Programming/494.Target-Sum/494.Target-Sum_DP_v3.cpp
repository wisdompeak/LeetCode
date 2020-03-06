class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S>sum || S<-sum) return false;
        
        int offset = sum;        
        vector<int>dp(2*offset+1);
        dp[0+offset] = 1;
        
        for (auto x: nums)
        {
            auto temp = dp;
            for (int i=-offset; i<=offset; i++)
            {
                dp[i+offset] = 0;
                if (i-x>=-offset)
                    dp[i+offset] += temp[i-x+offset];
                if (i+x<=offset)
                    dp[i+offset] += temp[i+x+offset];
                //cout<<x<<" "<<i<<" "<<dp[i+offset]<<endl;
            }
        }
        
        return dp[S+offset];
    }
};
