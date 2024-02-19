class Solution {
    int dp[100005][2];
public:
    int maxSelectedElements(vector<int>& nums) 
    {        
        sort(nums.begin(), nums.end());        
        int n = nums.size();
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        int ret = 1;
                
        for (int i=1; i<n; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;            
            
            if (nums[i] == nums[i-1])
            {
                dp[i][0] = max(dp[i][0], dp[i-1][0]+0);
                dp[i][1] = max(dp[i][1], dp[i-1][1]+0);
                dp[i][1] = max(dp[i][1], dp[i-1][0]+1);            
            }                
            else if (nums[i] - nums[i-1] == 1)
            {
                dp[i][0] = max(dp[i][0], dp[i-1][0]+1);
                dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
            }
            else if (nums[i] - nums[i-1] == 2)
                dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
                
            
            ret = max(ret, max(dp[i][0], dp[i][1]));
        }
        
        return ret;
    }
};
