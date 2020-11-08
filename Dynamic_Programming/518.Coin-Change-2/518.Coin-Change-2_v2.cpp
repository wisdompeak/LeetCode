class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for (int i=0; i<coins.size(); i++)
        {                        
            for (int c=1; c<=amount; c++)
            {        
                if (c>=coins[i])
                    dp[c] += dp[c-coins[i]];
            }
        }
        return dp[amount];        
    }    
};
