class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0) return false;
        
        vector<bool>dp(sum/2+1,0);
        dp[0] = true;

        for (auto x: nums)
        {
            for (int s = sum/2; s>=0; s--)
            {
                if (dp[s]==false) continue;
                if (s+x<=sum/2)
                    dp[s+x] = true;
            }        
        }
        return dp[sum/2];
    }
};
