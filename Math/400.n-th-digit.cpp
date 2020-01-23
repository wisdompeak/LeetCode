class Solution {
public:
    int findNthDigit(int N) 
    {
        int k = 0;
        long n = N;
        long nums = 0;
        while (n > 0)
        {        
            k++;    
            nums = kDigitNums(k);
            n -= nums;
        }

        if (n==0) return 9;

        n += nums;
        int m = n/k;
        if (n%k==0) m--;
        int r = n%k;
        if (r==0) r=k;

        int ret = pow(10,k-1) + m;
        return to_string(ret)[r-1] - '0';
    }

    long kDigitNums(int k)
    {
        return  (pow(10, k) - pow(10, k-1)) * k;
    }
};
