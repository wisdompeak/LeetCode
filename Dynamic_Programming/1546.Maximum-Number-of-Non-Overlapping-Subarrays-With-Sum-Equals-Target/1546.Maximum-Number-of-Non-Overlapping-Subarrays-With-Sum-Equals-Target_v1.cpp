class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) 
    {
        unordered_map<int,vector<int>>Map;
        int n = nums.size();
        vector<int>dp(n+1,0);
        vector<int>presum(n+1,0);
        nums.insert(nums.begin(),0);

        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+nums[i];
        Map[0].push_back(0);
        
        int ret = 0;
        for (int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1];
            for (auto j: Map[presum[i] - target])
                dp[i] = max(dp[i], dp[j]+1);
            ret = max(ret, dp[i]);

            Map[presum[i]].push_back(i);
        }
        return ret;
    }
};
