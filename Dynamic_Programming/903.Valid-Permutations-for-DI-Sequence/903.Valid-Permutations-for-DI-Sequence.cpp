class Solution {
public:
    int numPermsDISequence(string S) 
    {
        S = "#"+S;
        int N = S.size();        
        auto dp = vector<vector<int>>(N+1,vector<int>(N+1,0));
        dp[1][1] = 1;
        int MOD = 1e9+7;
        for (int i=2; i<=N; i++)
            for (int j=1; j<=i; j++)
            {
                if (S[i-1]=='I')
                {
                    for (int k=1; k<j; k++)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
                }
                else
                {
                    for (int k=j; k<=i; k++)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        int result = 0;
        for (int j=1; j<=N; j++)
            result = (result+dp[N][j])%MOD;
        return result;
    }
};
