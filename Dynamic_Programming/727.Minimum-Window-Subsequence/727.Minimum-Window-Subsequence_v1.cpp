class Solution {
public:
    string minWindow(string S, string T) 
    {
        int m = S.size();
        int n = T.size();
        S = "#"+S;
        T = "#"+T;
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for (int j=1; j<=n; j++)
            dp[0][j] = INT_MAX/2;
        for (int i=0; i<=m; i++)
            dp[i][0] = 0;
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (S[i]==T[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = dp[i-1][j]+1;
            }
        
        int len  = INT_MAX/2;
        int pos;
        for (int i=1; i<=m; i++)
        {
            if (dp[i][n] < len)
            {
                len = dp[i][n];
                pos = i;
            }
        }
        
        if (len>=INT_MAX/2)
            return "";
        else
            return S.substr(pos-len+1,len);
        
    }
};
