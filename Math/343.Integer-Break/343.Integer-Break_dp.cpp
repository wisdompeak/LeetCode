class Solution {
public:
    int integerBreak(int n) 
    {
        if (n==2) return 1;
        if (n==3) return 2;
        vector<int>dp(n+1,0);
        dp[2] = 2;
        dp[3] = 3;
        for (int i=4; i<=n; i++)
        {
            int temp = 0;
            for (int j=2; j<=i/2; j++)
            {
                if (dp[j]*dp[i-j]>temp)
                    temp = dp[j]*dp[i-j];
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
