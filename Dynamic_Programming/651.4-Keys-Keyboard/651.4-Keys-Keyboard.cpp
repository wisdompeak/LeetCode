class Solution {
public:
    int maxA(int N) 
    {
        if (N==1) return 1;
        
        vector<int>dp(N+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i=3; i<=N; i++)
        {            
            for (int j=0; j<=i-1; j++)
            {
                dp[i] = max(dp[i], dp[j]+i-j);
                if (i-j>=2)
                    dp[i] = max(dp[i], dp[j]*(i-j-2+1));
            }
        }
        return dp[N];        
    }
};
