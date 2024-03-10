using LL = long long;
class Solution {    
public:
    long long maximumStrength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        vector<vector<vector<LL>>>dp(n+1, vector<vector<LL>>(k+1, vector<LL>(2, LLONG_MIN/3)));
               
        for (int i=0; i<=n; i++)
        {
            dp[i][0][0] = 0;
        }
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=k; j++)
            {
                if (j%2==0)
                {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
                    dp[i][j][1] = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][1])) - (LL)nums[i]*(k+1-j);                                        
                }
                else
                {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
                    dp[i][j][1] = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][1])) + (LL)nums[i]*(k+1-j);
                }                
            }
        
        return max(dp[n][k][0],dp[n][k][1]);
                
    }
};
