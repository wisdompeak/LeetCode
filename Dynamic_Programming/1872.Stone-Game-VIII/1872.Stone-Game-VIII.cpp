class Solution {
public:
    int stoneGameVIII(vector<int>& stones) 
    {
        int n = stones.size();
        stones.insert(stones.begin(), 0);
        vector<int>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+stones[i];        
        
        vector<int>dp(n+1);
        dp[1] = 0;
        dp[2] = presum[n];
        int maxVal = max(presum[n]-dp[1], presum[n-1]-dp[2]);
        
        for (int i=3; i<=n; i++)
        {
            dp[i] = maxVal;
            maxVal = max(maxVal, presum[n-i+1]-dp[i]);
        }
        
        return dp[n];            
    }
};
