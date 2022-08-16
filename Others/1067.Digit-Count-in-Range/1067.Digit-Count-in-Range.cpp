class Solution {
public:
    int digitsCount(int d, int low, int high) 
    {       
        return helper(d, high)-helper(d,low-1);
    }
    
    int helper(int d, int n)
    {       
        string s = to_string(n);
        int len = s.size();
        int count = 0;
        
        if (d!=0)            
        {
            for (int i=1; i<=len; i++)
            {
                int divisor = pow(10,i);
                count += n/divisor * pow(10,i-1);
                
                int y = s[len-i]-'0';
                if (y > d)
                    count += pow(10,i-1);
                else if (y==d)
                    count += n%(int)(pow(10,i-1)) + 1;          
            }
        }
        else
        {
            for (int i=1; i<len; i++)
            {
                int divisor = pow(10,i);                                
                count += (n/divisor-1) * pow(10,i-1);
                
                int y = s[len-i]-'0';
                if (y > d)
                    count += pow(10,i-1);
                else if (y==d)
                    count += n%(int)(pow(10,i-1)) + 1;                    
            }
        }
        
        return count;
    }
};
