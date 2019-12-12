class Solution {
public:
    int countDigitOne(int n) 
    {
        if (n<0) return 0;
        
        int count = 0;
        string str = to_string(n); 
        
        reverse(str.begin(),str.end());
        
        for (int i=1; i<=str.size(); i++)
        {
            int a = n/(int)pow(10,i);
            count += a*(int)pow(10,i-1);
            
            int digit = str[i-1]-'0';
            
            if (digit>1)
                count += pow(10,i-1);
            else if (digit==1)
                count += n%(int)pow(10,i-1)+1;
        }
        
        return count;
    }
};
