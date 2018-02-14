class Solution {
public:
    int numDecodings(string s) 
    {
        long long N=pow(10,9)+7;
        s = "x"+s;
        long long k, k1, k2 = 1;
        
        if (s[1]=='*') k1=9;
        if (s[1]=='0') k1=0;
        if (s[1]>='1' && s[1]<='9') k1=1;
        if (s.size()==2) return k1;        
        
        for (int i=2; i<s.size(); i++)
        {                
            if (s[i]=='0')
            {
                if (s[i-1]=='0' || s[i-1]>='3' && s[i-1]<='9')
                    return 0;
                else if (s[i-1]=='1'||s[i-1]=='2')
                    k=k2;
                else if (s[i-1]=='*')
                    k=k2*2;
            }
            else if (s[i]>='1' && s[i]<='6')
            {
                k=k1;
                if (s[i-1]=='*')
                    k+=k2*2;
                else if (s[i-1]=='0')
                    ;
                else
                {
                    int num=stoi(s.substr(i-1,2));
                    if (num>=11 && num<=26)
                    k+=k2;
                }                
            }
            else if (s[i]>='7' && s[i]<='9')
            {
                k=k1;
                if (s[i-1]=='*')
                    k+=k2;
                else if (s[i-1]=='0')
                    ;
                else
                {
                    int num=stoi(s.substr(i-1,2));
                    if (num>=11 && num<=26)
                    k+=k2;
                }
            }
            else if (s[i]=='*')
            {
                k=k1*9;
                if (s[i-1]=='*')
                    k+=k2*15;
                else if (s[i-1]=='0' || s[i-1]>='3' && s[i-1]<='9')
                    ;
                else if (s[i-1]=='1')
                    k+=k2*9;
                else if (s[i-1]=='2')
                    k+=k2*6;                
            }            
            
            k = k%N;
            k2 = k1;
            k1 = k;            
        }        
        return k;
    }
};
