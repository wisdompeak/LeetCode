class Solution {
public:
    string findLexSmallestString(string s, int a, int b) 
    {
        string ret = s;
        int n = s.size();

        int evenLimit = 10;
        if (b%2==0)
            evenLimit = 1;
        
        for (int i=0; i<evenLimit; i++)
            for (int j=0; j<10; j++)
            {
                string t = s;
                
                for (int k=0; k<n; k+=2)
                    t[k] = (t[k]-'0'+a*i) %10 + '0';
                for (int k=1; k<n; k+=2)
                    t[k] = (t[k]-'0'+a*j) %10 + '0';                
                
                string p = t;
                for (int k=0; k<=n/gcd(n,b); k++)
                {
                    p = p.substr(n-b) + p.substr(0, n-b);
                    ret = min(ret, p);
                }
            }
        
        return ret;        
    }
};
