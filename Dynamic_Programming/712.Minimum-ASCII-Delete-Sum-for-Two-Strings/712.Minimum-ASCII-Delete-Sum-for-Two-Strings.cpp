class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int m=s1.size();
        int n=s2.size();
        auto dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        s1.insert(s1.begin(),'0');
        s2.insert(s2.begin(),'0');
        
        for (int i=1; i<=m; i++)
            dp[i][0]=dp[i-1][0]+s1[i];
        
        for (int j=1; j<=n; j++)
            dp[0][j]=dp[0][j-1]+s2[j];
        
        for (int i=1; i<=m; i++)
         for (int j=1; j<=n; j++)
         {
             if (s1[i]==s2[j])
                 dp[i][j]=dp[i-1][j-1];
             else
             {
                 dp[i][j] = min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j]);                 
             }
         }
        
        return dp[m][n];
    }
};
