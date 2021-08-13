class Solution {
public:
    int countDigitOne(int n) 
    {
        string N = to_string(n);
        long len = N.size();
        long count = 0;
        
        for (int i=1; i<=len; i++)
        {   
            long divisor = pow(10,i);
            count += n/divisor*1*pow(10,i-1);

            int digit = N[len-i]-'0';
            
            if (digit > 1)
                count += pow(10,i-1);
            else if (digit == 1)
                count += n%(int)pow(10,i-1) + 1;
        }
        return count;
    }
};
