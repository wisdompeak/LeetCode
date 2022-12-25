using LL = long long;
class Solution {
    LL dp[1005][1005];
    LL M = 1e9+7;
public:
    int countPartitions(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        LL total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total < k*2) return 0;
        
        dp[0][0] = 1;
        dp[0][min(k, nums[0])] = 1;
        
        for (int i=0; i<n-1; i++)
            for (int s = 0; s<=k; s++)
            {                
                dp[i+1][s] = (dp[i+1][s] + dp[i][s]) % M;                
                dp[i+1][min(k, s+nums[i+1])] = (dp[i+1][min(k, s+nums[i+1])] + dp[i][s]) % M;             
            }
        
        LL d = 0;
        for (int s=0; s<k; s++)
            d = (d+dp[n-1][s]) % M;
        
        return (dp[n-1][k] - d + M) % M;        
    }
};
