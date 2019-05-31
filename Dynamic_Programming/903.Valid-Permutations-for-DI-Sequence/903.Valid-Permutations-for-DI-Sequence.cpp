class Solution {
public:
    int numPermsDISequence(string S) 
    {
        int N = S.size();
        S = "#"+S;
        auto dp = vector<vector<int>>(N+1,vector<int>(N+1));
        dp[0][0] = 1;
        int M = 1e9+7;
        
        for (int i=1; i<=N; i++)        
            for (int j=0; j<=i; j++)
            {
                if (S[i]=='D')
                {
                    for (int k=j; k<=i-1; k++)
                    {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j]%=M;
                    }                        
                }
                else
                {
                    for (int k=0; k<j; k++)
                    {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j]%=M;
                    }                        
                }                    
            }
        
        int result = 0;
        for (int j=0; j<=N; j++)
            result = (result+dp[N][j])%M;
        
        return result;
    }
};
