class Solution {
    int dp[25][2005];
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S>sum || S<-sum) return false;
        
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        int offset = 1000;                
        dp[0][offset] = 1;
        
        for (int i=1; i<=n; i++)
            for (int s = -1000; s<=1000; s++)
            {
                if (s-nums[i]<=1000 && s-nums[i]>=-1000)
                    dp[i][s+offset] += dp[i-1][s-nums[i]+offset];

                if (s+nums[i]<=1000 && s+nums[i]>=-1000)
                    dp[i][s+offset] += dp[i-1][s+nums[i]+offset];
            }
        
        return dp[n][S+offset];
    }
};
