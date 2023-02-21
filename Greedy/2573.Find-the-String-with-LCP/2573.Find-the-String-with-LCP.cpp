class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) 
    {
        int n = lcp.size();
        string s(n, '0');

        int i = 0;
        for (char ch = 'a'; ch<='z'; ch++)
        {
            while (i<n && s[i]!='0')
                i++;
            if (i==n) break;
            for (int j=0; j<n; j++)
            {
                if (lcp[i][j]!=0)
                    s[j] = ch;
            }            
        }        
        for (int i=0; i<n; i++)
            if (s[i]=='0') return "";

        vector<vector<int>>dp(n, vector<int>(n,0));
        for (int i=n-1; i>=0; i--)
            for (int j=n-1; j>=0; j--)
            {                
                if (s[i]==s[j])
                    dp[i][j] = (i==n-1 || j==n-1)? 1: (dp[i+1][j+1] + 1);
                if (dp[i][j] != lcp[i][j])
                    return "";
            }                

        return s;
    }
};
