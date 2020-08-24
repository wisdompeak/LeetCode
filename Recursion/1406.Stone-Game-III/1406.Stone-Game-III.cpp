class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
        stoneValue.insert(stoneValue.begin(),0);

        vector<int>presum(n+1,0);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+stoneValue[i];

        vector<int>dp(n+1,INT_MIN);  // dp[i] : the max score when player can get after i piles have been taken
        dp[n] = 0;

        for (int i = n-1; i >= 0; i--)
        {
            int sum = 0;
            for (int k=1; k<=3; k++)
            {
                if (i+k>n) break;
                sum += stoneValue[i+k];
                dp[i] = max(dp[i], sum + presum[n]-presum[i+k]-dp[i+k]);
            }
        }

        if (dp[0] > presum[n]-dp[0])
            return "Alice";
        else if (dp[0] < presum[n]-dp[0])
            return "Bob";
        else
            return "Tie";

    }
};
