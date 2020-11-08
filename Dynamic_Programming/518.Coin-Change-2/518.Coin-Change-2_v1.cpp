class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for (int i=0; i<coins.size(); i++)
        {            
            auto dp_temp = dp;            
            for (int c=1; c<=amount; c++)
            {
                dp[c] = 0;
                for (int k=0; k<=c/coins[i]; k++)
                    if (c>=k*coins[i])
                        dp[c] += dp_temp[c-k*coins[i]];
            }
        }
        return dp[amount];        
    }    
};
