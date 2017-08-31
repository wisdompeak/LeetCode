class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if (n1+n2!=n3) return false;

        s1.insert(s1.begin(),'0');
        s2.insert(s2.begin(),'0');
        s3.insert(s3.begin(),'0');
        
        auto dp=vector<vector<int>>(n1+1,vector<int>(n2+1,0));

        dp[0][0]=1;
        
        for (int i=1; i<=n1; i++)
        {
            if (dp[i-1][0]==1 && s1[i]==s3[i])
                dp[i][0]=1;
        }
        
        for (int j=1; j<=n2; j++)
        {
            if (dp[0][j-1]==1 && s2[j]==s3[j])
                dp[0][j]=1;
        }
        
        for (int i=1; i<=n1; i++)
         for (int j=1; j<=n2; j++)
         {
             if (dp[i-1][j]==1 && s1[i]==s3[i+j])
                 dp[i][j]=1;
             else if (dp[i][j-1]==1 && s2[j]==s3[i+j])
                 dp[i][j]=1;
         }
        
        return dp[n1][n2];
    }
};
