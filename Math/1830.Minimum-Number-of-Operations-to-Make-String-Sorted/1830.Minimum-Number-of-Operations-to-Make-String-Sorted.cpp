typedef long long LL;
class Solution {
    LL mod = 1e9+7;
    int freq[26];
public:
    int makeStringSorted(string s) 
    {        
        for (auto ch:s)
            freq[ch-'a']++;
        
        LL factorial[3001];
        factorial[0] = 1;
        for (int i=1; i<=3000; i++)
            factorial[i] = factorial[i-1]*i%mod;

        LL ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            LL count = 0;
            for (int k=0; k<s[i]-'a'; k++)
                count+=freq[k];
            
            LL ans = factorial[s.size() - i - 1] % mod;
            for (int k=0; k<26; k++)
                ans = ans * inv(factorial[freq[k]]) % mod;
            
            ret = (ret + count * ans % mod) % mod;            
            freq[s[i]-'a']--;
        }
        return ret;
    }    
    
    LL inv(LL x) 
    {
        LL s = 1;
        for (; x > 1; x = mod %x)
          s = s*(mod - mod/x) % mod;
        return s;
    }
    
};
