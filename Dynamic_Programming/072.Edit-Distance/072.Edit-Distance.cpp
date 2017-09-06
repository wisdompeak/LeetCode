class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n1=word1.size();
        int n2=word2.size();
        word1.insert(word1.begin(),'0');
        word2.insert(word2.begin(),'0');
        
        auto dp=vector<vector<int>>(n1+1,vector<int>(n2+1,INT_MAX));        
        
        dp[0][0]=0;
        for (int i=1; i<=n1; i++)
            dp[i][0]=i;
        for (int j=1; j<=n2; j++)
            dp[0][j]=j;
        
        for (int i=1; i<=n1; i++)
         for (int j=1; j<=n2; j++)
         {
             if (word1[i]==word2[j])
                 dp[i][j]=dp[i-1][j-1];
             else
             {
                 dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                 dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                 dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
             }                 
         }
        
        return dp[n1][n2];
    }
};
