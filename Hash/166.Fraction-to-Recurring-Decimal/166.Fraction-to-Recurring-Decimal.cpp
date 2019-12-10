class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        long A = numerator;
        long B = denominator;
        
        if (A==0) return "0";
        
        int sign = 1;
        if (A<0)
        {
            sign *= -1;
            A = abs(A);
        }
        if (B<0)
        {
            sign *= -1;
            B = abs(B);
        }
        
        string ret;
        if (sign==-1) ret = "-";
        
        ret += to_string(A/B);
        
        if (A%B==0) return ret;
        else ret+=".";
        
        long C = A%B;
        
        unordered_map<int,int>Map;
        
        while (C!=0 && Map.find(C)==Map.end())
        {
            Map[C] = ret.size();
            ret.push_back('0'+C*10/B);
            C = C*10%B;
        }
        
        if (C==0) return ret;
        
        ret.insert(ret.begin()+Map[C], '(');
        ret.push_back(')');
        
        return ret;
    }
};
