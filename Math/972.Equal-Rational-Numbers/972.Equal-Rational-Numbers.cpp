class Solution {
public:
    bool isRationalEqual(string S, string T) 
    {
        double valS,valT;
        string strS, strT;
        bool isValS = parseVal(S, valS, strS);
        bool isValT = parseVal(T, valT, strT);
        
        if (isValS!=isValT)
            return false;
        if (isValS)
            return abs(valS-valT)<1e-12;
        else
            return strS==strT;
        
    }
    
    bool parseVal(string S, double &val, string &str)
    {
        int i = S.find("(");
        if (i==-1)
        {
            val = stod(S);
            return true;
        }
        
        // "x.y(z)""
        string a = S.substr(0,i);       // a => x.y
        string b = S.substr(i+1, S.size()-i-2);     // b=> z
        
        bool flag0 = true;
        for (auto ch: b)
        {
            if (ch!='0')
            {
                flag0 = false;
                break;
            }
        }
        if (flag0)
        {
            val = stod(a);
            return true;
        }
        
        bool flag9 = true;
        for (auto ch: b)
        {
            if (ch!='9')
            {
                flag9 = false;
                break;
            }
        }
        if (flag9)
        {
            int i = a.find(".");
            int k = a.size()-1-i;
            val = stod(a) + 1.0/pow(10,k);
            return true;
        }
        
        while (a.size()<20)
            a+=b;
        str = a.substr(0,20);
        return false;        
    }
};
