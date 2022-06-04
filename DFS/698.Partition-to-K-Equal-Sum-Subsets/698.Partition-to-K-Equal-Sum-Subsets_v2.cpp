class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%k!=0) return false;
        int target = sum / k;
        
        vector<int>dp(1<<n, -1);
        dp[0] = 0;
        for (int state=0; state<(1<<n); state++)
        {
            if (dp[state]==-1) continue;
            for (int i=0; i<n; i++)
            {                                
                if (!((state>>i)&1) && (dp[state]+nums[i] <= target))
                    dp[state + (1<<i)] = (dp[state]+nums[i]) % target;
            }
        }
        
        return dp[(1<<n)-1] != -1;
        
    }
};
