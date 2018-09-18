class Solution {
public:
    string shortestPalindrome(string s) 
    {
        if (s=="") return s;
        string t = s;
        reverse(t.begin(),t.end());
        
        int N = s.size();
        int len = N;
        while (s.substr(0,len)!=t.substr(N-len,len))
            len--;
        
        t = s.substr(len);
        reverse(t.begin(),t.end());
        return t+s;
        
    }
};
