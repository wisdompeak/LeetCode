class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int M = str1.size();
        int N = str2.size();
        str1 = "#"+str1;
        str2 = "#"+str2;

        auto dp = vector<vector<int>>(M+1,vector<int>(N+1));
        for (int i=0; i<=M; i++)
            dp[i][0] = i;
        for (int j=0; j<=N; j++)
            dp[0][j] = j;

        for (int i=1; i<=M; i++)
            for (int j=1; j<=N; j++)
            {
                if (str1[i]==str2[j])                
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j])+1;
            }

        int i=M;
        int j=N;
        string result;
        while (i>0 && j>0)
        {            
            if (str1[i]==str2[j])
            {
                result.push_back(str1[i]);
                i--;
                j--;                
            }
            else if (dp[i][j]==dp[i-1][j]+1)
            {
                result.push_back(str1[i]);
                i--;                
            }            
            else {
                result.push_back(str2[j]);
                j--;
            }
        }
        while (i>0)
        {
            result.push_back(str1[i]);
            i--;
        }
        while (j>0)
        {
            result.push_back(str2[j]);
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
