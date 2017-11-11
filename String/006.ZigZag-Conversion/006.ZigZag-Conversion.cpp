class Solution {
public:
    string convert(string s, int numRows) 
    {        
        int T=numRows*2-2;
        if (T==0) return s;
        string result;
        
        for (int i=0; i<=T/2; i++)
        {
            int a=i;
            int b=T-a;
            while (a<s.size())
            {
                result+=s[a];
                if (b<s.size() && b!=a && b!=a+T)
                    result+=s[b];
                a+=T;
                b+=T;
            }
        }
        return result;
    }
};
