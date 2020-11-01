class Solution {
    long long p[1005][27];
    long long dp[1005][1005];
    long long M = 1e9+7;
public:
    int numWays(vector<string>& words, string target) 
    {
        int m = 0;
        for (auto word: words)
        {
            m = max(m, (int)word.size());
            for (int i=0; i<word.size(); i++)                
                p[i+1][word[i]-'a']+=1;
        }
                    
        int n = target.size();
        target = "#"+target;
        for (int k=0; k<=m; k++)
            dp[0][k] = 1;
        
        for (int i=1; i<=n; i++)
            for (int k=1; k<=m; k++)
            {
                dp[i][k] = dp[i][k-1];
                if (p[k][target[i]-'a']!=0)
                {
                    dp[i][k] += dp[i-1][k-1]*p[k][target[i]-'a']%M;
                    dp[i][k]%=M;
                }
                
            }
        return dp[n][m];        
    }
};
