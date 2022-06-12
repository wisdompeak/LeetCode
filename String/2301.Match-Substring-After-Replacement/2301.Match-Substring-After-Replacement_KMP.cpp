class Solution {
    // unordered_map<char, unordered_set<char>>>Map; // 't'-> {'7','8'}
    bool table[128][128];
    
public:
    bool equal(char x, char y)
    {
        return (x==y || table[y][x]);
    }
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        for (auto x: mappings)
            table[x[0]][x[1]] = 1;
        
        return strStr(s, sub)!= -1;        
    }
    
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        if (m==0) return 0;
        if (n==0) return -1;    

        vector<int> suf = preprocess(needle);
        
        vector<int>dp(n,0);
        dp[0] = equal(haystack[0], needle[0]);
        if (m==1 && dp[0]==1)
            return 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && !equal(haystack[i], needle[j]))
                j = suf[j-1];
            dp[i] = j + equal(haystack[i], needle[j]);
            if (dp[i]==needle.size())
                return i-needle.size()+1;
        }
        return -1;
    }
    
    bool equal2(char x, char y)
    {
        if (x==y) return true;
        for (int i=0; i<128; i++)
            if (table[x][i]==table[y][i])
                return true;
        return false;
    }

    vector<int> preprocess(string s)
    {
        int n = s.size();
        vector<int>dp(n,0);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && !equal2(s[j],s[i]))
            {
                j = dp[j-1];
            }          
            dp[i] = j + equal2(s[j],s[i]);
        }
        return dp;
    }
};
