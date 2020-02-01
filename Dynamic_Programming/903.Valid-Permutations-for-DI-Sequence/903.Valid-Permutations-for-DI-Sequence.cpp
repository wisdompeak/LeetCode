class Solution {
public:
    int numPermsDISequence(string S) 
    {
        int N = S.size();
        S = "#"+S;
        auto dp = vector<vector<int>>(N+1,vector<int>(N+1,0));

        dp[0][0] = 1;
        int M = 1e9+7;

        for (int i=1; i<=N; i++)
            for (int j=0; j<=i; j++)
            {
                if (S[i]=='I')
                {
                    for (int k=j; k<=N; k++)
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                }
                else
                {
                    for (int k=0; k<j; k++)
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                }
            }

        int ret = 0;
        for (int i=0; i<=N; i++)
            ret = (ret+dp[N][i])%M;
        return ret;
            
    }
};
