class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int>dp(10001,0);
        for (int i=0; i<nums.size(); i++)
            dp[nums[i]]+=nums[i];
        
        for (int i=2; i<=10000; i++)             
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        return dp[10000];
    }
};
