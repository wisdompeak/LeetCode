class Solution {
public:
    int minimumOneBitOperations(int n) 
    {
        if (n==0) return 0;
        string str = bitset<32>(n).to_string();
        int i = 0;
        while (i<str.size() && str[i]=='0')
            i++;
        str = str.substr(i);

        int lastDigit = 0;
        int ret = 0;
        for (int i=0; i<str.size(); i++)
        {
            // x ^ lastDigit = str[i]
            int x;
            if (str[i]=='1')
                x = lastDigit==1 ? 0 : 1;
            else
                x = lastDigit==1 ? 1 : 0;
            lastDigit = x;
            ret = ret*2+x;
        }

        return ret;        
    }    
};
