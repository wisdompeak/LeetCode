class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        
        auto dp = vector<vector<int>>(n, vector<int>(n,0));
        for (int i=0; i<n; i++)
            dp[i][i] = nums[i];
        
        for (int len = 2; len <=n; len++)
            for (int i= 0; i+len-1<n; i++)
            {
                int j = i+len-1;
                dp[i][j] = max(nums[i]+ ((i+2>j)?0:dp[i+2][j]), dp[i+1][j]);
            }
        
        return max(nums[0]+((2>n-2)?0:dp[2][n-2]), dp[1][n-1]);
    }
};
