class Solution {
    vector<int> strStr(string haystack, string needle) 
    {
        vector<int>rets;
        
        int n = haystack.size();
        int m = needle.size();
        if (m==0) return {};
        if (n==0) return {};    

        vector<int> suf = preprocess(needle);
        
        vector<int>dp(n,0);
        dp[0] = (haystack[0]==needle[0]);
        if (m==1 && dp[0]==1)
            rets.push_back(0);

        
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && haystack[i]!=needle[j])
                j = suf[j-1];
            dp[i] = j + (haystack[i]==needle[j]);
            if (dp[i]==needle.size())
                rets.push_back(i-needle.size()+1);
        }
        return rets;
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
    
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) 
    {
        vector<int> A = strStr(s,a);
        vector<int> B = strStr(s,b);

        vector<int>rets;
        for (int i:A)
        {
            auto iter1 = lower_bound(B.begin(), B.end(), i-k);
            auto iter2 = upper_bound(B.begin(), B.end(), i+k);
            if (iter2-iter1>=1)
                rets.push_back(i);            
        }
        return rets;
        
    }
};
