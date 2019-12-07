class Solution {
public:
    bool divisorGame(int N) 
    {
        vector<int>dp(N+1,0);
        
        dp[1] = 0;
        
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j*2<=i; j++)
            {
                if (i%j==0 && dp[i-j]==0)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};
