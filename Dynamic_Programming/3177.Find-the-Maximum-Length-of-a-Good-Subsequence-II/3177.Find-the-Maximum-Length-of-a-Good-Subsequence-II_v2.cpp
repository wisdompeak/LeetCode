class Solution {
    int dp[5005][55];
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<unordered_map<int,int>>max_value(55);
        vector<int>max_all(55);
        
        int ret = 1;
        
        for (int i=0; i<n; i++)
        {
            for (int t=0; t<=k; t++)
            {
                int ans = 1;
                if (max_value[t].find(nums[i])!=max_value[t].end())
                    ans = max(ans, max_value[t][nums[i]] + 1);                
                if (t>=1)
                    ans = max(ans, max_all[t-1]+1);

                dp[i][t] = ans;
                ret = max(ret, ans);
            }

            for (int t=0; t<=k; t++)
            {
                max_value[t][nums[i]] = max(max_value[t][nums[i]], dp[i][t]);
                max_all[t] = max(max_all[t], dp[i][t]);
            }
        }
        
        return ret;      
    }
};
