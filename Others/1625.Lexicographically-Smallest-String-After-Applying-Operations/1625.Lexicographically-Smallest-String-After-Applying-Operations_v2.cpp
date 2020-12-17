class Solution {
public:
    string findLexSmallestString(string s, int a, int b) 
    {
        string ret = s;
        int n = s.size();
        
        for (int k=0; k<=n/gcd(n,b); k++)
        {
            s = s.substr(n-b) + s.substr(0, n-b);            

            string t = s;
            int minHead = t[0]-'0';
            int count = 0;

            if (b%2==1)
            {
                for (int i=0; i<10; i++)
                {
                    if ((t[0]-'0' + i*a)%10 < minHead)
                    {
                        minHead =( t[0]-'0' + i*a) % 10;
                        count = i;
                    }
                }
                for (int i=0; i<n; i+=2)
                {
                    t[i] = (t[i]-'0'+a*count)%10+'0';
                }
            }

            minHead = t[1]-'0';
            count = 0;
            for (int i=0; i<10; i++)
            {
                if ((t[1]-'0' + i*a) % 10 < minHead)
                {
                    minHead = (t[1]-'0' + i*a)%10;
                    count = i;
                }
            }
            for (int i=1; i<n; i+=2)
            {
                t[i] = (t[i]-'0'+a*count)%10+'0';
            }

            ret = min(ret, t);
        }
        
        return ret;        
    }
};
