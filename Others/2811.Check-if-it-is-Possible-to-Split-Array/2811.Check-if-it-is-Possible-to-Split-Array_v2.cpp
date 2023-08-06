class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) 
    {        
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+nums[i];
        
        vector<vector<int>>dp(n+1, vector<int>(n+1, 1));
        for (int len=3; len<=n; len++)
            for (int i=1; i+len-1<=n; i++)
            {
                int j = i+len-1;
                dp[i][j] = (dp[i][j-1]&&(presum[j-1]-presum[i-1]>=m)) || (dp[i+1][j]&&(presum[j]-presum[i]>=m));
            }
        
        return dp[1][n];
    }
};
