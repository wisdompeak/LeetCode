class Solution {
    int dp[1005][1005];
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) 
    {        
        int n = nums.size();
        int ret = 0;

        dp[0][n-1] = 0;
        for (int len = n-1; len >=1; len--)
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                if (i-1>=0)
                {
                    int t = dp[i-1][j];                    
                    if (t<queries.size() && nums[i-1] >= queries[t])
                        dp[i][j] = max(dp[i][j], t + 1);
                    else
                        dp[i][j] = max(dp[i][j], t);
                }
                if (j+1<n)
                {
                    int t = dp[i][j+1];
                    if (t<queries.size() && nums[j+1] >= queries[t])
                        dp[i][j] = max(dp[i][j], t + 1);
                    else
                        dp[i][j] = max(dp[i][j], t);
                }                              
            }

        for (int i=0; i<n; i++)
        {
            if (dp[i][i]<queries.size() && nums[i]>=queries[dp[i][i]])
                ret = max(ret, dp[i][i]+1);  
            else
                ret = max(ret, dp[i][i]);
        }
        return ret;
    }
};
