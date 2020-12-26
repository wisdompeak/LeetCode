class Solution {
public:
    string maximumBinaryString(string binary) 
    {
        int ones = 0, zeros = 0;        
        for (auto ch:binary)
        {
            if (ch=='1')
                ones++;
            else
                zeros++;
        }
        if (zeros <= 1)
            return binary;
        
        string ret;      
        int i = 0;  
        while (i<binary.size() && binary[i]=='1')
        {
            ret+="1";
            ones--;
            i++;
        }        
            
        for (int i=0; i<zeros-1; i++)
            ret+="1";
        ret+="0";
        for (int i=0; i<ones; i++)
            ret+="1";
    
        return ret;        
    }
};
