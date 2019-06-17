class Solution {
public:
    int digitsCount(int d, int low, int high) 
    {       
        return helper(d, high)-helper(d,low-1);
    }
    
    int helper(int digit, int x)
    {       
        int len = to_string(x).size();
        int count = 0;
        
        if (digit!=0)            
        {
            for (int i=1; i<=len; i++)
            {
                int divisor = pow(10,i);
                count += x/divisor * pow(10,i-1);
                
                int y = (x - x/divisor*divisor)/pow(10,i-1);
                if (y > digit)
                    count += pow(10,i-1);
                else if (y==digit)
                    count += (x%(int)(pow(10,i-1)))+1;          
            }
        }
        else
        {
            for (int i=1; i<len; i++)
            {
                int divisor = pow(10,i);                                
                count += (x/divisor-1) * pow(10,i-1);
                
                int y = (x - x/divisor*divisor)/pow(10,i-1);
                if (y > digit)
                    count += pow(10,i-1);
                else if (y==digit)
                    count += (x%(int)(pow(10,i-1)))+1;                    
            }
        }
        
        return count;
    }
};
