using LL = long long;
class Solution {
    LL dp[105][105][105];
    LL M = 1e9+7;
public:
    int sumOfPower(vector<int>& nums, int k) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        dp[0][0][0] = 1;
        
        for (int i=1; i<=n; i++)
            for (int s=0; s<=k; s++)
                for (int j=0; j<=i; j++)
                {
                    dp[i][s][j] = dp[i-1][s][j];                    
                    if (s>=nums[i] && j>0)
                        dp[i][s][j] += dp[i-1][s-nums[i]][j-1]; 
                    dp[i][s][j] %= M;
                }
        
        vector<LL>power(10005);
        power[0] = 1;
        for (int i=1; i<=n; i++)
            power[i] = power[i-1]*2%M;
        
        LL ret = 0;
        for (int j=1; j<=n; j++)
        {
            LL t = dp[n][k][j];
            ret = (ret + t*power[n-j]%M) % M;
        }            
        
        return ret;
    }
};
