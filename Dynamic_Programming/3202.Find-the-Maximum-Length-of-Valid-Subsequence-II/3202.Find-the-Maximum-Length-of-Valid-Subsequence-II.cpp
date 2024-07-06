class Solution {
    int dp[1005][1005];
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        vector<int>last(k, -1);
        int ret = 0;

        int n = nums.size();
        for (int i=0; i<n; i++)
        {
            for (int r=0; r<k; r++)
            {
                int d = (r - nums[i]%k + k) % k;
                if (last[d] != -1) 
                {
                    int j = last[d];
                    dp[i][r] = dp[j][r] + 1;
                } 
                else
                {
                    dp[i][r] = 1;
                }
                ret = max(ret, dp[i][r]);
            }
            last[nums[i]%k] = i;
        }

        return ret;
    }
};
