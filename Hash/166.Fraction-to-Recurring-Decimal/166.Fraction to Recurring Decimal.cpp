class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if (numerator==0) return "0";
        
        long long A=(long long)numerator;
        long long B=(long long)denominator;
        
        int sign=1;
        if (A<0) 
        {
            sign*=-1;
            A=-A;
        }
        if (B<0) 
        {
            sign*=-1;
            B=-B;
        }        
        
        string result="";
        if (sign==-1) result="-";
        result+=to_string(A/B);
        
        long long t = A%B;
        
        if (t==0) return result;
        
        result+='.';
        
        unordered_set<int>Set;
        unordered_map<int,int>Map;
        
        while (t!=0 && Set.find(t)==Set.end())
        {
            Set.insert(t);
            Map[t]=result.size();
            
            result.push_back((t*10/B)+'0');
            t=t*10%B;
        }
        
        if (t==0) return result;
        
        int pos=Map[t];
        result.insert(result.begin()+pos,'(');
        result.push_back(')');
        
        cout<<result<<" "<<sign<<endl;
        
        return result;
        
    }
};
