class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) 
    {
        auto dp = vector<vector<long>>(L+1,vector<long>(N+1,0));
        dp[1][1] = N;
        long MOD = 1e9+7;
        
        for (int i=2; i<=L; i++)
            for (int j=1; j<=min(N,i); j++)
            {
                if (j>K) dp[i][j] += dp[i-1][j]*(j-K);
                dp[i][j]%=MOD;
                if (N>j-1) dp[i][j] += dp[i-1][j-1]*(N-j+1);
                dp[i][j]%=MOD;                
            }
        
        return dp[L][N];
    }
};
