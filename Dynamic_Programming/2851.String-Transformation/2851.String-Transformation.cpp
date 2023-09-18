using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int numberOfWays(string s, string t, long long k) 
    {
        string ss = s+s;
        ss.pop_back();
        int p = strStr(ss,t);

        int n = s.size();
        vector<LL> T = {n-p-1, n-p, p, p-1};
        vector<LL> Tk = quickMul(T, k);

        if (s==t)
            return Tk[3];  // Tk * (0, 1)'
        else
            return Tk[2];  // Tk * (1, 0)'
    }

    vector<LL> multiply(vector<LL>mat1, vector<LL>mat2)
    {
        // a1 b1     a2  b2
        // c1 d1     c2  d2
        LL a1 = mat1[0], b1 = mat1[1], c1 = mat1[2], d1 = mat1[3];
        LL a2 = mat2[0], b2 = mat2[1], c2 = mat2[2], d2 = mat2[3];
        return {(a1*a2+b1*c2)%M, (a1*b2+b1*d2)%M, (c1*a2+d1*c2)%M, (c1*b2+d1*d2)%M};
    }

    vector<LL> quickMul(vector<LL>mat, LL N) {
        if (N == 0) {
            return {1,0,0,1};
        }
        vector<LL> mat2 = quickMul(mat, N/2);
        if (N%2==0)
            return multiply(mat2, mat2);
        else
            return multiply(multiply(mat2, mat2), mat);
    }

    int strStr(string haystack, string needle) 
    {
        int count = 0;

        int n = haystack.size();
        int m = needle.size();
        
        vector<int> suf = preprocess(needle);
        
        vector<int>dp(n,0);
        dp[0] = (haystack[0]==needle[0]);
        if (m==1 && dp[0]==1)
            count++;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && haystack[i]!=needle[j])
                j = suf[j-1];
            dp[i] = j + (haystack[i]==needle[j]);
            if (dp[i]==needle.size())
                count++;
        }
        return count;
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
