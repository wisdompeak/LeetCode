class Solution {
    bool table[256][256];
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        int m = s.size();
        
        for (auto x: mappings)
        {
            table[x[0]][x[1]] = 1;
        }
        
        return strStr(s, sub)!=-1;        
    }

    bool equal(char a, char b)
    {
        return (a==b || table[b][a]);
    }

    int strStr(string haystack, string needle) 
    {
        string s = haystack;
        string p = needle;
        int n = s.size();
        int m = p.size();
        
        if (m==0) return 0;
        if (n==0) return -1;
        
        vector<int>dp(n,0);
        dp[0] = equal(s[0], p[0]);
        if (m==1 && dp[0]==1)
            return 0;
        
        vector<int>suffix = preprocess(p);
        
        for (int i=1; i<n; i++)
        {
            // compute dp[i]
            int j = dp[i-1];
            while (j>0 && !equal(s[i], p[j]))
                j = suffix[j-1];
            dp[i] = j + equal(s[i], p[j]);

            if (dp[i]==p.size())
                return i - p.size() + 1;
        }
        
        return -1;
        
    }
    
    vector<int> preprocess(string s) 
    {
        int n = s.size();
        vector<int>dp(n);
        dp[0] = 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && !equal(s[j],s[i]))
            {
                j = dp[j-1];
            }          
            dp[i] = j + equal(s[j], s[i]);
        }

        return dp;
    }
};
