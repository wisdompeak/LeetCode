class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int m = str1.size();
        int n = str2.size();
        str1 = "#"+str1;
        str2 = "#"+str2;
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));

        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (str1[i]==str2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
       
        int i=m, j=n;
        string ret;
        while (i>0 && j>0)
        {
            if (str1[i]==str2[j])
            {
                ret.push_back(str1[i]);
                i--;
                j--;
            }
            else if (dp[i][j] == dp[i-1][j])
            {
                ret.push_back(str1[i]);
                i--;
            }
            else
            {
                ret.push_back(str2[j]);
                j--;
            }
        }
        
        while (i>0)
        {
            ret.push_back(str1[i]);
            i--;
        }
        while (j>0)
        {
            ret.push_back(str2[j]);
            j--;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
