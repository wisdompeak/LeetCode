class Solution {
public:
    int strangePrinter(string s) 
    {        
        int N = s.size();
        if (N==0) return 0;
        
        auto dp = vector<vector<int>>(N,vector<int>(N));
        for (int i=0; i<N; i++)
            dp[i][i] = 1;
                
        for (int len=2; len<=N; len++)
            for (int i=0; i<=N-len; i++)
            {
                int j = i+len-1;
                dp[i][j] = 1+dp[i+1][j];
                
                for (int k=i+1; k<=j; k++)
                {
                    if (s[k]==s[i])
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k-1] + ((k+1>j)?0:dp[k+1][j]));
                    }                        
                }    
                
            }        
        return dp[0][N-1];
    }
};
