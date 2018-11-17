class Solution {
public:
    int countPalindromicSubsequences(string S) 
    {
        int M = 1e9+7;
        int N = S.size();
        auto next = vector<vector<int>>(N,vector<int>(4,N));
        auto prev = vector<vector<int>>(N,vector<int>(4,-1));        
        auto dp = vector<vector<int>>(N,vector<int>(N,0));  
        
        for (int k=0; k<4; k++)
        {
            int i = 0;
            for (int j=0; j<N; j++)
            {
                if (S[j]!='a'+k) continue;
                while (i<=j)
                {
                    next[i][k] = j;
                    i++;
                }
            }
        }
        
        for (int k=0; k<4; k++)
        {
            int i = N-1;
            for (int j=N-1; j>=0; j--)
            {
                if (S[j]!='a'+k) continue;
                while (i>=j)
                {
                    prev[i][k] = j;
                    i--;
                }
            }
        }
        
        for (int i=0; i<N; i++) dp[i][i]=1;
        
        for (int len = 2; len<=N; len++)
            for (int i=0; i<=N-len; i++)
            {
                int j = i+len-1;
                for (int k=0; k<4; k++)
                {
                    if (next[i][k]<prev[j][k])
                        dp[i][j]+=dp[next[i][k]+1][prev[j][k]-1]+1;
                    if (next[i][k]<=j)
                        dp[i][j]+=1;
                    dp[i][j] = dp[i][j]%M;                                        
                }
            }
        return dp[0][N-1];
    }
};
