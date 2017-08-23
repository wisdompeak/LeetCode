class Solution {
public:
    int maxA(int N) 
    {
        vector<int>dp(N+1,0);
                
        dp[1]=1;
        dp[2]=2;
                    
        for (int i=3; i<=N; i++)
        {
            dp[i]=i;
            for (int j=1; j<i; j++)
            {
                dp[i]=max(dp[i],dp[j]+i-j);
                if (j>2)
                    dp[i]=max(dp[i],dp[j]*(i-j-2+1));
            }
        }
        
        return dp[N];
    }
};
