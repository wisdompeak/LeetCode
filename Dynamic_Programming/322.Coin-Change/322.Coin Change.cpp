class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount==0) return 0;
        
        vector<int>dp(amount+1,-1);
        
        for (int i=0;i<coins.size(); i++)
        {
            if (coins[i]>amount) continue;
            dp[coins[i]]=1;
        }
        
        for (int k=1; k<=amount; k++)
        {
            if (dp[k]!=-1) continue;

            
            int temp = INT_MAX;
            for (int i=0; i<coins.size(); i++)
            {
                if (k-coins[i]>0 && dp[k-coins[i]]!=-1)
                {
                    temp = min(temp, dp[k-coins[i]]+1);
                }
            }
            if (temp==INT_MAX) 
                dp[k] = -1;
            else
                dp[k] = temp;
        
        return dp[amount];
        
    }
};
