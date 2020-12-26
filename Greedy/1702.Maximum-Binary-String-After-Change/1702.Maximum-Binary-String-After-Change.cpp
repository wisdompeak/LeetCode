class Solution {
public:
    string maximumBinaryString(string binary) 
    {
        int n = binary.size();
        int m = 0;        
        for (auto ch:binary)
        {
            if (ch=='0')
                m++;
        }
        if (m<=1)  return binary;
        
        string ret;      
        int i = 0;  
        while (i<binary.size() && binary[i]=='1')
        {
            ret+="1";
            i++;
        }                    
        for (int i=0; i<m-1; i++)
            ret+="1";
        ret+="0";
        while (ret.size() < n)
            ret+="1";
    
        return ret;        
    }
};
