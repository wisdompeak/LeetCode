class Solution {
public:
    int minCut(string s) 
    {
        int N = s.size();
        
        auto isPal = vector<vector<bool>>(N,vector<bool>(N,0));
        for (int len = 1; len<=N; len++)
            for (int i=0; i<=N-len; i++)
            {
                int j = i+len-1;
                // update isPal[i][j]
                if (s[i]==s[j])
                {
                    if (i+1>=j-1)
                        isPal[i][j] = true;
                    else 
                        isPal[i][j] = isPal[i+1][j-1];
                }
            }
        
        
        vector<int>dp(N, INT_MAX/2);
        
        dp[0] = 1;
        
        for (int i=1; i<N; i++)
        {
            for (int j=0; j<=i; j++)
            {
                if (isPal[j][i])
                {
                    if (j==0)
                        dp[i] = 1;
                    else
                        dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        
        return dp[N-1]-1;
    }
    
};
