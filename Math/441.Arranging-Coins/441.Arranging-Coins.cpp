class Solution {
public:
    int arrangeCoins(int n) 
    {
        if (n==0) return 0;
        long m = n;
        for (long k = sqrt(2*m)-1;  k < sqrt(2*m); k++)
        {
            if (k*(k+1) <= 2*m && 2*m < (k+1)*(k+2))
                return k;
        }
        return -1;        
    }
};
