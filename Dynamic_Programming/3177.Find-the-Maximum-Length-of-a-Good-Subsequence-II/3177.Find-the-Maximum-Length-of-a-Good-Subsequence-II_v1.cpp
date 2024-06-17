class Solution {
    int dp[505][26];
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        int ret = 1;
        
        for (int i=0; i<n; i++)
        {
            for (int t=0; t<=k; t++)
            {
                int ans = 1;

                for (int j=0; j<i; j++)
                {
                    if (nums[j]==nums[i])
                        ans = max(ans, dp[j][t]+1);
                    else if (t>=1)
                        ans = max(ans, dp[j][t-1]+1);
                }

                dp[i][t] = ans;
                ret = max(ret, ans);
            }
        }
        
        return ret;      
    }
};
