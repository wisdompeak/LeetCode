class Solution {
public:
    int arrangeCoins(int n) 
    {
        long m = n;
        for (long k = sqrt(2*m)-2;  k < sqrt(2*m)+2; k++)
        {
            if (k*(k+1) <= 2*m && 2*m < (k+1)*(k+2))
                return k;
        }
        return -1;
        
    }
};
