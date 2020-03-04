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
            dp[i] = dp[i-1]+1;
            for (int j=0; j<=i-2; j++)
            {                                
                dp[i] = max(dp[i], dp[i-j-2]*(j+1));
            }
        }
        return dp[N];        
    }
};
