class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int N = nums.size();
        auto dp = vector<vector<long>>(N+1,vector<long>(m+1));
        nums.insert(nums.begin(),0);
        
        for (int i=1; i<=N; i++)
            dp[i][1] = dp[i-1][1]+nums[i];
        
        for (int i=1; i<=N; i++)
            for (int k=2; k<=min(m,i); k++)
            {
                dp[i][k] = INT_MAX;
                for (int j=1; j<=i-1; j++)
                {
                    long temp = max(dp[j][k-1],dp[i][1]-dp[j][1]);
                    dp[i][k] = min(dp[i][k], temp);
                }
            }
        
        return dp[N][m];
    }
};
