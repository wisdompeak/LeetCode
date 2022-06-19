class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        string t;
        while (k>0)
        {
            if (k%2==0)
                t.push_back('0');
            else
                t.push_back('1');
            k/=2;
        }
        reverse(t.begin(), t.end());
        
        int m = s.size();
        int n = t.size();
        
        if (m<n) return m;
        
        int ret = n-1;        
        ret = max(ret, countZeros(s, m-n+1) + n-1);
        
        int i = m-n;
        if (s.substr(i) <= t)
        {
            ret = max(ret, countZeros(s, i) + n);
        }
        
        return ret ;        
    }
    
    int countZeros(string&s, int k)
    {
        int count = 0;
        for (int i=0; i<k; i++)
            count+= s[i]=='0';
        return count;
    }
};
