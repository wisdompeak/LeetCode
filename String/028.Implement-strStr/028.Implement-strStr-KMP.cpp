class Solution {

public:
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        if (m==0) return 0;
        if (n==0) return -1;    

        vector<int> suf = preprocess(needle);
        
        vector<int>dp(n,0);
        dp[0] = (haystack[0]==needle[0]);
        if (m==1 && dp[0]==1)
            return 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && haystack[i]!=needle[j])
                j = suf[j-1];
            dp[i] = j + (haystack[i]==needle[j]);
            if (dp[i]==needle.size())
                return i-needle.size()+1;
        }
        return -1;
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
