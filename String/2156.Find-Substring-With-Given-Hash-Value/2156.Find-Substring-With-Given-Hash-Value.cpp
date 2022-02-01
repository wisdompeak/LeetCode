using LL = long long;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) 
    {
        int n = s.size();
        LL sum = 0, M = modulo;
        
        LL pk = 1;
        for (int i=0; i<k-1; i++)
            pk = pk*power%M;                
        
        int ret = -1;
        for (int i=n-1; i>=0; i--)
        {            
            if (i+k<n)
            {
                sum = sum - (s[i+k]-'a'+1) * pk % M;
                sum = (sum + M) % M;
            }
            
            sum = (sum * power % M + s[i]-'a'+1) % M;
            sum = (sum + M) % M;
            
            if (i+k<=n && sum==hashValue)
                ret = i;
        }
        
        return s.substr(ret, k);
    }
};
