class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int>dp(2*sum+2, false);
        int offset = sum;
        
        dp[stones[0]+offset] = 1;
        dp[-stones[0]+offset] = 1;
        
        for (int i=1; i<stones.size(); i++)
        {
            vector<int>dp2(2*sum+2, false);
            for (int s = -sum; s<= sum; s++)
            {                
                if (s-stones[i] >= -sum && s-stones[i] <= sum)
                    dp2[s+offset] = dp2[s+offset] || dp[s-stones[i]+offset];
                if (s+stones[i] >= -sum && s+stones[i] <= sum)                
                    dp2[s+offset] = dp2[s+offset] || dp[s+stones[i]+offset];                
            }
            dp = std::move(dp2);
        }
                
        for (int s = 0; s<=sum; s++)
            if (dp[s+offset])
                return s;
        return 0;
    }
};
