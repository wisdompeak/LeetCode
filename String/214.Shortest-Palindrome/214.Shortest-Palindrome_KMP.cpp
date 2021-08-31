class Solution {
public:
    string shortestPalindrome(string s) 
    {
        if (s=="") return s;
        string r = s;
        reverse(r.begin(), r.end());
        vector<int>suf = preprocess(s);

        // s = A'AB
        // r = BA'A

        int n = r.size();        
        vector<int>dp(n,0);
        dp[0] = (r[0]==s[0]);

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && s[j]!=r[i])
                j = suf[j-1];
            dp[i] = j + (s[j]==r[i]);
        }

        int len = dp[n-1];
        string ret = s.substr(len);
        reverse(ret.begin(), ret.end());
        ret += s;
        return ret;
    }

    vector<int> preprocess(string s)
    {
        int n = s.size();
        vector<int>dp(n,0);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && s[j]!=s[i])
            {
                j = dp[j-1];
            }          
            dp[i] = j + (s[j]==s[i]);
        }
        return dp;
    }
};
