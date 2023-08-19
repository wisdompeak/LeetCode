class Solution {
    int dp[105][4];
public:
    int minimumOperations(vector<int>& nums) 
    {        
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i=1; i<=n; i++)
        {
            dp[i][1] = dp[i-1][1] + (nums[i]!=1);
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + (nums[i]!=2);
            dp[i][3] = min(min(dp[i-1][1], dp[i-1][2]), dp[i-1][3]) + (nums[i]!=3);
        }
        
        return min(min(dp[n][1], dp[n][2]), dp[n][3]);
            
    }
};
