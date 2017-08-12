class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        auto dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for (int k=0; k<strs.size(); k++)
        {
            int ones=0;
            int zeros=0;
            for (int i=0; i<strs[k].size(); i++)
            {
                if (strs[k][i]=='0') zeros++;
                else ones++;
            }
                            
            auto temp=dp;
            for (int i=zeros; i<=m; i++)
             for (int j=ones; j<=n; j++)
             {
                 dp[i][j]=max(temp[i][j],temp[i-zeros][j-ones]+1);
             }
        }
                
        return dp[m][n];
    }
};
