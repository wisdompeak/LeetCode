class Solution {
public:
    int preimageSizeFZF(int K) 
    {
        long left = 1;
        long right = 5e9;
        
        while (left<right)
        {
            long mid = left+(right-left)/2;
            
            if (countTrailingZeros(mid) < K)
                left = mid+1;
            else if (countTrailingZeros(mid) > K)
                right = mid-1;
            else
                right = mid;
        }
        
        if (left>right) return 0;
        if (left==right && countTrailingZeros(left)==K)
            return 5;
        else
            return 0;
    }
    
    long countTrailingZeros(long x)
    {
        long count = 0;
        for (long i=5; i<=x; i=i*5)
            count += x/i;
        return count;
    }
};
